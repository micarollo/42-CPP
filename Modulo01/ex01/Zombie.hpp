#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
  std::string _name;
  
public:
  Zombie(std::string name);
  Zombie(void);
  ~Zombie(void);
  void announce();
  void set_name(std::string name);
};

#endif