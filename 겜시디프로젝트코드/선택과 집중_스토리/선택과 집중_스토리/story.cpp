#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "story.h"
using namespace std;

void ClearLineFromReadBuffer() { while (getchar() != '\n'); }

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
	cout << "���ѷα�" << endl << endl << endl;
	cout << "\t1���� '�丣�׺�ũ'�� �˷�þ� ���ְ� '�󺣴Ͼ�'���� �׷� ���� ����" << endl;
	cout << "\t'�˷�þ� ���� �׷� ���� ���'�� ������� '�丣�׺�ũ'�� �������� �Ѵ�" << endl << endl;
	cout << "....����(�ƹ�Ű �Է�)" << endl << endl << endl;
	//print_Line();
	char keyPressed = _getch();
	system("cls");
	//print_Line();
	cout << "���ѷα�" << endl << endl << endl;
	cout << "\t�߸��� ����(Reven) ����� �پ �Ƿ��� ���� ��Ŀ �̸� '�Ƴ׸��'" << endl;
	cout << "\t������ ���� ���� �� ������ ������ ��� ������ ������ ���� �پ ��Ŀ '�Ƴ׸��'���� �Ƿڸ� �ִ´�" << endl << endl;
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
		ClearLineFromReadBuffer();
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
		if (p == 1) {
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
		if (p == 2) {
			if (m == 1) {
				fout.open("ch3_2p_p_mission.txt");//ch2_2p_p_mission.txt
			}
			else {
				fout.open("ch3_2p_l_mission.txt");//ch2_2p_l_mission.txt
			}
		}
		else if (p == 1) {
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
		if (p == 3) {
			fout.open("ch4_3p_p_mission.txt");//ch2_3p_p_mission.txt
		}
		else if (p == 2) {
			if (m == 1) {
				fout.open("ch4_2pl_p_mission.txt");//ch2_2pl_p_mission.txt
			}
			else {
				fout.open("ch4_2pl_l_mission.txt");//ch2_2pl_l_mission.txt
			}
		}
		else if (p == 1) {
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
			cout << "�丣�׺�ũ" << endl << endl << endl;
			cout << "\t�츮���� �Ƿڸ� �޾Ƶ鿩�༭ ����," << endl;
			cout << "\t ���� �󺣴Ͼư� �����ϰ� �� ���� ������ ����ٴ� ������ �������" << endl;
			cout << "\t�� ��ġ�� �˾Ƴ����� ���߳� �ڳװ� �� ������ ���׿��ְ�" << endl;
		}
		else {
			cout << "�󺣴Ͼ�" << endl << endl << endl;
			cout << "\t�ڳװ� �Ƿڸ� �޾Ƶ鿩 �ִ� ����ϱ�..." << endl;
			cout << "\t��Ʈ����ũ �� ���ﱤ ����� �츮�� ��ȭ�� �ٶ��ٰ� ���ؿ԰͸� �ᱹ ������ �����߾�." << endl;
			cout << "\t������ �־���. �츮 �Ƿڴ� �丣�׺�ũ ���� �α��� ���� â�� ��ġ�� �˾Ƴ������� �ϳ�. ��Ź�ϳ�" << endl;
		}
		break;
	case 1:
		if (p == 1) {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "\t�ٽ� �ѹ� �츮���� �Ƿڸ� �޾��༭ ����." << endl;
				cout << "\t�󺣴Ͼư� ���� ��ó �ҵ��� '����'�� ���ȭ �Ѵٴ� ����̱�." << endl;
				cout << "\t�̹� �Ƿڴ� '����' ���ȭ ��ȹ���� ���赵 �� ���ȭ�� ���õ� ��� ������ ������ְ�." << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t�Ŀ�...�ڳװ� �����̶� �츮 �Ƿڸ� �޾��ִٴ� ����." << endl;
				cout << "\t�̹� �˰������� �𸣰����� �츮�� ��з� ����� ���� ������ �ϼ����ڸ��� ������߳�." << endl;
				cout << "\t�׵��� ��� �˾Ƴ´��� �𸣰�����...�ϴ�, �츮�� �Ƿڴ� ��Ʈ����ũ�� ���� ��ǥ�� ���ݷθ� �˾ƿ��ְ�. �ε� ������ �ż��ϰ� �˾ƿ��ְ�" << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "\t���� �Ƿڴ� �����ϴ��� �̹����� �Ƿڸ� �޾��ִ±� ������ �ٲ���? �� �̷� �̾��ϱ�, ���� ����â�� ���ݰ� ��� ���ڱ� Ƣ��� ���� ������ ���� �� ������ ���� ���� ���� �����ΰ� �������� �ְŵ�," << endl;
				cout << "\t�Ƿڸ� ������ ������. �󺣴Ͼ��� ���� ��ġ ��Ȳ�� �̵� ��ȹ�� �˾ƿ��ְ�.. ������ ��Ȯ�ϸ� �����ž�" << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t�ڳ� ���п� �丣�׺�ũ��鿡�� ũ�� �ѹ� �Կ���, �����Ⱑ ���� �̹����� �Ƿڸ� ��Ź����" << endl;
				cout << "\t���޿� ������ ���� �丣�׺�ũ ����� ���� ���� ������ �˾ƿ��ְ�" << endl;
			}
		}
		break;
	case 2:
		if (p == 2) {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "\t�̹����� �Ƿڸ� ��Ź����" << endl;
				
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t�̹����� �Ƿڸ� ��Ź����" << endl;
			}
		}
		else if (p == 1) {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "\t�̹����� �Ƿڸ� ��Ź����" << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t�̹����� �Ƿڸ� ��Ź����" << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "\t�̹����� �Ƿڸ� ��Ź����" << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t�̹����� �Ƿڸ� ��Ź����" << endl;
			}
		}
		break;
	case 3:
		if (p == 3) {
			cout << "�丣�׺�ũ" << endl << endl << endl;
			cout << "\t�ڳ� ���п� ��� ������ ������Ű�� ���� ��� ������ �¸��� �� �־���. ��ǻ� ������ �츮�� �¸���." << endl;
			cout << "\t�̹��� ������ �Ƿڴ�. �̹� �Ƿڱ��� ������Ű�� �ڳ׿��� ���ڸ��� ����ϵ�������. ����ص� ����" << endl;
		}
		else if (p == 2) {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "\t�׶��� �� ũ�� ��߳��� �ս��� ������ �¸��� �� �־��µ�, ��Ȳ�� �þ�����" << endl;
				cout << "\t�׷��� �Ƿڸ� �ϵ�������. ��������� ���� ��Ȳ�� �츮 ������ Ȯ���ϰ� ������ �� �ִ� ������ �����ְ�" << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t�и��� �ִ� ��Ȳ���� �ڳװ� �� �� �Ƿڸ� �������� ���п� ��Ƽ�� ������ �̴�δ� �� �и� ���� ����" << endl;
				cout << "\t������ �Ұ����ϴ��� ��� �츮 ������ ��ã�ƿ;ߵǳ�. ��Ȳ�� ������ ��ŭ �׵鿡�� ġ������ ������ ���� �ְ�" << endl;
			}
		}
		else if (p == 1) {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "\t�츮�� �� ���￡�� �츮�� �и��� �ִٴ� �̺��� ġ�����ϼ� ����. �̷��ٰ� �丣�׺�ũ�� ��" << endl;
				cout << "\t��� ��Ȳ�� �ݹ����� ����� �丣�׺�ũ�� ���� �츮�� ������� ��⸦ �÷��ߵǳ�. �󺣴Ͼƿ��� ġ������ ������ ���� �ְ�" << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t�ڳ״��п� ��Ȳ�� �츮���� �������� �̴�� ������ �������� ����, �丣�׺�ũ �׵��� �ٽô� �󺣴ϾƸ� �Ѻ��� ���ϰ� �ؾ��ϳ� " << endl;
				cout << "\t�׷��� �Ƿڸ� �ϵ�������. ��������� ���� ��Ȳ�� �츮 ������ Ȯ���ϰ� ������ �� �ִ� ������ �����ְ�" << endl;
			}
		}
		else {
			cout << "�󺣴Ͼ�" << endl << endl << endl;
			cout << "\t�ڳ� ���п� �丣�׺�ũ����� �� ���￡�� ������ �츮�� �¸��� �յΰ� �丣�׺�ũ�� �����ų�� ��ȸ�� �յΰ� �ֳ�" << endl;
			cout << "\t��� ������ �ɰ� �Ƿڸ� �Ѱ����� �ڳװ� ������ ���� ���п� ū ���ؾ��� �� �� �־���." << endl;
			cout << "\t������ �Ƿ��ϼ�. �� �Ƿڰ� ������ �ڳ׸� �󺣴Ͼ��� �ͺ����� �ʴ��� �����̳� ����ϰ�" << endl;
		}
	}

	Sleep(5000);
}

