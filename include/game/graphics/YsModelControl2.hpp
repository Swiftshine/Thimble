#pragma once

#include <gfl/gflMath.hpp>
#include <gfl/gflModel.hpp>
#include <ghs_stl/string.hpp>
#include <graphics/FlfMdlDraw.hpp>
#include <graphics/ModelResourceTable.hpp>
#include <types.h>

class YsModelControl2 {
public:
    static u32 sInstanceCount;

    YsModelControl2();
    virtual ~YsModelControl2();

    void Reset();
    void Init(FlfMdlDraw* pFlfMdlDraw, const char* pArchiveName, const char* pBFRESName,
              ModelResourceTable* pResourceList, u32 flags, u32 arg6);
    void UpdateMatrix(const gfl::Matrix34& rMatrix);
    void PlaySkeletalAnimation(u32 id);
    float GetUpdateRate() const;
    void SetUpdateRate(float rate);
    void UpdateFrame(float step);
    float GetCurrentFrame() const;
    float GetEndFrame() const;
    bool IsAnimationDone() const;
    // it's only used in a couple places so it's difficult to determine *how*
    // to use this
    void EnableAnimationReaction(bool react);
    bool HasAnimation() const;

public:
    /* 0x00 */ u32 mFlags;
    /* 0x04 */ ghs::std::string mArchivePath;
    /* 0x24 */ ghs::std::string mResourceName;
    /* 0x44 */ int m_44;
    /* 0x48 */ FlfMdlDraw* mFlfMdlDraw;
    /* 0x4C */ gfl::Model* mModel;
    /* 0x50 */ ModelResourceTable* mModelResourceTable;
    /* 0x54 */ u32 mCurrentAnimIndex;
    /* 0x58 */ u32 mCurrentSkeletalAnimIndex;
    /* 0x5C */ float mUpdateRate;
    /* 0x60 */ gfl::Matrix34 m_60;
    /* 0x90 */ gfl::Matrix34 m_90;
    /* 0xC0 */ u32 m_C0;
    /* 0xC4 */ u32 m_C4;
};

SIZE_ASSERT(YsModelControl2, 0xCC);
