#include "iostream"

using namespace std;

class Shape {
 public:
  virtual int getArea() = 0;
};

class Rectangle : public Shape {
 public:
  int getArea();
};

int Rectangle::getArea() { return 0; }

int main(int argc, char const* argv[]) {
  Rectangle rec = Rectangle();
  cout << "Rectangle: " << &rec << endl;
  return 0;
}
