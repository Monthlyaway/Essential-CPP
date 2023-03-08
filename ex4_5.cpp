///* Implement a 4x4 Matrix class
// * supporting at least the following general interface:
// * addition and multiplication of two Matrix objects,
// * a print() member function
// * a compound += operator
// * subscripting supported through a pair of overloaded function call operators
// */
//#include <iostream>
//using namespace std;
//
//typedef float elemType;
//
//class Matrix {
//public:
//	friend Matrix operator+(const Matrix&, const Matrix&);
//	friend Matrix operator*(const Matrix&, const Matrix&);
//
//	// use an array to initialize matrix
//	Matrix(const elemType*);
//	Matrix(elemType = .0, elemType = .0, elemType = .0, elemType = .0,
//		elemType = .0, elemType = .0, elemType = .0, elemType = .0,
//		elemType = .0, elemType = .0, elemType = .0, elemType = .0,
//		elemType = .0, elemType = .0, elemType = .0, elemType = .0);
//	// don't need copy constructor or deconstructor
//	// or copy assignment operator for the Matrix class
//
//	// read access functions
//	// simplifies transition to general matrix
//	int rows(void) const { return 4; }
//	int cols(void) const { return 4; }
//	ostream& print(ostream&) const;
//	void operator+=(const Matrix&);
//
//	elemType& operator()(int row, int col) // can not 
//	{
//		return _matrix[row][col];
//	}
//	elemType operator()(int row, int col) const
//	{
//		return _matrix[row][col];
//	}
//
//
//private:
//	elemType _matrix[4][4];
//};
//
//Matrix::Matrix(const elemType* array)
//{
//	const elemType* ptr = array;
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4; j++)
//			_matrix[i][j] = *(ptr++);
//}
//
//Matrix::Matrix(
//	elemType a11, elemType a12, elemType a13, elemType a14,
//	elemType a21, elemType a22, elemType a23, elemType a24,
//	elemType a31, elemType a32, elemType a33, elemType a34,
//	elemType a41, elemType a42, elemType a43, elemType a44)
//{
//	_matrix[0][0] = a11; _matrix[0][1] = a12;
//	_matrix[0][2] = a13; _matrix[0][3] = a14;
//	_matrix[1][0] = a21; _matrix[1][1] = a22;
//	_matrix[1][2] = a23; _matrix[1][3] = a24;
//	_matrix[2][0] = a31; _matrix[2][1] = a32;
//	_matrix[2][2] = a33; _matrix[2][3] = a34;
//	_matrix[3][0] = a41; _matrix[3][1] = a42;
//	_matrix[3][2] = a43; _matrix[3][3] = a44;
//}
//
//ostream& Matrix::print(ostream& os) const
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//			os << _matrix[i][j] << " ";
//		os << endl;
//	}
//	return os;
//}
//
//ostream& operator<<(ostream& os, const Matrix& rhs)
//{
//	return rhs.print(os);
//}
//
//void Matrix::operator+=(const Matrix& rhs)
//{
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4; j++)
//			_matrix[i][j] += rhs._matrix[i][j];
//}
//
//Matrix operator+(const Matrix& m1, const Matrix& m2)
//{
//	Matrix result(m1);
//	result += m2;
//	return result;
//}
//
//Matrix operator*(const Matrix& m1, const Matrix& m2)
//{
//	Matrix result;
//	for (int i = 0; i < m1.rows(); i++)
//		for (int j = 0; j < m2.cols(); j++)
//		{
//			result(i, j) = 0;
//			for (int k = 0; k < m1.cols(); k++)
//				result(i, j) += m1(i, k) * m2(k, j);
//		}
//	return result;
//}
//
////int main(void)
////{
////	Matrix m;
////	cout << m << endl;
////
////	elemType ar[16] = {
////	1., 0., 0., 0., 0., 1., 0., 0.,
////	0., 0., 1., 0., 0., 0., 0., 1. };
////
////	Matrix identity(ar);
////	cout << identity << endl;
////
////	Matrix m2(identity);
////	cout << m2 << endl;
////
////	elemType ar2[16] = {
////	 1.3, 0.4, 2.6, 8.2, 6.2, 1.7, 1.3, 8.3,
////	4.2, 7.4, 2.7, 1.9, 6.3, 8.1, 5.6, 6.6 };
////	Matrix m3(ar2); cout << m3 << endl;
////
////	Matrix m4 = m3 * identity; cout << m4 << endl;
////	Matrix m5 = m3 + m4; cout << m5 << endl;
////	m3 += m4; cout << m3 << endl;
////
////	return 0;
////}