#include "RunSession.h"
#include <iostream>
#include <sstream>
#include <utility>

RunSession::RunSession(int totalRounds)
    : currentHandValue(0),
      currentBaseScore(0),
      currentRoundScore(0),
      currentGoldReward(0) {
    state.totalRounds = totalRounds;
}

bool RunSession::isGameOver() const {
    return state.currentRound > state.totalRounds;
}

void RunSession::startRun() {
    std::cout << "=== RUN START ===\n";

    while (!isGameOver()) {
        printRoundHeader();
        playerActionPhase();
        systemEvaluationPhase();
        rewardPhase();
        updateStatePhase();
        shopPhase();
        advanceRound();

        if (!isGameOver()) {
            std::cout << "\n";
        }
    }

    printRunSummary();
}

void RunSession::printRoundHeader() const {
    std::cout << "Round " << state.currentRound << "\n";
}

void RunSession::playerActionPhase() {
    currentHand = handGenerator.drawHand();
    currentHandValue = calculateHandValue(currentHand);

    std::cout << "[PLAYER] drew hand: " << handToString(currentHand)
              << " | value: " << currentHandValue << "\n";
    std::cout << "[PLAYER] active modifiers: "
              << scoringSystem.activeModifiers() << "\n";
}

void RunSession::systemEvaluationPhase() {
    currentBaseScore = scoringSystem.calculateBaseScore(currentHandValue);
    currentRoundScore = scoringSystem.applyModifiers(currentBaseScore);

    std::cout << "[SYSTEM] base score: " << currentBaseScore << "\n";
    std::cout << "[SYSTEM] final score after modifiers: "
              << currentRoundScore << "\n";
}

void RunSession::rewardPhase() {
    currentGoldReward = rewardSystem.calculateGoldReward(currentRoundScore);

    std::cout << "[REWARD] gold gained: " << currentGoldReward << "\n";
}

void RunSession::updateStatePhase() {
    state.totalScore += currentRoundScore;
    state.gold += currentGoldReward;

    std::cout << "[STATE] total score: " << state.totalScore
              << " | gold: " << state.gold << "\n";
}

void RunSession::shopPhase() {
    if (state.currentRound == state.totalRounds) {
        std::cout << "[SHOP] no shop after the last round\n";
        return;
    }

    ShopResult result = shopSystem.offer(state.gold, scoringSystem.hasAnyModifier());

    if (result.modifier) {
        state.gold -= result.goldSpent;
        scoringSystem.addModifier(std::move(result.modifier));
        std::cout << "[SHOP] gold after purchase: " << state.gold << "\n";
    }
}

void RunSession::advanceRound() {
    ++state.currentRound;
}

void RunSession::printRunSummary() const {
    std::cout << "=== RUN END ===\n";
    std::cout << "Final score: " << state.totalScore << "\n";
    std::cout << "Final gold: " << state.gold << "\n";
    std::cout << "Modifiers: " << scoringSystem.activeModifiers() << "\n";
}

int RunSession::calculateHandValue(const std::vector<int>& hand) const {
    int total = 0;
    for (int value : hand) {
        total += value;
    }
    return total;
}

std::string RunSession::cardName(int value) const {
    if (value == 1) return "A";
    if (value == 11) return "J";
    if (value == 12) return "Q";
    if (value == 13) return "K";
    return std::to_string(value);
}

std::string RunSession::handToString(const std::vector<int>& hand) const {
    std::ostringstream out;
    out << "[ ";
    for (int value : hand) {
        out << cardName(value) << " ";
    }
    out << "]";
    return out.str();
}