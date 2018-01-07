#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;
using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

HelloWorld::~HelloWorld()
{
	_myJump->release();
	_mycallback->release();
	if (obstacle != NULL) delete obstacle;
	if (runner != NULL) delete runner;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);

// 音效與音樂 --------------------------------------------------------------------------------
	bkmusic = (cocostudio::ComAudio *)rootNode->getChildByName("bkmusic")->getComponent("bkmusic");
	pointmusic = (cocostudio::ComAudio *)rootNode->getChildByName("ScoreMusic")->getComponent("ScoreMusic");
	hpmusic = (cocostudio::ComAudio *)rootNode->getChildByName("HPMusic")->getComponent("HPMusic");
	overmusic = (cocostudio::ComAudio *)rootNode->getChildByName("OverMusic")->getComponent("OverMusic");
	//SimpleAudioEngine::getInstance()->unloadEffect("thinking cloud.mp3");  // 釋放音效檔
// Button -------------------------------------------------------------------------------------
	c3btn.playbtn =dynamic_cast<Button*>(rootNode->getChildByName("PlayBtn"));
	c3btn.replaybtn= dynamic_cast<Button*>(rootNode->getChildByName("ReplayBtn"));	
	c3btn.playbtn->addTouchEventListener(CC_CALLBACK_2(HelloWorld::PlayBtnTouchEvent, this));
	c3btn.replaybtn->addTouchEventListener(CC_CALLBACK_2(HelloWorld::ReplayBtnTouchEvent, this));
	sausagebtn= dynamic_cast<Button*>(rootNode->getChildByName("Sausage"));//sausageBtn
	sausagebtn->addTouchEventListener(CC_CALLBACK_2(HelloWorld::SausageTouchEvent, this));

// 文本 TTF 字型-------------------------------------------------------------------------------
	c3btn.playtxt = (cocos2d::ui::Text *)rootNode->getChildByName("PlayTxt");
	score=(cocos2d::ui::Text*)rootNode->getChildByName("Score");	
	overtxt = (cocos2d::ui::Text *)rootNode->getChildByName("OverTxt");
// loadingBar -------------------------------------------------------------------------------
	hp=(cocos2d::ui::LoadingBar *)rootNode->getChildByName("HP");
	hp->setDirection(LoadingBar::Direction::LEFT);
//sprite-----------------------------------------------------------------------------------------
	line1= (cocos2d::Sprite *)rootNode->getChildByName("line1");
	line2 = (cocos2d::Sprite *)rootNode->getChildByName("line2");
//註冊dostepSchedule
	this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::doStep));
	_listener1 = EventListenerTouchOneByOne::create();	//創建一個一對一的事件聆聽器
	_listener1->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);		//加入觸碰開始事件
	_listener1->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);		//加入觸碰移動事件
	_listener1->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);		//加入觸碰離開事件
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//加入剛創建的事件聆聽器
//runner
	runner = new CRunner("RunnerNode.csb", *this);
	runner->setPosition(visibleSize.width / 2.0f + 300, visibleSize.height / 2.0f);
	runner->setAnimation("cuberanim.plist");
	actionBody = runner->_bodyRoot;
	//runnerJump
	_myJump = JumpBy::create(1.0f, Point(0, 0), 230, 1);
	_myJump->retain();
	_runnerPt = runner->_bodyRoot->getPosition();
	_mycallback = CallFunc::create(this, callfunc_selector(HelloWorld::actionFinished));
	_mycallback->retain();
