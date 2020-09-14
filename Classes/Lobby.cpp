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

}