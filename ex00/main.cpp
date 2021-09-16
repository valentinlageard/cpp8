#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {

	std::vector<int> vect;
	for (int count=0; count < 6; ++count){
		vect.push_back(count);
	}

	try {
		std::cout << easyfind(vect, 4) << std::endl;
		std::cout << easyfind(vect, 9) << std::endl;
	}
	catch (std::exception const & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::list<int> list;
	for (int count=0; count < 6; ++count){
		list.push_back(count);
	}

	try {
		std::cout << easyfind(list, 4) << std::endl;
		std::cout << easyfind(list, 9) << std::endl;
	}
	catch (std::exception const & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
