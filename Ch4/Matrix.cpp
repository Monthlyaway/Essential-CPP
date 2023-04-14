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

	~Matrix()
	{
		// destructor frees the resource
		delete[] _pmat;
	}
private:
	int _row, _col;
	double* _pmat;
};