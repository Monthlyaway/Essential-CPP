//#pragma once
///**************************************************
// * Essential C++ -- Stanley Lippman
// * Addison-Wesley
// * ISBN 0-201-48518-4
// * homepage: www.objectwrite.com
// * email: slippman@objectwrite.com
// *************************************************/
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//class Triangular {
//public:
//	Triangular(int len = 1, int bp = 1);
//	Triangular(const Triangular& rhs);
//
//	int length(void) const { return _length; }
//	int beg_pos(void) const { return _beg_pos; }
//	int get_elem(int pos) const;
//
//	void set_length(int nlen) { _length = nlen; }
//	void set_beg_pos(int nbp) { _beg_pos = nbp; }
//
//	void next_reset() const { _next = _beg_pos - 1; }
//
//	static bool is_elem(int);
//	static void gen_elements(int length);
//	static void gen_elems_to_value(int value);
//	static void display(int length, int beg_pos,
//		ostream& os = cout);
//private:
//	int _length; 	// number of elements
//	int _beg_pos; // beginning position of range,starting from 1
//	mutable int _next;    // next element to iterate over
//
//	static const int _max_elems = 1024;
//	static vector<int> _elems;
//
//};
//
