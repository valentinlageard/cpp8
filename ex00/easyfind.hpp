#ifndef easyfind_HPP
# define easyfind_HPP

# include <iterator>
# include <stdexcept>

template <typename T>
int & easyfind(T container, int n) {
	typename T::iterator it;

	it = container.begin();
	while (it != container.end()) {
		if (*it == n) {
			return *it;
		}
		++it;
	}
	throw std::runtime_error("value wasn't found");
}

#endif
