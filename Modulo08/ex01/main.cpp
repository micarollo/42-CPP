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

    return 0;
}