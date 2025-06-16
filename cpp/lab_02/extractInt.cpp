#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/* func. prototypes. */
bool get_int(ifstream&, bool&, int&, string&);
int get_file_size(ifstream&);

/* this is the main func. */
int main(int argc, char *argv[]) {
	int data;
	string junk_data;
	bool flag = false; /* the flag is used to rep. whether the val. is good... */
	string file_name = "";

	cout << "Please enter the input filename: ";
	cin >> file_name; /* read the user-specified filename into the file_name var. */
	cout << endl;

	/* open the file in read-only mode with the ifstream object called fin. */
	ifstream fin;
	fin.open(file_name, ios::in);

	/* check if the file opened successfully. if not, then exit the program. */
	if(!fin.is_open()) {
		cout << "error: failed to open the input stream." << endl;
		return -1; /* exit with an error status. */
	}

	/* print the file size. */
	cout << "File Size (in bytes): " << get_file_size(fin) << endl;

	ofstream intValsFile("intVals.txt", ios::out); /* open the output stream to intVals.txt. */
	ofstream junkValsFile("junkVals.txt", ios::out); /* open the output stream to junkVals.txt. */

	if(!intValsFile.is_open()) { /* check if successfully opened the output stream. */
		cout << "error: failed to open the output stream." << endl;
		fin.close(); /* close the input stream. */
		return -1; /* exit with an error status. */
	}

	if(!junkValsFile.is_open()) { /* check if successfully opened the output stream. */
		cout << "error: failed to open the output stream." << endl;
		fin.close(); /* close the input stream */
		return -1; /* exit with an error status. */
	}

	int count = 0;
	while(get_int(fin, flag, data, junk_data)) {
		/* check if the value in data is good (i.e., it is an integer). */
		/* note: accomplish by checking the boolean flag. */
		/* if the value is good, then save the data in intVals.txt. else, save the junk_data in junkVals.txt. */
		count++;
		if(flag) {
			intValsFile << data << endl;
		} else {
			junkValsFile << junk_data << endl;
		}
	}

	/* close the files. */
	fin.close(); /* close the input stream. */
	intValsFile.close(); /* close the 1st output stream. */
	junkValsFile.close(); /* close the 2nd output stream. */

	cout << "Number of Lines: " << count << endl;
	cout << "You can now open intVals.txt and junkVals.txt to verify the output!" << endl;
	return 0;
}

/* func. purpose: obtains the file size in bytes. */
int get_file_size(ifstream &fin) {
	/* source: https://www.tutorialspoint.com/how-can-i-get-a-file-s-size-in-cplusplus */
	int file_size = 0;
	fin.seekg(0, ios::end);
	file_size = fin.tellg();
	fin.seekg(0, ios::beg);
	return file_size;
}

/* func. purpose: return false if you cannot continue reading the file (i.e., either the EOF | flag was set). */
bool get_int(ifstream &fin, bool &flag, int &data, string &junk_data) {
	/* source: https://www.geeksforgeeks.org/extract-integers-string-c/ */
	bool can_continue = false;
	string tmp;
	if(getline(fin, tmp)) {
		stringstream ss(tmp);
		ss >> data;
		if(!ss.fail()) {
			flag = true;
			can_continue = true;
		} else {
			flag = false;
			junk_data = tmp;
			can_continue = true;
		}
	}
	return can_continue;
}
