#pragma once

#include <types.h>

namespace nw {
namespace ut {

class IAllocator {
public:
    virtual void vfC();
    virtual ~IAllocator();
    virtual void* Allocate(size_t align, size_t size);
    virtual void Free(void* pBlock);
};
}
}
