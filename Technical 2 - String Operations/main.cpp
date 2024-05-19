#include <iostream>
#include <cstring>
#include <limits>
#include "string_operations.h"

using namespace std;

int string_length(const char *str) {
	const char *ptr = str;
	while (*ptr != '\0') {
		ptr++;
		}
	return ptr - str;
	}

int string_compare(const char *s1 , const char *s2) {
	while ( *s1 == *s2) {
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
		}
		return *s1 - *s2;
	}
	
void string_concatenate(char *s1, const char *s2){
	while (*s1) {
		s1++;
	}
	while (*s2) {
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

int main() {
	string again;
	char str1[100], str2[100];
	int opt;
	
	cout << "\nWhat would you like to do?" << endl;
	cout << "1. Find the string length." << endl;
	cout << "2. Compare two strings."    << endl;
	cout << "3. Concatenate two strings."<< endl;
	cout << "4. Exit."   				 << endl;
	while (!(cin >> opt)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		cout << "Invalid input. Please 1 - 4: ";
	}
	cout << endl;
	switch(opt) {
		
		case 1:
		length:
			cout << "Enter a string: ";
			cin  >> str1;
			cout << "length of the string: " << string_length(str1) << endl; 
		break;	
		
		case 2:
		compare:
			cout << "Enter the first string: ";
			cin  >> str1;
			cout << "Enter the second string: ";
			cin  >> str2;
			if(string_compare(str1,str2) == 0)
				cout << "The strings are equal." << endl;
			else if(string_compare(str1,str2) > 0)
				cout << "String one is smaller." << endl;
			else
				cout << "string one is bigger." << endl;
		break;
		
		case 3: 
		Concatenate:
			cout << "Enter the first string: ";
			cin	 >> str1;
			cout << "Enter the second string: ";
			cin >> str2;
			
			string_concatenate(str1,str2);
			cout << "Concatenated string: " << str1 << endl;
			break;
		case 4:
			cout << "Than you for using our program!" << endl;
			break;
		default:
			cout << "Invalid input, please try again." << endl;
		break;
	}
	again:
			cout << "\nDo you want to try again [Y/N]";
			cin >> again;
			if (again == "Y" || again == "y"){
				main();
			} else if (again == "N" || again == "n") {
			cout << "\nThanks for using our program." << endl;	
			} else {
				cout << "Invalid input." << endl;
				goto again;
			}
}
