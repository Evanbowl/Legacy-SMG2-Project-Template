#pragma once

#include "kamek.h"

namespace MR
{
    void goToGalaxy(const char *);

    bool isStageFileSelect();
    bool isStageWorldMap();
    bool isStageMarioFaceShip();
    bool isStageStaffRoll();

    bool isEqualStageName(const char *);

    u32 getCurrentScenarioNo();
};