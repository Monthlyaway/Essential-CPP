#pragma once
#include "num_sequence.h"

class Fibonacci : public num_sequence {
public:
	Fibonacci(size_t beg_pos = 1, size_t len = 1) :
		num_sequence(beg_pos, len, &_elems)
	{
		check_integrity(_beg_pos + _len - 1, _relems.size());
	}

	unsigned long int back(void) const {
		return _relems[_beg_pos + _len - 2];
	}
	string what_am_i(void) const {
		return "Fibonacci";
	}

protected:

private:
	static vector<int> _elems;

	bool gen_elem_to_pos(size_t pos) {
		if (pos <= _relems.size())
		{
			cout << "Warning: no need to generate sequence to position "
				<< pos << endl;
			return true;
		}
		else
		{
			unsigned long int new_val;
			unsigned long int vsize = _relems.size();
			if (vsize == 0)
			{
				_relems.push_back(1);
				_relems.push_back(1);
			}
			else if (vsize == 1)
				_relems.push_back(1);

			for (unsigned long int ix = _relems.size(); ix < pos; ix++)
			{
				new_val = _relems[ix - 2] + _relems[ix - 1];
				_relems.push_back(new_val);
			}
			return true;
		}
	}
};

vector<int> Fibonacci::_elems;
