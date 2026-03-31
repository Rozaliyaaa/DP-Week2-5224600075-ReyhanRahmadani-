#pragma once
#include <memory>
#include "DoubleScoreModifier.h"

class ModifierFactory {
public:
    static std::unique_ptr<IModifier> createDoubleScoreModifier() {
        return std::make_unique<DoubleScoreModifier>();
    }
};