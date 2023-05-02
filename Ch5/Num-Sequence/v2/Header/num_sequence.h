#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/* 
* The base class now has all the information necessary to search and display the 
* elements of the numeric sequence.
*/
//class num_sequence {
//public:
//	virtual ~num_sequence() {}
//	virtual string what_am_i() const = 0;
//	int elem(int pos) {
//		check_integrity(pos, _relems.size());
//		if (pos > _relems.size())
//			gen_elem_to_pos(pos);
//		return _relems[pos - 1];
//	}
//	ostream& print(ostream& os = cout) const {
//		os << what_am_i() << ": (" << _beg_pos << ", " << _len << ") ";
//		for (unsigned long int ix = _beg_pos - 1; ix <= _beg_pos + _len - 2; ix++)
//			os << _relems[ix] << " ";
//		return os;
//	}
//	int size() const { return _len; }
//	int beg_pos() const { return _beg_pos; }
//	static size_t max_elems() { return 50; }
//	int back(void) const {
//		return _relems[_beg_pos + _len - 2];
//	}
//protected:
//	virtual bool gen_elem_to_pos(size_t pos) = 0;
//	bool check_integrity(size_t pos, size_t size) {
//		if (pos < 1 || pos > max_elems()) {
//			cerr << "Error: " << what_am_i() << ": check_integrity() invalid pos" << endl;
//			return false;
//		}
//		if (pos > size) {
//			gen_elem_to_pos(pos);
//			return true;
//		}
//	}
//	num_sequence(size_t bp = 1, size_t len = 1, vector<int>& re = *(new vector<int>()))
//		: _len(len), _beg_pos(bp), _relems(re) {
//		check_integrity(_beg_pos + _len - 1, _relems.size());
//	}
//	// declare reference to vector, no need to check nullptr
//	int _len;
//	int _beg_pos;
//	vector<int>& _relems;
//};

class num_sequence {
public:
	virtual ~num_sequence() {}
	virtual num_sequence* clone() = 0;

	virtual const char* what_am_i() const = 0;
	int elem(int pos) const;
	ostream& print(ostream& os = cout) const;
	int length() const { return _length; }
	int beg_pos() const { return _beg_pos; }
	static int max_elems() { return 64; }
protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_integrity(int pos, int size) const;

	num_sequence(int len, int bp, vector<int>& re)
		: _length(len), _beg_pos(bp), _relems(re) {}
	//num_sequence(int len = 1, int bp = 1, vector<int>* pe = nullptr)
	//	: _length(len), _beg_pos(bp), _relems(*pe) {}
	num_sequence& operator=(const num_sequence& rhs) {
		if (this != &rhs) {
			_length = rhs._length;
			_beg_pos = rhs._beg_pos;
			_relems = rhs._relems;
		}
		return *this;
	}

	int _length;
	int _beg_pos;
	vector<int>& _relems;
};
