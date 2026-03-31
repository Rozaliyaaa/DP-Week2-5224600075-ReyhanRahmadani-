#pragma once
#include <string>
#include <vector>
#include "GameState.h"
#include "HandGenerator.h"
#include "RewardSystem.h"
#include "ScoringSystem.h"
#include "ShopSystem.h"

class RunSession {
private:
    GameState state;
    HandGenerator handGenerator;
    ScoringSystem scoringSystem;
    RewardSystem rewardSystem;
    ShopSystem shopSystem;

    std::vector<int> currentHand;
    int currentHandValue;
    int currentBaseScore;
    int currentRoundScore;
    int currentGoldReward;

    bool isGameOver() const;
    void playerActionPhase();
    void systemEvaluationPhase();
    void rewardPhase();
    void updateStatePhase();
    void shopPhase();
    void advanceRound();
    void printRoundHeader() const;
    void printRunSummary() const;

    int calculateHandValue(const std::vector<int>& hand) const;
    std::string cardName(int value) const;
    std::string handToString(const std::vector<int>& hand) const;

public:
    explicit RunSession(int totalRounds = 3);
    void startRun();
};