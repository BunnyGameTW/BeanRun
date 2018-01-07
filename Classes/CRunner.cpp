#include "CRunner.h"

USING_NS_CC;

//
// �إߨ��⤧�e�A�������T�w�w�gŪ�J�x�s����Ҧ��ʺA�Ϥ��� plist ��
//

CRunner::CRunner(const char *csbname, cocos2d::Layer &parent)
{
	// Ū������
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
	// ���B���]�x�s����Ҧ��ʺA�Ϥ��� plist �ɤw�gŪ�J
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
