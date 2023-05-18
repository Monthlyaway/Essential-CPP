#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

template <typename elemType>
class LessThan {
public:
	LessThan(const elemType& val) : _val(val) {}
	LessThan(const elemType&& val) : _val(val) {}
	bool operator() (const elemType& val) const {
		return val < _val;
	}
	bool operator() (const elemType&& val) const {
		return val < _val;
	}
	void val(const elemType& nval) {
		_val = nval;
	}
	void val(const elemType&& nval) {
		_val = nval;
	}
	elemType val() const {
		return _val;
	}

private:
	elemType _val;
};

template <typename elemType, typename Comp = std::less<elemType> >
class LessThanPred {
public:
	LessThanPred(const elemType& val) : _val(val) {}
	LessThanPred(const elemType&& val) : _val(val) {}
	bool operator()(const elemType& val) const
	{
		return Comp()(val, _val);
		// Comp is a function type
		//return val < _val;
	}
	bool operator()(const elemType&& val) const
	{
		return Comp()(val, _val);
		//return val < _val;
	}
	void val(const elemType& newval) { _val = newval; }
	void val(const elemType&& newval) { _val = newval; }
	elemType val() const { return _val; }
private:
	elemType _val;
};

class StringLen {
public:
	bool operator()(const string& lhs, const string& rhs) {
		return lhs.length() < rhs.length();
	}
	bool operator()(const string& lhs, const string&& rhs) {
		return lhs.length() < rhs.length();
	}
	bool operator()(const string&& lhs, const string& rhs) {
		return lhs.length() < rhs.length();
	}
	bool operator()(const string&& lhs, const string&& rhs) {
		return lhs.length() < rhs.length();
	}
};

template <typename elemType, typename BinaryComp>
class Compare {
public:
	Compare(const elemType& val) : _val(val) {}
	Compare(const elemType&& val) : _val(val) {}
	bool operator()(const elemType& val) const
	{
		return BinaryComp()(val, _val);
		// Comp is a function type
		//return val < _val;
	}
	bool operator()(const elemType&& val) const
	{
		return BinaryComp()(val, _val);
		//return val < _val;
	}

	void val(const elemType& newval) { _val = newval; }
	void val(const elemType&& newval) { _val = newval; }

	elemType val() const { return _val; }
private:
	elemType _val;
};
void prog1()
{
	LessThan<int> lti(1024);
	LessThan<string> lts("Hello");
	cout << "500 is less than 1024: " << lti(500) << endl;
	cout << "Zpple is less than Hello: " << lts("Zpple") << endl;
}

void prog2()
{
	LessThanPred<int> lti(1024);
	int val(500);
	cout << "500 is less than 1024: " << lti(500) << endl;

	LessThanPred<string, StringLen> lts("Pooh");
	cout << "Eriksen size is less than 1024: " << lts("Eriksen") << endl;
}

void prog3()
{
	Compare<int, std::greater<int> > gti(1024);
	cout << "500 is greater than 1024: " << gti(500) << endl;
}

int main(void)
{
	//prog1();
	//prog2();
	prog3();
	return 0;
}