//reset
	reset();
	return true;
}
void HelloWorld::actionFinished() {
	//_NoJumps--;
	if (_NoJumps == 1) {
		auto moveto = MoveTo::create(0.15f, _runnerPt);
		//auto actionBody = runner->_runnerRoot->getChildByTag(101);
		actionBody->runAction(moveto);
		_NoJumps--;
	}
}
void HelloWorld::TimeCounter(float dt) {
	timer++;
	flip = !flip;
	if (timer == 1)c3btn.playtxt->setString("2");
	else if (timer == 2)c3btn.playtxt->setString("1");
	else if (timer == 3)c3btn.playtxt->setString("GO");
	else if (timer == 4) {
		c3btn.playtxt->setVisible(false);
		bkmusic->playBackgroundMusic();
		sausagebtn->setTouchEnabled(true);
		sausagebtn->setBright(true);
		runner->go();
		isStart = true;
	}
	if (isStart) {
		if (isSausage) {
			sausageTimer++;

			if (sausageTimer==3 && sausage != NULL) {			
				sausage->sRoot->setVisible(false);
				isSausage = false;
			}
		}
		if (timer % 5 == 0) {//
			int i = random(1, 3);
			Size visibleSize = Director::getInstance()->getVisibleSize();
			_oMove = MoveBy::create(i + 1, Point(1450, 0));
			if (obstacle != NULL ) {
				delete obstacle;
				isO = false;
			}
			obstacle = new CObstacle("ObstacleNode.csb", *this);//障礙物
			odis = 0;
			isGood = true;
			isPoint = false;
			isO = true;
			obstacle->setPosition(visibleSize.width / 2.0f - 700, visibleSize.height / 2.0f);
			obstacle->setScale(0.8f);
			obstacle->play(i);
			obstacle->_oRoot->runAction(_oMove);
		}
		line1->setVisible(flip);
		line2->setVisible(!flip);
	}
	
}
void HelloWorld::reset() {
	isSausage = false;
	sausagebtn->setBright(false);
	sausagebtn->setTouchEnabled(false);
	odis = 0;
	bkmusic->stopBackgroundMusic();
	isO = false;
	hp->setPercent(100);
	timer = 0;
	c3btn.playtxt->setVisible(false);
	_scoreno = 0;
	strcpy(this->_cScoreNo, "SCORE : 000");
	score->setString(_cScoreNo);
	overtxt->setVisible(false);
	_NoJumps = 0;	
	if (obstacle != NULL && isStart) {
		obstacle->_oRoot->setVisible(false);
	}
	line1->setVisible(true);
	line2->setVisible(false);
	runner->stop();
	runner->init();
	isStart = false;
}

