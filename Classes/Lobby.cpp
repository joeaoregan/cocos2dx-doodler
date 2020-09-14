#include "Lobby.h"

USING_NS_CC;

bool Lobby::init() {
	if (!cocos2d::Node::init()) {
		return false;
	}

	LayerColor* background = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(background);

	return true;
}

void Lobby::onEnter() {
	Lobby::setupUI();
}

void Lobby::setupUI() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite* logo = Sprite::create("doodlerLogo.png");
	logo->setAnchorPoint(Vec2(0.5f, 0.5f));
	logo->setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.75f));
	this->addChild(logo);

	ui::Button* soloButton = ui::Button::create();
	soloButton->setAnchorPoint(Vec2(0.5f, 0.5f));
	soloButton->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height * 0.4f));
	soloButton->loadTextures("soloButton.png", "soloButtonPressed.png");
	soloButton->addTouchEventListener(CC_CALLBACK_2(Lobby::soloPressed, this));
	this->addChild(soloButton);
	
	ui::Button* duoButton = ui::Button::create();
	duoButton->setAnchorPoint(Vec2(0.5f, 0.75f));
	duoButton->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height * 0.25f));
	duoButton->loadTextures("duoButton.png", "duoButtonPressed.png");
	duoButton->addTouchEventListener(CC_CALLBACK_2(Lobby::duoPressed, this));
	this->addChild(duoButton);
}

void Lobby::soloPressed(Ref *pSender, ui::Widget::TouchEventType eEventType)
{

}

void Lobby::duoPressed(Ref *pSender, ui::Widget::TouchEventType eEventType)
{

}
