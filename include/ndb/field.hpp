#ifndef FIELD_H_NDB
#define FIELD_H_NDB

#include <nse/type.hpp>

namespace ndb
{
    //TODO : Ajouter le detail_table::size dans le field_table (les champs où on stock des tables)

    // base field
    struct field_base {};

    //detail_field
    template<std::size_t Size, typename... Options>
    struct detail_field {
        static constexpr size_t size = Size + sizeof...(Options);
    };

    // static field
    template<class T, size_t Size = sizeof(T), typename... Options>
    struct field : field_base
    {
        using type = T;

        static constexpr size_t size = Size;
        using detail_ = detail_field<Size, Options...>;
    };

    // dynamic field
    template<class T, size_t Size>
    struct field<T*, Size>
    {
        using type = T*;

        static constexpr size_t size = sizeof(size_t);
    };
} // ndb

#endif // FIELD_H_NDB

/*! \class field can be static or dynamic, data will be stored in static or dynamic section of a table
 * Size is the space required for a field, it will be dynamic for dynamic fields
 *
 * Example :
 * field<int>
 * field<char, 255>
 * field<dynamic_size_object*>
 * field<dynamic_size_object_with_static_capacity*, 5000>
 */