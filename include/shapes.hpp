#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <array>

struct Shape {
  float x, y;
};

struct Point : Shape {};

struct Circle : Shape {
  float radius;
};

struct Line : Shape {
  float endX, endY;
};

struct AABB : Shape {
  float w, h;
};

struct OBB  : AABB {
  float rotation;
};

struct Polygon : Shape {
	std::vector<Point> vertices;
	float rotation;
};

#endif //SHAPE_HPP
