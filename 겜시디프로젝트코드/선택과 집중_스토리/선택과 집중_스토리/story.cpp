#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "story.h"
using namespace std;

int Country::Get_sd() { return selected; }
void Country::sd_Plus() { selected++; }

void Game::ready() {
	ifstream fin1;
	ifstream fin2;

	bool fin1_check = false;
	bool fin2_check = false;

	while (true){
		cout << "�Ƿ� ������ ���� �ܼ��� �غ�Ǿ����� Ȯ���մϴ�." << endl;

		fin1.open("./P_Console_check.txt");
		fin2.open("./L_Console_check.txt");

		Sleep(1000);
		

		if (!fin1) {
			cout << "�丣�׺�ũ �Ƿ� ����� �ܼ��� ������ �ʾҽ��ϴ�" << endl;
		}
		else {
			fin1_check = true;
		}

		if (!fin2) {
			cout << "�󺣴Ͼ� �Ƿ� ����� �ܼ��� ������ �ʾҽ��ϴ�" << endl;
		}
		else {
			fin2_check = true;
		}

		Sleep(1000);

		if (fin1_check && fin2_check) {
			cout << "�غ� �Ϸ�Ǿ����ϴ�" << endl;
			char keyPressed = _getch();
			system("cls");
			break;
		}
		fin1.close();
		fin2.close();
		system("cls");
	}


}

void Game::print_Line() {
	cout << "------------------------------------------------------------------------------------------" << endl;
}

void Game::prologue() {
	int temp;
	//print_Line();
	cout << "\t\t���ѷα�" << endl << endl << endl;
	cout << "\t\t1���� '�丣�׺�ũ'�� �˷�þ� ���ְ� '�󺣴Ͼ�'���� �׷� ���� ����" << endl;
	cout << "\t\t'�˷�þ� ���� �׷� ���� ���'�� ������� '�丣�׺�ũ'�� �������� �Ѵ�" << endl << endl;
	cout << "....����(�ƹ�Ű �Է�)" << endl << endl << endl;
	//print_Line();
	char keyPressed = _getch();
	system("cls");
	//print_Line();
	cout << "\t\t���ѷα�" << endl << endl << endl;
	cout << "�߸��� ����(Reven) ����� �پ �Ƿ��� ���� ��Ŀ �̸� '��ī'" << endl;
	cout << "������ ���� ���� �� ������ ������ ��� ������ ������ ���� �پ ��Ŀ '��ī'���� �Ƿڸ� �ִ´�" << endl << endl;
	cout << "....����(�ƹ�Ű �Է�)" << endl << endl << endl;
	//print_Line();
	keyPressed = _getch();
	system("cls");
}

int Game::Choice_Mission() {
	int m;
	//print_Line();
	cout << "�Ƿ� ����" << endl;
	cout << "�丣�׺�ũ�� �󺣴Ͼ� �� �������� �Ƿڰ� ���Դ�" << endl;;
	cout << "��� ���� �Ƿڸ� �����ұ�? �丣�׺�ũ(1) or �󺣴Ͼ�(2) >> ";
	while (true) {
		cin >> m;
		if (m == 1 || m == 2) {
			break;
		}
		else {
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ��� >> ";
		}
	}

	if (m == 1) {
		cout << "�丣�׺�ũ�� �Ƿڸ� �����ߴ�" << endl;
	}
	else {
		cout << "�󺣴Ͼ��� �Ƿڸ� �����ߴ�" << endl;
	}


	return m;
}

void Game::Create_Mission_File(int c, int p, int l, int m) {
	ofstream fout;

	switch (c) {
	case 0:
		if (m == 1) {
			fout.open("ch1_0_p_mission.txt");
		}
		else {
			fout.open("ch1_0_l_mission.txt");
		}
		break;
	case 1:
		if (p == 1 && l == 0) {
			if (m == 1) {
				fout.open("ch2_p_p_mission.txt");//ch2_p_p_mission.txt
			}
			else {
				fout.open("ch2_p_l_mission.txt");//ch2_p_l_mission.txt
			}
		}
		else {
			if (m == 1) {
				fout.open("ch2_l_p_mission.txt");//ch2_l_p_mission.txt
			}
			else {
				fout.open("ch2_l_l_mission.txt");//ch2_l_l_mission.txt
			}
		}
		break;
	case 2:
		if (p == 2 && l == 0) {
			if (m == 1) {
				fout.open("ch3_2p_p_mission.txt");//ch2_2p_p_mission.txt
			}
			else {
				fout.open("ch3_2p_l_mission.txt");//ch2_2p_l_mission.txt
			}
		}
		else if (p == 1 && l == 1) {
			if (m == 1) {
				fout.open("ch3_pl_p_mission.txt");//ch2_pl_p_mission.txt
			}
			else {
				fout.open("ch3_pl_l_mission.txt");//ch2_pl_l_mission.txt
			}
		}
		else {
			if (m == 1) {
				fout.open("ch3_2l_p_mission.txt");//ch2_2l_p_mission.txt
			}
			else {
				fout.open("ch3_2l_l_mission.txt");//ch2_2l_l_mission.txt
			}
		}
		break;
	case 3:
		if (p == 3 && l == 0) {
			fout.open("ch4_3p_p_mission.txt");//ch2_3p_p_mission.txt
		}
		else if (p == 2 && l == 1) {
			if (m == 1) {
				fout.open("ch4_2pl_p_mission.txt");//ch2_2pl_p_mission.txt
			}
			else {
				fout.open("ch4_2pl_l_mission.txt");//ch2_2pl_l_mission.txt
			}
		}
		else if (p == 1 && l == 2) {
			if (m == 1) {
				fout.open("ch4_p2l_p_mission.txt");//ch2_p2l_p_mission.txt
			}
			else {
				fout.open("ch4_p2l_l_mission.txt");//ch2_p2l_l_mission.txt
			}
		}
		else {
			fout.open("ch4_3l_l_mission.txt");//ch2_3l_l_mission.txt
		}
		break;
	default:
		cout << "���ϻ��� ����";
		break;
	}

	if (!fout) {
		cout << "���ϻ��� ����";
	}

	fout.close();
}

