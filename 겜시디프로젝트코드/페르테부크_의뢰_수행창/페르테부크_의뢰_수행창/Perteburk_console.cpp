#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include "Console.h"
#include "Puzzle.h"
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
			//�Ƿ� ���� �ν�
			pz = PC.Find_File(ch, p, l);
			if (pz == 1) {
				PC.Puzzled(ch);
				PC.create_Clear_File(ch, p, l);
				p++;
				system("cls");
				break;
			}
			else if (pz == 2) {
				l++;
				system("cls");
				break;
			}
			else {
				cout << "���� �Ƿڸ� �ȹ޾ҽ��ϴ�." << endl;
			}
		}
		ch++;
	}

	cout << "��� �Ƿڸ� �����Ͽ����ϴ�." << endl;
	char keyPressed = _getch();


	return 0;
}