#include <iostream>
#include "mutantstack.hpp"
#include "mutantstack.cpp" // bof bof mais on a pas vraiment le choix...

int main() {

	MutantStack<int> mstack;

	{
		// Test basic stack methods


		std::cout << "push(5)" << std::endl;
		mstack.push(5);
		std::cout << "push(17)" << std::endl;
		mstack.push(17);

		std::cout << "top: " << mstack.top() << std::endl;

		// Test iteration

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		std::cout << "Iterate through the stack: " << std::endl;
		while (it != ite) {
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
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "-------------------" << std::endl;

	}

	{
		// Test copy and assignation

		MutantStack<int> mstack_copied(mstack);
		MutantStack<int> mstack_assigned;

		mstack_assigned = mstack_copied;

		std::cout << "Copied: " << std::endl;
		for (MutantStack<int>::iterator it = mstack_copied.begin(); it != mstack_copied.end(); it++) {
			std::cout << *it << std::endl;
		}
		std::cout << "-------------------" << std::endl;

		std::cout << "Assigned: " << std::endl;
		for (MutantStack<int>::iterator it = mstack_assigned.begin(); it != mstack_assigned.end(); it++) {
			std::cout << *it << std::endl;
		}
		std::cout << "-------------------" << std::endl;

		return 0;
	}
}
