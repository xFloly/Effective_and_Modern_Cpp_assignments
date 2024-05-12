#include "Ex3_Timer.h"

Timer::~Timer(){
  std::cout << name << " : " << durationInNanoseconds() << " ms. " << std::endl;
}

auto Timer::durationInNanoseconds() -> double{
  auto now = std::chrono::steady_clock::now();
  auto time_span  = std::chrono::duration_cast<std::chrono::duration<double>>(now-start_time);
  return time_span.count();
}