#pragma once

#include <nw/ut/ut_IAllocator.hpp>

namespace gfl {

class HeapWiiU;

class NwAllocator : nw::ut::IAllocator {
public:

private:
    /* 0x4 */ HeapWiiU* mHeap;
};
}
