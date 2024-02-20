#pragma once
#include <Geode/Geode.hpp>


using namespace geode::prelude;

class CheeseMake : public geode::Popup<> {
protected:
    int Script(int po) override;
    bool setup() override;
public:
    static CheeseMake* create();
};