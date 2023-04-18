#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
	Matrix(int row, int col)
		: _row(row), _col(col) {
		// constructor allocates a resource
		// note: no error checking is shown
		_pmat = new double[row * col];
	}

	// memberwise initialization
	Matrix(const Matrix& rhs)
		: _row(rhs._row), _col(rhs._col)
	{
		// create a deep copy of the array addressed by rhs._pmat
		int elem_count = _row * _col;
		_pmat = new double[elem_count];

		// copy each element
		for (int ix = 0; ix < elem_count; ix++)
			_pmat[ix] = rhs._pmat[ix];
	}

	// copy assignment, why return Matrix&, for multiple assignment
	Matrix& operator=(const Matrix& rhs);

	~Matrix()
	{
		// destructor frees the resource
		delete[] _pmat;
	}
private:
	int _row, _col;
	double* _pmat;
};

class LessThan {
public:
	// constructor
	LessThan(int val) : _val(val) {}
	// getter
	int comp_val() const { return _val; }
	// setter
	int comp_val(int nval) { _val = nval; }
	// utility
	bool operator() (int value) const;

private:
	int _val;
};

inline Matrix& Matrix::operator=(const Matrix& rhs)
{
	// what if tri1 = tri1, do not need another memory allocation
	if (this != &rhs)
	{
		_row = rhs._row;
		_col = rhs._col;
		int elem_cnt = _row * _col;

		// delete the whole array
		delete[] _pmat;
		_pmat = new double[elem_cnt];
		for (int ix = 0; ix < elem_cnt; ix++)
			_pmat[ix] = rhs._pmat[ix];
	}
}

inline bool LessThan::operator() (int value) const
{
	return value < _val;
}

void prog1(void)
{
	cout << "Program 1\nPracticing the LessThan function object" << endl;
	LessThan lt10(10);

	bool less_than_10 = lt10(12);
	cout << 12  << (less_than_10 ? " is " : " is not ") << "than 10" << endl;
	cout << "Bye!" << endl;
}

int main(void)
{
	//prog1();

	return 0;
}