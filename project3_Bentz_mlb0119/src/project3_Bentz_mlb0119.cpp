//============================================================================
// Name        : project3_Bentz_mlb0119.cpp
// Author      : Matthew Bentz mlb0119
// Version     : 1.0
// Description : Project 3, learning iostream.
// References  : Project 3 Hints
//			   : cplusplus.com/reference/algorithm/sort/ for sorting vector 3
// 			   : cplusplus.com/doc/tutorial/files/ for writing to a file
// Compile	   : Compiled with MinGW GCC C++ Compiler
//============================================================================

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ----- FUNCTION DECLARATION ----- //

bool check_file(string);
vector<int> read_file(string);
void write_file(string, vector<int>);
vector<int> merge(vector<int>, vector<int>);
void to_string(vector<int>);

// ----- MAIN ----- //

int main() {

	// ----- LOCAL VARIABLES ----- //

	string file1;
	string file2;
	string file3;
	vector<int> numbers1;
	vector<int> numbers2;
	vector<int> numbers3;

	// ----- USER INTERFACE ----- //

	cout << "*** Welcome to Matthew's sorting program ***" << endl;

	// FILE 1 //

	do {
		cout << "Enter the first input file name: ";
		cin >> file1;
	} while (cin.fail() || !check_file(file1));

	numbers1 = read_file(file1);
	cout << "The list of " << numbers1.size()
		 << " numbers in the file " + file1 + " is:\n";
	to_string(numbers1);

	// FILE 2 //

	do {
		cout << "Enter the second input file name: ";
		cin >> file2;
	} while (cin.fail() || !check_file(file2));

	numbers2 = read_file(file2);
	cout << "The list of " << numbers2.size()
		 << " numbers in file " + file2 + " is:\n";
	to_string(numbers2);

	// Combine vectors and display the sorted result
	// Note: Uses different format than to_string() method.
	numbers3 = merge(numbers1, numbers2);
	cout << "The sorted list of " << numbers3.size() << " numbers is: ";
	for (unsigned int i=0; i < numbers3.size(); i++) {
		cout << numbers3.at(i) << " ";
	}
	cout << endl;

	// FILE 3 //

	do {
		cout << "Enter the output file name: ";
		cin >> file3;
	} while (cin.fail());

	write_file(file3, numbers3);

	cout << "*** Please check the new file - " + file3 + " ***" << endl
		 << "*** Goodbye. ***";

	return 0;
}

// ----- FUNCTION DEFINITION ----- //

/* Returns true if parameter 'file' exists. */
bool check_file(string file) {
	ifstream stream;

	// check if file exists
	stream.open(file.c_str());
	if (stream.fail()) {
		stream.close();
		return false;
	}
	stream.close();

	return true;
}

/* Reads integer i in parameter 'file' then adds them to return vector 'v' */
vector<int> read_file(string file) {
	ifstream stream;
	vector<int> v;
	int i;

	// add each number in the file to a vector
	stream.open(file.c_str());
	while (stream >> i) {
		v.insert(v.end(), i);
	}
	stream.close();

	return v;
}

/* Creates a new file with name of parameter 'file' and writes values of vector 'v' */
void write_file(string file, vector<int> v) {
	ofstream stream;

	stream.open(file.c_str());
	for (unsigned int i=0; i < v.size(); i++) {
		stream << v.at(i) << endl;
	}
	stream.close();
}

/* Combines vectors 'v1' and 'v2' into return vector 'v3' and sorts it */
vector<int> merge(vector<int> v1, vector<int> v2) {
	vector<int> v3;

	// concat vectors and sort ascending order
	v3 = v1;
	v3.insert(v3.end(), v2.begin(), v2.end());
	sort(v3.begin(), v3.end());

	return v3;
}

/*Prints the numbers in vector parameter 'v' from beginning to end.*/
void to_string(vector<int> v) {
	// display the numbers contained in a vector
	for (unsigned int i=0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
	cout << endl;
}
