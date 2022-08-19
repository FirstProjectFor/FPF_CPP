#include <cstring>
#include <iostream>

using namespace std;

// definition of showPersonInfo method
void showPeronInfo(struct Person p);
void showPeronInfoP(struct Person* p);

struct Person {
  char name[20];
  int age;
};

int main() {
  Person p;
  Person* pp = &p;

  strcpy(p.name, "p");
  p.age = 10;

  cout << "before showPeronInfo, p address is: " << pp << endl;
  showPeronInfo(p);

  cout << "before showPeronInfoP, pp address is: " << &pp << endl;
  showPeronInfoP(pp);

  return 0;
}

// implement of showPersonInfo method
void showPeronInfo(struct Person p) {
  cout << "in showPeronInfo, p address is:" << &p << endl;
  cout << "Name: " << p.name << " Age: " << p.age << endl;
}

// implement of showPersonInfo method
void showPeronInfoP(struct Person* p) {
  cout << "in showPeronInfoP, pp address is: " << &p << endl;
  cout << "Name: " << p->name << " Age: " << p->age << endl;
}