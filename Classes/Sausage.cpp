#include "Sausage.h"
USING_NS_CC;
using namespace cocostudio::timeline;
Sausage::Sausage(const char *csbname, cocos2d::Layer &parent) {
	sRoot = CSLoader::createNode(csbname);
	sbody = (cocos2d::Sprite *)sRoot->getChildByName("sausage");
	oAction =(ActionTimeline *)CSLoader::createTimeline(csbname);
	oAction->retain();
	parent.addChild(sRoot);
}
Sausage::~Sausage() {
	
	oAction->release();
}
void Sausage::play() {
	
	sRoot->runAction(oAction);
	oAction->setTimeSpeed(0.5);
	oAction->gotoFrameAndPlay(0, 12, true);
}
void Sausage::setRot(const float r) {
	sRoot->setRotation(r);
}

void Sausage::setPosition(const cocos2d::Point &pos) {
	sRoot->setPosition(pos);
}
void Sausage::setPosition(const float x, const float y) {
	sRoot->setPosition(x,y);
}

void Sausage::setScale(const float f) {
	sRoot->setScale(f);
}
