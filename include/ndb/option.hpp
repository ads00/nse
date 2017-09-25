#ifndef OPTION_H_NDB
#define OPTION_H_NDB

namespace ndb
{
    struct field_option
    {
        struct none { static constexpr auto value = 0; };
        struct unique { static constexpr auto value = 1; };
        struct autoincrement { static constexpr auto value = 2; };
        struct primary { static constexpr auto value = 4; };
        struct not_null { static constexpr auto value = 8; };
    };

    template<class...>
    class option {};

    template<class Needle, class Haystack>
    class has_option;

    template<class Needle, template<class...> class Haystack, class T1, class... T>
    struct has_option<Needle, Haystack<T1, T...>> { static constexpr bool value = has_option<Needle, Haystack<T...>>::value; };

    template<class Needle, template<class...> class Haystack>
    struct has_option<Needle, Haystack<>> : std::false_type {};

    template<class Needle, template<class...> class Haystack, class... T>
    struct has_option<Needle, Haystack<Needle, T...>> : std::true_type {};

} // ndb

#endif // OPTION_H_NDB