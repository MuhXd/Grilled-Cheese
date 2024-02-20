#include "CheeseMake.hpp"
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
int CheeseMake::Script(int scriptnum) {
    if (scriptnum) == 1 {
        std::this_thread::sleep_for(std::chrono::seconds(3));
         std::cout << "Script place\n I love scripts";
    }
}
bool CheeseMake::setup() {
        auto winSize = CCDirector::get()->getWinSize();
		auto versionLabel = CCLabelBMFont::create("https://www.allrecipes.com/recipe/23891/grilled-cheese-sandwich/", "chatFont.fnt");
		versionLabel->setOpacity(60);
		versionLabel->setAnchorPoint(ccp(0.0f,0.5f));
		versionLabel->setPosition(winSize/2 + ccp(-winSize.width/2, -winSize.height/2) + ccp(3, 6));
		versionLabel->setScale(0.5f);
		this->addChild(versionLabel);
		this->setTitle("Grilled Cheese");
		auto menu = CCMenu::create();
    	menu->setPosition({0, 0});
    	m_mainLayer->addChild(menu);
        std::thread CheeseMake::Script(1)
    return true;
}

CheeseMake* CheeseMake::create() {
    auto ret = new CheeseMake;
    if (ret && ret->init(420.f, 210.f)) {
        ret->autorelease();
        ret->setID("Cheese"_spr);
        return ret;
    }

    CC_SAFE_DELETE(ret);
    return nullptr;
}