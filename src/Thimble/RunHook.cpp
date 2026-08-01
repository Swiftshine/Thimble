#include <telkin/Print.h>
#include <telkin/Hooks.h>
#include <game/Game.hpp>
#include <thimble/ThimbleConfig.hpp>

namespace th {

void RunHook() {
    // collect configs
    ThimbleConfig::Instance().ConfigureFrom("thimble/config.cfg");
    bool zlib = ThimbleConfig::Instance().ReadParam<bool>("use_zlib");

    Game::Run();
}


// Hook into main()
tBranch(0x02BBE464, RunHook, tk::BranchType::bl);

}
