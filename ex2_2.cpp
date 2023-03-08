//#include <iostream>
//#include <vector>
//#include <cstdlib>
//using namespace std;
///* Introduce a static local vector to hold the elements of your Pentagonal series.This function returns
//a const pointer to the vector. */
//vector<int>* pent_seq(int pos);
//
///*Write a second function that, given a vector, displays its elements. It should take a second
//parameter identifying the type of numeric series the vector represents.*/
//template <typename elemType>  // no ;, yes <>
//void display_seq(const vector<elemType>& vec);
//
///*Implement a second function that, given a position, returns the element at that
//position.*/
//template <typename elemType>
//elemType seq_elem(const vector<elemType>& vec, int pos);
//template <typename elemType>
//bool size_is_ok(const vector<elemType>& vec, int pos);
//
//int main(void)
//{
//	int pos;
//	vector<int>* seq_ptr = 0;
//	cout << "Enter an integer number (q to quit): ";
//	while (scanf_s("%d", &pos) == 1)
//	{
//		seq_ptr = pent_seq(pos);
//		display_seq(*seq_ptr);
//		
//		cout << "The " << pos << "th element is " << seq_elem(*seq_ptr, pos) << endl;
//		cout << "Enter an integer number (q to quit): ";
//	}
//	
//
//	return 0;
//}
//
//vector<int>* pent_seq(int pos)
//{
//	const int max_size = 1024;
//	static vector<int> elems;
//	if (pos <= 0 || pos >= 1024)
//	{
//		cerr << "Position is out of range." << endl;
//		return 0;
//	}
//	if (pos > elems.size())
//	{
//		for (int i = elems.size(); i < pos; i++)
//			/* Pn=n*(3n-1)/2 */
//			elems.push_back((i + 1) * (3 * (i + 1) - 1) / 2);
//	}
//
//	return &elems;
//}
//
//template <typename elemType>
//void display_seq(const vector<elemType>& vec)
//{
//	for (int i = 0; i < vec.size(); i++)
//	{
//		cout << vec[i] << ' ';
//		if ((i + 1) % 10 == 0)
//			cout << '\n';
//	}
//	cout << endl;
//}
//
//template <typename elemType>
//elemType seq_elem(const vector<elemType>& vec, int pos)
//{
//	if (!size_is_ok(vec, pos))
//	{
//		cout << "Exit Program" << endl;
//		exit(EXIT_FAILURE);
//	}
//	return vec[pos - 1];
//}
//template <typename elemType>
//bool size_is_ok(const vector<elemType>& vec, int pos)
//{
//	if (pos <= 0 || pos > vec.size())
//	{
//		cerr << "Position is out of range." << endl;
//		return false;
//	}
//	else
//		return true;
//}