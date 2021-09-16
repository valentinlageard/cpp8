#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include "span.hpp"

int main() {
	srand(time(NULL));

	{
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		Span sp = Span(100000);
		for (int i=0; i < 100000; ++i) {
			sp.addNumber(rand());
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		Span sp = Span(5);

		try {
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception const & e) {
			std::cout << "Error: " << e.what() << std::endl;
		}


		try {
			sp.addNumber(5);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception const & e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		try {
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(42);
		}
		catch (std::exception const & e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	{
		std::vector<int> v;
		Span sp = Span(5);

		for (int i=0; i < 5; ++i) {
			v.push_back(rand() % 100);
		}
		sp.addNumber(v.begin(), v.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::vector<int> v;
		Span sp = Span(5);

		for (int i=0; i < 10; ++i) {
			v.push_back(rand() % 100);
		}
		try {
			sp.addNumber(v.begin(), v.end());
		}
		catch (std::exception const & e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	return 0;
}
