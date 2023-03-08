///**************************************************
// * Essential C++ -- Stanley Lippman
// * Addison-Wesley
// * ISBN 0-201-48518-4
// * homepage: www.objectwrite.com
// * email: slippman@objectwrite.com
// *************************************************/
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//void prog1()
//{
//	char ch;
//	bool more = true;
//
//	while (more)
//	{
//		cout << "Enter value: ";
//		int ival;
//		cin >> ival;
//
//		bool is_elem = Triangular::is_elem(ival);
//
//		cout << ival
//			<< (is_elem ? " is " : " is not ")
//			<< "an element in the Triangular series.\n"
//			<< "Another value? (y/n) ";
//
//		cin >> ch;
//		if (ch == 'n' || ch == 'N')
//			more = false;
//	}
//}
//
//int main(void)
//{
//	prog1();
//}