#pragma once
class BotPlayer : public Player {
public:
    BotPlayer(const std::string& name) : Player(name) {
        std::srand(static_cast<unsigned int>(std::time(0)));
    }
    bool isBot() const override { return true; }
};
