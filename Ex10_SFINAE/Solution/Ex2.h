
#ifndef EX10_SFINAE_EX2_H
#define EX10_SFINAE_EX2_H
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <type_traits>

//median of a random access container
template <typename Container>
typename std::enable_if<std::is_arithmetic_v<typename Container::value_type> &&
                        std::is_same_v<typename std::iterator_traits<typename Container::iterator>::iterator_category,
                            std::random_access_iterator_tag>, double>::type
median(Container& container) {
  if (!container.empty()){
    std::sort(container.begin(), container.end());

    size_t size = container.size();
    if (size % 2 == 0) {
      return static_cast<double>(container[size / 2 - 1] + container[size / 2]) / 2.0;
    } else {
      return container[size / 2];
    }
  }
  return 0;
}

//default
template <typename Container>
typename std::enable_if<std::is_arithmetic_v<typename Container::value_type> &&
                        !std::is_same_v<typename std::iterator_traits<typename Container::iterator>::iterator_category,
                            std::random_access_iterator_tag>, double>::type
median(Container& container) {
  using value_type = typename Container::value_type;
  {
  std::vector<value_type> temp(container.begin(), container.end());

  if (!temp.empty()){
    std::sort(temp.begin(), temp.end());

    size_t size = temp.size();
    if (size % 2 == 0) {
      return static_cast<double>(temp[size / 2 - 1] + temp[size / 2]) / 2.0;
    } else {
      return temp[size / 2];
    }
  }
  }
  return 0;
}
#endif //EX10_SFINAE_EX2_H
