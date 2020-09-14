#include "Lobby.h"
#include "DrawingCanvas.h"
#include "Constants.h"

USING_NS_CC;

bool Lobby::init() {
	if (!cocos2d::Node::init()) {
		return false;
	}

	LayerColor* background = LayerColor::create(Color4B(COLOUR_WHITE));
	this->addChild(background);

	return true;
}

void Lobby::onEnter() {
	Node::onEnter();
	Lobby::setupUI();
}

void Lobby::setupUI() {
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// display Doodler logo
	Sprite* logo = Sprite::create("doodlerLogo.png");
	logo->setAnchorPoint(Vec2(0.5f, 0.5f));
	logo->setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.75f));
	this->addChild(logo);

	// create solo button
	ui::Button* soloButton = ui::Button::create();
	soloButton->setAnchorPoint(Vec2(0.5f, 0.5f));
	soloButton->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height * 0.4f));
	soloButton->loadTextures("soloButton.png", "soloButtonPressed.png");
	soloButton->addTouchEventListener(CC_CALLBACK_2(Lobby::soloPressed, this));
	this->addChild(soloButton);

	// create duo button
	ui::Button* duoButton = ui::Button::create();
	duoButton->setAnchorPoint(Vec2(0.5f, 0.85f));
	duoButton->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height * 0.25f));
	duoButton->loadTextures("duoButton.png", "duoButtonPressed.png");
	duoButton->addTouchEventListener(CC_CALLBACK_2(Lobby::duoPressed, this));
	this->addChild(duoButton);
}

void Lobby::soloPressed(Ref *pSender, ui::Widget::TouchEventType eEventType)
{
	if (eEventType == ui::Widget::TouchEventType::ENDED)
	{
		Scene* scene = Scene::create();

		DrawingCanvas* drawingCanvas = DrawingCanvas::create();
		scene->addChild(drawingCanvas);

		Director::getInstance()->pushScene(scene);
	}
}

void Lobby::duoPressed(Ref *pSender, ui::Widget::TouchEventType eEventType)
{

}
