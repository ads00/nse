#ifndef SETUP_H_NDB
#define SETUP_H_NDB

//! \brief compile time configuration

namespace ndb
{
    class global;
    template<class T = global> struct setup {};
} // ndb

#endif // SETUP_H_NDB