#include <gfl/gflPointer.hpp>
#include <ghs_stl/list.hpp>
#include <manager/ObjectManager.hpp>
#include <object/GimmickObject.hpp>
#include <object/ObjectProfile.hpp>
#include <object/PlEgg.hpp>
#include <object/control/OtherEggCtrl.hpp>
#include <telkin/Print.h>
#include <thimble/RegistrarManager.hpp>

class EggSpawner : public GimmickObject {
public:
    static GimmickObject* Build(u32 id, GimmickBuildInfo* pBuildInfo);
    static void InitProfile(GimmickProfile* pProfile, const char* pName, u32 objectID, u32 gimmickID);

    EggSpawner(GimmickBuildInfo* pBuildInfo);
    ~EggSpawner();

    void Update() override;

private:
    gfl::Pointer<OtherEggCtrl> mEggCtrl;
};

GimmickObject* EggSpawner::Build(u32 id, GimmickBuildInfo* pBuildInfo) {
    return new (gfl::HeapID::Work) EggSpawner(pBuildInfo);
}

REGISTER_GIMMICK(EggSpawner, "th_egg_spawn");

void EggSpawner::InitProfile(GimmickProfile* pProfile, const char* pName, u32 objectID, u32 gimmickID) {
    pProfile->mName = pName;
    pProfile->mObjectID = static_cast<ObjectID>(objectID);
    pProfile->mGimmickID = static_cast<GimmickID>(gimmickID);
    pProfile->mBuildFunction = EggSpawner::Build;
}

EggSpawner::EggSpawner(GimmickBuildInfo* pBuildInfo)
    : GimmickObject(pBuildInfo, "EggSpawner")
    , mEggCtrl(new (gfl::HeapID::Work) OtherEggCtrl) {
    tk::println("EggSpawner::EggSpawner");
}

EggSpawner::~EggSpawner() {}

void EggSpawner::Update() {
    GimmickObject::Update();

    if (mFramesActive % (60 * 3) == 0) {
        u32 color = rand() % 13;

        Player* player = ObjectManager::sInstance->FindNearestPlayer(mPosition);
        gfl::Vec3 dir = (player->mPosition - mPosition).Normalized();
        PlEgg::BuildInfo info {};
        info.mBehavior = PlEgg::Behavior::Owned;
        info.mSize = static_cast<PlEgg::Size>(rand() % 3);
        info.m_14 = -1u;

        ObjectManager::SpawnPlEgg(color, mPosition, dir, &info, mEggCtrl);
    }
}
