#pragma once
#include <string>

enum class MobsState {
	left,
	righ,
	up,
	down,
	upAttack,
	downAttack,
	rightAttack,
	leftAttack,

};

using Distance = float;


struct Coord {
	Coord() : x(0), y(0) {};
	Coord(float _x, float _y) : x(_x), y(_y) {};
	friend bool operator<(const Coord& c1, const Coord& c2);
	friend bool operator==(const Coord& c1, const Coord& c2);

	friend Coord operator+(const Coord& left, const Coord& right);
	friend Coord operator-(const Coord& left, const Coord& right);
	Coord operator/(float del);
	Coord del(float d) const;
	std::string toString() const;
	Distance length() const;
	Coord revert() const;
	float x;
	float y;
};
