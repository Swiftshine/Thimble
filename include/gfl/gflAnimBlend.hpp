#pragma once

#include <ghs_stl/list.hpp>
#include <types.h>

namespace gfl {

class Model;
class Anim;

class AnimBlend {
public:
    virtual ~AnimBlend();

private:
    /* 0x00 */ Model* mModel;
    /* 0x04 */ Anim* mAnim;
    /* 0x08 */ ghs::std::list<placeholder_t>* m_8;
    /* 0x0C */ float m_C;
    /* 0x10 */ float m_10;
    /* 0x14 */ u32 m_14;
    /* 0x18 */ u32 m_18;
    /* 0x1C */ u32 m_1C;
    /* 0x20 */ u32 m_20;
    /* 0x24 */ bool m_24;
};

SIZE_ASSERT(AnimBlend, 0x2C);

} // namespace gfl
