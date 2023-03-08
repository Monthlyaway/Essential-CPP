///*Write a program to read a sequence of integer numbers 
//* from standard input using an istream_iterator. 
//* Write the odd numbers into one file using an ostream_iterator.
//* Each value should be separated by a space.
//* Write the even numbers into a second file,
//* also using an ostream_iterator.
//* Each of these values should be placed on a separate line.*/
//#include <iostream>
//#include <vector>
//#include <fstream>  // for even and odd file output
//#include <iterator>  // for istream_iter, ostream_iter, mention the bind method
//#include <algorithm>  // for partiton algorithm, using devision iter
//
//using namespace std;
//
//bool elem_is_even(int a);
//int main(void)
//{
//	//cout << "Hello" << endl;
//
//	ofstream even_file("ex3_4_even_file.txt");
//	ofstream odd_file("ex3_4_odd_file.txt");
//	if (!even_file || !odd_file)
//	{
//		perror("Can not open file");
//		return -1;
//	}
//
//	vector<int> ivec;
//
//	//cout << "before defining is_iter" << endl;
//	cout << "Please enter some integer numbers." << endl;
//	istream_iterator<int> cin_it(cin), eos;
//	//cout << "after defining is_iter" << endl;
//
//	copy(cin_it, eos, back_inserter(ivec));
//	/*back_inserter() overrides the assignment operator. 
//	The elements are now inserted using push_back(). */
//
//	vector<int>::iterator division = 
//		stable_partition(ivec.begin(), ivec.end(), elem_is_even);
//	//cout << "partitioned" << endl;
//
//	// We bind our two ostream_iterators to the respective ofstream objects.
//	// must use string not char to be delimeter
//	// define right before useing them
//	ostream_iterator<int> odd_iter(odd_file, " ");
//	ostream_iterator<int> even_iter(even_file, "\n");
//	//cout << "define odd_iter even_iter" << endl;
//
//	copy(ivec.begin(), division, even_iter);
//	copy(division, ivec.end(), odd_iter);
//	//cout << "Copied" << endl;
//
//	even_file.close();
//	odd_file.close();
//	//cout << "File closed" << endl;
//
//	return 0;
//}
//
//bool elem_is_even(int a)
//{
//	return (a % 2 == 0) ? true : false;
//}
