/**************************************************
 * Essential C++ -- Stanley Lippman
 * Addison-Wesley
 * ISBN 0-201-48518-4
 * homepage: www.objectwrite.com
 * email: slippman@objectwrite.com
 *************************************************/
/*
* Implement a two-level stack hierarchy. The base class is a pure abstract Stack class that minimally supports the following interface: pop(), push(), size(), empty(), full(), peek(), and print(). The two concrete derived classes are LIFO_Stack and Peekback_Stack. The Peekback_Stack allows the user to retrieve the value of any element in the stack without modifying the stack itself. 
*/
#include <string>
#include <iostream>
#include <vector>

using namespace std;

typedef string elemType;

class Stack {
    // base class Stack just provide an interface
public:
    virtual ~Stack() {};  // always provide a virtual destructor in base class
    virtual bool pop(elemType& elem) = 0;
    virtual bool push(const elemType& elem) = 0;
    virtual bool peek(int index, elemType& elem) = 0;
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual void print(ostream& os) const = 0;
};

ostream& operator<<(ostream& os, const Stack& rhs)
{
    rhs.print(os);
    return os;
}

class Peekback_Stack : public Stack {
public:
    Peekback_Stack(int size = 0) : _top(0) {
        _stack.reserve(size);
    }
    bool pop(elemType& elem) {
        if (empty())
        {
            cerr << "LIFO_Stack is empty, can not pop. Return false" << endl;
            return false;
        }
        elem = _stack[--_top];
        _stack.pop_back();
        return true;
    }
    bool push(const elemType& elem) {
        if (full())
            return false;
        _stack.push_back(elem);
        _top++;
    }
    size_t size() const {
        return _stack.size();
    }
    bool empty() const {
        return _stack.size() == 0;
    }
    bool full() const {
        return _stack.size() == _stack.max_size();
    }
    void print(ostream& os) const {
        vector<elemType>::const_reverse_iterator
            rit = _stack.rbegin(),
            rend = _stack.rend();
        os << "\n\tPeekback_Stack"
            << "\n\t------------------\n\t";
        while (rit != rend)
            os << *(rit++) << "\n\t";
        os << endl;
    }
    bool peek(int index, elemType& elem);

private:
    vector<elemType> _stack;
    int _top;
};

bool Peekback_Stack::
peek(int index, elemType& elem) {
    if (empty())
        return false;
    if (index >= _top || index < 0)
        return false;
    elem = _stack[index];
    return true;
}

void peek(Stack& st, int index)
{
    string tp;
    if (st.peek(index, tp))
        cout << "peek: \"" << tp << "\" at " << index << endl;
    else
        cout << "peek failed!" << endl;
}

void ex5_1()
{
    Stack* st;
    st = new Peekback_Stack();
    string str;

    cout << "Please enter a series of strings." << endl;
    while (cin >> str) {
        st->push(str);
    }
    cout << *st;
}

int main()
{
    ex5_1();
}