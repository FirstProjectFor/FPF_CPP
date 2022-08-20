#include "iostream"

using namespace std;

class Shape {
 public:
  //virtual 声明虚函数实现该接口的类需要实现该函数
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
