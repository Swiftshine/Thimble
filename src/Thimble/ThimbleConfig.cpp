#include <telkin/Telkin.h>
#include <gfl/gflResArchivedFileInfo.hpp>
#include <gfl/gflMemoryUtil.hpp>
#include <game/file/Bson.hpp>
#include <thimble/ThimbleConfig.hpp>

using namespace th;

ThimbleConfig::ThimbleConfig()
    : mBson(nullptr)
{ }

ThimbleConfig::~ThimbleConfig() { }

ThimbleConfig& ThimbleConfig::Instance() {
    static ThimbleConfig inst;
    return inst;
}

void ThimbleConfig::ConfigureFrom(const char* pFilepath) {
    gfl::ResFileObject res = gfl::ResArchivedFileInfo::OpenFileFromArchive(pFilepath, 0);

    Bson* bson = reinterpret_cast<Bson*>(gfl::Alloc(gfl::HeapID::Work, sizeof(Bson), 4));

    if (bson != nullptr) {
        mBson = bson;
    } else {
        tk::fatal("Failed to construct Bson object!");
        mBson = nullptr;
        return;
    }

    mBson->ParseFromFileInfo(res);
}

const Bson* ThimbleConfig::GetBSON() const {
    return mBson.get();
}
