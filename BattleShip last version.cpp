
#include <iostream>
#include<vector>
#include<string>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono> 
#include <thread>
#include<conio.h>

using namespace std;

#include"Coordinate.h"
#include"Ship.h"
#include"Board.h"
#include"Player.h"
#include"BotPlayer.h"
#include"HumanPlayer.h"
#include"Game.h"

int main()
{ 
    srand(static_cast<unsigned int>(time(0)));
  cout << "Welcome to battleShip";
  cout << "\n PLayer vs Bot";
  cout << "\n PLayer vs PLayer";
  cout << "\n Bot vs Bot";
  cout << "\nSeciminizi edin:";
  int choosing;
  cin >> choosing;
  while (choosing < 1 || choosing > 3) {
      cout << " Invalid choice. Please try again.\n";
      cout << "1. Player vs Bot\n";
      cout << "2. Player vs Player\n";
      cout << "3. Bot vs Bot\n";
      cout << "Please make your choice (1-3): ";
      cin >> choosing;
  }
  Player* p1 = nullptr;
  Player* p2 = nullptr;
  string name;
  switch (choosing) {
  case 1:
      cout << "Enter your name: ";
      cin >> name;
      p1 = new HumanPlayer(name);
      p2 = new BotPlayer("BOT");
      break;
  case 2:
      cout << "1. Enter first player`s name: ";
      cin >> name;
      p1 = new HumanPlayer(name);
  
      cout << "2. Enter second player`s name: ";
      cin >> name;
      p2 = new HumanPlayer(name);
      break;
  case 3:
      p1 = new BotPlayer("Bot1");
      p2 = new BotPlayer("Bot2");
      break;
  default:
      cout << "Wrong choose\n";
      return 0;
  }
  Game game(p1, p2);
  game.play();

  return 0;

  
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
