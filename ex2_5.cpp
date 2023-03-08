///*Implement an overloaded set of max() functions to accept (a) two integers, (b) two floats, (c) two 
//strings, (d) a vector of integers, (e) a vector of floats, (f) a vector of strings, (g) an array of integers 
//and an integer indicating the size of the array, (h) an array of floats and an integer indicating the 
//size of the array, and (i) an array of strings and an integer indicating the size of the array. Again, 
//write a main() function to exercise these functions. 
//*/
//#include <iostream>
//#include <cstring>
//#include <vector>
//#include <cstdlib>
//using namespace std;
//
//int max(int a, int b);
//float max(float a, float b);
//string max(string a, string b);
//
//vector<int> max(vector<int> a, vector<int> b);
//vector<float> max(vector<float> a, vector<float> b);
//vector<string> max(vector<string> a, vector<string> b);
//
//int max(int* array, int size);
//float max(float* array, int size);
//string max(string* array, int size);
//int main(void)
//{
//	cout << max(1, 3) << endl;
//	cout << max(1.9, 3.6) << endl;
//	
//
//	return 0;
//}
//
//int max(int a, int b)
//{return (a > b) ? a : b;}
//float max(float a, float b)
//{return (a > b) ? a : b;}
//string max(string a, string b)
//{return (a.compare(b) > 0) ? a : b;}
//
//vector<int> max(vector<int> a, vector<int> b)
//{
//	int sum_a = 0, sum_b = 0;
//	for (int i = 0; i < a.size(); i++)
//		sum_a += a[i];
//	for (int i = 0; i < b.size(); i++)
//		sum_b += b[i];
//	return (sum_a > sum_b) ? a : b;
//}
//vector<float> max(vector<float> a, vector<float> b)
//{
//	float sum_a = 0, sum_b = 0;
//	for (int i = 0; i < a.size(); i++)
//		sum_a += a[i];
//	for (int i = 0; i < b.size(); i++)
//		sum_b += b[i];
//	return (sum_a > sum_b) ? a : b;
//}
//vector<string> max(vector<string> a, vector<string> b)
//{return (a.size() > b.size()) ? a : b;}
//
//int max(int* array, int size)
//{
//	int max = array[0];
//	for (int i = 1; i < size; i++)
//		if (array[i] > max)
//			max = array[i];
//	return max;
//}
//float max(float* array, int size)
//{
//	float max = array[0];
//	for (int i = 1; i < size; i++)
//		if (array[i] > max)
//			max = array[i];
//	return max;
//}
//string max(string* array, int size)
//{
//	int* str_size = new int[size + 1];
//	for (int i = 0; i < size; i++)
//		str_size[i] = array[i].length();
//	int max_index = 0;
//
//	for (int i = 1; i < size; i++)
//	{
//		if (str_size[i] > str_size[max_index])
//			max_index = i;
//	}
//	delete[]str_size;
//
//	return array[max_index];
//}