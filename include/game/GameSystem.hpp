#pragma once

#include <gfl/gflTask.hpp>
#include <gfl/gflCamera.hpp>
#include <gfl/gflScene.hpp>
#include <gfl/gflSingleton.hpp>

class GameSystem {
public:
    static gfl::Singleton<GameSystem> sInstance;

    GameSystem();
    ~GameSystem();

    gfl::Camera* GetWorldCamera();
// private:
    /* 0x000 */ gfl::Task mUpdateTask;
    /* 0x01C */ gfl::Task mAftAnmTask;      // "after animation"
    /* 0x038 */ gfl::Task mAftOhTask;       // "after ObjHit"?
    /* 0x054 */ gfl::Task mDebugTask;
    /* 0x070 */ gfl::Task mDebugAftAnmTask;
    /* 0x08C */ gfl::Task mDebugAftOhTask;
    /* 0x0A8 */ gfl::Task mSceneUpdateTopTask;
    /* 0x0C4 */ gfl::Task mSceneUpdateViewTask;
    /* 0x0E0 */ gfl::Task mSceneWorldMtxTask;
    /* 0x0FC */ gfl::Task mSceneDrawTopTask;
    /* 0x118 */ gfl::Task mSceneDrawDRCTopTask;
    /* 0x134 */ u32 mNumFrames;
    /* 0x138 */ gfl::Camera* mWorldCamera;
    /* 0x13C */ gfl::Camera* mUICamera;
    /* 0x140 */ gfl::Camera* mUIPerspectiveCamera;
    /* 0x144 */ gfl::Scene* mFar00Scene;
    /* 0x148 */ gfl::Scene* mGameScene;
    /* 0x14C */ gfl::Scene* mNear00Scene;
    /* 0x150 */ gfl::Scene* mNear01ZCScene;
    /* 0x154 */ gfl::Scene* m3DUIZCScene;
    /* 0x158 */ gfl::Scene* mUIPersScene;
    /* 0x15C */ gfl::Scene* mUIScene;
    /* 0x160 */ gfl::Scene* mUISystemScene;
    /* 0x164 */ gfl::Scene* mUICaptureScene;
    /* 0x168 */ gfl::Scene* mStageDebugScene;
    /* 0x16C */ STRUCT_FILL(0x3E0 - 0x16C);
};

SIZE_ASSERT(GameSystem, 0x3E0);
