#pragma once

#include <types.h>

namespace gfl {

class FileWiiU;

class BpeDecoderFile {
public:
    BpeDecoderFile(FileWiiU* pFileWiiU, size_t gfcpOffset);
    virtual ~BpeDecoderFile();

    void* Decode(size_t* pDecompressedSize, u8 heapID, size_t align);
private:
    /* 0x00 */ FileWiiU* mFileWiiU;
    /* 0x04 */ size_t mGFCPHeaderOffset;
    /* 0x08 */ void* m_8;
    /* 0x0C */ u32 m_C;
    /* 0x10 */ u32 m_10;
    /* 0x14 */ u32 m_14;
};

SIZE_ASSERT(BpeDecoderFile, 0x1C);

}
