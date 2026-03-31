#pragma once
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include "IModifier.h"

class ScoringSystem {
private:
    std::vector<std::unique_ptr<IModifier>> modifiers;

public:
    int calculateBaseScore(int handValue) const {
        return handValue * 10;
    }

    int applyModifiers(int baseScore) const {
        int finalScore = baseScore;
        for (const auto& modifier : modifiers) {
            finalScore = modifier->apply(finalScore);
        }
        return finalScore;
    }

    void addModifier(std::unique_ptr<IModifier> modifier) {
        modifiers.push_back(std::move(modifier));
    }

    bool hasAnyModifier() const {
        return !modifiers.empty();
    }

    std::string activeModifiers() const {
        if (modifiers.empty()) {
            return "None";
        }

        std::ostringstream out;
        for (std::size_t i = 0; i < modifiers.size(); ++i) {
            if (i > 0) {
                out << ", ";
            }
            out << modifiers[i]->name();
        }
        return out.str();
    }
};