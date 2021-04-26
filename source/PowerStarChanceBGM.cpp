#include "Actor/AreaObj/AreaObj.h"
#include "Util/PlayerUtil.h"
#include "Util/StageUtil.h"
#include "Sound/AudioLib.h"
#include "kamek.h"

//This removes the hardcoded "Star Chance" BGM after a star spawn. \
If you want to add to this, MR::isEqualStageName("") is the galaxy name. \
MR::getCurrentScenarioNo == 0 is the scenario check. Here are a few examples. \
\
|| MR::isEqualStageName("OmoteuLandGalaxy") && MR::getCurrentScenarioNo() == 2                                                                           \
\
This will disable ALL star chance music from Flipsville Galaxy, Star 2. \
Another example \
\
|| MR::isEqualStageName("IslandFleetGalaxy")
\
//That will disable ALL star chance music from Sky Station, no matter which star.

char *FUN_8007C880();
void FUN_8007C8D0(int, int, int);
void FUN_8001C140();

void PowerStarBGMChange(bool PlayStarChance2) 
{
    int StarChance3SoundID;
    int StarChance2SoundID;
    int StarChance1SoundID;

    char *ptr1 = FUN_8007C880();
    ptr1[0xC] = 1;

    FUN_8001C140();

    if (MR::isPlayerDead() || MR::isEqualStageName("GalaxyNameHere") && MR::getCurrentScenarioNo() == 1
                                              || MR::isEqualStageName("GalaxyNameHere") && MR::getCurrentScenarioNo() == 1 //Duplicate this line to add another entry, and remove the "&& MR::getCurrentScenarioNo() == 1" to remove the Star Chance for all stars in the specified galaxy.




)
    {
        return;
    } 
    else 
    {
        if (MR::isEqualStageName("VsKoopaLv1Galaxy") ||
            MR::isEqualStageName("VsKoopaGravityGalaxy") || 
            MR::isEqualStageName("VsKoopaLv3Galaxy") ||
            MR::isEqualStageName("QuicksandGalaxy") && MR::getCurrentScenarioNo() == 1) 
        {
            #ifdef USA
            AudSoundNameConverter::getSoundID(&StarChance3SoundID, *(void **)0x807D0D80, "STM_STAR_CHANCE_3");
            FUN_8007C8D0(StarChance3SoundID, 0, -1);
            #endif

            #ifdef PAL
            AudSoundNameConverter::getSoundID(&StarChance3SoundID, *(void **)0x807D6480, "STM_STAR_CHANCE_3");
            FUN_8007C8D0(StarChance3SoundID, 0, -1);
            #endif
        } 
        else 
        {
            if (PlayStarChance2) 
            {
                #ifdef USA
                AudSoundNameConverter::getSoundID(&StarChance2SoundID, *(void **)0x807D0D80, "MBGM_STAR_CHANCE_2");
                FUN_8007C8D0(StarChance2SoundID, 0, -1);
                #endif

                #ifdef PAL
                AudSoundNameConverter::getSoundID(&StarChance2SoundID, *(void **)0x807D6480, "MBGM_STAR_CHANCE_2");
                FUN_8007C8D0(StarChance2SoundID, 0, -1);
                #endif
            } 
            else 
            {
                #ifdef USA
                AudSoundNameConverter::getSoundID(&StarChance1SoundID, *(void **)0x807D0D80, "MBGM_STAR_CHANCE");
                FUN_8007C8D0(StarChance1SoundID, 0, -1);
                #endif

                #ifdef PAL
                AudSoundNameConverter::getSoundID(&StarChance1SoundID, *(void **)0x807D6480, "MBGM_STAR_CHANCE");
                FUN_8007C8D0(StarChance1SoundID, 0, -1);
                #endif
            }
        }
    }
    return;
}

kmBranch(0x8001BCF0, PowerStarBGMChange);
