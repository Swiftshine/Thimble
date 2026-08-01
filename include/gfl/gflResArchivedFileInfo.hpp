#pragma once
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
    char mFilename[0x20]; // std::string
    char rest[0x14];
};

static_assert(sizeof(ResInfo) == 0x44, "gfl::ResInfo size mismatch");

class ResArchivedFileInfo : public ResInfo {
public:
    virtual ~ResArchivedFileInfo();
    virtual void IncrementRefCount();
    virtual void TryDestroy();
    virtual void* GetData() const;
    virtual size_t GetFilesize() const;
    virtual void vf34();

    static ResArchivedFileInfo* OpenFileFromArchive(const char* pFilepath, u32 arg2);

    /* 0x44 */ u32 m_44;
    /* 0x48 */ void* mData;
    /* 0x4C */ u32 m_4C;
};

static_assert(sizeof(ResArchivedFileInfo) == 0x50, "gfl::ResArchivedFileInfo size mismatch");

// todo; move the stuff from the old repo here
class ResFileObject {
public:
    ResFileObject(ResArchivedFileInfo* p)
        : ptr(p)
    { }

    ~ResFileObject() {
        if (ptr != nullptr) {
            ptr->TryDestroy();
        }

        ptr = nullptr;
    }

    ResArchivedFileInfo* get() {
        return ptr;
    }

    void* GetData() const {
        return ptr->GetData();
    }

    size_t GetFilesize() const;
private:
    /* 0x0 */ ResArchivedFileInfo* ptr;
};

}
