#include <iostream>
#include <vector>
using namespace std;

/*
 * num_sequence is like a starting menu, or a control panel for
 * all the sequences, it does not handle the detail of all the sequences,
 * nor does it contain static member data,
 * it consists of function pointers to generate suquences
 */
class num_sequence
{
public:
	typedef void (num_sequence::* PtrType)(int);
	// _pmf addresses one of these
	void fibonacci(int);
	void pell(int);
	void lucas(int);
	void triangular(int);
	void square(int);
	void pentagonal(int);
	/*
	* If the position requested by the user is valid and if
	* the number of elements currently stored does not include that position, the
	* necessary elements are generated through an invocation of the function addressed
	* by _pmf.
	* First check integrity of the position, then generate
	*/
	int elem(int pos);
	enum ns_type {
		ns_unset, ns_fibonacci, ns_pell, ns_lucas, ns_triangular,
		ns_square, ns_pentagonal
	};
	ns_type check_nstype(int num);
	void set_sequence(ns_type nst);
	void display(ostream& os, num_sequence& ns, int pos);
	string what_am_i(void) const;

private:
	// points to the current vector
	PtrType _pmf;
	// points to the current vector sequence
	vector<int>* _elem;
	// identifies current sequence type, see enum ns_type
	ns_type _isa;
	// see the function table, contains null pointer, so 7
	static const int _num_seq = 7;
	// function table, consists of pointer to member functions above
	static PtrType func_tbl[_num_seq];

	/*
	 * vector 1: fibonacci
	 * vector 2: pell
	 * vector 3: lucas
	 * ...
	 * can not ommit space between the two >, because of maximal munch complilation rule
	 */
	static vector<vector<int> > _seq;

	// private functions
	bool check_integrity(int pos);
};

const int num_sequence::_num_seq;
vector<vector<int>> num_sequence::_seq;
typedef num_sequence::PtrType PtrType;
PtrType num_sequence::func_tbl[_num_seq] = {
	0,
	// pointer style &, address operator
	&num_sequence::fibonacci,
	&num_sequence::pell,
	&num_sequence::lucas,
	&num_sequence::triangular,
	&num_sequence::square,
	&num_sequence::pentagonal };


inline int num_sequence::elem(int pos)
{
	if (!check_integrity(pos))
		return 0;
	if (pos > _elem->size())
		(this->*_pmf)(pos - 1);
	return (*_elem)[pos - 1];
}
inline num_sequence::ns_type num_sequence::check_nstype(int num) {
	return num < 0 || num >= _num_seq
		? ns_unset : static_cast<ns_type>(num);
}
inline void num_sequence::set_sequence(num_sequence::ns_type nst) {
	// set _pmf, _elem, _isa

	switch (nst)
	{
	default: cerr << "invalid type: setting to 0" << endl;
		// deliberate fall-through
	case ns_unset: _pmf = 0; _elem = 0; _isa = ns_unset; break;

	case ns_fibonacci: case ns_lucas: case ns_pell: case ns_pentagonal:
	case ns_square: case ns_triangular:
		_pmf = func_tbl[nst];
		_elem = &(_seq[nst]);
		_isa = nst;
		break;
	}

}
inline void num_sequence::display(ostream& os, num_sequence& ns, int pos) {
	os << "The element at position "
		<< pos << " for the "
		<< ns.what_am_i() << " sequence is "
		<< ns.elem(pos) << endl;
}

inline string num_sequence::what_am_i(void) const {
	vector<string> seq_name{
		"notSet",
 "fibonacci", "pell",
 "lucas", "triangular",
 "square", "pentagonal"
	};
	return seq_name[_isa];
}

int main(void)
{

	return 0;
}