#ifndef easyfind_HPP
# define easyfind_HPP

# include <iterator>
# include <stdexcept>
# include <algorithm>

template <typename T>
int const & easyfind(T container, int n) {
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end()) {
		throw std::runtime_error("value wasn't found");
	}
	return *it;
}

#endif
