#pragma once

#include <gfl/gflSingleton.hpp>

#include <manager/ObjectManager.hpp>

class GameManager {
public:
    static gfl::Singleton<GameManager> sInstance;

    size_t GetNumPlayers() const;
    Player* GetPlayer(size_t playerID) const;
    ObjectManager* GetObjectManager() const;
};
