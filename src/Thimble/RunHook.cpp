#include <telkin/Telkin.h>
#include <game/Game.hpp>
#include "ThimbleConfig.hpp"

namespace th {
const char* CONFIG_PATH = "thimble/config.bson";

extern void SetupAdditionalGimmickProfiles();

void RunHook() {
    tk::println("Running pre-run tasks...");

    // collect configs
    tk::println("\t (1/3) Setting up ThimbleConfig...");
    ThimbleConfig& config = ThimbleConfig::Instance();

    tk::println("\t (2/3) Reading from %s...", CONFIG_PATH);
    config.ConfigureFrom(CONFIG_PATH);

    {
        const char* msg = config.GetBSON()->GetStringFromRoot("test_field");
        tk::println("Found msg: %s", msg);
    }

    // set up additional gimmick profiles
    tk::println("\t (3/3) Setting up additional gimmick profiles...");
    SetupAdditionalGimmickProfiles();

    tk::println("Done with pre-run tasks.");

    Game::Run();
}
}

// Hook into main()
tBranch(0x02BBE464, th::RunHook, tk::BranchType::bl);
