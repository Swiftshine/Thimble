#pragma once

#include <types.h>
#include <gflFileWiiU.hpp>

namespace gfl {

class GfArch {
public:

    virtual ~GfArch();
    void Decompress(FileWiiU* pFileWiiU);
    void Decompress(byte_t* pRawData);
// private:
    /* 0x00 */ FileWiiU* mFileWiiU;
    /* 0x04 */ byte_t* mRawArchiveData;
    /* 0x08 */ size_t mDefaultGFCPHeaderOffset;
    /* 0x0C */ u8 mHeapID;
    /* 0x10 */ size_t mAlignment;
    /* 0x14 */ u32 mIsCompressed;
    /* 0x18 */ size_t mEntryInfoOffset;
    /* 0x1C */ size_t mFileInfoSize;
    /* 0x20 */ size_t mCompressedDataOffset;
    /* 0x24 */ size_t mCompressedSize;
    /* 0x28 */ size_t mDecompressedSize;
    /* 0x2C */ byte_t* mEntryInfoData;
    /* 0x30 */ byte_t* mDecompressedData;
    /* 0x34 */ ghs::std::string mFilename;
    /* 0x54 */ void* m_54;
};

}
