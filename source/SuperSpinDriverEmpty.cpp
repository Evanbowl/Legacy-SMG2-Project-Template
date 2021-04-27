//SuperSpinDriverEmpty by Evanbowl
#include "spack/Actor/SuperSpinDriverEmpty.h"
#include "Util/JMapUtil.h"
#include "Util/LiveActorUtil.h"
#include "Util/SwitchUtil.h"
#include "Util/ObjUtil.h"

/* This is the transparent launch star seen on the comet observatory, until you get all 3 green stars.

Interestingly, this object has a texture for a Red variant, even though a red launch star is never in either game.

But we don't need this texture, since Red isn't used. It has been replaced with Pink.

Unlike SMG1, you can change this object's color with obj_arg0.
It will also disappear if it's assigned SW_B is triggered.
*/
void SuperSpinDriverEmpty::init(const JMapInfoIter& rIter) {
    MR::initDefaultPos(this, rIter);
    initModelManagerWithAnm("SuperSpinDriverEmpty", NULL);
    MR::connectToSceneMapObj(this);
    MR::useStageSwitchReadB(this, rIter);
    MR::getJMapInfoArg0NoInit(rIter, &mBtpFrame);
    MR::startBtp(this, "superspindriverempty");

    MR::setBtpFrameAndStop(this, mBtpFrame);

    makeActorAppeared();
}

void SuperSpinDriverEmpty::movement()
{
    if (MR::isOnSwitchB(this)){
    makeActorDead();
    }
}