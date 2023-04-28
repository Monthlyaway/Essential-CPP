#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
* redesign the num_sequence class into an abstract base class
* from which we inherit each of the numeric sequence classes
*/
class num_sequence {
public:
	virtual ~num_sequence() {
		cout << "Base class destructor!" << endl;
	}

	virtual unsigned long int elem(int pos) = 0;
	virtual unsigned long int beg_pos(int pos) const = 0;
	virtual unsigned long int back(void) const = 0;
	virtual unsigned long int size(void) const = 0;
	virtual ostream& display(ostream& os = cout) const = 0;
	virtual string what_am_i(void) const = 0;

	friend ostream& operator<<(ostream& os, const num_sequence& ns) {
		return ns.display(os);
	}
protected:
	virtual bool gen_elem_to_pos(unsigned long int pos) = 0;
	virtual bool check_integrity(int pos) const = 0;

	const static int _max_pos = 50;
};

class Fibonacci : public num_sequence {
public:
	Fibonacci(unsigned long int beg_pos = 1, unsigned long  int len = 1) :
		_len(len), _beg_pos(beg_pos) {
		gen_elem_to_pos(_beg_pos + len - 1);
	}
	//~Fibonacci() { 
	//	cout << "Fibonacci::~Fibonacci() destructor!" << endl; 
	//}

	unsigned long int elem(int pos) {
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
	unsigned long int beg_pos(int pos) const {
		return _beg_pos;
	}
	ostream& display(ostream& os = cout) const {
		os << what_am_i() << ": (" << _beg_pos << ", " << _len << ") ";
		for (unsigned long int ix = _beg_pos - 1; ix <= _beg_pos + _len - 2; ix++)
			os << _elems_vec[ix] << " ";
		return os;
	}
	string what_am_i(void) const {
		return "Fibonacci";
	}

protected:
	bool check_integrity(int pos) const {
		if (pos < 0 || pos > _max_pos)
		{
			cerr << "Invalid position: " << pos << endl;
			return false;
		}
		return true;
	}

private:
	unsigned long int _len;
	unsigned long int _beg_pos;
	static vector<unsigned long int> _elems_vec;

	virtual bool gen_elem_to_pos(unsigned long int pos) {
		if (!check_integrity(pos))
			return false;
		else if (pos <= _elems_vec.size())
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

void test_constructor_and_cout(void){
	Fibonacci fb2(1, 20);
	cout << fb2;
}
void test_new_and_delete(void) {
	num_sequence *pns = new Fibonacci(1, 10);
	// ok: invokes Fibonacci::what_am_i() through virtual mechanism 
	cout << pns->what_am_i() << endl;
	// ok: invokes inherited num_sequence::max_elems(); 
	cout << "sequence back elem: " << pns->back() << endl;
	// ok: invokes Fibonacci destructor through virtual mechanism 
	delete pns;
}
void test_memfunc_elem(void) {
	Fibonacci fb(1, 10);
	cout << fb << endl;
	cout << "Elem at position 5: " << fb.elem(5) << endl;
}
int main(void)
{
	//test_constructor_and_cout();
	//test_new_and_delete();
	//test_memfunc_elem();

	return 0;
}