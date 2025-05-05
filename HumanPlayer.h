#pragma once
class HumanPlayer : public Player {
public:
    HumanPlayer(const std::string& name) : Player(name) {}
    virtual bool isBot() const { return false; }
};
