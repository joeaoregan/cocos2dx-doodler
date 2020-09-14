#ifndef __DOODLER_LOBBY__
#define __DOODLER_LOBBY__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Lobby : public cocos2d::Node
{
public:
	CREATE_FUNC(Lobby);

protected:
	bool init() override;
	void onEnter() override;
	void setupUI();
	void soloPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
	void duoPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__DOODLER_LOBBY__) */