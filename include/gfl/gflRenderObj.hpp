#pragma once

#include <types.h>

#include <gflIGpuRefObj.hpp>

namespace gfl {

class RenderObj : public IGPURefObj {
public:
    ~RenderObj();
private:
    /* 0x04 */ u32 m_4;
    /* 0x08 */ u32 m_8;
    /* 0x0C */ u32 m_C;
    /* 0x10 */ bool m_10;
    /* 0x11 */ bool m_11;
    /* 0x12 */ bool m_12;
    /* 0x13 */ bool m_13;
    /* 0x14 */ u32 mMaterialFlags;
    /* 0x18 */ STRUCT_FILL(0x70 - 0x18);
};

SIZE_ASSERT(RenderObj, 0x70);

}
