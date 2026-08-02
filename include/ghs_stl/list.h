#pragma once

namespace ghs::std {
    template <typename T>
    struct list {
        size_t size() const {
            return _Mysize;
        }
        unsigned int _0;
        void* _Myhead;
        size_t _Mysize;
    };
}
