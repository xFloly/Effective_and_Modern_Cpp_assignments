#ifndef EX10_SFINAE_EX3_TIMER_H
#define EX10_SFINAE_EX3_TIMER_H
#pragma once
#include <iostream>
#include <chrono>
#include <string>

using namespace std::chrono;

class Timer{
  std::string name;
  std::chrono::steady_clock::time_point start_time;
public:

  Timer(const std::string & name) : name(name), start_time(std::chrono::steady_clock::now()){
  }


  ~Timer();

  auto durationInNanoseconds()->long long;

};


#endif //EX10_SFINAE_EX3_TIMER_H
