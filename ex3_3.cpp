///*Define a map for which the index is the family surname and
//* the key is a vector of the children's names.
//* Populate the map with at least six entries.
//* Test it by supporting user queries based on a
//* surname and printing all the map entries.
//*
//* reference website: https://www.geeksforgeeks.org/different-ways-to-access-characters-in-a-given-string-in-c/?ref=gcse
//*
//*/
//
//#include <iostream>
//#include <map>
//#include <fstream>
//#include <string>
//#include <vector>
//using namespace std;
//
////int coutindex = 0;
//typedef vector<string> vstring;
//
//void populate_map(map<string, vstring>& families, ifstream& in_file);
//void display_map(const map<string, vstring>& families, ostream& os);
//void query_map(const string& family,
//	const map<string, vstring>& families);
//
//int main(void)
//{
//	ifstream in_file("ex3_3_input_file.txt");
//	ofstream out_file("ex3_3_output_file.txt");
//
//	if (!in_file || !out_file)
//	{
//		perror("Can not open files");
//		return -1;
//	}
//
//	// string for family's name, vstring for children's names
//	map<string, vstring> families;
//	populate_map(families, in_file);
//	display_map(families, cout);
//	display_map(families, out_file);
//
//	string search_name;
//	cout << "Please enter a family name or q to quit." << endl;
//	while (search_name != "q")
//	{
//		cin >> search_name;
//		query_map(search_name, families);
//		cout << "Please enter a family name or q to quit." << endl;
//	}
//
//	return 0;
//}
//
//void populate_map(map<string, vstring>& families, ifstream& in_file)
//{
//	string textline;
//
//	while (getline(in_file, textline, '\n'))
//	{
//		string tfamily_name;
//		vstring tchildren_name;
//		string::size_type
//			pos = 0, prev_pos = 0, len = 0;  // serve as index
//
//		// ok, find each word seperated by space
//		while ((pos = textline.find_first_of(" ", pos))
//			!= string::npos)  // update pos
//		{
//			// figure out length of the substring
//			len = pos - prev_pos;
//
//			// if prev_pos is not set, this is a family name
//			if (!prev_pos)
//			{
//				tfamily_name = textline.substr(prev_pos, len);
//			}
//			// otherwise we are reading children
//			else
//			{
//				
//				tchildren_name.push_back(textline.substr(prev_pos, len));
//				//cout << ++coutindex << textline.substr(prev_pos, len) << endl;
//			}
//			prev_pos = ++pos;
//		}
//
//		// handle last child
//		if (prev_pos)
//		{
//			len = pos - prev_pos;
//			tchildren_name.push_back(textline.substr(prev_pos, len));
//		}
//		else
//			tfamily_name = textline;
//		//cout << ++coutindex << textline.substr(prev_pos, len) << endl;
//
//		if (!families.count(tfamily_name))
//			families[tfamily_name] = tchildren_name;
//		else
//			cerr << "Oops! We already have a "
//			<< tfamily_name << " family in our map." << endl;
//	}
//}
//
//void display_map(const map<string, vstring>& families, ostream& os)
//{
//	map<string, vstring>::const_iterator it = families.begin();
//	for (; it != families.end(); it++)
//	{
//		if (it->second.size())
//		{
//			os << "The " << it->first << " family has "
//				<< it->second.size() << " children: ";
//			vstring::const_iterator vit = it->second.begin();
//			for (; vit != it->second.end(); vit++)
//				os << *vit << " ";
//			os << endl;
//		}
//		else
//		{
//			os << "The " << it->first << " family has no children" << endl;
//		}
//	}
//}
//
//void query_map(const string& family,
//	const map<string, vstring>& families)
//{
//	map<string, vstring>::const_iterator it;
//	it = families.find(family);
//
//	cout << "The " << family << " has ";
//	if (it == families.end())
//		 cout << " is not currently enterd." << endl;
//	else
//	{
//		if (it->second.size())
//		{
//			cout << it->second.size() << " children: ";
//			vstring::const_iterator vit = it->second.begin();
//			while (vit != it->second.end())
//			{
//				cout << *vit << " ";
//				vit++;
//			}
//			cout << endl;
//		}
//		else
//			cout << "no children." << endl;
//	}
//}