void Game::print_clear_Story(int c, int p, int l, int m) {
	switch (c) {
	case 0:
		if (m == 1) {
			cout << "�丣�׺�ũ" << endl << endl << endl;
			cout << "\t����, �ڳ� ���п� �󺣴Ͼ� ����� ���� ������� ���� ���� ��ġ�� �˾Ƴ¾�. �� ����� �츮�� ���� ���� ��ġ�� �˾Ƴ��͵� ��ü �ų��� ������ ����� �ְ���..." << endl;
			cout << "\t�� �ϼ����� ���� �븮��... ��. �ƴҼ� �Ƿ� ������ �ڳ� ��а��·� �־����������..." << endl;

			cout << "���� ���� ����" << endl << endl << endl;
			cout << "\t�丣�׺�ũ�� ���� ���� �� �������� ������ ���۵Ǿ����ϴ�. �丣�׺�ũ�� ����� �󺣴Ͼ��� ������ �ѱ� ���������� �󺣴Ͼƴ� �������̶� �մϴ�..." << endl;
			cout << "\t�Ӻ��Դϴ�! �丣�׺�ũ�� �󺣴Ͼ��� ���� ��ó ���� ������ �߰��ϰ� ������״ٰ� �մϴ�..." << endl;
		}
		else {
			cout << "�󺣴Ͼ�" << endl << endl << endl;
			cout << "\t����, ���п� �丣�׺�ũ ����� ���� â�� �����ϰ� ����� �ĵ�� ���� �ð��� ���� �� �־���." << endl;
			cout << "\t�츮 ������� �丣�׺�ũ�� ���� ���� ��� �غ��صΰ� �־����� ���п� �ѽø� ���ҳ�. ������ �������ҳ�." << endl;

			cout << "���� ���� ����" << endl << endl << endl;
			cout << "\t�丣�׺�ũ�� ���� ���� �� �������� ������ ���۵Ǿ����ϴ�. ���� �丣�׺�ũ�� ������ ���� â�� �Ϻΰ� ���ݴ��ϸ鼭 �丣�׺�ũ�� ���� �ӵ��� ������ ���..." << endl;
		}
		break;
	case 1:
		if (p == 1) {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "\t���� �ڳ� ���п� '����'�� ������ �� �ſ� �����ϰھ�. �ڳװ� ���� ��Ŀ�� ���簡 �츮 �������� �־����� �󸶳� �������� �ͱ�." << endl;
				cout << "\t������ ����� �� ���� ���� ��������. ������ �� �����ϱ� �ٶ���." << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t�丣�׺�ũ-�󺣴Ͼ� ������ ��â ���̸� ���� �߿� ������ ���ȭ�� '����'�Դϴ�." << endl;
				cout << "\t���� ���������� �丣�׺�ũ�� ���ȭ�� '����'�� �մ� ���� ��ƴٰ� ����Ǿ����� �ǿܷ� �丣�׺�ũ�� ����� �ּ����� �սǷ� '����'�� ���� ���� ������ Ȯ�Ή�����..." << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t�̷��� ���� ������ ���� �ִٴ� ����ϱ�... ���п� ������ ���ﶧ �����ϰھ�." << endl;
				cout << "\t������ ���·� ���³�, �Ƹ� �ٽ� �ڳ׿��� �Ƿڸ� �� ���ɼ��� ����. �׶��� �ε� ���� ������ ���ֱ� �ٶ��..." << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t���� �ʹݺκ��� ���� ���� �ϳ��� �ı��Ǹ鼭 �丣�׺�ũ�� ������ ���� �ӵ��� ����ȭ�һ������� �󺣴Ͼ� ������ ���������� ����� �����ϸ鼭 �󺣴Ͼ��� ������ �и��� �ʰ� �ִٰ� �մϴ�." << endl << endl;

				cout << "��� : �丣�׺�ũ�� �ǽ��� �ϱ� �����մϴ�." << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "�̷��� ���� �˾ƿ��ִٴ�, Ȯ���� �Ƿ��� ����Ѱ� ����. ������ �غ��س���" << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t�����ϴ� �丣�׺�ũ ���� �������� �ٽ� ������ �����̱� �����ϸ鼭 �󺣴Ͼ� ������ ��ȿŸ�� �ְ� �ִٰ� �մϴ�." << endl << endl;

				cout << "��� : �󺣴Ͼư� �ǽ��� �ϱ� �����մϴ�." << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t������ ���·� ���³�, �������� ��Ź����" << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t�󺣴Ͼư� X �������� �������� ��Ƚ��ϴ�." << endl << endl;
			}
		}
		break;
	case 2:
		if (p == 2) {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "������ ����� �Ƿ��̱�. ������ �غ��س���" << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t�丣�׺�ũ�� X ������ ������Ű�� ��Ⱑ �ö����ϴ�." << endl << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t������ ���·� ���³�, �������� ��Ź����" << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t�󺣴Ͼư� X �������� �������� ��Ƚ��ϴ�." << endl << endl;

				cout << "��� : �丣�׺�ũ�� �ǽ��� �ϱ� �����մϴ�." << endl;
			}
		}
		else if (p == 1) {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "������ ����� �Ƿ��̱�. ������ �غ��س���" << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t�丣�׺�ũ�� X ������ ������Ű�� ��Ⱑ �ö����ϴ�." << endl << endl;

				cout << "��� : �󺣴Ͼư� ����� ����ϱ� �����մϴ�." << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t������ ���·� ���³�, �������� ��Ź����" << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t�󺣴Ͼư� X �������� �������� ��Ƚ��ϴ�." << endl << endl;

				cout << "��� : �丣�׺�ũ�� ����� ����ϱ� �����մϴ�." << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "����� �Ƿ��̱�. ������ �غ��س���" << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t�丣�׺�ũ�� X ������ ������Ű�� ��Ⱑ �ö����ϴ�." << endl << endl;

				cout << "��� : �󺣴Ͼư� ����� ����ϱ� �����մϴ�." << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t������ ���·� ���³�, �������� ��Ź����" << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t�󺣴Ͼư� X �������� �������� ��Ƚ��ϴ�." << endl << endl;
			}
		}
		break;
	case 3:
		if (p == 3) {
			cout << "�丣�׺�ũ" << endl << endl << endl;
			cout << "\t���� �丣�׺�ũ�� ������ �̷������. �󺣴ϾƸ� �����߾�. ���� ����� �����ؾ߰���" << endl;
			cout << "\t�� �츮����� ��ȭ�ϰ� �̹� �ڳ׸� ���� �ο� �Ƿ��� ������ �ִ� �������� �غ��ص׳�" << endl << endl << endl;

			cout << "���� ���� ����" << endl << endl << endl;
			cout << "\t�丣�׺�ũ�� �ᱹ �󺣴ϾƸ� �����Ű�� �� ���並 �����Ͽ����ϴ�. " << endl;
			cout << "\t���� �����׺�ũ�� �������� �����ϴ°� �ƴ��� ���� ���ε��� �Ҿ��� Ŀ���� �ֽ��ϴ�." << endl << endl;
		}
		else if (p == 2) {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "\t���п� ��Ȳ�� Ȯ���ϰ� �츮���� �پ���. ���ۿ� �̷��� ���� �ߴµ� ��� ������ �귯������..." << endl;
				cout << "\t�̴�� ���� �츮�� ���￡�� �¸��� Ȯ������. �ڳ� ���� Ŀ, �׸�ŭ Ŀ�ٶ� ������ �����׳�. ��������" << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t������ �ǵ��� �丣�׺�ũ�� ��� ��� �󺣴Ͼƿ��� �������� ������ ��û�ϰ� �ִٰ� �մϴ�." << endl << endl;

				cout << "�󺣴Ͼư� ����� �ຸ�� �˾�ë���ϴ�" << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t�ڳװ� �������� ���� ���п� �������� �¸��ϰ� �츮 ���並 ���Ǵ� ��ã�ƿԳ�." << endl;
				cout << "\t�̹��� �ڳ��� ���� ���� ū��ŭ ������ ��� ��������. Ư���� ������ ���� �� �����̴� ����ϰ�..." << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t�󺣴Ͼư� ���� �������� �︮�� ���� ������ 90% ������ ��� �� �ܿ��� ���鼭 ������ ���ȭ�� �� �ִٴ� �������� �Ǵ���..." << endl << endl;

				cout << "��� : �丣�׺�ũ�� ����� ����ϱ� �����մϴ�." << endl;
			}
		}
		else if (p == 1) {
			if (m == 1) {
				cout << "�丣�׺�ũ" << endl << endl << endl;
				cout << "\t�̹��� ������ ������ ����� ���並 �����߾�. ���п� ġ���� ���߱�" << endl;
				cout << "\t�̹��� �ڳ��� ���� ���� ū��ŭ ������ ��� ��������. Ư���� ������ ���� �� �����̴� ����ϰ�..." << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t�丣�׺�ũ�� �ٽ� ��⸦ �ø��� �з��ִ� ������ ������ �����ذ��� �����߽��ϴ�" << endl;
				cout << "\t�� �ܿ��� ���鼭 ������ ���ȭ�� �� �ִٴ� �������� �Ǵ���..." << endl << endl;

				cout << "��� : �󺣴Ͼư� ����� ����ϱ� �����մϴ�." << endl;
			}
			else {
				cout << "�󺣴Ͼ�" << endl << endl << endl;
				cout << "\t������ ���·� ���³�, �������� ��Ź����" << endl << endl << endl;

				cout << "���� ���� ����" << endl << endl << endl;
				cout << "\t�󺣴Ͼư� X �������� �������� ��Ƚ��ϴ�." << endl << endl;

				cout << "�丣�׺�ũ�� ����� �ຸ�� ��ġë���ϴ�." << endl;
			}
		}
		else {
			cout << "�󺣴Ͼ�" << endl << endl << endl;
			cout << "\t�ᱹ �丣�׺�ũ�� �츮�� �տ� ����߳�. ���� ����� ��ȭ�� ������ �� �ִµ� �׵� ������ ����� �����Ѱ���" << endl;
			cout << "\t�ڳ� �󺣴ϾƷ� ��ȭ�� ���� ����? �󺣴Ͼƴ� ������ �ڳװ��� ���縦 �ʿ�� �ϳ�." << endl;
			cout << "\t������ �̾߱�� ���� ���� ����ϵ��� ����. VIP �ʴ����� �ڳ׿��� ��������. �״� ���� ������ ���Ǵ� ��" << endl;

			cout << "���� ���� ����" << endl << endl << endl;
			cout << "\t�丣�׺�ũ�� �ڽŵ��� �������� �� �󺣴Ͼƿ��� ������߽��ϴ�. ���� �����δ� �󺣴Ͼƿ��� ���� ��å ���⿡ ����..." << endl << endl;
		}
	}

	Sleep(5000);
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

	cout << "p: " << P->Get_sd() << ",l: " << L->Get_sd() << endl;
	char keyPressed = _getch();


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
		else if (p == 2) {
			m = Choice_Mission();
			PCFP(chapter, p, l, m);
			if (m == 1) {
				P->sd_Plus();
			}
			else if (m == 2) {
				L->sd_Plus();
			}
		}
		else if (p == 1) {
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

void Game::Ending(int p) {
	switch (p) {
	case 0:
		//�󺣴Ͼ� ����
		cout << "\t�󺣴Ͼƿ� �������� �ɾ��� �丣�׺�ũ�� ������ �󺣴Ͼ��� �տ� ����� ���� �ɾ���." << endl;
		cout << "\t�󺣴Ͼ��� �¸��� ū �⿩�� '�Ƴ׸��'�� �ʴ�ް� �󺣴Ͼƿ��� ������ �ο� �Բ� ��ȭ�� ����������" << endl;
		cout << "\t'�Ƴ׸��'�� �̸� �����ϰ� �ͺ��� �������� ������ ���� '����'�� '�󺣴Ͼ�'������ �߿��� �ô´�" << endl;
		cout << "ending3(��ȭ�� �󺣴Ͼ�)" << endl << endl << endl;
		break;
	case 1:
		//bed ����2(�丣�׺�ũ�� ����)
		cout << "\t�丣�׺�ũ�� �󺣴Ͼ� ���̿��� ���� ���� �Ƿڸ� ������ '�Ƴ׸��'" << endl;
		cout << "\t�󺣴Ͼ� �Ƿڸ� �����ϴ� �ᱹ �丣�׺�ũ���� �׵��� ������ �󺣴Ͼƿ��� �� ���� ��Ű�� ����." << endl;
		cout << "\t�ڽ��� �ຸ�� ��Ų '�Ƴ׸��'�� �丣�׺�ũ�� ���� �ϻ��ڿ��� ����� �Ҵ´�." << endl;
		cout << "ending1(�丣�׺�ũ�� Į��)" << endl << endl << endl;
		break;
	case 2:
		// true ending
		cout << "\t�丣�׺�ũ�� �󺣴Ͼ� ���̿��� ���� ���� �Ƿڸ� ������ '�Ƴ׸��'" << endl;
		cout << "\t'�Ƴ׸��'�� �ǽ��ϴ� �� ������ �ᱹ '�Ƴ׸��'�� ���� ø������ �Ѵٴ� ���� ��ġæ��" << endl;
		cout << "\t�� ���� ��� '�Ƴ׸��'�� ������ڷ� �Ǵ�, �� ������ ���(�ϻ���)�� ���� ó���Ϸ� ������" << endl;
		cout << "\t���(�ϻ���)���� '�Ƴ׸��'�� ��ó�� �ĵ�����, �̹� '�Ƴ׸��'�� ���ݱ���  �޾Ҵ� ������ ì��� ������ ���߾���." << endl;
		cout << "\t'�Ƴ׸��'�� ���� ø�� �ൿ���� �� ������ ��� �±⸦ ���� ����ä ������ ����ȭ�Ǹ� �ܿ��� �ٰ����� ������ ������� �����Ѵ�." << endl;
		cout << "true ending" << endl << endl << endl;
		break;
	case 3:
		// bed ����1
		cout << "\t�丣�׺�ũ�� �󺣴Ͼ� ���̿��� ���� ���� �Ƿڸ� ������ '�Ƴ׸��'" << endl;
		cout << "\t�丣�׺�ũ �Ƿڸ� �����ϴ� �ᱹ �󺣴Ͼƿ��� �׵��� ������ �丣�׺�ũ���� �� ���� ��Ű�� ����." << endl;
		cout << "\t�ڽ��� �ຸ�� ��Ų '�Ƴ׸��'�� �󺣴Ͼư� ���� �ϻ��ڿ��� ����� �Ҵ´�." << endl;
		cout << "ending2(�󺣴Ͼ��� ����)" << endl << endl << endl;
		break;
	case 4:
		//�丣�׺�ũ ����
		cout << "\t�丣�׺�ũ�� �ٶ���� �󺣴ϾƸ� �����Ű�� �׵��� ���並 �����Ѵ�" << endl;
		cout << "\t�丣�׺�ũ�� �¸��� Ŀ�ٶ� �⿩���� '�Ƴ׸��'�� ���� ������ �ڷ���ä �丣�׺�ũ�� �����ϰ� �������� �ɴ´�" << endl;
		cout << "\t�󺣴ϾƸ� �����ϸ� ������ ������ ���� �丣�׺�ũ�� �߿��� ������ �ʰ� �������� �����ų���� �Ѵ�." << endl;
		cout << "ending4(ö���� �丣�׺�ũ)" << endl << endl << endl;
		break;
	}

	Sleep(5000);
	char keyPressed = _getch();
}

void Game::start() {
	Country Perteburk;
	Country Lavenia;

	prologue(); // ���ѷα�

	ready(); //�丣�׺�ũ�� �󺣴Ͼ� �Ƿ� ���� â�� �������� Ȯ��

	Proglation(&Perteburk, &Lavenia); // ���丮���� 1
	system("cls");
	Proglation(&Perteburk, &Lavenia); // ���丮���� 2
	system("cls");
	Proglation(&Perteburk, &Lavenia); // ���丮���� 3
	system("cls");
	Proglation(&Perteburk, &Lavenia); // ���丮���� 4
	system("cls");

	Ending(Perteburk.Get_sd());
}