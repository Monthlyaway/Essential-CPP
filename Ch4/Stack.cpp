#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Stack {
public:
	bool push(const string&);
	bool pop(string& elem);

	bool peek(string& elem);
	int count(void) const { return _stack.size(); }
	bool find(const string& elem) const {
		return std::find(_stack.begin(), _stack.end(), elem) != _stack.end();
	}
	bool find(const string&& elem) const {
		return std::find(_stack.begin(), _stack.end(), elem) != _stack.end();
	}

	bool empty(void);
	bool full(void);

	int size() const { return _stack.size(); }

private:
	vector<string> _stack;
};

bool Stack::push(const string& elem)
{
	if (full())
		return false;
	_stack.emplace_back(elem);
	return true;
}

bool Stack::pop(string& elem)
{
	if (empty())
		return false;
	elem = _stack.back();
	_stack.pop_back();
	return true;
}

bool Stack::peek(string& elem)
{
	if (empty())
		return false;
	elem = _stack.back();
	return true;
}

inline bool Stack::empty(void)
{
	return _stack.empty();
}

bool Stack::full(void)
{
	return _stack.size() == _stack.max_size();
}

void fill_stack(Stack& stack, istream& is = cin)
{
	string input;

	while (is >> input && !stack.full())
	{
		stack.push(input);
	}
	cout << "Read in " << stack.size() << " elements" << endl;
}


void ex4_1(void)
{
	Stack stack;

	stack.push("Spam");
	stack.push("and");
	stack.push("Egg");

	cout << "cout: " << stack.count() << endl;
	cout << "Is stack full? " << stack.full() << endl;
	cout << "Find Egg in stack? " << stack.find("Spam") << endl;

}
int main(void)
{
	//ex4_1();


	return 0;
}