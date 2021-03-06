#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack():
	std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & original):
	std::stack<T>(original)
{}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const & rhs) {
	if (this == &rhs) {
		return *this;
	}
	std::stack<T>::operator=(rhs);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}
