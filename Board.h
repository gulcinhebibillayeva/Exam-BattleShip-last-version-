#pragma once
#include<vector>
class Board {
private:
	char** grid;
	vector<Ship*> ships;
public:
	Board() {
		grid = new char* [10];
		for (int i = 0; i < 10; ++i) {
			grid[i] = new char[10];
			for (int j = 0; j < 10; ++j)
				grid[i][j] = '.';
		}
	}
	
	~Board() {
		for (int i = 0; i < 10; ++i)
			delete[] grid[i];
		delete[] grid;

		for (size_t i = 0; i < ships.size(); ++i)
			delete ships[i];
	}

	void print(bool showShips) {
		cout << "  ";
		for (int j = 0; j < 10; ++j) cout << j << " ";
		cout << "\n";

		for (int i = 0; i < 10; ++i) {
			cout << i << " ";
			for (int j = 0; j < 10; ++j) {
				char cell = grid[i][j];
				if (cell == 'S' && !showShips)
					cout << ". ";
				else
					cout << cell << " ";
			}
			cout << "\n";
		}
	}


	

	bool placeShip(const vector<Coordinate>& positions, bool showError = true) {
		try {
			
			for (const auto& pos : positions) {
				int x = pos.getX(), y = pos.getY();
				if (x < 0 || x >= 10 || y < 0 || y >= 10 || grid[x][y] != '.') {
					throw runtime_error("Wrong place!");
				}

				
				for (int dx = -1; dx <= 1; ++dx) {
					for (int dy = -1; dy <= 1; ++dy) {
						int nx = x + dx, ny = y + dy;
						if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && grid[nx][ny] == 'S') {
							throw runtime_error("Ships must not touch each other.");
						}
					}
				}
			}

			
			Ship* newShip = new Ship(positions);

			
			for (const auto& pos : positions) {
				grid[pos.getX()][pos.getY()] = 'S';
			}

			
			ships.push_back(newShip);
			return true;
		}
		catch (const exception& ex) {
			if (showError)
				cout<< "Error: " << ex.what() << endl;
			return false;
		}
	}

	bool attack(const Coordinate& coord, char& result) {
		int x = coord.getX(), y = coord.getY();
		if (x < 0 || x >= 10 || y < 0 || y >= 10)
			return false;

		for (Ship* ship : ships) {
			if (ship->receiveHit(coord)) {
				result = ship->isSunk() ? 'h' : 'y';
				grid[x][y] = result;
				return true;
			}
		}

		result = 'm';
		grid[x][y] = result;
		return false;
	}
	bool allShipsSunk() const {
		for (const Ship* ship : ships)
			if (!ship->isSunk()) return false;
		return true;
	}

	char getCellState(int x, int y) const {
		return grid[x][y];
	}


};