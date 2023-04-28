#include "..\Header\all-sequences.h"

using namespace std;

inline void display(ostream& os, num_sequence& ns, size_t pos) {
	os << "The element at position "
		<< pos << " for the "
		<< ns.what_am_i() << " sequence is "
		<< ns.elem(pos) << endl;
}

void prog1(void) {
	// test display(), which invokes what_am_i() and elem(pos)
	// need virtual mechanism
	const int pos = 8;
	Fibonacci fib;
	display(cout, fib, pos);
	Pell pell;
	display(cout, pell, pos);
	Lucas lucas;
	display(cout, lucas, pos);
	Triangular trian;
	display(cout, trian, pos);
	Square square;
	display(cout, square, pos);
	Pentagonal penta;
	display(cout, penta, pos);
}
void prog2(void) {
	// test operator<< overload, which invokes virtual print()
	Fibonacci fib(1, 8);
	Pell pell(4,6);
	Lucas lucas(7,10);
	Triangular trian(1,12);
	Square square(6, 6);
	Pentagonal penta(1, 8);
	cout << "fib: " << fib << '\n'
		<< "pell: " << pell << '\n'
		<< "lucas: " << lucas << '\n'
		<< "trian: " << trian << '\n'
		<< "square: " << square << '\n'
		<< "penta: " << penta << endl;

}
int main(void)
{
	//prog1();
	prog2();

	return 0;
}