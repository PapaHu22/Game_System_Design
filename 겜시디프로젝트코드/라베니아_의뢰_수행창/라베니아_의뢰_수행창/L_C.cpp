#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include "Console.h"
using namespace std;

void Console::Open() {
	ofstream fout;
	fout.open("./L_Console_check.txt");
	cout << "라베니아 의뢰 수행용 콘솔이 켜졌습니다." << endl;
	cout << "페르테부크 해킹을 준비합니다." << endl;
	//char keyPressed = _getch();

	fout.close();
}

void Console::Wait() {
	cout << "의뢰 대기 중입니다. 준비가 완료되면 아무키나 눌러주세요." << endl;
	char keyPressed = _getch();
	system("cls");
}

int Console::Find_File(int ch, int p, int l) {
	ifstream fin;
	switch (ch) {
	case 0:
		fin.open("ch1_0_p_mission.txt");
		Sleep(500);
		if (!fin) {
			fin.close();
			fin.open("ch1_0_l_mission.txt");
			if (!fin) {
				cout << "1의뢰 파일을 못찾았습니다" << endl;
				return 0;
			}
			fin.close();
			return 2;
		}
		else {
			fin.close();
			return 1;
		}
		break;
	case 1:
		if (p == 1) {
			fin.open("ch2_p_p_mission.txt");
			Sleep(500);
			if (!fin) {
				fin.close();
				fin.open("ch2_p_l_mission.txt");
				if (!fin) {
					cout << "2의뢰 파일을 못찾았습니다" << endl;
					return 0;
				}
				fin.close();
				return 2;
			}
			else {
				fin.close();
				return 1;
			}
		}
		else {
			fin.open("ch2_l_p_mission.txt");
			Sleep(500);
			if (!fin) {
				fin.close();
				fin.open("ch2_l_l_mission.txt");
				if (!fin) {
					cout << "2의뢰 파일을 못찾았습니다" << endl;
					return 0;
				}
				fin.close();
				return 2;
			}
			else {
				fin.close();
				return 1;
			}
		}
		break;
	case 2:
		if (p == 2) {
			fin.open("ch3_2p_p_mission.txt");
			Sleep(500);
			if (!fin) {
				fin.close();
				fin.open("ch3_2p_l_mission.txt");
				if (!fin) {
					cout << "3의뢰 파일을 못찾았습니다" << endl;
					return 0;
				}
				fin.close();
				return 2;
			}
			else {
				fin.close();
				return 1;
			}
		}
		else if (p == 1 && l == 1) {
			fin.open("ch3_pl_p_mission.txt");
			Sleep(500);
			if (!fin) {
				fin.close();
				fin.open("ch3_pl_l_mission.txt");
				if (!fin) {
					cout << "3의뢰 파일을 못찾았습니다" << endl;
					return 0;
				}
				fin.close();
				return 2;
			}
			else {
				fin.close();
				return 1;
			}
		}
		else {
			fin.open("ch3_2l_p_mission.txt");
			Sleep(500);
			if (!fin) {
				fin.close();
				fin.open("ch3_2l_l_mission.txt");
				if (!fin) {
					cout << "3의뢰 파일을 못찾았습니다" << endl;
					return 0;
				}
				fin.close();
				return 2;
			}
			else {
				fin.close();
				return 1;
			}
		}
		break;
	case  3:
		if (p == 3) {
			fin.open("ch4_3p_p_mission.txt");
			if (!fin) {
				cout << "4의뢰 파일을 못찾았습니다" << endl;
				return 0;
			}
			fin.close();
			return 1;
		}
		else if (p == 2 && l == 1) {
			fin.open("ch4_2pl_p_mission.txt");
			Sleep(500);
			if (!fin) {
				fin.close();
				fin.open("ch4_2pl_l_mission.txt");
				if (!fin) {
					cout << "4의뢰 파일을 못찾았습니다" << endl;
					return 0;
				}
				fin.close();
				return 2;
			}
			else {
				fin.close();
				return 1;
			}
		}
		else if (p == 1 && l == 2) {
			fin.open("ch4_p2l_p_mission.txt");
			Sleep(500);
			if (!fin) {
				fin.close();
				fin.open("ch4_p2l_l_mission.txt");
				if (!fin) {
					cout << "4의뢰 파일을 못찾았습니다" << endl;
					return 0;
				}
				fin.close();
				return 2;
			}
			else {
				fin.close();
				return 1;
			}
		}
		else {
			fin.open("ch4_3l_l_mission.txt");
			if (!fin) {
				cout << "4의뢰 파일을 못찾았습니다" << endl;
				return 0;
			}
			fin.close();
			return 2;
		}
	}
}

void Console::Puzzle(int ch) {
	char keyPressed;
	switch (ch) {
	case 0:
		keyPressed = _getch();
		cout << "퍼즐을 수행하였습니다" << endl;
		//퍼즐
		break;
	case 1:
		keyPressed = _getch();
		cout << "퍼즐을 수행하였습니다" << endl;
		//퍼즐
		break;
	case 2:
		keyPressed = _getch();
		cout << "퍼즐을 수행하였습니다" << endl;
		//퍼즐
		break;
	case 3:
		keyPressed = _getch();
		cout << "퍼즐을 수행하였습니다" << endl;
		//퍼즐
		break;
	default:
		cout << "오류" << endl;
	}
}

void Console::create_Clear_File(int ch, int p, int l) {
	ofstream fout;

	switch (ch) {
	case 0:
		fout.open("./ch1_clear");
		break;
	case 1:
		fout.open("./ch2_clear");
		break;
	case 2:
		fout.open("./ch3_clear");
		break;
	case 3:
		fout.open("./ch4_clear");
		break;
	default:
		cout << "클리어 파일 생성 오류" << endl;
		break;
	}

	fout.close();
}