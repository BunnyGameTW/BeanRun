
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
using namespace cocostudio::timeline;

  class CObstacle {
  public:
	  CObstacle(const char *csbname, cocos2d::Layer &parent);
	  ~CObstacle();
	  cocos2d::Sprite *_shadow;
	  cocos2d::Sprite *_body;
	  cocos2d::Node   *_oRoot;
	  cocos2d::Sprite *o1;
	  cocos2d::Sprite *o2;
	  cocos2d::Sprite *o3;
	  int I;
	  void diff(int i);
	  void play(int i);
	  void setPosition(const cocos2d::Point &pos);
	  void setPosition(const float x, const float y);
	  void setScale(const float f);
	  int getI();
	  cocostudio::timeline::ActionTimeline *oAction;
};