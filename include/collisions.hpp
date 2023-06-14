#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP

#include "shapes.hpp"

// BOOLEAN ONLY FOR THE MOMENT
[[maybe_unused]] bool point_vs_point (Point a, Point b);
[[maybe_unused]] bool circle_vs_circle (Circle a, Circle b);
[[maybe_unused]] bool aabb_vs_aabb (AABB a, AABB b);

// Point Circle
[[maybe_unused]] bool point_vs_circle (Point a, Circle b);
[[maybe_unused]] inline bool circle_vs_point (Circle a, Point b) { return point_vs_circle (b, a); }
// Point AABB
[[maybe_unused]] bool point_vs_aabb (Point a, AABB b);
[[maybe_unused]] inline bool aabb_vs_point (AABB a, Point b) { return point_vs_aabb(b, a); }
// AABB Circle
[[maybe_unused]] bool aabb_vs_circle (AABB a, Circle b);
[[maybe_unused]] inline bool circle_vs_aabb (Circle a, AABB b) { return aabb_vs_circle(b, a);}

#endif //COLLISIONS_HPP
