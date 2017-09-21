#ifndef ENGINE_NSE_NSE_H_NDB
#define ENGINE_NSE_NSE_H_NDB

#include <ndb/engine.hpp>
#include <ndb/model.hpp>
#include <iostream>

namespace ndb
{
    class nse : engine<nse>
    {
    public:
        template<class Model>
        static constexpr void make()
        {
            constexpr generic_model<Model> m;

            static_assert(m.get<0>() == 0x61, "");
            //std::cout << "\nmake : " << Model::name_ << " test : " << m.get<0>() << m.get<1>();
        }
    };
} // db

#endif // ENGINE_NSE_NSE_H_NDB