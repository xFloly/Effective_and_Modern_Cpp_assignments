#include "Ex3_Timer.h"


Timer::~Timer(){
  {
    std::cout << name << " : " << duration_cast<microseconds>(steady_clock::now() - start_time).count() << " ms. " << std::endl;
  }
}

auto Timer::durationInNanoseconds()->long long {
  auto now = std::chrono::steady_clock::now();
  return std::chrono::duration_cast<std::chrono::nanoseconds>(now-start_time).count();
}