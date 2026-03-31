#pragma once
#include <random>
#include <vector>

class HandGenerator {
private:
    std::mt19937 engine;
    std::uniform_int_distribution<int> distribution;

public:
    HandGenerator()
        : engine(std::random_device{}()), distribution(1, 13) {}

    std::vector<int> drawHand() {
        std::vector<int> hand;
        for (int i = 0; i < 5; ++i) {
            hand.push_back(distribution(engine));
        }
        return hand;
    }
};