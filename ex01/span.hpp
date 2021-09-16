#ifndef Span_HPP
# define Span_HPP

# include <iostream>
# include <set>
# include <limits>

class Span {

public:
	Span(unsigned int max_size);
	Span(Span const & original);
	virtual ~Span();
	Span & operator=(Span const & rhs);

	void addNumber(int n);
	template <typename T>
	void addNumber(T begin, T end);


	int shortestSpan() const;
	int longestSpan() const;

private:
	Span();
	unsigned int _max_size;
	std::multiset<int> _set;
};

template <typename T>
void Span::addNumber(T begin, T end) {
	if (std::distance(begin, end) + _set.size() > _max_size) {
		throw std::runtime_error("span would be full");
	}
	while (begin != end) {
		_set.insert(*begin);
		++begin;
	}
}


#endif
