#include "cocos2d.h"

class DrawingCanvas : public cocos2d::Node
{
public:
	CREATE_FUNC(DrawingCanvas);

protected:
	cocos2d::DrawNode* drawNode;

	bool init() override;
	void onEnter() override;
	void setupTouchHandling();

	cocos2d::LayerColor* background;
};
