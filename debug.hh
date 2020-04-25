#pragma once

#include <ostream>

#define DEBUG(x) ::std::cerr << __FILE__ ":" << __LINE__ << ": " << x << ::std::endl

template <typename Iterator>
struct Iterable {
  Iterable(Iterator first, Iterator last): first_(first), last_(last) {
  }
private:
  Iterator first_, last_;
  template <typename Iterator2>
  friend std::ostream& operator<<(std::ostream&, const Iterable<Iterator2>&);
};

template <typename Iterator>
Iterable<Iterator> MakeIterable(Iterator first, Iterator last) {
  return Iterable<Iterator>(first, last);
}

template <typename Iterator>
std::ostream& operator<<(std::ostream& out, const Iterable<Iterator>& xs) {
  out << '{';
  for (Iterator it = xs.first_; it != xs.last_; it++) {
    if (it != xs.first_) out << ',';
    out << *it;
  }
  out << '}';
  return out;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& xs) {
  return out << '{' << xs.first << ',' << xs.second << '}';
}
