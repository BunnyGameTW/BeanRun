#include "C3SButton.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

void C3SButton::play() {
	if (isFirst)playtxt->setVisible(true);
	isFirst = false;
	playbtn->setBright(false);
	playbtn->setTouchEnabled(false);
}
void C3SButton::replay() {
	playtxt->setVisible(false);
	playtxt->setString("3");
	isFirst = true;
	playbtn->setBright(true);
	playbtn->setTouchEnabled(true);
}