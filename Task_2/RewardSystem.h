#pragma once

class RewardSystem {
public:
    int calculateGoldReward(int roundScore) const {
        return (roundScore / 100) + 1;
    }
};
