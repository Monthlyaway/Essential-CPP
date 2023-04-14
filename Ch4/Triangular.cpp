#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Triangular {
public:
	// overloaded sets of constructors
	Triangular() : _name("Triangular"), _length(1), _beg_pos(1), _next(0) {}  // default constructor

	Triangular(int len) : _name("Triangular"), _beg_pos(1), _next(0)
	{
		_length = len > 0 ? len : 1;
	}
	/*Triangular t3 = 8;  causes the one-argument integer constructor to be applied.*/

	Triangular(int len, int beg_pos) : _name("Triangular")
	{
		_length = len > 0 ? len : 1;
		_beg_pos = beg_pos > 0 ? beg_pos : 1;
		_next = beg_pos - 1;
	}
	/*
	Triangular tri(8, 3);
	tri contains an instance of _length (initialized to 8), _beg_pos (initialized to 3), and _next (initialized to 2 because the third element is indexed within the vector at position 2).
	*/

	// const member functions
	int length() const { return _length; }
	int beg_pos() const { return _beg_pos; }
	int elem(int pos) const { return _elems[pos - 1]; }

	// non-const member functions
	bool next(int& val);
	void reset_next(void) { _next = _beg_pos - 1; }
private:
	string _name;
	int _length;
	int _beg_pos;
	int _next;  // the next position to iterate

	static vector<int> _elems;
};
int main(void)
{

	// define a vector

	return 0;
}