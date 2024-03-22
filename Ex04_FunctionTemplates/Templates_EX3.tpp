#include "Templates.h"

template<
        template<typename, typename> class OutContainer,
        typename T,
        typename Alloc,
        template<typename, typename> class InContainer,
        typename Predicate>
OutContainer<T,Alloc> selectIf(InContainer<T,Alloc> c, Predicate p){
    OutContainer<T, Alloc> new_c;
    std::copy_if (c.begin(), c.end(), std::back_inserter(new_c), p );
    return new_c;
}