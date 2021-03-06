#ifndef DEBUG_H_NSE
#define DEBUG_H_NSE

#include <nse/block_base.hpp>
#include <nse/dynamic_block.hpp>
#include <iostream>
#include <fstream>
#include <string>

#ifndef nse_debug_mode
    #define nse_debug_mode true
#endif
#if nse_debug_mode == false
    #define nse_debug_mode_enable true
#else
    #define nse_debug_mode_enable false
#endif

#define nse_debug if (nse_debug_mode_enable) {} else std::cout << std::endl

namespace graphic
{
    inline std::ostream &operator<<(std::ostream &os, char c)
    {
        return os << (std::is_signed<char>::value ? static_cast<int>(c) : static_cast<unsigned int>(c));
    }

    inline std::ostream &operator<<(std::ostream &os, signed char c)
    {
        return os << static_cast<int>(c);
    }

    inline std::ostream &operator<<(std::ostream &os, unsigned char c)
    {
        return os << static_cast<unsigned int>(c);
    }
} // graphic


namespace nse
{
    class debug
    {
    public:
        static void display(block_base& buf, size_t split = 0)
        {
            for(size_t i = 0; i < buf.size(); ++i)
            {
                if (split != 0 && i % split == 0 && i > 0) std::cout << std::endl;
                using namespace std;
                auto p = static_cast<uint8_t>(buf.at(i));
                using namespace graphic;
                if (p < 10) std::cout << "0";
                if (p < 100) std::cout << "0";
                cout << p << " ";
            }
            std::cout << std::endl;
        }

        static void display_info(block_base& buf, size_t split = 0)
        {
            std::cout << "\n////////////////////////////////  BLOCK";
            std::cout << "\ncapacity : " << buf.capacity();
            std::cout << "\ndata_size : " << buf.size();
            std::cout << "\nDATA\n";
            for(size_t i = 0; i < buf.size(); ++i)
            {
                if (split != 0 && i % split == 0 && i > 0) std::cout << std::endl;
                using namespace std;
                auto p = static_cast<uint8_t>(buf.at(i));
                using namespace graphic;
                if (p < 10) std::cout << "0";
                if (p < 100) std::cout << "0";
                cout << p << " ";
            }
            std::cout << "\nEND\n";
        }

        static void display_file(block_base& b, size_t split = 0)
        {
            std::remove("debug.txt");
            std::fstream fs("debug.txt", std::ios::app | std::ios::out | std::ios::binary);
            std::cout << "\ndebug file created";
            std::string info = "Block info :";
            info += "\ncapacity : " + std::to_string(b.capacity());
            info += "\ndata_size : " + std::to_string(b.size());
            info += "\nDATA";
            fs.write(info.c_str(), info.size());
            fs.write(b.data(), b.size());
        }
    };
} // nse

#endif // DEBUG_H_NSE
