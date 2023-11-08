#include "MutantStack.hpp"

int	main( void )
{
	MutantStack<int>	mStack;
	MutantStack<int>	mStack1;

	std::cout << std::endl << "1. Should print < 2 >" << std::endl;
		mStack.push(1);
		mStack.push(2);
		std::cout << "< " << mStack.top() << " >" << std::endl;

	std::cout << std::endl <<"---------------------------------------------------" << std::endl;
		
	std::cout << "2. Should print < 1 >" << std::endl;
		
		mStack.pop();

		std::cout << "< " << mStack.size() << " >" << std::endl;

	std::cout << std::endl <<"---------------------------------------------------" << std::endl;

	std::cout << "3. Should print < 1 3 4 5 6 >" << std::endl;
		mStack.push(3);
		mStack.push(4);
		mStack.push(5);
		mStack.push(6);

		MutantStack<int>::iterator it = mStack.begin();
		MutantStack<int>::iterator ite = mStack.end();

		++it;
		--it;
		std::cout << "< ";
		while(it != ite)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << ">" << std::endl;
	std::cout << std::endl <<"---------------------------------------------------" << std::endl;

	std::cout << "4. Should print < 4 2 >" << std::endl;
		mStack1.push(4);
		mStack1.push(2);

		mStack = mStack1;

		it = mStack.begin();
		ite = mStack.end();

		std::cout << "< ";
		while(it != ite)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << ">" << std::endl;

	std::cout << std::endl << "---------------------------------------------------" << std::endl;
	
	std::stack<int> s(mStack);

	std::cout << "5. Should print < 4 2 >" << std::endl;

		MutantStack<int>	mStack2(mStack1);
		it = mStack2.begin();
		ite = mStack2.end();

		std::cout << "< ";
		while(it != ite)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << ">" << std::endl;

	std::cout << std::endl << "---------------------------------------------------" << std::endl;
	
	return (0);
}