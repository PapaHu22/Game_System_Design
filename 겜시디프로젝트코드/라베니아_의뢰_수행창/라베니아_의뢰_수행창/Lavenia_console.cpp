#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "Console.h"
#include "dpuzzle.h"
using namespace std;

int main() {
	Console PC;
	int ch;
	int pz;
	int p, l;
	ch = 0;
	p = 0;
	l = 0;
	PC.Open();



	while (ch <= 4) {
		while (true) {
			PC.Wait();
			//의뢰 파일 인식
			pz = PC.Find_File(ch, p, l);
			if (pz == 1) {
				p++;
				system("cls");
				break;
			}
			else if (pz == 2) {
				PC.Puzzle(ch);
				PC.create_Clear_File(ch, p, l);
				l++;
				system("cls");
				break;
			}
			else {
				cout << "아직 의뢰를 안받았습니다." << endl;
			}
		}
		ch++;
	}

	cout << "모든 의뢰를 수행하였습니다." << endl;
	char keyPressed = _getch();

	return 0;
}