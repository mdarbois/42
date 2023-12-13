#include "MutantStack.hpp"

int main()
{
    {
        std::cout << "STACK" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "TOP: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "SIZE: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
   std::list<int> s(mlist);
    }
    {
        std::cout << "Reverse" << std::endl;
        MutantStack<char> reverse;
        for (int i = 0; i < 26; i++)
		    reverse.push('a' + i);
        std::cout << "SIZE: " << reverse.size() << std::endl;
        std::cout << "TOP: " << reverse.top() << std::endl;
        MutantStack<char>::reverse_iterator itr = reverse.rbegin();
        MutantStack<char>::reverse_iterator itre = reverse.rend();
        while (itr != itre)
        {
        std::cout << *itr << std::endl;
        ++itr;
        }
        reverse.pop();
        MutantStack<char>::iterator it = reverse.begin();
        MutantStack<char>::iterator ite = reverse.end();
        std::cout << "SIZE: " << reverse.size() << std::endl;
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
    }
    return (0);
}
