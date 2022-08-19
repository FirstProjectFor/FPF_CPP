#include "person.h"

#include <iostream>

using namespace std;

Person::Person(int age) { this->age = age; }

int Person::getAge() { return this->age; }

Person::~Person() { cout << "~Person()" << endl; }