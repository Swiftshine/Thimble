#pragma once

#include <types.h>

namespace gfl {

class File {
public:
    /* 0x0C */ virtual void vfC();
    /* 0x14 */ virtual ~File();
    /* 0x1C */ virtual bool Read(void* pDst, size_t size, size_t offset);

    /* 0x00 */ char mFilename[0x20]; // std::string
    /* 0x20 */ u32 m_20;
};
}
