#include <iostream>
#include <sys/time.h>

//定义 hello 函数
void hello();

class GLobalNamespace {
 public:
  void hello() { std::cout << "Hello In CLass GlobalNamespace" << std::endl; };
  void invokeHello() {
    //调用当前类的hello方法
    hello();
  };
  void invokeGlobalHello() {
    //调用全局的hello方法
    ::hello();
  };
};

int main(int argc, char const* argv[]) {
  // std::表示std作用域
  std::cout << "global namespace example" << std::endl;
  GLobalNamespace gn = GLobalNamespace();
  gn.invokeHello();
  gn.invokeGlobalHello();
  return 0;
}

void hello() { std::cout << "Hello In Global" << std::endl; }
