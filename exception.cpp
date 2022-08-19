#include <iostream>

using namespace std;

int main() {
  try {
    throw "Test Exception";
  } catch (const char* msg) {
    cout << msg << endl;
  }

  return 0;
}