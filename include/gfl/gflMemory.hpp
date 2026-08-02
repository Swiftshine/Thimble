#pragma once

#include <types.h>
#include <gflHeapWiiU.hpp>
#include <gflSingleton.hpp>

#define HEAP_COUNT 24

namespace gfl {

class MemoryBaseImpl {
public:
    virtual ~MemoryBaseImpl();
public:
    /* 0x00 */ HeapWiiU* mHeaps[HEAP_COUNT];
};

class Memory : public MemoryBaseImpl {
public:
    static Singleton<Memory> sInstance;
    static Memory* InitInstance();

    static inline Memory* TryGetInstance() {
        Memory* inst = sInstance;
        
        if (inst == nullptr) {
            return InitInstance();
        }
        
        return inst;
    }

    void AddHeap(HeapWiiU* pHeap);
public:
    /* 0x064 */ HeapWiiU mLibHeap;
    /* 0x0BC */ HeapWiiU mStringHeap;
    /* 0x114 */ HeapWiiU mEtcHeap;
    /* 0x16C */ HeapWiiU mSoundHeap;
    /* 0x1C4 */ HeapWiiU mDisplayListHeap;
    /* 0x21C */ HeapWiiU mVRAMHeap;
    /* 0x274 */ HeapWiiU mForegroundBucketHeap;
};

}
