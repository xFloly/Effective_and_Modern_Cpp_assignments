

#ifndef LAB6_RANGE_H
#define LAB6_RANGE_H

template <typename T>
class Range{
  T start;
  T stop;
  T step;
public:

  struct Iterator{
    T current;
    const T* stop_ptr;
    const T* step_ptr;

    Iterator(T start,const T* stop,const T* step) : current(start), stop_ptr(stop),step_ptr(step){}

    constexpr T operator*() const{
      return current;
    }

    constexpr T operator->() const{
      return current;
    }

    constexpr Iterator operator++() {
      current += *step_ptr;
      return *this;
    }

    constexpr Iterator operator++(int) {
      auto tmp = Iterator(current, stop_ptr, step_ptr);
      ++(*this);
      return tmp;
    }

    constexpr bool operator == (const Iterator& other) const {
      return current == other.current || (*stop_ptr == *(other.stop_ptr) && current >= *stop_ptr && other.current >= *(other.stop_ptr));
    }

    constexpr bool operator != (const Iterator& other) const {
      return !(*this == other);
    }
  };

  explicit Range(T stop) : start(0), stop(stop), step(1){};
  explicit Range(T start,T stop,T step=1) : start(start), stop(stop), step(step){};

  Range<T>::Iterator begin() const{
    return Iterator(start,&stop,&step);
  }

  Range<T>::Iterator end() const{
    return Iterator(stop,&stop,&step);
  }

};

template <typename T>
Range<T> make_range(T stop){
  return Range<T>(stop);
}


template <typename T>
Range<T> make_range(T start,T stop,T step=1){
  return Range<T>(start,stop,step);
}

#endif //LAB6_RANGE_H
