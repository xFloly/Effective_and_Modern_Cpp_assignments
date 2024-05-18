
#ifndef EX10_SFINAE_EX2_H
#define EX10_SFINAE_EX2_H
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <type_traits>

template<class T>
struct is_random_access_iterator
: std::integral_constant<
    bool,
    std::is_same_v<typename std::iterator_traits<typename T::iterator>::iterator_category,
            std::random_access_iterator_tag>
    > {};

template <typename Container>
double median_impl(Container container, std::false_type) {
  container.sort();
  size_t size = container.size();
  auto length = std::distance(container.begin(), container.end());

  if (size % 2 == 0) {
    auto middlePosition = length / 2 - 1;
    auto it = container.begin();
    std::advance(it, middlePosition);
    auto result1 = *it;
    std::advance(it, 1);
    auto result2 = *it;
    return (static_cast<double>(result1) + static_cast<double>(result2)) / 2.0;
  } else {
    auto middlePosition = length / 2;
    auto it = container.begin();
    std::advance(it, middlePosition);
    return static_cast<double>(*it);
  }
}

template <typename Container>
double median_impl(Container container, std::true_type){
  std::sort(container.begin(), container.end());
  size_t size = container.size();
  if (size % 2 == 0) {
    return static_cast<double>(container[size / 2 - 1] + container[size / 2]) / 2.0;
  } else {
    return container[size / 2];
  }
}

template <typename T>
inline constexpr bool is_random_access_iterator_v = is_random_access_iterator<T>::value;


template <typename Container>
double median(Container& container) {
  if (!container.empty()) {
    return median_impl(container, is_random_access_iterator<Container>{});
  }
  return 0;
}
#endif //EX10_SFINAE_EX2_H
