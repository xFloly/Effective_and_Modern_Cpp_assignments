
#ifndef EX11_CONCEPTS_FILESYSTEM_REGEX_LITERALS_H
#define EX11_CONCEPTS_FILESYSTEM_REGEX_LITERALS_H

long double constexpr operator ""_m(long double value) {
  return value;
}
long double constexpr operator ""_m(unsigned long long value) {
  return (long double)value;
}

long double constexpr operator ""_cm(long double value) {
  return value / 100;
}

long double constexpr operator ""_cm(unsigned long long value) {
  return (long double)value / 100.0;
}

long double constexpr operator ""_km(long double value) {
  return value * 1000;
}
long double constexpr operator ""_km(unsigned long long value) {
  return (long double)value * 1000;
}

long double constexpr operator ""_s(long double value) {
  return value;
}
long double constexpr operator ""_s(unsigned long long value) {
  return (long double)value;
}

long double constexpr operator ""_ms(long double value) {
  return value / 1000;
}

long double constexpr operator ""_ms(unsigned long long value) {
  return (long double)value / 1000;
}
long double constexpr operator ""_h(long double value) {
  return value * 3600;
}
long double constexpr operator ""_h(unsigned long long value) {
    return (long double)value * 3600;
}

#endif //EX11_CONCEPTS_FILESYSTEM_REGEX_LITERALS_H
