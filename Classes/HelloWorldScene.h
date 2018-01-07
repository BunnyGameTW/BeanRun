#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "CRunner.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "C3SButton.h"
#include "CObstacle.h"
#include "math\CCMath.h"
#include "Sausage.h"
class HelloWorld : public cocos2d::Layer
{
private:

	cocos2d::ui::Text *playtxt;
	cocos2d::ui::Text *overtxt;
	cocos2d::Sprite *line1, *line2;
	C3SButton c3btn,c3btn2;
	cocos2d::ui::Button *playbtn;
	cocos2d::ui::Text *score;
	cocos2d::ui::LoadingBar *hp;
	CRunner *runner;
	CObstacle *obstacle;
	Sausage *sausage;
public:
	cocostudio::ComAudio *overmusic, *pointmusic, *hpmusic,*bkmusic;
	int  _scoreno;
	char _cScoreNo[12];

	~HelloWorld();
    static cocos2d::Scene* createScene();
	void doStep(float dt);

	void TimeCounter(float dt);
	int timer,sausageTimer;
    virtual bool init();	
	void PlayBtnTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void ReplayBtnTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void SausageTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);


	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰開始事件
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰移動事件
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰結束事件 

	cocos2d::JumpBy   *_myJump;
	int _NoJumps;
	cocos2d::CallFunc *_mycallback;
	cocos2d::Point _runnerPt;
	void actionFinished();
	bool isStart,flip;
	void collide();
	cocos2d::MoveBy * _oMove,*sMove;

	bool isGood,isPoint,isO,isSausage;
	void reset();
	void over();
	cocos2d::Node *actionBody;
	cocos2d::ui::Button *sausagebtn;
	int odis;
	// implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
