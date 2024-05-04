
#ifndef LAB8_FILTER_H
#define LAB8_FILTER_H

#include <utility>

template<typename Container, typename Predicate>
class Filter{
  Container&& c;
  Predicate&& p;
public:
  struct iterator{
    typename std::remove_reference_t<Container>::iterator current;
    typename std::remove_reference_t<Container>::iterator end;
    Predicate predicate;

    inline void get_next(){
      while(current != end && !predicate(*current)){
        current++;
      }
    }

    iterator(typename std::remove_reference_t<Container>::iterator begin,
             typename std::remove_reference_t<Container>::iterator end,
             Predicate p)
             : current(begin), end(end), predicate(p) {
      get_next();
    }

    decltype(auto) operator*() const{
      return *current;
    }

    decltype(auto) operator->() const{
      return current;
    }

    iterator& operator++(){
      current++;
      get_next();
      return *this;
    }

    iterator operator++(int){
      auto tmp = *this;
      this->operator++();
      return tmp;
    }

    bool operator==(const iterator& other) const {
      return current == other.current;
    }

    bool operator!=(const iterator& other) const {
      return !(*this == other);
    }

  };

  Filter(Container&& c, Predicate&& p)  : c(std::forward<Container>(c)), p(std::forward<Predicate>(p)){};

  iterator begin() const{
    return iterator(c.begin(),c.end(),p);
  }

  iterator end() const{
    return iterator(c.end(),c.end(),p);
  }
};

template<typename Container, typename Predicate>
Filter<Container,Predicate> make_filter(Container&& c, Predicate&& p){
  return Filter<Container,Predicate>(std::forward<Container>(c),std::forward<Predicate>(p));
}
#endif //LAB8_FILTER_H
