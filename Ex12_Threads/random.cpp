#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cctype>
#include <ctime>
#include <thread>
#include <utility>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

struct RandomGenerator{
  std::mutex rand_mutex;

  int generate() {
    std::lock_guard<std::mutex> lock(rand_mutex);
    return rand();
  }
};


template <int N>
struct Array{
  int a[N];
  int i  = 0;
  int value = 1;
  RandomGenerator rand_gen;
  static inline std::mutex m1;
  static inline std::mutex m1_2;
  static inline std::mutex m2;
  static inline std::mutex m3;
  static inline std::condition_variable cv;
  static inline int threads_ready = 0;
  static inline std::mutex cv_mutex;

  long long sum = 0;

	int f(int x){
		int y = x%11;
		return (y*y+1);
	}

	void generateArray(){
    while (true) {
      int idx;
      {
        lock_guard<mutex> lock(m1);
        if (i >= N) {
          break;
        }
        idx = i++;
      }
      a[idx] = rand_gen.generate();
    }

    while (true) {
      int idx;
      {
        lock_guard<mutex> lock(m2);
        if (i >= N * 2) break;
        idx = i++ - N;
      }
      a[idx] = f(a[idx]);
    }
  }
	
	long long computeSum(){
    sum = 0;
		for(int x : a){
      m3.lock();
      sum += x;
      m3.unlock();
    }
		return sum;
	}
};

int main(){
	srand(2019);
	using A = Array<40>;
	A array;
  array.generateArray();
	std::thread t1(&A::generateArray, &array);
//  What happens if you uncomment this line?
  std::thread t2(&A::generateArray, &array);
  std::thread t3(&A::generateArray, &array);
  std::thread t4(&A::generateArray, &array);
	t2.join();
  t1.join();
  t3.join();
  t4.join();
  for(int i=0; i<40; i++){
    cout << array.a[0+i] << "  ";
	}
	long long sum = array.computeSum();
	cout << "\n sum := " << sum << endl;

  cout<<"\n correct:"<<"\n 82  2  10  2  1  82  5  50  82  50  82  26  82  2  82  5  2  101  82  37  1  50  1  82  10  2  1  101  1  65  82  10  5  17  82  50  10  10  26  1";
  cout << "\n sum  := 1474" << endl;
}
