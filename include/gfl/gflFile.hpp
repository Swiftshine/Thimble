#pragma once

#include <types.h>
#include <ghs_stl/string.h>

namespace gfl {

class File {
public:
    /* 0x0C */ virtual void vfC();
    /* 0x14 */ virtual ~File();
    /* 0x1C */ virtual bool Read(void* pDst, size_t size, size_t offset);

// protected:
    ghs::std::string mFilename;
    u32 m_20;
};

// SIZE_ASSERT(File, 0x28);

}
