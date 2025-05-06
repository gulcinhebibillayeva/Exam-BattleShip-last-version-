#pragma once


class Game {
private:
    Player* player1;
    Player* player2;

public:
    Game(Player* p1, Player* p2) : player1(p1), player2(p2) {}

    ~Game() {
        delete player1;
        delete player2;
    }

    void setup(Player* player) {
        cout <<"placing ships for: " << player->getName();

        vector<int> shipSizes = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };

        for (int size : shipSizes) {
            bool placed = false;

            while (!placed) {
                vector<Coordinate> positions;
                bool vertical;

                if (player->isBot()) {
                    vertical = rand() % 2;
                    int x = rand() % (vertical ? 10 - size + 1 : 10);
                    int y = rand() % (vertical ? 10 : 10 - size + 1);

                    for (int i = 0; i < size; ++i) {
                        if (vertical)
                            positions.push_back(Coordinate(x + i, y));
                        else
                            positions.push_back(Coordinate(x, y + i));
                    }

                    placed = player->getOwnBoard()->placeShip(positions, false); 
                }
                else {
                   cout << " Ship size: " << size << "\n";
                    cout << "Placement direction: (v: vertical, h: horizontal): ";
                    char dir;
                   cin >> dir;
                    vertical = (dir == 'v');

                    int x, y;
                    cout << " Starting position (x y): ";
                    cin >> x >> y;

                    positions.clear();
                    for (int i = 0; i < size; ++i) {
                        if (vertical)
                            positions.push_back(Coordinate(x + i, y));
                        else
                            positions.push_back(Coordinate(x, y + i));
                    }

                    placed = player->getOwnBoard()->placeShip(positions, true); 

                    if (!placed) {
                        cout << "try again!\n";
                    }
                }
            }

            player->getOwnBoard()->print(!player->isBot()); 
            
        }
    }

    void play() {
        player1->setEnemyBoard(player2->getOwnBoard());
        player2->setEnemyBoard(player1->getOwnBoard());


        setup(player1);
        setup(player2);

        Player* current = player1;
        Player* opponent = player2;

        while (true) {
            cout << current->getName() << " plays:\n";
            cout << " Enemy board:\n";
            current->getEnemyBoard()->print(false); 

            
            if (!current->isBot()) {
                cout << "Your board:\n";
                current->getOwnBoard()->print(true);
            }

            Coordinate target = current->makeMove();

            char result;
            bool hit = opponent->getOwnBoard()->attack(target, result);
            current->getEnemyBoard()->attack(target, result); // enemy board-u yenilə

            if (result == 'y')cout << " You got hit!\n";
            else if (result == 'h') cout << " You sank the ship!\n";
            else cout << "Miss.\n";

            if (current->isBot()) {
                this_thread::sleep_for(chrono::milliseconds(800)); // yavaşıt
            }

            if (opponent->getOwnBoard()->allShipsSunk()) {
                cout << current->getName() << " win!\n";
                break;
            }

            swap(current, opponent);
        }
    }
};