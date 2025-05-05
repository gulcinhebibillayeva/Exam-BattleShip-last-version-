#pragma once
class Ship {
private:
	Coordinate* positions;
	bool* hits;
	int size;

public:
	Ship(const vector<Coordinate>& pos) {
		size = pos.size();
		positions = new Coordinate[size];
		hits = new bool[size];
		for (int i = 0; i < size; ++i) {
			positions[i] = pos[i];
			hits[i] = false;
		}
	}
	Ship(const Ship& other) {
		size = other.size;
		positions = new Coordinate[size];
		hits = new bool[size];

		for (int i = 0; i < size; ++i) {
			positions[i] = other.positions[i];
			hits[i] = other.hits[i];
		}
	}
	Ship& operator=(const Ship& other) {
		if (this != &other) {
			delete[] positions;
			delete[] hits;
			size = other.size;
			positions = new Coordinate[size];
			hits = new bool[size];
			for (int i = 0; i < size; ++i) {
				positions[i] = other.positions[i];
				hits[i] = other.hits[i];
			}
		}
		return *this;
	}


	~Ship() {
		delete[] positions;
		delete[] hits;
	}

};
