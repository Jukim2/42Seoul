#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *arr;
        unsigned int len;

    public:
        Array() : arr(new T[0])m, len(0) {}
        Array(unsigned int n) : arr(new T[n]), len(n) {}
        Array(Array& other) : arr(new T[other.len]), len(other.len) {
            for (unsigned int i = 0; i < len; ++i) {
                arr[i] = other.arr[i];
            }
        }
        Array& operator=(Array& other) {
            if (this == &other) {
                return *this;
            }
            delete[] arr;
            len = other.len;
            arr = new T[len];
            for (unsigned int i = 0; i < len; ++i) {
                arr[i] = other.arr[i];
            }
            return *this;
        }
        ~Array() { delete[] arr; }

        unsigned int size() { return len; }

        T& operator[](unsigned int index) {
            if (index >= len) {
                throw std::out_of_range("Index out of range");
            }
            return arr[index];
        }

        const T& operator[](unsigned int index) const {
            if (index >= len) {
                throw std::out_of_range("Index out of range");
            }
            return arr[index];
        }
};

#endif

