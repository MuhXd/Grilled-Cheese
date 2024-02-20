#include "CheeseMake.hpp"


bool CheeseMake::setup() {
        auto winSize = CCDirector::get()->getWinSize();
		auto versionLabel = CCLabelBMFont::create("Step One", "chatFont.fnt");
		versionLabel->setOpacity(60);
		versionLabel->setAnchorPoint(ccp(0.0f,0.5f));
		versionLabel->setPosition(winSize/2 + ccp(-winSize.width/2, -winSize.height/2) + ccp(3, 6));
		versionLabel->setScale(0.5f);
		this->addChild(versionLabel);
		this->setTitle("Grilled Cheese");
		auto menu = CCMenu::create();
    	menu->setPosition({0, 0});
    	m_mainLayer->addChild(menu);
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