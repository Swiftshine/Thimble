#pragma once

#include <gfl/gflMath.hpp>
#include <ghs_stl/string.hpp>
#include <graphics/FlfMdlDraw.hpp>
#include <graphics/ResourceList.hpp>
#include <types.h>

class YsModelControl2 {
public:
    static u32 sInstanceCount;

    YsModelControl2();
    virtual ~YsModelControl2();

    void Reset();
    void Init(FlfMdlDraw* pFlfMdlDraw, const char* pArchiveName, const char* pBFRESName, ResourceList* pResourceList,
              u32 flags, u32 arg6);
    void UpdateMatrix(const gfl::Matrix34& rMatrix);

public:
    /* 0x00 */ u32 m_0;
    /* 0x04 */ ghs::std::string mArchivePath;
    /* 0x24 */ ghs::std::string mResourceName;
    /* 0x44 */ int m_44;
    /* 0x48 */ u32 m_48;
    /* 0x4C */ void* m_4C;
    /* 0x50 */ u32 m_50;
    /* 0x54 */ int m_54;
    /* 0x58 */ u32 m_58;
    /* 0x5C */ float m_5C;
    /* 0x60 */ gfl::Matrix34 m_60;
    /* 0x90 */ gfl::Matrix34 m_90;
    /* 0xC0 */ u32 m_C0;
    /* 0xC4 */ u32 m_C4;
};

SIZE_ASSERT(YsModelControl2, 0xCC);
