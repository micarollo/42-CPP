#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base *generate(void)
{
    srand(time(NULL));
    switch (std::rand() % 3)
    {
    case 0:
        return new A;

    case 1:
        return new B;

    default:
        return new C;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::exception &e) {}
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    }
    catch (const std::exception &e) {}
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
    catch (const std::exception &e) {}
}

int main(void)
{
    Base *p = generate();
    identify(p);
    identify(*p);
    delete p;
    return 0;
}