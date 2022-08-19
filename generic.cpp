#include <iostream>

using namespace std;

//泛型函数 inline 表示内联函数 编译时调用处会用代码代替
// const & 表示不能再函数内修改参数的值
template <typename T>
inline T const& Max(T const& a, T const& b) {
  // a is  read only
  // a = 10;
  return a >= b ? a : b;
}

/// 泛型类
template <class T>
class A {
 private:
  T data;

 public:
  T getData();
  A(T data) { this->data = data; }
};

template <class T>
T A<T>::getData() {
  return data;
}

int main(int argc, char const* argv[]) {
  // function generic
  int a = 1;
  int b = 2;
  cout << "Max<a,b>" << Max(a, b) << endl;

  // class generic
  int dataInt = 10;
  A<int> aInt = A<int>(dataInt);
  cout << "A<int>: " << aInt.getData() << endl;

  string dataString = "1";
  A<string> aString = A<string>(dataString);
  cout << "A<string>: " << aString.getData() << endl;

  return 0;
}
