/**
 * @name: main.cpp
 * @date: 24 January 2019
 * @desc: "Implementation of Vignere Cipher in GNU C++"
 * @author: Robert Maloy
 *
 * This program is licensed under the GNU GPL v2.0 license. Please see LICENSE for further details. **/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;
int msgLen, keyLen;
int i,j;

int getLen(char Set, char Key){
	msgLen = strlen(Set);
	keyLen = strlen(Key);
}

int main() {
	
	/* setting up our messages with spaces! */
	char msg1[] = "A HEALTHY ATTITUDE IS CONTAGIOUS BUT DONT WAIT TO CATCH IT FROM OTHERS.\n";
	char msg2[] = "IF YOU CARRY YOUR CHILDHOOD WITH YOU YOU NEVER BECOME OLDER.\n";
	char msg3[] = "FROM PRINCIPLES IS DERIVED PROBABILITY BUT TRUTH OR CERTAINTY IS OBTAINED ONLY FROM FACTS.\n";

	/* our encryption key... */
	char encKey[] = "MALOY";
	char testKey[] = "KHOSHAVI"; //this is included in order to test the example test case given in the project PDF. Debug only.

	cout << "Message 1: " << msg1;
	cout << "Message 2: " << msg2;
	cout << "Message 3: " << msg3;

	for (i = 0; i < 

	return 0;
}


