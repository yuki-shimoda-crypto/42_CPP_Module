#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
public:
  Brain();
  Brain(const Brain &brain);
  Brain &operator=(const Brain &brain);
  ~Brain();
  std::string getIdea(int i) const;

private:
  std::string _ideas[100];
};

#endif
