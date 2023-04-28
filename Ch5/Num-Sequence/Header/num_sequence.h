#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class num_sequence {
public:
	virtual ~num_sequence() {
		//cout << "Base class destructor!" << endl;
	}

	virtual unsigned long int elem(int pos) = 0;
	virtual unsigned long int beg_pos(void) const = 0;
	virtual unsigned long int back(void) const = 0;
	virtual unsigned long int size(void) const = 0;
	virtual ostream& display(ostream& os = cout) const = 0;
	virtual string what_am_i(void) const = 0;

	friend ostream& operator<<(ostream& os, const num_sequence& ns) {
		return ns.display(os);
	}
protected:
	virtual bool gen_elem_to_pos(size_t pos) = 0;
	bool check_integrity(int pos, int size)
	{
		if (pos <= 0 || pos > _max_pos) {
			cerr << "Invalid position: " << pos << endl;
			return false;
		}
		else if (pos > size)
		{
			// gen_elem_to_pos is invoked through virual mechanism,
			// because it is a pure virtual function in base class.
			gen_elem_to_pos(pos);
			return true;
		}
	}

	const static int _max_pos = 50;
};
