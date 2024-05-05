#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.num = 3;

    uintptr_t serializedData = Serializer::serialize(&data);
    Data* dataPtr = Serializer::deserialize(serializedData);
}