#include "export.h"

class TEST_EXPORT Person {
 public:
  int age;
  int getAge();
  Person(int age);
  ~Person();
};
