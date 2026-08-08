#pragma once

#include <cstdlib>
#include <types.h>

namespace gfl {

void* Memcpy(void* dst, size_t size, const void* src);
void* Memset(void* dst, char data, size_t size);
void Memclear(void* dst, size_t size);

enum class HeapID : u8 {
    Lib = 1,
    String = 3,
    Etc = 4,
    DisplayList = 5,
    Sound = 6,
    VRAM = 7,
    ForegroundBucket = 8,
    Work = 10,
    Resource = 11,
    SubResource = 12,
};

void* Alloc(HeapID heapID, size_t size, size_t align);
void Free(void* ptr);

} // namespace gfl

void* operator new(size_t size, gfl::HeapID heapID);
