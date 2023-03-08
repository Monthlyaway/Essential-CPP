//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
///*Read in a text file ¡ª it can be the same one as in Exercise 3.1 ¡ª 
//* storing it in a vector. 
//* Sort the vector by the length of the string.
//* Define a function object to pass to sort();
//* it should accept two strings and
//* return true if the first string is shorter than the second. Print the sorted vector.
//*/
//
//void process_file(vector<string>& svec, ifstream& ifile);
//bool shorter_string(string& s1, string& s2);  // function object, pass to sort
//void display_vec(vector<string>& vec, ostream& os = cout);
//int main(void)
//{
//	ifstream in_file("ex3_2_input_file.txt");
//	ofstream out_file("ex3_2_output_file.txt");
//
//	// check if file opened successfully
//	if (!in_file || !out_file)
//	{
//		perror("Can not open file");
//		return -1;
//	}
//
//	vector<string> words;
//	process_file(words, in_file);
//	sort(words.begin(), words.end(), shorter_string);
//	display_vec(words, out_file);
//
//	return 0;
//}
//
//void process_file(vector<string>& svec, ifstream& ifile)
//{
//	string tword;
//	while (ifile >> tword)
//		svec.push_back(tword);
//}
//
//bool shorter_string(string& s1, string& s2)
//{
//	if (s1.size() < s2.size())
//		return true;
//	else
//		return false;
//}
//
//void display_vec(vector<string>& vec, ostream& os)
//{
//	for (auto u : vec)
//		os << u << " ";
//	cout << endl;
//}