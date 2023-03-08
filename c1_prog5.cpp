///* how to use array and vector
//* see document onenote->C++ Primer->Vector 101
//*/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void c1_prog5(void);
//int main(void)
//{
//	c1_prog5();
//
//	return 0;
//}
//
//void c1_prog5(void)
//{
//	// initialzie vector
//	const int seq_size = 18;
//	int elem_val[seq_size] = {
//	1,2,3,  3,4,7,  2,5,12,
//	3,6,10,  4,9,16,  5,12,22 };
//	vector<int> elem_seq(elem_val, elem_val + seq_size);
//
//	// init sequence name
//	const int max_seq = 6;
//	const string seq_names[max_seq] = {
//		"Fibonacci",
//		"Lucas",
//		"Pell",
//		"Triangular",
//		"Square",
//		"Pentogonal"
//	};
//	// show six sequent tuple
//	int cur_tuple = 0;
//	int cur_count = 0;  // currect times
//
//	while (cur_tuple < seq_size)
//	{
//		cout << "The first two elements of the sequence are: "
//			<< elem_seq[cur_tuple] << " "
//			<< elem_seq[cur_tuple + 1]
//			<< "\nWhat is the next element?" << endl;
//		// get user's  guess
//		int usr_guess = -5;
//		cin >> usr_guess;
//		// compare with the answer
//		if (usr_guess == elem_seq[cur_tuple + 2])  
//		{  // guess right
//			cur_count++;
//			cout << "Very good. Yes, "
//				<< elem_seq[cur_tuple + 2]
//				<< " is the next element in the "
//				<< seq_names[cur_tuple / 3] << " sequence." << endl;
//			cur_tuple += 3;
//		}
//		else
//		{  // guess wrong
//			cout << "Sorry, no. Do you want to skip to next sequence? ";
//			string usr_rsp;
//			cin >> usr_rsp;
//			if (usr_rsp[0] == 'N' || usr_rsp[0] == 'n')
//				continue;
//			else
//			{
//				cur_tuple += 3;
//				cout << elem_seq[cur_tuple + 2]
//				<< " is the next element in the "
//				<< seq_names[cur_tuple / 3] << " sequence." << endl;
//			}
//		}
//	}
//}