void Game::print_Story(int c , int p, int l, int m) {
	switch (c) {
	case 0:
		if (m == 1) {
			cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
			cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
		}
		else {
			cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
			cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
		}
		break;
	case 1:
		if (p == 1 && l == 0) {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		break;
	case 2:
		if (p == 2 && l == 0) {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		else if (p == 1 && l == 1) {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		break;
	case 3:
		if (p == 3) {
			cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
			cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
		}
		else if (p == 2 && l == 1) {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		else if (p == 1 && l == 2) {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		else {
			cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
			cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
		}
	}
}

void Game::print_clear_Story(int c, int p, int l, int m) {
	switch (c) {
	case 0:
		if (m == 1) {
			cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
			cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
		}
		else {
			cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
			cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
		}
		break;
	case 1:
		if (p == 1 && l == 0) {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		break;
	case 2:
		if (p == 2 && l == 0) {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		else if (p == 1 && l == 1) {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		break;
	case 3:
		if (p == 3) {
			cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
			cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
		}
		else if (p == 2 && l == 1) {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		else if (p == 1 && l == 2) {
			if (m == 1) {
				cout << "�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����, ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
				cout << "�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
			}
			else {
				cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
				cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
			}
		}
		else {
			cout << "�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�.. ��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
			cout << "������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
		}
	}
}

void Game::Find_Clear_File(int ch) {
	ifstream fin;
	bool clear_check = false;

	while (!clear_check) {
		switch (ch) {
		case 0:
			fin.open("./ch1_clear");
			if (!fin) {
				cout << "���� �Ƿڸ� �Ϸ����� �ʾҽ��ϴ�." << endl;
			}
			else {
				clear_check = true;
			}
			break;
		case 1:
			fin.open("./ch2_clear");
			if (!fin) {
				cout << "���� �Ƿڸ� �Ϸ����� �ʾҽ��ϴ�." << endl;
			}
			else {
				clear_check = true;
			}
			break;
		case 2:
			fin.open("./ch3_clear");
			if (!fin) {
				cout << "���� �Ƿڸ� �Ϸ����� �ʾҽ��ϴ�." << endl;
			}
			else {
				clear_check = true;
			}
			break;
		case 3:
			fin.open("./ch4_clear");
			if (!fin) {
				cout << "���� �Ƿڸ� �Ϸ����� �ʾҽ��ϴ�." << endl;
			}
			else {
				clear_check = true;
			}
			break;
		default:

			break;
		}
		Sleep(1000);
		system("cls");
	}
	fin.close();
}

void Game::PCFP(int c, int p, int l, int m) {
	print_Story(chapter, p, l, m); // ���丮
	char keyPressed = _getch();
	Create_Mission_File(chapter, p, l, m); // �Ƿ� ���� �����
	Find_Clear_File(chapter); // Ŭ���� ���� ã��
	print_clear_Story(chapter, p, l, m);// �Ϸ� �� ���丮
}

void Game::Proglation(Country* P, Country* L) {
	int m;
	int p = P->Get_sd();
	int l = P->Get_sd();

	switch (chapter) {
	case 0:
		m = Choice_Mission();
		PCFP(chapter, p, l, m);
		if (m == 1) {
			P->sd_Plus();
		}
		else if (m == 2) {
			L->sd_Plus();
		}
		break;
	case 1:
		m = Choice_Mission();
		PCFP(chapter, p, l, m);
		if (m == 1) {
			P->sd_Plus();
		}
		else if (m == 2) {
			L->sd_Plus();
		}
		break;
	case 2:
		m = Choice_Mission();
		PCFP(chapter, p, l, m);
		if (m == 1) {
			P->sd_Plus();
		}
		else if (m == 2) {
			L->sd_Plus();
		}
		break;
	case 3:
		if (p == 3) {
			PCFP(chapter, p, l, 1);
		}
		else if (p == 2 && l == 1) {
			m = Choice_Mission();
			PCFP(chapter, p, l, m);
			if (m == 1) {
				P->sd_Plus();
			}
			else if (m == 2) {
				L->sd_Plus();
			}
		}
		else if (p == 1 && l == 2) {
			m = Choice_Mission();
			PCFP(chapter, p, l, m);
			if (m == 1) {
				P->sd_Plus();
			}
			else if (m == 2) {
				L->sd_Plus();
			}
		}
		else {
			PCFP(chapter, p, l, 2);
		}
		break;
	default:
		cout << "����" << endl;
	}
	

	chapter++;
}

void Game::start() {
	Country Perteburk;
	Country Lavenia;

	prologue(); // ���ѷα�

	ready(); //�丣�׺�ũ�� �󺣴Ͼ� �Ƿ� ���� â�� �������� Ȯ��

	Proglation(&Perteburk, &Lavenia); // ���丮���� 1
	Proglation(&Perteburk, &Lavenia); // ���丮���� 2
	Proglation(&Perteburk, &Lavenia); // ���丮���� 3
	Proglation(&Perteburk, &Lavenia); // ���丮���� 4


}