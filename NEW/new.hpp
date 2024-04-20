#include "new.h"
#include <cstdlib>

template<typename T>
T* neww()
{
    void* p1 = std::malloc(sizeof(T));
    T* p = static_cast<T*>(p1);
    return p;
}

template<typename T>
void deletee(T* p)
{
    if (p) {
        std::free(p);
    }
}

template<typename T>
T* neww_array(size_t size)
{
    void* a1 = std::malloc(sizeof(T) * size);
    T* a = static_cast<T*>(a1);
    return a;
}

template<typename T>
void deletee_array(T* a)
{
    if (a) {
        std::free(a);
    }
}
