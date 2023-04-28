#include <iostream>
#include "../Header/fibonacci.h"

using namespace std;

static void test_constructor_and_cout(void) {
	Fibonacci fb2(1, 20);
	cout << fb2;
}
static void test_new_and_delete(void) {
	num_sequence* pns = new Fibonacci(1, 10);
	// ok: invokes Fibonacci::what_am_i() through virtual mechanism 
	cout << pns->what_am_i() << endl;
	// ok: invokes inherited num_sequence::max_elems(); 
	cout << "sequence back elem: " << pns->back() << endl;
	// ok: invokes Fibonacci destructor through virtual mechanism 
	delete pns;
}
static void test_memfunc_elem(void) {
	Fibonacci fb(1, 10);
	cout << fb << endl;
	cout << "Elem at position 5: " << fb.elem(5) << endl;
}
int main(void)
{
	test_constructor_and_cout();
	//test_new_and_delete();
	//test_memfunc_elem();

	return 0;
}