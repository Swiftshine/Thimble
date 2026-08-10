#include <cstring>
#include <telkin/Telkin.h>
#include <thimble/RegistrarManager.hpp>

using namespace th;

RegistrarManager::RegistrarManager() {
    mHighestObjectID = ObjectID::NUM_OBJECTS_ORIGINAL;
    mHighestGimmickID = GimmickID::NUM_GIMMICKS_ORIGINAL;
}

RegistrarManager& th::RegistrarManager::Instance() {
    static RegistrarManager inst;
    return inst;
}

void RegistrarManager::AddGimmickID() {
    increment(mHighestObjectID);
    increment(mHighestGimmickID);

    mGimmickIDSets.emplace_back(YsGameObj::ObjectCategory::GimmickObject, mHighestObjectID,
                                static_cast<u32>(mHighestGimmickID));
}
