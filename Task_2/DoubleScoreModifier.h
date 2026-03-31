#pragma once
#include "IModifier.h"

class DoubleScoreModifier : public IModifier {
public:
    int apply(int score) const override {
        return score * 2;
    }

    std::string name() const override {
        return "Double Score";
    }
};