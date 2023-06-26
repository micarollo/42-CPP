#include <string>
#include <iostream>

class Zombie {
private:
  std::string name;
  
public:
  Zombie(std::string name);
  ~Zombie(void);
  const std::string& get_name();
  void announce();
  Zombie* newZombie( std::string name );
};