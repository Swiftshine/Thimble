#pragma once

#include <gflMemoryUtil.hpp>
#include <gflHeapWiiU.hpp>

namespace gfl {

template <typename T>
class Pointer {
public:
    Pointer()
        : ptr(0)
    { }

    Pointer(T* p)
        : ptr(p)
    { }
    
    ~Pointer() {
        if (ptr) {
            delete ptr;
        }
        ptr = nullptr;
    }

    void operator=(T* p) {
        if (ptr) {
            delete ptr;
        }
        ptr = p;
    }

    T* operator->() {
        return ptr;
    }

    const T* operator->() const {
        return ptr;
    }

    operator T*() {
        return ptr;
    }

    operator const T*() const {
        return ptr;
    }

    T* get() {
        return ptr;
    }

    const T* get() const {
        return ptr;
    }
private:
    T* ptr;
};
}
