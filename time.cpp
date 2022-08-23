#include <ctime>
#include <iostream>
#include <sys/time.h>

int main(int argc, char const* argv[]) {
  ::timeval now_timeval;
  ::gettimeofday(&now_timeval, nullptr);
  const std::time_t now_seconds = now_timeval.tv_sec;
  struct std::tm now_components;
  ::localtime_r(&now_seconds, &now_components);

  std::cout << "seconds: " << now_timeval.tv_sec << std::endl;
  std::cout << "unix seconds: " << now_timeval.tv_usec << std::endl;

  std::cout << "hour:" << now_components.tm_hour << std::endl;
  std::cout << "minute:" << now_components.tm_min << std::endl;
  std::cout << "second:" << now_components.tm_sec << std::endl;
  return 0;
}
