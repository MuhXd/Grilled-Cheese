#include "CheeseMake.hpp"
#include <chrono>
#include <thread>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
void Script(int scriptnum) {
    if (scriptnum == 1) {
        int pause = 0;
        auto timer = CCLabelBMFont::create("", "chatFont.fnt");
          while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(0.5));
        pause+=0.5;
        pause->setString(std::string(pause));
        log::info("Paused for added 0.5");
        if (pause >= 3) {
log::info("Paused for 3s");
break;
        }
          }
    }
}
bool CheeseMake::setup() {
        auto winSize = CCDirector::get()->getWinSize();
		auto recipe = CCLabelBMFont::create("https://www.allrecipes.com/recipe/23891/grilled-cheese-sandwich/", "chatFont.fnt");
		recipe->setOpacity(60);
		recipe->setAnchorPoint(ccp(0.0f,0.5f));
		recipe->setPosition(winSize/2 + ccp(-winSize.width/2, -winSize.height/2) + ccp(3, 6));
		recipe->setScale(0.5f);
		this->addChild(recipe);
		this->setTitle("Grilled Cheese");
		auto menu = CCMenu::create();
    	menu->setPosition({0, 0});
    	m_mainLayer->addChild(menu);
       std::thread e(Script, 1);
       e.detach();
    return true;
}

CheeseMake* CheeseMake::create() {
    auto ret = new CheeseMake;
    if (ret && ret->initAnchored(420.f, 210.f)) {
        ret->autorelease();
        ret->setID("Cheese"_spr);
        return ret;
    }

    CC_SAFE_DELETE(ret);
    return nullptr;
}