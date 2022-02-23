/* Name:   [Matt Tranchina]
   Date:   [02-20-2022]
   Course: [CS-210-H7526]

   * Create program to import a txt file and organize with options for user to   *
   * navigate to search for specific items or display entire list of items with  *
   * number of times said item appears in list. Using Python to read and create  *
   * files for C++ to read and organize original txt file.						 * 

*/

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include <sstream>
#undef max

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
void callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	//return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

// Removes unwanted characters from string and displays only letters
void getItemName(string temp) {
	vector<char> name;
	int length = temp.length();

	// Loop to find only letters and add them to char vector
	for (int i = 0; i < length; ++i) {
		if (((temp[i] >= 'a') && (temp[i] <= 'z')) || ((temp[i] >= 'A') && (temp[i] <= 'Z'))) {
			name.push_back(temp[i]);
		}
	}

	// Loop to print letters in vector to screen
	for (int j = 0; j < name.size(); ++j) {
		cout << name.at(j);
	}
	cout << ": ";

	// Clears vector
	name.clear();
}

// Changes a number to '$' in the amount of the number
void changeNumbers(string temp) {
	// Turns a string value to a int value
	stringstream num(temp);
	int number;
	num >> number;

	// Loops to display '$' amount of times set by string
	for (int i = 0; i < number; i++) {
		cout << "$";
	}
	cout << endl;
}

// Makes first letter of user-input a Capital Letter
string makeUppercase(string item) {
	// Int set to the length of the string
	int length = item.length();

	// Vector to hold each letter
	vector<char> name;

	// For loop set to the length of the string and add letters to vector
	for (int i = 0; i < length; ++i) {
		name.push_back(item[i]);
	}
	
	// Make first char Capital
	name.at(0) = toupper(name.at(0));

	// Assign new string with vector elements
	string changed(name.begin(), name.end());

	// Clears the vector
	name.clear();

	// Returns the original string with a Capitalized first letter
	return changed;
}

void Menu() {
	int num = 5;
	string item;
	string temp;
	string holder;
	string holder1;

	// While loop to keep asking user for input until 'Exit' is chosen
	while (num != 4) {

		// Default display
		if (num == 5) {

			// Clears screen
			system("CLS");

			// Displays user interface with options
			cout << "************************ Corner Grocer **************************" << endl;
			for (int i = 0; i < 65; ++i) {
				cout << "*";
			}
			cout << endl;
			cout << "*                                                               *" << endl;
			cout << "* 1 - Get list of all items with number of purchases            *" << endl;
			cout << "* 2 - Find number of times a specific item was purchased        *" << endl;
			cout << "* 3-  Display Histogram of list                                 *" << endl;
			cout << "* 4 - Exit                                                      *" << endl;
			cout << "*                                                               *" << endl;
			for (int i = 0; i < 65; ++i) {
				cout << "*";
			}
			cout << endl;

			// Asks user for input
			cout << "Enter option number: ";

			// Clears input before user enters input
			cin.clear();
			cin >> num;
		}

		// Option 1, display list of purchased items with amount of purchases
		if (num == 1) {
			cout << endl;
			cout << "*** List of Purchased Products ***" << endl;

			// Calls Python function 
			CallProcedure("printList");
			cout << endl;

			// Clears user input and ask user for new input
			cout << "Choose new option, 4 to Exit, 5 to repeat options: ";
			cin.clear();
			cin >> num;
		}

		// Option 2, Ask for a specific item to search and return number of purchases 
		if (num == 2) {
			cout << endl;

			// Ask user for item 
			cout << "Enter item to search: ";
			cin >> item;
			cout << endl;

			// Changes first letter to uppercase if not already
			item = makeUppercase(item);

			// Calls Python function to return amount of user input
			callIntFunc("findItemNumbers", item);
			cout << endl;

			// Clears user input and ask user for new input
			cin.clear();
			cout << "Choose new option, 4 to Exit, 5 to repeat options: ";
			cin.clear();
			cin >> num;
		}

		// Option 3, Displays histogram version of list, replacing number with '$' in 
		// the amount of said number
		if (num == 3) {
			cout << endl;
			cout << "***** Historgram List *****" << endl;

			// Calls Python funtion to create file of list for C++ to read
			CallProcedure("printHistogram");

			// Creates new file and opens file made my Python
			ifstream newList;
			newList.open("frequency.dat");

			// If file can not open, display error message
			if (!newList.is_open()) {
				cout << "File couldn't open" << endl;
			}

			/* Take first word seperated by a whitespace, send that word to 'getItemName' function, 
			   then take next string which will be a number and turn the string nummber into an integer 
			   number. Do this until file ends
			*/
			if (newList.is_open()) {
				while (!newList.fail()) {
					getline(newList, holder, ' ');
					if (!holder.empty()) {
						getItemName(holder);
						holder.clear();
						getline(newList, holder1, ' ');
						changeNumbers(holder1);
						holder1.clear();
					}
				}
			}

			// Close file
			newList.close();

			// Clears input and ask user for new input
			cout << endl;
			cout << "Choose new option, 4 to Exit, 5 to repeat options: ";
			cin.clear();
			cin >> num;
		}

		// Option 4, Exit program
		if (num == 4) {

		}

		// Option 5, Clears screen and displays user interface
		if (num == 5) {
			cin.clear();
			num = 5;
		}

		// If user enters invalid option number, diplay error message
		if ((num > 5) || (num < 0)) {
			cout << endl;
			cout << "Error, please select an option from the menu: ";
			cin.clear();
			cin >> num;
		}		

		// If user enters anything besides valid option (string or char), display error message
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;
			cout << "Error, please select an option from the menu: ";
			cin >> num;
		}
	}
}

int main()
{

	Menu();


	return 0;
}