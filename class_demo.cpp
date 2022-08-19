#include <iostream>

using namespace std;

class Demo {
 public:
  //静态变量，也叫类变量，类的对象共享
  static int Id;

  int age;

  int getAge(void);
  void setAge(int age);

  uint32_t getPhone();
  void setPhone(uint32_t phone);

  //友元方法，可以访问类的所有变量
  friend char getSex(Demo demo);
  //友元类，可以访问类的所有变量
  friend class FriendDemo;

  //构造函数
  Demo(int age, uint32_t phone);
  //  析构函数
  ~Demo();

  //静态方法，只能访问静态变量
  int static getId() { return Id; }

 protected:
  uint32_t phone;

 private:
  char sex;
};

//初始化静态变量
int Demo::Id = 0;

Demo::Demo(int age, uint32_t phone) : phone(phone) {
  this->Id++;
  this->age = age;
  cout << "Demo construct is running !" << endl;
}

Demo::~Demo() {
  this->phone = 0;
  this->age = 0;
  this->sex = 0;
  cout << "Demo deconstruct is running !" << endl;
}

int Demo::getAge() { return this->age; }

void Demo::setAge(int age) { this->age = age; }

void Demo::setPhone(uint32_t phone) { this->phone = phone; }

uint32_t Demo::getPhone() { return this->phone; }

char getSex(Demo demo) { return demo.sex; }

// 友元类，在 Demo 中声明，声明之后友元类可以访问 Demo 的所有变量
class FriendDemo {
 public:
  FriendDemo(Demo* demo);
};

FriendDemo::FriendDemo(Demo* demo) {
  cout << "FriendDemo, age: " << demo->age << endl;
}

//继承 public/protected/private，继承会使成员的可访问权限变得更加严格
class ChildDemo : public Demo {
 public:
  uint32_t getPhone();
  ChildDemo(int age, uint32_t phone);
};

//调用父类的构造函数
ChildDemo::ChildDemo(int age, uint32_t phone) : Demo(age, phone) {
  cout << "ChildDemo construct running!" << endl;
}

uint32_t ChildDemo::getPhone() { return this->phone - 1; }

int main() {
  uint32_t phone = 0;
  int age = 0;

  cout << "Demo1" << endl;
  cout << "before new, Demo Id: " << Demo::getId() << endl;
  Demo demo1 = Demo(age, phone);
  cout << "after new, Demo Id: " << Demo::Id << endl;

  cout << "before set, age: " << demo1.getAge() << endl;
  cout << "before set, phone: " << demo1.getPhone() << endl;
  demo1.setAge(10);
  demo1.setPhone(110);
  cout << "after set, age: " << demo1.getAge() << endl;
  cout << "after set, phone: " << demo1.getPhone() << endl;
  cout << "Demo Id: " << Demo::Id << endl;

  // 友元类
  cout << "FriendDemo" << endl;
  FriendDemo friendDemo = FriendDemo(&demo1);

  //继承
  cout << "ChildDemo" << endl;
  cout << "before new, Demo Id: " << Demo::getId() << endl;
  ChildDemo childDemo = ChildDemo(age, phone);
  cout << "after new, Demo Id: " << Demo::Id << endl;

  cout << "before set, age: " << childDemo.getAge() << endl;
  cout << "before set, phone: " << childDemo.getPhone() << endl;
  childDemo.setAge(10);
  childDemo.setPhone(110);
  cout << "after set, age: " << childDemo.getAge() << endl;
  cout << "after set, phone: " << childDemo.getPhone() << endl;

  cout << "Demo2" << endl;
  Demo demo2 = childDemo;
  //会调用父函数的方法
  cout << "before set, age: " << demo2.getAge() << endl;
  cout << "before set, phone: " << demo2.getPhone() << endl;
  demo2.setAge(10);
  demo2.setPhone(110);
  cout << "after set, age: " << demo2.getAge() << endl;
  cout << "after set, phone: " << demo2.getPhone() << endl;

  return 0;
}
