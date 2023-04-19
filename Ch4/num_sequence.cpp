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
	typedef void (num_sequence::*PtrType)(int);

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

private:
	// points to the current vector
	PtrType _pmf;
	// points to the current vector sequence
	vector<int> *_elem;
	// see the function table, contains null pointer, so 7
	static const int num_seq = 7;
	// function table, consists of pointer to member functions above
	static PtrType func_tbl[num_seq];

	/*
	 * vector 1: fibonacci
	 * vector 2: pell
	 * vector 3: lucas
	 * ...
	 * can not ommit space between the two >, because of maximal munch complilation rule
	 */
	static vector<vector<int>> seq;

	// private functions
	bool check_integrity(int pos);
};

const int num_sequence::num_seq;
vector<vector<int>> num_sequence::seq;
typedef num_sequence::PtrType PtrType;
PtrType num_sequence::func_tbl[num_seq] = {
	0,
	// pointer style &, address operator
	&num_sequence::fibonacci,
	&num_sequence::pell,
	&num_sequence::lucas,
	&num_sequence::triangular,
	&num_sequence::square,
	&num_sequence::pentagonal};


int num_sequence::elem(int pos)
{
	if (!check_integrity(pos))
		return 0;
	if (pos > _elem->size())
		(this->*_pmf)(pos - 1);
	return (*_elem)[pos - 1];
}

int main(void)
{
	
	return 0;
}