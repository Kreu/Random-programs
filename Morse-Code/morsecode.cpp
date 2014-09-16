#include <iostream>
#include <map>
#include <string>
#include "Windows.h"

int main() {

	const int LENGTH_OF_UNIT = 60;
	const int FREQ = 1500;

	std::map<char, std::string> morse;

	//Alphabet character to morse
	morse['A'] = ".-",	morse['B'] = "-...",	morse['C'] = "-.-.";
	morse['D'] = "-..",	morse['E'] = ".",	morse['F'] = "..-.";
	morse['G'] = "--.",	morse['H'] = "....",	morse['I'] = "..";
	morse['J'] = ".---",	morse['K'] = "-.-",	morse['L'] = ".-..";
	morse['M'] = "--",	morse['N'] = "-.",	morse['O'] = "---";
	morse['P'] = ".--.",	morse['Q'] = "--.-",	morse['R'] = ".-.";
	morse['S'] = "...",	morse['T'] = "-",	morse['U'] = "..-";
	morse['V'] = "...-",	morse['W'] = ".--",	morse['X'] = "-..-";
	morse['Y'] = "-.--",	morse['Z'] = "--..";
	
	morse['1'] = ".----",	morse['2'] = "..---",	morse['3'] = "...--";
	morse['4'] = "....-",	morse['5'] = ".....",	morse['6'] = "-....";
	morse['7'] = "--...",	morse['8'] = "---..",	morse['9'] = "----.";
	morse['0'] = "-----";

	std::string message("");
	std::cout << "Enter a text to convert into morse\nDo not use any formatting characters, they won't work.\n";
	while (std::cin >> message) {
		for (char c : message) {
			c = toupper(c);
			std::cout << c << '\n';
			for (char cs : morse[c]) {
				std::cout << cs << "";
				if (cs == '.') {
					Beep(FREQ, LENGTH_OF_UNIT);
				}
				else if (cs == '-') {
					Beep(FREQ, LENGTH_OF_UNIT * 3);
				}
				//Space between units of same letter is one unit
				Sleep(LENGTH_OF_UNIT);
			}
			std::cout << " \n";
			//Space between letters is three units
			Sleep(LENGTH_OF_UNIT * 3);
		}
		//Space between words is seven units
		Sleep(LENGTH_OF_UNIT * 7);
	}
}
