#include "collisions.hpp"

// XD
bool point_vs_point (Point a, Point b)
{
  return a.x == b.x && a.y == b.y;
}
bool point_vs_circle (Point a, Circle b)
{
  float dx = a.x - b.x;
  float dy = a.y - b.y;

  // An old trick is to use square distance, the save a sqrt call
  return dx * dx + dy * dy <= b.radius * b.radius;
}
bool circle_vs_circle (Circle a, Circle b)
{
  float dx = a.x - b.x;
  float dy = a.y - b.y;

  return dx * dx + dy * dy <= (a.radius + b.radius) * (a.radius + b.radius);
}
bool point_vs_aabb (Point a, AABB b)
{
  return a.x >= b.x - b.w / 2.0f && a.x <= b.x + b.w / 2.0f &&
		 a.y >= b.y + b.h / 2.0f && a.y <= b.y - b.h / 2.0f;
}
bool aabb_vs_aabb (AABB a, AABB b)
{
  return a.x + a.w / 2.0f >= b.x - b.w / 2.0f && a.x - a.w / 2.0f <= b.x + b.w / 2.0f &&
		 a.y + a.h / 2.0f >= b.y - b.h / 2.0f && a.y - a.h / 2.0f <= b.y + b.h / 2.0f;
}
bool aabb_vs_circle (AABB a, Circle b)
{
  float x = b.x;
  float y = b.y;

  if (b.x < a.x - a.w / 2.0f) x = a.x - a.w / 2.0f;
  else if (b.x > a.x + a.w / 2.0f) x = a.x + a.w / 2.0f;

  if (b.y < a.y + a.h / 2.0f) y = a.y + a.h / 2.0f;
  else if (b.y > a.y - a.h / 2.0f) y = a.y - a.h / 2.0f;

  auto dx = b.x - x;
  auto dy = b.y - y;

  return dx * dx + dy * dy <= b.radius * b.radius;

}
