#ifndef MutantStack_HPP
# define MutantStack_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T> {

public:
	MutantStack();
	MutantStack(MutantStack const & original);
	virtual ~MutantStack();
	MutantStack & operator=(MutantStack const & rhs);
	
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
};

#endif
