///**************************************************
// * Essential C++ -- Stanley Lippman
// * Addison-Wesley
// * ISBN 0-201-48518-4
// * homepage: www.objectwrite.com
// * email: slippman@objectwrite.com
// *************************************************/
//
//#include "Triangular.h"
//
// /* we must provide an explicit
// * definition of that instance within a program text file.
// * The definition looks like the global definition
// * of an object except that its name is qualified with
// * the class scope operator:
// */
//vector<int> Triangular::_elems;
//
//Triangular::
//Triangular(int len, int bp)
//	:_length(len > 0 ? len : 1),
//	_beg_pos(bp > 0 ? bp : 1)
//{
//	_next = _beg_pos - 1;  // index of vector _elems
//	int elem_cnt = _beg_pos + _length - 1;
//
//	// vector is static
//	// expand if size is less then elem_cnt
//	if (_elems.size() < elem_cnt)
//		gen_elements(elem_cnt);
//}
//
//Triangular::
//Triangular(const Triangular& rhs)
//	:_length(rhs._length),
//	_beg_pos(rhs._beg_pos),
//	_next(rhs._next)
//{}  // ok, empty
//
//int Triangular::
//get_elem(int pos) const
//{
//	return _elems[pos - 1];
//}
//
//bool Triangular::
//is_elem(int value)
//{
//	if (!_elems.size() || _elems[_elems.size() - 1] < value)
//		gen_elems_to_value(value);
//
//	vector<int>::const_iterator found_it;
//	found_it = find(_elems.begin(), _elems.end(), value);
//	return found_it != _elems.end();
//}
//
//void Triangular::
//gen_elements(int length)
//{
//	if (!length)
//	{
//		cerr << "Triangular Sequence: length is 0 in \"gen_elements\"" << endl;
//		exit(EXIT_FAILURE);
//	}
//	else if (length > _max_elems)
//	{
//		cerr << "Triangular Sequence: oops: invalid size in \"gen_elements\": "
//			<< length << " -- max size is "
//			<< _max_elems << endl;
//		exit(EXIT_FAILURE);
//	}
//
//	if (_elems.size() < length)
//	{
//		for (int ix = _elems.size(); ix < length; ix++)
//			_elems.push_back((ix + 2) * (ix + 1) / 2);
//	}
//}
//
//void Triangular::  // no static definition
//gen_elems_to_value(int value)
//{
//	int ix = _elems.size();
//	if (!ix)  // no element
//	{
//		_elems.push_back(1);
//		ix = 1;
//	}
//
//	while (_elems[_elems.size() - 1] < value
//		&& ix < _max_elems)
//	{
//		_elems.push_back((ix + 1) * (ix + 2) / 2);
//		ix++;
//	}
//	if (ix == _max_elems)
//		cerr << "Triangular Sequence: gen_elems_to_value: "
//		<< "value too large " << value << " -- exceeds max "
//		<< "size of " << _max_elems << endl;
//}
//
//void Triangular::
//display(int length, int beg_pos,
//	ostream& os)
//{
//	if (length <= 0 || beg_pos <= 0)
//	{
//		cerr << "invalid parameters in \"display\"-- unable to fulfill request: "
//			<< length << ", " << beg_pos << endl;
//		return;
//	}
//
//	int elem_cnt = beg_pos + length - 1;
//	if (_elems.size() < elem_cnt)
//		gen_elements(elem_cnt);
//
//	for (int ix = beg_pos - 1; ix < beg_pos + length; ix++)
//		os << _elems[ix] << " ";
//	os << endl;
//}
