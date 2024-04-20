#ifndef NEW_H
#define NEW_H

#include <cstddef>

template <typename T>
T* neww();

template <typename T>
void deletee(T* p);

template <typename T>
T* neww_array(size_t size);

template <typename T>
void deletee_array(T* a);

#endif
  
