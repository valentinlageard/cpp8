#include <iostream>
#include "mutantstack.hpp"
#include "mutantstack.cpp" // bof bof mais on a pas vraiment le choix...

int main() {
	MutantStack<int> mstack;

	std::cout << "push(5)" << std::endl;
	mstack.push(5);
	std::cout << "push(17)" << std::endl;
	mstack.push(17);

	std::cout << "top: " << mstack.top() << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Iterate through the stack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "-------------------" << std::endl;

	std::cout << "Size after 1 pop: " << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	it = mstack.begin();
	ite = mstack.end();

	std::cout << "Iterate through the stack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "-------------------" << std::endl;

	std::stack<int> s(mstack); // Test the copy operator

	std::cout << "pop/top the parent copy: " << std::endl;
	while (s.size() >= 1)
	{
		std::cout << "s top: " << s.top() << std::endl;
		std::cout << "s.pop(): " << std::endl;
		s.pop();
	}
	std::cout << "-------------------" << std::endl;

	return 0;
}
