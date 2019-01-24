/**
 * @name: main2.cpp
 * @date: 24 January 2019
 * @desc: "Implementation of Vignere Cipher in GNU C++"
 * @author: Robert Maloy
 *
 * This program is licensed under the GNU GPL v2.0 license. Please see LICENSE for further details. **/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

int main() {
	int i, j; //declare empty integer variables for counter purposes!
	string inString; //declare empty variable for a string
	cout << "Please enter a string to encrypt\n :> "; //ask user to input a string into the thing.
	getline(cin, inString);

	string inKey; //declare empty variable for key!
	cout << "Please enter your key. Save this, as you will need it in order to properly decrypt things!" << endl;
	cout << ":> ";
	getline(cin, inKey);

	int msgLen = inString.length(); //get length and commit it to an integer
	char msg[msgLen]; //create a char array matching those parameters
	strcpy(msg, inString.c_str()); //copy the string we created into the new array.

	/* Now we're going to repeat the same process we just did but with the key. 
	Retrieve user input, get an integer of length, create a character array, copy string into array. */

	int keyLen = inKey.length();
	char key[keyLen];
	strcpy(key, inKey.c_str());

	char keyGen[msgLen];

	for (i = 0, j = 0; i < msgLen; ++i, ++j) {
		if (msg[i] == ' ') {
			keyGen[i] = ' ';
			i++;
		}
		if (j == keyLen) {
			j = 0;
		}
		keyGen[i] = key[j];
		printf("%s\n", keyGen);
	}

	return 0;
}