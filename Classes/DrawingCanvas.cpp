#include "DrawingCanvas.h"
#include <iostream>
#include "Constants.h"

using namespace cocos2d;

bool DrawingCanvas::init() {
	if (! cocos2d::Node::init()) {
		return false;
	}

	background = LayerColor::create(Color4B(COLOUR_WHITE));
	this->addChild(background);

	drawNode = DrawNode::create();
	this->addChild(drawNode);

	return true;
}

void DrawingCanvas::onEnter() {
	Node::onEnter();

	Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	this->setContentSize(visibleSize);
	drawNode->setContentSize(visibleSize);

	DrawingCanvas::setupTouchHandling();
	DrawingCanvas::setupMenus(); // Create buttons
}

void DrawingCanvas::setupTouchHandling() {
	static Vec2 lastTouchPos;
	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = [&](Touch* touch, Event* event) {
		lastTouchPos = drawNode->convertTouchToNodeSpace(touch);
		return true;
	};

	touchListener->onTouchMoved = [&](Touch* touch, Event* event) {
		Vec2 touchPos = drawNode->convertTouchToNodeSpace(touch);
		//log("Touch Moved! x:%f y:%f", touchPos.x, touchPos.y);

		drawNode->drawSegment(lastTouchPos, touchPos, INITIAL_RADIUS, Color4F(0.0f, 0.0f, 0.0f, 1.0f));
		lastTouchPos = touchPos;
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void DrawingCanvas::setupMenus() {
	Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	// create solo button
	ui::Button* clearButton = ui::Button::create();
	clearButton->setAnchorPoint(Vec2(1.0f, 1.0f));
	clearButton->setPosition(Vec2(visibleSize.width, visibleSize.height));
	clearButton->loadTextures("clearButton.png", "clearButtonPressed.png");
	clearButton->addTouchEventListener(CC_CALLBACK_2(DrawingCanvas::clearPressed, this));
	this->addChild(clearButton);

	// create duo button
	ui::Button* backButton = ui::Button::create();
	backButton->setAnchorPoint(Vec2(0.0f, 1.0f));
	backButton->setPosition(Vec2(0.0f, visibleSize.height));
	backButton->loadTextures("backButton.png", "backButtonPressed.png");
	backButton->addTouchEventListener(CC_CALLBACK_2(DrawingCanvas::backPressed, this));
	this->addChild(backButton);
}

void DrawingCanvas::clearPressed(Ref *pSender, ui::Widget::TouchEventType eEventType) {
	if (eEventType == ui::Widget::TouchEventType::ENDED)
	{
		drawNode->clear();
	}
}

void DrawingCanvas::backPressed(Ref *pSender, ui::Widget::TouchEventType eEventType) {
	if (eEventType == ui::Widget::TouchEventType::ENDED)
	{
		Director::getInstance()->popScene();
	}
}
