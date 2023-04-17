#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// xml documentation for the class
/// <summary>
/// Triangular class
/// </summary>
/// <remarks>
/// This class is used to generate Triangular numbers
/// </remarks>
/// <example>
/// <code>
/// Triangular tri(5, 3);
/// cout << tri << endl;
/// </code>
/// </example>
/// <seealso cref="Triangular"/>


class Triangular {
public:
	// xml documentation for the constructor
	/// <summary>
	/// Default constructor
	///	</summary>
	/// <remarks>
	/// This constructor is used to create a Triangular object with default values
	/// </remarks>
	/// <example>
	/// <code>
	/// Triangular tri;
	/// cout << tri << endl;
	/// </code>
	/// </example>
	/// <seealso cref="Triangular"/>
	
	Triangular() : _name("Triangular"), _length(_initial_length), _beg_pos(1), _next(0) {}

	// xml documentation for the copy constructor
	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <remarks>
	/// This constructor is used to create a Triangular object from another Triangular object
	/// </remarks>
	/// <example>
	/// <code>
	///	Triangular tri1(5, 3);
	/// cout << tri1 << endl;
	/// </code>
	/// </example>
	/// <seealso cref="Triangular"/>
	
	Triangular(const Triangular& rhs) : _name(rhs._name), _length(rhs._length), _beg_pos(rhs._beg_pos), _next(rhs._beg_pos - 1) {}

	// xml documentation for the constructor
	/// <summary>
	/// Constructor
	/// </summary>
	/// <remarks>
	///	This constructor is used to create a Triangular object with a specified length
	/// </remarks>
	/// <example>
	/// <code>
	/// Triangular tri(5);
	/// cout << tri << endl;
	/// </code>
	/// </example>
	/// <seealso cref="Triangular"/>
	Triangular(int len) : _name("Triangular"), _beg_pos(1), _next(0)
	{
		_length = len > 0 ? len : 1;
	}
	
	// xml documentation for the constructor
	/// <summary>
	/// Constructor
	/// </summary>
	/// <remarks>
	/// This constructor is used to create a Triangular object with a specified length and beginning position
	/// </remarks>
	/// <example>
	/// <code>
	/// Triangular tri(5, 3);
	/// cout << tri << endl;
	/// </code>
	/// </example>
	/// <seealso cref="Triangular"/>
	Triangular(int len, int beg_pos) : _name("Triangular"), _length(len > 0 ? len : 1), _beg_pos(beg_pos > 0 ? beg_pos : 1)
	{
		_next = beg_pos - 1;
		int elem_cnt = _beg_pos + _length - 1;

		if (_elems.size() < elem_cnt)
			gen_elems_to_len(elem_cnt);
	}
	
	// xml documentation for the friend function
	/// <summary>
	/// Friend function
	/// </summary>
	/// <remarks>
	/// This function is used to output the Triangular object
	/// </remarks>
	/// <example>
	/// <code>
	/// Triangular tri(5, 3);
	/// cout << tri << endl;
	///	</code>
	/// </example>
	/// <seealso cref="Triangular"/>
	friend ostream& operator<<(ostream& os, const Triangular& tri)
	{
		int elem;
		tri.reset_next();
		os << "(" << tri._beg_pos << ", " << tri._length << ") ";
		while (tri.next(elem))
			os << elem << ' ';
		return os;
	}

	// const member functions
	int length() const { return _length; }
	int beg_pos() const { return _beg_pos; }
	int elem(int pos) const { return _elems[pos - 1]; }

	// non-const member functions
	bool next(int& val) const
	{
		if (_next >= _beg_pos + _length - 1)
		{
			_next = _beg_pos - 1;
			return false;
		}
		val = _elems[_next++];
		return true;
	}
	void reset_next(void) const { _next = _beg_pos - 1; }
	static void gen_elems_to_len(int len);
	static void gen_elems_to_val(int val);
	static bool is_elem(int val)
	{
		if (!_elems.size() || _elems.back() < val)
			gen_elems_to_val(val);
		auto found_it = find(_elems.begin(), _elems.end(), val);
		return found_it != _elems.end();
	}
	static void display(int len, int beg_pos, ostream& os = cout);

	
	Triangular& copy(const Triangular& rhs)
	{
		_length = rhs._length;
		_beg_pos = rhs._beg_pos;
		_name = rhs._name;
		_next = rhs._beg_pos - 1;

		return *this;
	}

private:
	string _name;
	int _length;
	int _beg_pos;
	mutable int _next;  // the next position to iterate

	const static int _initial_length = 8;
	const static int _max_elem = 1024;
	static vector<int> _elems;
};
vector<int> Triangular::_elems;  // provide storage for the static data member

void Triangular::gen_elems_to_len(int len)
{
	if (len < 0)
	{
		cerr << "Error: Can not generate Triangular Sequence to a negative length" << endl;
		return;
	}

	while (_elems.size() < len)
	{
		int ix = !_elems.size() ? 1 : _elems.size();
		_elems.push_back((ix + 1) * (ix + 2) / 2);
	}

	cout << "Generating Triangular Sequence to length: " << len
		<< "\n _elems.back() = " << _elems.back() << endl;

}

// xml documentation for the gen_elems_to_val function
/// <summary>
/// Static member function
/// </summary>
/// <remarks>
/// This function is used to generate the Triangular Sequence to a specified value
/// </remarks>
/// <example>
/// <code>
///	Triangular::gen_elems_to_val(100);
/// </code>
/// </example>
/// <seealso cref="Triangular"/>
void Triangular::gen_elems_to_val(int val)
{
	if (val <= 0)
	{
		cerr << "Error: Can not generate Triangular Sequence to a negative value" << endl;
		return;
	}
	if (!_elems.size())
		_elems.push_back(1);

	int ix = _elems.size();
	while (true)
	{
		int new_val = (ix + 1) * (ix + 2) / 2;
		if (new_val <= val && new_val < _max_elem)
		{
			_elems.push_back(new_val);
			ix++;
		}
		else
			break;
	}

	cout << "Generating Triangular Sequence to value: " << val
		<< "\n _elems.back() = " << _elems.back() << endl;
	if (_elems.back() == _max_elem)
		cerr << "Error: Triangular Sequence exceeds max element: " << _max_elem << endl;

}
void Triangular::display(int len, int beg_pos, ostream& os)
{
	cout << "\nDisplay Triangular Sequence: ";
	for (auto u : _elems)
		cout << u << " ";
	cout << endl;
}

int sum(const Triangular& tri)
{
	if (tri.length() == 0)
		return 0;

	int val, sum = 0;
	tri.reset_next();
	while (tri.next(val))
		sum += val;
	return sum;
}

int main(void)
{
	char ch;
	bool more = true;
	while (more)
	{
		cout << "Enter value: ";
		int ival;
		cin >> ival;
		bool is_elem = Triangular::is_elem(ival);
		cout << ival
			<< (is_elem ? " is " : " is not ")
			<< "an element in the Triangular series.\n"
			<< "Another value? (y/n) ";
		cin >> ch;
		cin.ignore();
		if (ch == 'n' || ch == 'N')
			more = false;
	}

	return 0;
}