
#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <cocos2d.h>
#include <vector>
#include <chrono>

/*
https://www.allrecipes.com/recipe/23891/grilled-cheese-sandwich/
*/
class CheeseMake : public geode::Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override {
	  auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
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
	}
	static CheeseMake* create() {
        auto ret = new CheeseMake();
    }
	public:
	  void open(CCObject*) {
		auto layer = create();
		layer->m_noElasticity = false;
		layer->show();
	}
};
class $modify(customMenu, MenuLayer) {
	
	
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		/**
		 * See this page for more info about buttons
		 * https://docs.geode-sdk.org/tutorials/buttons
		*/
		auto myButton = CCMenuItemSpriteExtra::create(
			ButtonSprite::create("Teeeeest"),
			this,
			/**
			 * Here we use the name we set earlier for our modify class.
			*/
			menu_selector(customMenu::onMyButton)
		);

		
		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(myButton);

		
		myButton->setID("my-button"_spr);

		menu->updateLayout();

		return true;
	}

	/**
	 * This is the callback function for the button we created earlier.
	 * The signature for button callbacks must always be the same,
	 * return type `void` and taking a `CCObject*`.
	*/
	void onMyButton(CCObject* po ) {
		geode::createQuickPopup(
            "Grilled Cheese",
            "Are you <cg>Sure</c> you want to cook a <cy>Grilled Cheese</c>?",
            "Cancel", "Confirm",
            [](FLAlertLayer* tis, bool btn2) {
                if (btn2) {  
                    CheeseMake::open(po);
                }
            }
        );
    }
	
};
