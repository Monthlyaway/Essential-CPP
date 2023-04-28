#pragma once
#include "num_sequence.h"

class Fibonacci : public num_sequence {
public:
	Fibonacci(unsigned long int beg_pos = 1, unsigned long  int len = 1) :
		_len(len), _beg_pos(beg_pos) {
		check_integrity(_beg_pos + _len - 1, _elems_vec.size());
	}
	//~Fibonacci() { 
	//	cout << "Fibonacci::~Fibonacci() destructor!" << endl; 
	//}

	unsigned long int elem(int pos) {
		check_integrity(pos, _elems_vec.size());
		if (pos > _elems_vec.size())
			Fibonacci::gen_elem_to_pos(pos);
		return _elems_vec[pos - 1];
	}
	unsigned long int back(void) const {
		return _elems_vec[_beg_pos + _len - 2];
	}
	unsigned long int size(void) const {
		return _len;
	}
	unsigned long int beg_pos(void) const {
		return _beg_pos;
	}
	ostream& print(ostream& os = cout) const {
		os << what_am_i() << ": (" << _beg_pos << ", " << _len << ") ";
		for (unsigned long int ix = _beg_pos - 1; ix <= _beg_pos + _len - 2; ix++)
			os << _elems_vec[ix] << " ";
		return os;
	}
	string what_am_i(void) const {
		return "Fibonacci";
	}

protected:

private:
	unsigned long int _len;
	unsigned long int _beg_pos;
	static vector<unsigned long int> _elems_vec;

	bool gen_elem_to_pos(size_t pos) {
		if (pos <= _elems_vec.size())
		{
			cout << "Warning: no need to generate sequence to position "
				<< pos << endl;
			return true;
		}
		else
		{
			unsigned long int new_val;
			unsigned long int vsize = _elems_vec.size();
			if (vsize == 0)
			{
				_elems_vec.push_back(1);
				_elems_vec.push_back(1);
			}
			else if (vsize == 1)
				_elems_vec.push_back(1);

			for (unsigned long int ix = _elems_vec.size(); ix < pos; ix++)
			{
				new_val = _elems_vec[ix - 2] + _elems_vec[ix - 1];
				_elems_vec.push_back(new_val);
			}
			return true;
		}
	}
};

vector<unsigned long int> Fibonacci::_elems_vec;
