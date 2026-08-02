#pragma once

#include <types.h>
#include <gflNwAllocator.hpp>
#include <gflMemoryUtil.hpp>

namespace gfl {

// unofficial name
class HeapBounds {
public:
    void Init(void* pStart, size_t size);
    void Reset();
public:
    bool m_0;
    void* mStart;
    void* mEnd;
    size_t mSize;
    STRUCT_FILL(0x1C);
};

class HeapWiiU {
public:
    enum class HeapType : s32 {
        Mem1    = 1,
        Mem2    = 2,
        Bucket  = 3,
    };

    HeapWiiU();
    ~HeapWiiU();
    void Init(size_t heapSize, int _, int heapType);
    void SetName(const char* pName);
public:
    /* 0x00 */ HeapID mHeapID;
    /* 0x01 */ char mHeapName[25];
    /* 0x1C */ HeapBounds mHeapBounds;
    /* 0x48 */ HeapType mHeapType;
    /* 0x4C */ NwAllocator mAllocator;
    /* 0x54 */ bool m_54;
};


}
