#include <thimble/CustomIDManager.hpp>

using namespace th;

CustomIDManager::CustomIDManager() {
    mHighestObjectID = ObjectID::NUM_OBJECTS_ORIGINAL;
    mHighestGimmickID = GimmickID::NUM_GIMMICKS_ORIGINAL;
}

CustomIDManager& th::CustomIDManager::Instance() {
    static CustomIDManager inst;
    return inst;
}
