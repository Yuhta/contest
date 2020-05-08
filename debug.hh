#pragma once

#include <ostream>
#include <tuple>

#define DEBUG(x) ::std::cerr << __FILE__ ":" << __LINE__ << ": " << x << ::std::endl

namespace debug {

template <typename Iterator>
struct Iterable {
  Iterator first, last;
};

template <size_t...>
struct IndexSequence {};

template <size_t N, size_t... Is>
struct MakeIndexSequence: MakeIndexSequence<N-1, N-1, Is...> {};

template <size_t... Is>
struct MakeIndexSequence<0, Is...>: IndexSequence<Is...> {};

template <typename Tuple, size_t... Is>
void PrintTuple(std::ostream& out, const Tuple& xs, IndexSequence<Is...>) {
  using Expand = int[];
  Expand{0, ((out << (Is == 0 ? "" : ",") << std::get<Is>(xs)), 0)...};
}

}

template <typename Iterator>
debug::Iterable<Iterator> Iterable(Iterator first, Iterator last) {
  return debug::Iterable<Iterator>{first, last};
}

template <typename Iterator>
std::ostream& operator<<(std::ostream& out, const debug::Iterable<Iterator>& xs) {
  out << '{';
  for (Iterator it = xs.first; it != xs.last; it++) {
    if (it != xs.first) out << ',';
    out << *it;
  }
  out << '}';
  return out;
}

template <typename... Types>
std::ostream& operator<<(std::ostream& out, const std::tuple<Types...>& xs) {
  out << '{';
  PrintTuple(out, xs, debug::MakeIndexSequence<sizeof...(Types)>{});
  return out << '}';
}
