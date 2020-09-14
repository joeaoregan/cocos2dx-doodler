#include "cocos2d.h"
#include "ui/CocosGUI.h"

class DrawingCanvas : public cocos2d::Node
{
public:
	CREATE_FUNC(DrawingCanvas);

protected:
	cocos2d::DrawNode* drawNode;

	bool init() override;
	void onEnter() override;
	void setupTouchHandling();
	void setupMenus();
	void clearPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
	void backPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);

	cocos2d::LayerColor* background;
};
