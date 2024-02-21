#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPN
{
public:
    RPN();
    ~RPN();
    void evaluate(std::string s);
    class Error : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Error";
		}
	};

private:
    std::stack<int> _stack;
};