void HelloWorld::over() {
	if (hp->getPercent() == 0) {
		overtxt->setVisible(true);
		isStart = false;
		runner->stop();
		bkmusic->stopBackgroundMusic();
		overmusic->playEffect();
	}
}
void  HelloWorld::collide() {
	
	if (obstacle != NULL && isO) {
		Point obPt = obstacle->_oRoot->getPosition();
		Point runnerPt = runner->_runnerRoot->getPosition()+ runner->_bodyRoot->getPosition();
		if (sausage!=NULL && obPt.distance(sausage->sRoot->getPosition()) < 20.0f) {
			sausage->sRoot->setVisible(false);
			odis = 3;
		}

		if (obPt.x+100.0f >= runnerPt.x) {	//遇到後	
			
			if (runnerPt.distance(obPt) < 150.0f) {//沒跳過
				isGood = false;
			}
			//runner->_depressedFace->setVisible(!isGood);//表情怪怪
			runner->_normalFace->setVisible(false);
			//runner->_happyFace->setVisible(isGood);		
			if (isGood) {//分數
				runner->_depressedFace->setVisible(false);
				runner->_happyFace->setVisible(true);
				runner->setColor(Color3B(75, 75, 77));
				if (_scoreno < 999 && !isPoint) {
					int I=obstacle->getI();
					if(I==1)_scoreno++;
					else if (I == 2)_scoreno+=10;
					else if (I == 3)_scoreno+=100;
					isPoint = true;
					pointmusic->playEffect();

					int i = _scoreno, j = 0;
					if (i < 10) {
						this->_cScoreNo[10] = i + 48;
						this->_cScoreNo[9] = 48;
						this->_cScoreNo[8] = 48;
					}
					else if(i>=10 && i<100){
						this->_cScoreNo[10] = i%10 + 48;
						this->_cScoreNo[9] = i/10 + 48;
						this->_cScoreNo[8] = 48;
					}
					else if (i >= 100 && i<1000) {
						this->_cScoreNo[10] = i%10 + 48;
						this->_cScoreNo[9] = (i / 10)%10 + 48;
						this->_cScoreNo[8] = i/100 + 48;
					}
					score->setString(_cScoreNo);
				}
			}
			else {
				runner->_depressedFace->setVisible(true);
				runner->_happyFace->setVisible(false);
				runner->setColor(Color3B(100, 209, 63));
				float t = hp->getPercent();
				if (t > 0 && !isPoint) {
					isPoint = true;
					hpmusic->playEffect();
					int I = obstacle->getI();
					if (I == 1)t -= 20;
					else if (I == 2)t -= 10;
					else if (I == 3)t -= 5;
					if (t <= 0)t = 0;
					hp->setPercent(t);
				}

			}
			

		}
		else {//遇到前
			runner->setColor(Color3B(255, 255, 255));
			runner->_depressedFace->setVisible(false);			
			runner->_happyFace->setVisible(false);
			runner->_normalFace->setVisible(true);
		}


	}
}
void HelloWorld::doStep(float dt)
{
	if (isStart) {
		collide();
		over();
		if (obstacle != NULL && odis==3) {
			obstacle->_oRoot->setVisible(false);
			isO = false;
		}
	}
	
}
void HelloWorld::ReplayBtnTouchEvent(Ref *pSender, Widget::TouchEventType type) {
	switch (type) {
	case Widget::TouchEventType::BEGAN:
		log("Touch Down");
		break;
	case Widget::TouchEventType::MOVED:
		log("Touch Move");
		break;
	case Widget::TouchEventType::ENDED:
		c3btn.replay();
		reset();
		this->unschedule(schedule_selector(HelloWorld::TimeCounter));

		break;
	case Widget::TouchEventType::CANCELED:
		log("Touch Cancelled");
		break;
	default:
		break;
	}

}
void HelloWorld::PlayBtnTouchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
		case Widget::TouchEventType::BEGAN:
			log("Touch Down");
			break;
		case Widget::TouchEventType::MOVED:
			log("Touch Move");
			break;
		case Widget::TouchEventType::ENDED:
			log("Touch Up");
			timer = 0;
			c3btn.play();
			this->schedule(schedule_selector(HelloWorld::TimeCounter), 1.0f);
			break;
		case Widget::TouchEventType::CANCELED:
			log("Touch Cancelled");
			break;
		default:
			break;
	}
}
void HelloWorld::SausageTouchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		log("Touch Down");
		break;
	case Widget::TouchEventType::MOVED:
		log("Touch Move");
		break;
	case Widget::TouchEventType::ENDED:
		log("Touch Up");
		if (!isSausage) {
			if (sausage != NULL) {
				delete sausage;
			}
			sausage = new Sausage("SausageNode.csb", *this);
			isSausage = true;
			sausageTimer = 0;
			sausage->setPosition(runner->_runnerRoot->getPosition().x - 50.0f, runner->_bodyRoot->getPosition().y + 350.0f);
			sausage->setRot(-90.0f);
			sausage->play();
			sMove = MoveBy::create(2, Point(-1000, 0));
			sausage->sRoot->runAction(sMove);
		}
		break;
	case Widget::TouchEventType::CANCELED:
		log("Touch Cancelled");
		break;
	default:
		break;
	}
}

bool  HelloWorld::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//觸碰開始事件
{
	Point touchLoc = pTouch->getLocation();
	if (obstacle != NULL) {
		Size osize = obstacle->_body->getContentSize();
		Point opoint = obstacle->_oRoot->getPosition();
		Rect rectO = Rect(opoint.x - osize.width / 2, opoint.y - osize.height / 2, osize.width, osize.height);

		if (rectO.containsPoint(touchLoc)) {
			if (odis < 3)odis++;
		}
	}
	if (_NoJumps == 0 && isStart) {  // 第一次被按下
		actionBody->runAction(Sequence::create(_myJump, _mycallback, NULL));
		_NoJumps++;
	}
	return true;
}

void  HelloWorld::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰移動事件
{


}

void  HelloWorld::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰結束事件 
{



}
