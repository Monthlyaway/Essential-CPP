//#include <iostream>
//#include <vector>
//#include "Triangular.h"
//#include "Triangular_iterator.h"
//using namespace std;
//
//
///*class Triangular_iterator start from here */
//inline bool Triangular_iterator::
//operator==(const Triangular_iterator& rhs) const
//{
//	return _index == rhs._index;
//}
//
//inline bool Triangular_iterator::
//operator!=(const Triangular_iterator& rhs) const
//{
//	return !(*this == rhs);
//}
//
///*An operator can be defined either as a member operator function, */
//inline int Triangular_iterator::
//operator*() const
//{
//	check_integrity();
//	return Triangular::_elems[_index];
//}
//
///*The check_integrity() member function ensures that
//_index is not larger than _max_elems and that
//_elems holds the necessary elements. */
//inline void Triangular_iterator::
//check_integrity() const
//{
//	// we'll look at the throw expression in Chapter 7 ... 
//	if (_index > Triangular::_max_elems)
//		throw iterator_overflow();
//	// grow vector if necessary ... 
//	if (_index > Triangular::_elems.size())
//		Triangular::gen_elements(_index);
//}
//
///*We must provide a prefix (++trian) and postfix (trian++)
//instance of the increment operator. */
//inline int& Triangular_iterator::
//operator++()
//{ // prefix instance 
//	++_index;
//	check_integrity();
//	return Triangular::_elems[_index];
//}
//
///*each overloaded operator must have a unique parameter list.
//The language solution is to require that
//we define the postfix instance with a single integer parameter: */
//inline int Triangular_iterator::
//operator++(int)
//{
//	// postfix instance 
//	check_integrity();
//	return Triangular::_elems[_index++];
//	//++it; // prefix 
//	//it++; // postfix 
//
//}
