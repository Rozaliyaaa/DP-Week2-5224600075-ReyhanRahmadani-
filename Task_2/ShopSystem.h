#pragma once
#include <iostream>
#include <memory>
#include "ModifierFactory.h"

struct ShopResult {
    std::unique_ptr<IModifier> modifier;
    int goldSpent = 0;
};

class ShopSystem {
public:
    ShopResult offer(int currentGold, bool alreadyHasModifier) const {
        std::cout << "[SHOP] offered: Double Score (cost 2 gold)\n";

        if (!alreadyHasModifier && currentGold >= 2) {
            std::cout << "[SHOP] purchased: Double Score\n";
            return {ModifierFactory::createDoubleScoreModifier(), 2};
        }

        std::cout << "[SHOP] skipped\n";
        return {nullptr, 0};
    }
};