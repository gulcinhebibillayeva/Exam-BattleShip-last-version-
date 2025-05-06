#pragma once
class BotPlayer : public Player {
public:
    BotPlayer(const string& name) : Player(name) {
        srand(static_cast<unsigned int>(time(0)));
    }

    Coordinate makeMove() override {
        int x, y;
        do {
            x = rand() % 10;
            y = rand() % 10;
        } while (enemyBoard->getCellState(x, y) == 'y' || enemyBoard->getCellState(x, y) == 'h' || enemyBoard->getCellState(x, y) == 'm');

        cout << name << " choose coordinate: " << x << ", " << y << endl;
        return Coordinate(x, y);
    }

    bool isBot() const override { return true; }


};