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
};