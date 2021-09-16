#include "span.hpp"

Span::Span() {}

Span::Span(unsigned int max_size):
	_max_size(max_size)
{}

Span::Span(Span const & original) {
	*this = original;
}

Span::~Span() {}

Span & Span::operator=(Span const & rhs) {
	if (this == &rhs) {
		return *this;
	}
	_max_size = rhs._max_size;
	_set = rhs._set;
	return *this;
}

void Span::addNumber(int n) {
	if (_set.size() < _max_size) {
		_set.insert(n);
	} else {
		throw std::runtime_error("span is full");
	}
}

int Span::shortestSpan() const {
	if (_set.size() <= 1) {
		throw std::runtime_error("span is not full enough");
	}
	std::multiset<int>::iterator it0 = _set.begin();
	std::multiset<int>::iterator it1 = _set.begin();
	int shortest_span = std::numeric_limits<int>::max();
	++it1;

	while (it1 != _set.end()) {
		if (*it1 - *it0 < shortest_span) {
			shortest_span = *it1 - *it0;
		}
		++it0;
		++it1;
	}

	return shortest_span;
}

int Span::longestSpan() const {
	if (_set.size() <= 1) {
		throw std::runtime_error("span is not full enough");
	}
	return (*(_set.rbegin()) - *(_set.begin()));
}
