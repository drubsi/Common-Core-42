#ifndef	MUTANTSTACK_HPP
#define	MUTANTSTACK_HPP
#include <stack>
#include <deque>

template <typename T, class container=std::deque<T> >
class MutantStack : public std::stack<T, container>
{
    public:
        typedef typename container::iterator iterator;
        MutantStack(){}
        MutantStack(const MutantStack<T, container>& copy) : std::stack<T, container>(copy)
        {
        }
        MutantStack& operator=(const MutantStack<T, container>& other)
        {
                if(this != &other)
                    std::stack<T, container>::operator=(other);
                return (*this);
        }
        ~MutantStack(){}
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};
#endif