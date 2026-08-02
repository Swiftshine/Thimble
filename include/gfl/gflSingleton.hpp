#pragma once

namespace gfl {

template <typename T>
class Singleton {
public:
    inline T* operator->() {
        return inst;
    }

    inline const T* operator->() const {
        return inst;
    }

    inline operator T*() {
        return inst;
    }

    inline operator const T*() const {
        return inst;
    }

    inline T* get() {
        return inst;
    }

    inline const T* get() const {
        return inst;
    }

    inline void operator=(T* p) {
        inst = p;
    }
private:
    T* inst;
};
}
