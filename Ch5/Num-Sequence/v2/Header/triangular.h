#pragma once
#include "num_sequence.h"

class Triangular : public num_sequence {
public:
	Triangular(size_t beg_pos = 1, size_t len = 1) : _beg_pos(beg_pos), _len(len) {
		if (_beg_pos < 1 || len < 1) {
			cerr << "Triangular constructor: invalid arguement, set to 1" << endl;
			_beg_pos = _len = 1;
		}
		if (_elems_vec.size() == 0)
			_elems_vec.push_back(1);
		if (_beg_pos + len - 1 > _elems_vec.size())
			gen_elem_to_pos(_beg_pos + len - 1);
	}

	unsigned long int elem(int pos) {
		if (!check_integrity(pos, _elems_vec.size()))
		{
			cerr << "Triangular::elem() Invalid argument" << endl;
			return -999;
		}
		return _elems_vec[pos - 1];
	}
	unsigned long int back(void) const {
		return _elems_vec.back();
	}
	unsigned long int size(void) const {
		return _elems_vec.size();
	}
	unsigned long int beg_pos(void) const {
		return _beg_pos;
	}
	ostream& print(ostream& os = cout) const {
		os << what_am_i() << " (" << _beg_pos << ", " << _len << ") ";
		for (int ix = _beg_pos - 1; ix <= _beg_pos + _len - 2; ix++)
			os << _elems_vec[ix] << " ";
		return os;
	}
	string what_am_i(void) const {
		return "Triangular";
	}

protected:


private:
	size_t _beg_pos;
	size_t _len;
	static vector<unsigned long int> _elems_vec;
	bool gen_elem_to_pos(size_t pos) {
		for (int ix = _elems_vec.size(), new_val = 0; ix < pos; ix++)
		{
			new_val = (ix + 2) * (ix + 1) / 2;
			_elems_vec.push_back(new_val);
		}
		return true;
	}
};

vector<unsigned long int> Triangular::_elems_vec;
