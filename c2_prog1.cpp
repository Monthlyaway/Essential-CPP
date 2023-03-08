//#include <iostream>
//using namespace std;
//
///* return true if calculated the element,
//* return false if pos is beyond range,
//* pass a reference of elem in main to change its value
//* see document: onenote C++ Primer-> Fibonacci
//*/
//
//void prog1(void);
//static bool fibon_elem(int pos, int& elem);
//static bool print_sequence(int pos);
//
//
////int main(void)
////{
////	prog1();
////	return 0;
////}
//
//void prog1(void)
//{
//	int pos = 0;
//	
//	cout << "Please enter some positions (enter q to quit): ";
//	while (scanf_s("%d", &pos) == 1)
//	{
//		int elem;
//		if (fibon_elem(pos, elem))
//			cout << "element # " << pos
//			<< " is " << elem << endl;
//		else
//			cout << "Sorry. Could not calculate element # "
//			<< pos << endl;
//
//		if (!print_sequence(pos))
//			cout << "Can not show the sequence." << endl;
//	}
//}
//
//static bool fibon_elem(int pos, int& elem)
//{
//	// check if pos is invalid
//	if (pos <= 0 || pos >= 1024)
//	{
//		cout << "Position is out of range." << endl;
//		elem = 0;
//		return false;
//	}
//
//	// elem is 1 positions 1 and 2
//	elem = 1;
//	int n_1 = 1, n_2 = 1;
//	for (int ix = 3; ix <= pos; ix++)
//	{
//		elem = n_1 + n_2;
//		n_1 = n_2; n_2 = elem;
//	}
//	return true;
//}
//
//static bool print_sequence(int pos)
//{
//	// check if pos is invalid
//	if (pos <= 0 || pos >= 1024)
//	{
//		cout << "Position is out of range." << endl;
//		return false;
//	}
//	cout << "The Fibonacci Sequence for "
//		<< pos << " positions: \n\t";
//
//	switch (pos)
//	{
//	default:  // if pos > 2, still go through case 2 and 1
//	case 2: cout << "1 ";  //  if pos is 2, go through case 2 and 1
//	case 1: cout << "1 "; break;
//	}
//	// elem is 1 positions 1 and 2
//	int elem = 1;
//	int n_1 = 1, n_2 = 1;
//	for (int ix = 3; ix <= pos; ix++)
//	{
//		elem = n_1 + n_2;
//		n_1 = n_2; n_2 = elem;
//		cout << elem << (!(ix % 10) ? "\n\t" : " ");  // brace the expression!
//	}
//	cout << endl;  // good habit
//	return true;
//}