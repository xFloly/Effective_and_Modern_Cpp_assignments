export module VectorModule;

#include "vector_policies.h"
#include "vector_traits.h"
#include "Vector.h"

export namespace emcpp {
  // Re-export the policies from vector_policies.h
  export using NoCheckingPolicy = ::emcpp::NoCheckingPolicy;
  export using ExceptionCheckingPolicy = ::emcpp::ExceptionCheckingPolicy;
  export using NoInit = ::emcpp::NoInit;
  export using ZeroInit = ::emcpp::ZeroInit;

  // Define additional policies as needed

  // Define the IntervalPolicy class
  template<typename T, typename CheckingPolicy, template<typename> class InitPolicy>
  class IntervalPolicy : public CheckingPolicy, public InitPolicy<T> {
  public:
    using InitPolicy<T>::init;
    using CheckingPolicy::check;
  };

  // Alias the predefined policies
  template<typename T>
  using SafePolicy = IntervalPolicy<T, ExceptionCheckingPolicy, ZeroInit>;
  template<typename T>
  using FastPolicy = IntervalPolicy<T, NoCheckingPolicy, NoInit>;
  template<typename T>
  using InitFastPolicy = IntervalPolicy<T, NoCheckingPolicy, ZeroInit>;

  // Export the Vector class
  export template <typename T, std::size_t N, template<typename> class IntervalPolicy = SafePolicy>
  class Vector;
}

// Disable instantiation of Vector for int, double, and std::string with SafePolicy
extern template class emcpp::Vector<int, 10, emcpp::SafePolicy>;
extern template class emcpp::Vector<double, 10, emcpp::SafePolicy>;
extern template class emcpp::Vector<std::string, 10, emcpp::SafePolicy>;
