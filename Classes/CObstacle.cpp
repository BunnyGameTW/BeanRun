#include "CObstacle.h"

USING_NS_CC;
using namespace cocostudio::timeline;

CObstacle::CObstacle(const char *csbname, cocos2d::Layer &parent) {
	// Åª¨ú¨¤¦â
	_oRoot = CSLoader::createNode(csbname);
	_body = (cocos2d::Sprite *)_oRoot->getChildByName("oBody");
	_shadow = (cocos2d::Sprite *)_oRoot->getChildByName("oShadow");

	o1 = (cocos2d::Sprite *)_oRoot->getChildByName("o1");
	o2 = (cocos2d::Sprite *)_oRoot->getChildByName("o2");
	o3 = (cocos2d::Sprite *)_oRoot->getChildByName("o3");
	o1->setColor(Color3B(10, 10, 10));
	o1->setVisible(false);
	o2->setVisible(false);
	o3->setVisible(false);
	_body->setVisible(false);
	oAction = (ActionTimeline *)CSLoader::createTimeline(csbname);
	oAction->retain();

	parent.addChild(_oRoot);
}
CObstacle::~CObstacle()
{
	_oRoot->removeAllChildren();
	oAction->release();
}
int CObstacle::getI() {
	return I;
}
void CObstacle::setScale(const float f)
{
	_oRoot->setScale(f);
}
void CObstacle::diff(int i) {
	I = i;
	if(i == 1)	o1->setVisible(true);
	if (i == 2)	o2->setVisible(true);
	if (i == 3)	o3->setVisible(true);
	
}
void CObstacle::play(int i) {
	diff(i);
	_oRoot->runAction(oAction);
	oAction->setTimeSpeed(0.5);
	oAction->gotoFrameAndPlay(0, 35, false);
}
void CObstacle::setPosition(const Point &pos)
{
	_oRoot->setPosition(pos);
}



void CObstacle::setPosition(const float x, const float y)
{
	_oRoot->setPosition(x, y);
}
