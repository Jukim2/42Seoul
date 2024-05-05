#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data
{
    int num;
};

class Serializer
{
    public:
        Serializer();
        Serializer(const Serializer& cpy);
        Serializer& operator=(const Serializer& rhs);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif