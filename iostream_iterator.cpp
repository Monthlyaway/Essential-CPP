//#include <iostream>
//#include <iterator>
//// To use either iterator class,
//#include <vector>
//#include <algorithm>
//#include <string>
//
//#include <fstream>  // for file operation
//using namespace std;
//
///* The tradition way of reading from input*/
////int main(void)
////{
////	string word;
////	vector<string> text; 
////	// now empty string vector
////
////	// ok: let's read each word in turn until done
////	while (cin >> word)
////		text.push_back(word);
////
////	// ok: sort it 
////	sort(text.begin(), text.end());
////
////	// ok: let's write them back 
////	for (auto u : text)
////		cout << u << " ";
////	cout << endl;
////
////
////	return 0;
////}
//
///*This main is for documentation of iosteam_iterator uses
//* Do not compile!!!
//*/
////int main(void)
////{
////	vector<string> text;
////
////	istream_iterator<string> is(cin);
////	// bound to standard input
////
////	/*
////	* For standard input, end-of-file represents 1 past the last element to be read. 
////    * How do we indicate that? The definition of an istream_iterator without an istream 
////	* object, such as eof
////	*/
////	istream_iterator<string> eof;
////	/*The definition of an istream_iterator without an istream object, such as 
////     *eof, represent EOF
////	*/
////
////	// we don't know what size the vector is, we use the back_inserter()
////	copy(is, eof, back_inserter(text));
////
////	ostream_iterator<string> os(cout, " ");
////	// The second argument: the 
////	// delimiter to output between the elements
////	// which I choose to be space
////	copy(text.begin(), text.end(), os);
////
////
////	return 0;
////}
//
///*This main read form stdin, sort text, output to stdout
//* Allow Compile
//*/
////int main(void)
////{
////	istream_iterator<string> is(cin);
////	istream_iterator<string> eof;  // EOF
////
////	vector<string> text;
////	copy(is, eof, back_inserter(text));
////
////	sort(text.begin(), text.end());
////
////	ostream_iterator<string> os(cout, " ");
////	copy(text.begin(), text.end(), os);
////
////	return 0;
////}
//
///*What about file operation?
//* we read from and write to
//* a file. How can we do that? We simply bind the istream_iterator to an
//* ifstream class object and the
//* ostream_iterator to an ofstream class object
//* stand for input file stream and output file stream
//*/
////int main(void)
////{
////	ifstream in_file("iostream_iterator_input_file.txt");  // input file name
////	ofstream out_file("iostream_iterator_output_file.txt", std::ofstream::app);
////
////	if (!in_file || !out_file)
////	{
////		perror("!!unable to open the necessary files.");
////		return -1;
////	}
////
////	// input
////	istream_iterator<string> is(in_file);
////	istream_iterator<string> eof;
////
////	vector<string> text;
////	cout << "Read in some words." << endl;
////	copy(is, eof, back_inserter(text));
////	sort(text.begin(), text.end());
////
////	// output
////	cout << "Output to file." << endl;
////	ostream_iterator<string> os(out_file, " ");
////	copy(text.begin(), text.end(), os);
////
////	//// input again
////	//cout << "Input again: " << endl;
////	//copy(is, eof, back_inserter(text));
////	//sort(text.begin(), text.end());
////	//copy(text.begin(), text.end(), os);
////
////	in_file.close();
////	out_file.close();
////
////	return 0;
////}