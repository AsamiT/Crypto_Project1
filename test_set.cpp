/**
	@name: test_set.cpp
	@date: 14 Feb 2019
	@author: Robert Maloy
	All code is licensed under the GNU GPL v2.0 license. Please refer to LICENSE for more details. **/

/* standard libraries included */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

/* not always the most acceptable convention but I, once again, don't care.
 >sosumi.wav */
using namespace std;

string cryptPhrases[] = {
    "7370696c796166", //should translate to 'liberty'/'spilyaf'
    "6d796c6c6b7674", //should become 'myllkvt', or 'freedom'.
    //"446f68612c20746c3f20", //"What, me?" or "Doha, tl?"
};

using namespace std;
int lenSet;
int hex_two;
size_t size = sizeof(cryptPhrases)/sizeof(cryptPhrases[0]);
int xorArray[200];

int main() {
    for (int i = 0; i < size; i++) {
        string Input = cryptPhrases[i];
        cout << Input << endl;
        //printf(" --> %lu\n", Input.length());
        if (sizeof(Input) > lenSet) {
            lenSet = sizeof(Input);
        }
        int j = 0;
        while (j < size) {
            //cout << j << endl;
            unsigned int hex_one = strtoul(cryptPhrases[i].substr(j, 2).c_str(), NULL, 16);
            if (hex_two != 0) {
                //cout << "hex:" << cryptPhrases[i].substr(j, 2).c_str() << endl;
                //cout << "hex one:" << hex_one << endl;
                //cout << "hex two:" << hex_two << endl;
                int xor_val = (hex_one) ^ (hex_two);
                xor_val += 64;
                cout << "xor symbol: " << (char)xor_val << endl;
            }
            hex_two = hex_one;
            hex_one = 0;
            j+=2;
        }
    }
    
}

