module;

#include <iostream>

export module policies;

export namespace emcpp {
  template<typename T, typename CheckingPolicy, template<typename> class InitPolicy>
  class IntervalPolicy : public CheckingPolicy, public InitPolicy<T> {
  public:

    using InitPolicy<T>::init;
    using CheckingPolicy::check;
  };


  struct NoCheckingPolicy {
    static void check(std::size_t index, std::size_t size) {}
  };


  struct ExceptionCheckingPolicy {
    static int errorCode;

    static void check(std::size_t index, std::size_t size) {
      if (index > size)
        throw std::runtime_error("Not correct interval bounds");
    }
  };

  template<typename T>
  struct NoInit {

    static void init(T &t) {}
  };


  template<typename T>
  struct ZeroInit {

    static void init(T &t) {
      t = T{};
    }
  };

  template<typename T>
  using SafePolicy = IntervalPolicy<T, ExceptionCheckingPolicy, ZeroInit>;

  template<typename T>
  using FastPolicy = IntervalPolicy<T, NoCheckingPolicy, NoInit>;

  template<typename T>
  using InitFastPolicy = IntervalPolicy<T, NoCheckingPolicy, ZeroInit>;
}
