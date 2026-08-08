#pragma once

#include <types.h>

namespace ghs::std {
template <typename T> struct list {
    inline list() {
        _Allocator = this;
        _Myhead = this;
        _Mysize = 0;
    }
    size_t size() const { return _Mysize; }

    /* 0x0 */ void* _Allocator; // probably
    /* 0x4 */ void* _Myhead;
    /* 0x8 */ size_t _Mysize;
};
} // namespace ghs::std
