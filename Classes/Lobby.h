#ifndef __DOODLER_LOBBY__
#define __DOODLER_LOBBY__

#include "cocos2d.h"

class Lobby : public cocos2d::Node
{
public:
	CREATE_FUNC(Lobby);

protected:
	bool init() override;
	void onEnter() override;
	void setupUI();
};

#endif /* defined(__DOODLER_LOBBY__) */