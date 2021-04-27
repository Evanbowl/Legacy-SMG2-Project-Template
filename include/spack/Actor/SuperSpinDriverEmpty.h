#pragma once

#include "Actor/LiveActor/LiveActor.h"

class SuperSpinDriverEmpty : public LiveActor
{
public:
	
	SuperSpinDriverEmpty(const char *pActorName) : LiveActor(pActorName)
	{

	}
	
	virtual void init(const JMapInfoIter &);
	virtual void movement();

    s32 mBtpFrame;
};