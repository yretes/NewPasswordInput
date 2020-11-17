#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>


static constexpr int KEY_UP = 72;
static constexpr int KEY_DOWN = 80;
static constexpr int KEY_LEFT = 75;
static constexpr int KEY_RIGHT = 77;

int main()
{
	std::string correctCode = "AAAAAA";
	std::string inputCode = "AAAAAA";
	std::vector<char> passwordPointer(6, ' ');
	char codePart = ' ';
	int input = 0;
	int pointerPos = 0;

	passwordPointer[0] = 'V';

	std::fstream Password("Password.txt");
	for (int i = 0; i < 6; i++) {
		Password >> codePart;
		correctCode[i] = codePart;
	}
	Password.close();
	do {
		printf("\033c");
		std::cout << "\t";
		for (int a = 0; a < 6; a++) {
			std::cout << "|  " << passwordPointer[a] << "  |";
			if (passwordPointer[a] == 'V')
				pointerPos = a;
		}
		std::cout << "\n\t";
		for (int a = 0; a < 6; a++) {
			std::cout << "|  " << inputCode[a] << "  |";
		}
		input = _getch();
		switch (input) {
		case KEY_UP:
			if (inputCode[pointerPos] != 'A') {
				inputCode[pointerPos] = inputCode[pointerPos] - 1;
			}
			else
				inputCode[pointerPos] = 'Z';
			break;
		case KEY_DOWN:
			if (inputCode[pointerPos] != 'Z') {
				inputCode[pointerPos] = inputCode[pointerPos] + 1;
			}
			else
				inputCode[pointerPos] = 'A';
			break;
		case KEY_LEFT:
			if (passwordPointer[0] != 'V')
				for (int a = 0; a < passwordPointer.size(); a++) {
					if (passwordPointer[a] == 'V') {
						passwordPointer[a] = ' ';
						passwordPointer[a - 1] = 'V';
					}
				}
			else
				std::cout << "Nuh uh";
			break;
		case KEY_RIGHT:
			if (passwordPointer[5] != 'V')
				for (int a = 0; a < passwordPointer.size(); a++) {
					if (passwordPointer[a] == 'V') {
						passwordPointer[a] = ' ';
						passwordPointer[a+1] = 'V';
						break;
					}
				}
			else
				std::cout << "Nuh uh";
			break;
		default:
			break;

		}


	} while (inputCode != correctCode);
	printf("\033c");
	std::cout << "Gottem";
}
