
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
using namespace cocostudio::timeline;

class Sausage{
public:
	Sausage(const char *csbname, cocos2d::Layer &parent);
	~Sausage();
	cocos2d::Node   *sRoot;
	cocos2d::Sprite *sbody;
	
	void play();
	void setPosition(const cocos2d::Point &pos);
	void setPosition(const float x, const float y);
	void setScale(const float f);
	void setRot(const float r);
	cocostudio::timeline::ActionTimeline *oAction;
};