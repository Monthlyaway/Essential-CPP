//#include <iostream>
//#include <fstream>
//#include <map>
//#include <set>
//#include <iterator>
//#include <algorithm>
//#include <string>
//using namespace std;
//
///*Write a program to read a text file.
//* Store each word in a map.
//* The key value of the map is the count of the number of times
//* the word appears in the text.
//* Define a word exclusion set containing words such as a, an, or, the, and, and but.
//* Before entering a word in the map, make sure it is not present in the word exclusion set.
//* Display the list of words and their associated count when the
//* reading of the text is complete.
//* As an extension, before displaying the text, allow the user to query
//* the text for the presence of a word.
//*/
//
//void print_map(map<string, int>& m);
//void initialize_exclusion_set(set<string>& exs);
//void process_file(map<string, int>& words,
//	const set<string>& exclude_set, ifstream& ifile);
//void user_query(const map<string, int>& word_map);
//void display_word_count(const map<string, int>& word_map, ofstream& ofile);
//
//int main(int argc, char* argv[])
//{
//	ifstream in_file("ex3_1_input_file.txt");
//	ofstream out_file("ex3_1_output_file.txt");
//
//	// check if file opened successfully
//	if (!in_file || !out_file)
//	{
//		perror("Can not open file");
//		return -1;
//	}
//
//	// element in set is unique
//	set<string> exclude_set;
//	initialize_exclusion_set(exclude_set);
//
//	map<string, int> words;
//	process_file(words, exclude_set, in_file);
//	user_query(words);
//	display_word_count(words, out_file);
//
//	print_map(words);
//
//	return 0;
//}
//
//void print_map(map<string, int>& m)
//{
//	map<string, int>::iterator it = m.begin();
//	for (; it != m.end(); it++)
//		cout << "key = " << it->first
//		<< " value = " << it->second << endl;
//}
//
//void initialize_exclusion_set(set<string>& exs)
//{
//	// excluded_words array should just initialize once
//	static string excluded_words[25] =
//	{
//		"the","and","but","that","then","are","been",
//		"can","a","could","did","for", "of",
//		"had","have","him","his","her","its","is",
//		"were","which","when","with","would"
//	};
//
//	// excluded_words is a pointer to strings
//	exs.insert(excluded_words, excluded_words + 25);
//}
//
//void process_file(map<string, int>& words,
//	const set<string>& exclude_set, ifstream& ifile)
//{
//	string tword;
//
//	while (ifile >> tword)
//	{
//		cout << "read in: " << tword << endl;
//		if (exclude_set.count(tword))
//			continue;
//		words[tword]++;
//	}
//}
//
//void user_query(const map<string, int>& word_map)
//{
//	string search_word;
//	cout << "Please enter a word to search: q to quit" << endl;
//	cout << "Search: ";
//	cin >> search_word;
//
//	while (search_word.size() && search_word != "q")
//	{
//		map<string, int>::const_iterator it;
//		if ((it = word_map.find(search_word))
//			!= word_map.end())
//			cout << "Found " << it->first
//			<< " Occurs " << it->second
//			<< (it->second == 1 ? " time." : " times.") << endl;
//		else
//			cout << search_word
//			<< "was not found in the text." << endl;
//
//		cout << "Please enter a word to search: q to quit" << endl;
//		cout << "Search: ";
//		cin >> search_word;
//	}
//
//}
//
//void display_word_count(const map<string, int>& word_map, ofstream& ofile)
//{
//	map<string, int>::const_iterator it = word_map.begin();
//	for (; it != word_map.end(); it++)
//		ofile << it->first << " ("
//			<< it->second << ")" << endl;
//	ofile << endl;
//}