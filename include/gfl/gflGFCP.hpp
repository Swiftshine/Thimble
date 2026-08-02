#pragma once

#include <types.h>

namespace gfl {

class GFCPWrapper {
public:
    GFCPWrapper(void* pData);
    ~GFCPWrapper();

    size_t GetDecompressedSize() const;
    size_t GetCompressedSize() const;
private:
    void* mData;
};
}
