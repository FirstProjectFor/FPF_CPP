#include "person.cpp"

using namespace std;

int main(int argc, char const* argv[]) {
  Person p = Person(10);
  cout << p.getAge() << endl;
  return 0;
}