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

	selectedColour = COLOUR_GREEN;

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

		drawNode->drawSegment(lastTouchPos, touchPos, INITIAL_RADIUS, Color4F(selectedColour));
		lastTouchPos = touchPos;
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void DrawingCanvas::setupMenus() {
	Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	// create clear button
	ui::Button* clearButton = ui::Button::create();
	clearButton->setAnchorPoint(Vec2(1.0f, 1.0f));
	clearButton->setPosition(Vec2(visibleSize.width, visibleSize.height));
	clearButton->loadTextures("clearButton.png", "clearButtonPressed.png");
	clearButton->addTouchEventListener(CC_CALLBACK_2(DrawingCanvas::clearPressed, this));
	this->addChild(clearButton);

	// create back button
	ui::Button* backButton = ui::Button::create();
	backButton->setAnchorPoint(Vec2(0.0f, 1.0f));
	backButton->setPosition(Vec2(0.0f, visibleSize.height));
	backButton->loadTextures("backButton.png", "backButtonPressed.png");
	backButton->addTouchEventListener(CC_CALLBACK_2(DrawingCanvas::backPressed, this));
	this->addChild(backButton);
	   
	// create check sprite
	check = Sprite::create("checkMark.png");
	check->setAnchorPoint(Vec2(0.5f, 0.5f));
	check->setNormalizedPosition(Vec2(0.5f, 0.5f));

	// colour buttons
	Node* colourButtonLayout = Node::create();
	colourButtonLayout->setContentSize(Size(visibleSize.width, visibleSize.height * 0.2f));
	colourButtonLayout->setAnchorPoint(Vec2(0.5f, 0.0f));
	colourButtonLayout->setPosition(Vec2(visibleSize.width / 2.0f, 0.0f));
	this->addChild(colourButtonLayout);

	// Add 5 buttons
	for (int i = 1; i <= 5; ++i) {
		ui::Button* colourButton = ui::Button::create();
		colourButton->setAnchorPoint(Vec2(0.5f, 0.0f));
		colourButton->setPosition(Vec2(visibleSize.width * i * (1.0f/6.0f), 0.0f));
		colourButton->loadTextures("colorSwatch.png", "colorSwatch.png");
		colourButton->addTouchEventListener(CC_CALLBACK_2(DrawingCanvas::colourChangePressed, this));
		if (i == 1)	colourButton->setColor(Color3B(COLOUR_RED));
		if (i == 2) colourButton->setColor(Color3B(COLOUR_YELLOW));
		if (i == 3)
		{
			colourButton->setColor(Color3B(COLOUR_GREEN));
			colourButton->addChild(check);
		}
		if (i == 4) colourButton->setColor(Color3B(COLOUR_BLUE));
		if (i == 5) colourButton->setColor(Color3B(COLOUR_PURPLE));
		colourButtonLayout->addChild(colourButton);
	}
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

void DrawingCanvas::colourChangePressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType) {
	ui::Button* pressedButton = static_cast<ui::Button*>(pSender);

	if (eEventType == ui::Widget::TouchEventType::ENDED) 
		//selectedColour = static_cast<Color4F>(pressedButton->getColor());
		selectedColour = Color4F(pressedButton->getColor());
	check->retain();	// retain so not deallocated
	check->removeFromParent();
	pressedButton->addChild(check);
	check->release();
	
	// button scale
	pressedButton->setScale(0.85f);
	if (eEventType == ui::Widget::TouchEventType::CANCELED || eEventType == ui::Widget::TouchEventType::ENDED) {
		pressedButton->setScale(1.0f);
	}
}
