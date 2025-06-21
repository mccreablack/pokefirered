#include "global.h"


#ifndef GUARD_CONSTANTS_LEVEL_CAP_H
#define GUARD_CONSTANTS_LEVEL_CAP_H

#define MAX_LEVEL_CAPS 10

extern const u8 gLevelCaps[MAX_LEVEL_CAPS];
u8 GetCurrentLevelCap(void);

#endif // GUARD_CONSTANTS_LEVEL_CAP_H
