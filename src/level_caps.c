#include "global.h"
#include "constants/level_caps.h"
#include "event_data.h" // for CountPlayerBadges()
#include "save.h"
#include "constants/flags.h"


u8 CountPlayerBadges(void)
{
    u8 count = 0;
    int i;
    u16 badgeFlags[] = {
        FLAG_BADGE01_GET,
        FLAG_BADGE02_GET,
        FLAG_BADGE03_GET,
        FLAG_BADGE04_GET,
        FLAG_BADGE05_GET,
        FLAG_BADGE06_GET,
        FLAG_BADGE07_GET,
        FLAG_BADGE08_GET
    };

    for (i = 0; i < sizeof(badgeFlags) / sizeof(*badgeFlags); i++)
    {
        if (FlagGet(badgeFlags[i]))
            count++;
    }

    return count;
}



const u8 gLevelCaps[MAX_LEVEL_CAPS] = {
    14, // 0 Badges
    21, // 1 Badge
    24, // 2
    28,
    31,
    43,
    47,
    50,
    55,
    100 // Final cap (fallback)
};

u8 GetCurrentLevelCap(void)
{
    u8 badgeCount = CountPlayerBadges();
    if (badgeCount >= MAX_LEVEL_CAPS)
        return gLevelCaps[MAX_LEVEL_CAPS - 1];
    return gLevelCaps[badgeCount];
}
