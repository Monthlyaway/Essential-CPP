#include <iostream>
#include "../Header/square.h"

using namespace std;

static void test_constructor_and_cout(void) {
	Square sq2(1, 20);
	cout << sq2;
}
static void test_new_and_delete(void) {
	num_sequence* pns = new Square(1, 10);
	// ok: invokes Square::what_am_i() through virtual mechanism 
	cout << pns->what_am_i() << endl;
	// ok: invokes inherited num_sequence::max_elems(); 
	cout << "sequence back elem: " << pns->back() << endl;
	// ok: invokes Square destructor through virtual mechanism 
	delete pns;
}
static void test_memfunc_elem(void) {
	Square sq(1, 10);
	cout << sq << endl;
	cout << "Elem at position 5: " << sq.elem(5) << endl;
}
//int main(void)
//{
//	test_constructor_and_cout();
//	//test_new_and_delete();
//	//test_memfunc_elem();
//
//	return 0;
//}