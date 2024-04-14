
#ifndef EX06_VARIADICTEMPLATE_PROXY_H
#define EX06_VARIADICTEMPLATE_PROXY_H

#include <iostream>
#include <typeinfo>
#include <boost/type_index.hpp>
template <typename... Ts>
void showNames(Ts&&... args) {
    int i = 1;
    ((std::cout << i++ << " > " << boost::typeindex::type_id_with_cvr<Ts>().pretty_name() << " [" << typeid(Ts).name() << "] = " << args << std::endl), ...);
}

template<typename F>
class Proxy{
private:
    const F f;
public:
    explicit Proxy(F f) : f(f) {}

    template<class ... Ts>
    decltype(auto) operator()(Ts&& ... args) const{
        showNames(std::forward<Ts>(args)...);
        return f(std::forward<Ts>(args)...);
    }


};

template <typename F>
Proxy<F> make_proxy(F&& func) {
    return Proxy<F>(std::forward<F>(func));
}


#endif //EX06_VARIADICTEMPLATE_PROXY_H
