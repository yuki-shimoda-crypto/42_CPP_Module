#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <class T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:
  typedef typename Container::iterator iterator;

  iterator begin() { return this->c.begin(); }

  iterator end() { return this->c.end(); }

private:
};

#endif
