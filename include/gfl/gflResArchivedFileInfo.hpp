#pragma once

#include <gflPointer.hpp>
#include <ghs_stl/string.hpp>
#include <types.h>

namespace gfl {
// there's a bunch of abstractions that i don't care to write rn
class ResInfo {
public:
    virtual ~ResInfo();

private:
    u16 m_0;
    u16 mRefCount;
    u32 m_4;
    u32 mChecksum;
    ghs::std::string mFilename;
    STRUCT_FILL(20);
};

class ResArchivedFileInfo : public ResInfo {
public:
    ~ResArchivedFileInfo();
    virtual void IncrementRefCount();
    virtual void TryDestroy();
    virtual void* GetData() const;
    virtual size_t GetFilesize() const;
    virtual void vf34();

    static ResArchivedFileInfo* OpenFileFromArchive(const char* pFilepath, u32 arg2);

public:
    u32 m_44;
    void* mData;
    u32 m_4C;
};

class ResFileObject {
public:
    ResFileObject(ResArchivedFileInfo* p)
        : ptr(p) {}

    ~ResFileObject() {
        if (ptr != nullptr) {
            ptr->TryDestroy();
        }

        ptr = nullptr;
    }

    ResArchivedFileInfo* get() { return ptr; }

    const ResArchivedFileInfo* get() const { return ptr; }

    void* GetData() const { return ptr->GetData(); }
    size_t GetFilesize() const;
    ghs::std::string* GetFilename() const;

private:
    ResArchivedFileInfo* ptr;
};

// SIZE_ASSERT(ResArchivedFileInfo, 0x54); // how big is this really?
} // namespace gfl
