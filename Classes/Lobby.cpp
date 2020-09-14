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
}