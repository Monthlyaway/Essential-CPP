#include <iostream>
#include "../Header/pell.h"

using namespace std;

static void test_constructor_and_cout(void) {
	Pell pl2(1, 20);
	cout << pl2;
}
static void test_new_and_delete(void) {
	num_sequence* pns = new Pell(1, 10);
	// ok: invokes Pell::what_am_i() through virtual mechanism 
	cout << pns->what_am_i() << endl;
	// ok: invokes inherited num_sequence::max_elems(); 
	cout << "sequence back elem: " << pns->back() << endl;
	// ok: invokes Pell destructor through virtual mechanism 
	delete pns;
}
static void test_memfunc_elem(void) {
	Pell pl(1, 10);
	cout << pl << endl;
	cout << "Elem at position 5: " << pl.elem(5) << endl;
}
//int main(void)
//{
//	//test_constructor_and_cout();
//	//test_new_and_delete();
//	//test_memfunc_elem();
//
//	return 0;
//}