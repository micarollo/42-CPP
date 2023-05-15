#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
  private:
    std::string name;
  
  public:
    Zombie(std::string name);
    void announce() const;
    ~Zombie();
};

#endif