#include <telkin/Hooks.h>
#include <telkin/Print.h>
#include <telkin/Telkin.h>
#include <thimble/ThimbleConfig.hpp>
#include <vector>

int YarnBallColor(void *, int) {
    int color = th::ThimbleConfig::Instance().ReadParam<int>("force_yarn_color");
    return color;
}

tBranch(0x0253a16c, YarnBallColor, tk::BranchType::bl);

void main() { }
