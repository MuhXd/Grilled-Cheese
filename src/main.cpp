
#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <cocos2d.h>
#include <vector>
#include <chrono>
#include "CheeseMake.cpp"

/*
https://www.allrecipes.com/recipe/23891/grilled-cheese-sandwich/
*/

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
	void onMyButton(CCObject*) {
		geode::createQuickPopup(
            "Grilled Cheese",
            "Are you <cg>Sure</c> you want to cook a <cy>Grilled Cheese</c>?",
            "Cancel", "Confirm",
            [](auto, bool btn2) {
                if (btn2) {  
                     auto popup = CheeseMake::create();
       				 popup->m_noElasticity = false;
        			 popup->show();
                }
            }
        );
    }
	
};
