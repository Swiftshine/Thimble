#include <telkin/Telkin.h>

#if !defined(__CONSOLE__) // This does not work on console
    // Prevent the game from switching into 30fps mode on the world map
    tPatch32u(0x02B38D7C, tk::ppc::b(0x20));
#endif
