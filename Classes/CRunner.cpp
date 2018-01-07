#include "CRunner.h"

USING_NS_CC;

//
// 建立角色之前，必須先確定已經讀入儲存角色所有動態圖片的 plist 檔
//

CRunner::CRunner(const char *csbname, cocos2d::Layer &parent)
{
	// 讀取角色
	_runnerRoot = CSLoader::createNode(csbname);
	_bodyRoot = (cocos2d::Node *)_runnerRoot->getChildByName("bodyRoot");

	_body = (cocos2d::Sprite *)_bodyRoot->getChildByName("body_cuber01");
	_shadow = (cocos2d::Sprite *)_runnerRoot->getChildByName("shadow_cuber01");

	_normalFace = (cocos2d::Node *)_bodyRoot->getChildByName("NormalFace");
	_happyFace = (cocos2d::Node *)_bodyRoot->getChildByName("HappyFace");
	_depressedFace = (cocos2d::Node *)_bodyRoot->getChildByName("DepressedFace");
	init();
	_bodyRoot->setTag(101);
	//_runnerRoot->setTag(101);
	parent.addChild(_runnerRoot);
}
void CRunner::init() {
	_body->setColor(Color3B(255, 255, 255));
	_happyFace->setVisible(false);
	_normalFace->setVisible(true);
	_depressedFace->setVisible(false);

}

CRunner::~CRunner()
{
	_runnerRoot->removeAllChildren();
	_action->release();
}


void CRunner::go()
{
	_body->runAction(_action);
}
void CRunner::stop() {
	_body->stopAction(_action);
}

void CRunner::setAnimation(const char *plistFile)
{
	// 此處假設儲存角色所有動態圖片的 plist 檔已經讀入
	auto cache = AnimationCache::getInstance();
	cache->addAnimationsWithFile(plistFile);
	auto animation = cache->getAnimation("running");
	_action = RepeatForever::create(Animate::create(animation));
	_action->retain();
}

void CRunner::setPosition(const Point &pos)
{
	_runnerRoot->setPosition(pos);
}



void CRunner::setPosition(const float x, const float y)
{
	_runnerRoot->setPosition(x,y);
}

void CRunner::setColor(const Color3B& color)
{
	_body->setColor(color);
}
