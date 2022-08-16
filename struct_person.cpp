#include <iostream>
#include <cstring>

using namespace std;

struct Person
{
    char name[20];
    uint8_t age;
};

int main()
{
    Person p1;
    Person p2;

    strcpy(p1.name, "p1");
    p1.age = 10;
    strcpy(p2.name, "p2");
    p2.age = 10;

    cout << "P1:" << p1.name << p1.age << endl;
    cout << "P2:" << p2.name << p2.age << endl;

    return 0;
}