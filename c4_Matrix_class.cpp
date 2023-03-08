#include <iostream>
class Matrix {
public:
	Matrix(int row, int col)
		:_row(row), _col(col)
	{
		std::cout << "Construct Matrix..." << std::endl;
		// constructor allocates a resource
		// note: no error checking is shown
		_pmat = new double[row * col];
		// specifies the number of elements in an array. 
	}

	Matrix(const Matrix& rhs)  // right hand side
		:_row(rhs._row), _col(rhs._col)
	{
		std::cout << "Creating a \"deep copy\" of the array addressed by rhs._pmat"
			<< ", Overloading default memberwise initialization." << std::endl;
		// create a "deep copy" of the array addressed by rhs._pmat
		int elem_cnt = _row * _col;
		_pmat = new double[elem_cnt];

		// copy the numbers one by one
		for (int ix = 0; ix < elem_cnt; ix++)
			_pmat[ix] = rhs._pmat[ix];
	}

	Matrix& operator=(const Matrix& rhs);

	~Matrix()
	{
		// destructor frees the resource 
		std::cout << "Destruct Matrix..." << std::endl;
		delete[]_pmat;
	}

	//...
private:
	int _row, _col;
	double* _pmat;
};

Matrix& Matrix::
operator=(const Matrix& rhs)
{
	if (this != &rhs)
	{
		_row = rhs._row; _col = rhs._col;
		int elem_cnt = _row * _col;

		delete[]_pmat;
		_pmat = new double[elem_cnt];
		for (int ix = 0; ix < elem_cnt; ix++)
			_pmat[ix] = rhs._pmat[ix];
	}
	return *this;
}