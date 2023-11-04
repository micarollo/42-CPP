#include "Span.hpp"

int main() {
    Span span(5);
    span.addNumber(5);
    span.addNumber(2);
    span.addNumber(9);
    span.addNumber(1);
    span.addNumber(7);

    try {
        int minSpan = span.shortestSpan();
        int maxSpan = span.longestSpan();

        std::cout << "Shortest Span: " << minSpan << std::endl;
        std::cout << "Longest Span: " << maxSpan << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl << "11. Add new vector to Span" << std::endl;
    Span	sp1 = Span(10);
		try	
		{
			std::vector<int> vec;
            sp1.addNumber(5);
			sp1.addNumber(5);
			vec.push_back(1);
			vec.push_back(2);
			vec.push_back(3);
			std::vector<int>::iterator it1 = vec.begin();
			std::vector<int>::iterator it2 = vec.end();

			sp1.addNumber(it1, it2);
			std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
			std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

    return 0;
}