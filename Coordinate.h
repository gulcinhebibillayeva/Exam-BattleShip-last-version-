#pragma once

class Coordinate {
private:
    int x, y;

public:
    Coordinate() : x(0), y(0) {}
    Coordinate(int x, int y) : x(x), y(y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    bool operator==(const Coordinate& other) const {
        return x == other.x && y == other.y;
    }
};
