#include <cmath>
#include <iostream>

struct Point {
  double x;
  double y;
};

using Life = unsigned int;

struct Player {
  Point position;
  Life life;
};

double calculate_distance(Point p1, Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
  Point p1{1.1, 2.7};
  Point p2{3.7, 4.4};

  std::cout << "A distância entre os pontos p1 e p2 é " << calculate_distance(p1, p2) << std::endl;

  return 0;
}
