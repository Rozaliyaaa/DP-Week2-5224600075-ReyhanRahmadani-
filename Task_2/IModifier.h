#pragma once
#include <string>

class IModifier {
public:
    virtual ~IModifier() = default;
    virtual int apply(int score) const = 0;
    virtual std::string name() const = 0;
};