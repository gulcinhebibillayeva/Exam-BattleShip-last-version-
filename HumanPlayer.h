#pragma once
#include "Player.h"
#include <iostream>
#include<conio.h>
#include"Board.h"
class HumanPlayer : public Player {
public:
    HumanPlayer(const string& name) : Player(name) {}

    Coordinate makeMove() override {
        return getArrowInput(enemyBoard);

    }

    Coordinate getArrowInput(Board* enemyBoard) {
        int x = 0, y = 0;

        while (true) {
            cout << " Use the left and right arrow keys to select a target, press Enter to attack..\n";


            cout << "  ";
            for (int j = 0; j < 10; ++j) cout << j << " ";
            cout << "\n";

            for (int i = 0; i < 10; ++i) {
                cout << i << " ";
                for (int j = 0; j < 10; ++j) {
                    if (i == x && j == y)
                        cout << "X ";
                    else {
                        char cell = enemyBoard->getCellState(i, j);
                        if (cell == 'S') cout << ". ";
                        else cout << cell << " ";
                    }
                }
                cout << "\n";
            }

            char ch = _getch();
            if (ch == -32) {
                ch = _getch();
                switch (ch) {
                case 72: if (x > 0) --x; break;
                case 80: if (x < 9) ++x; break;
                case 75: if (y > 0) --y; break;
                case 77: if (y < 9) ++y; break;
                }
            }
            else if (ch == 13) {
                return Coordinate(x, y);
            }
        }
    }
    };