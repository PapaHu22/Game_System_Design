#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;

class Draw_art {
	int c;
	int num = 0;
	int key[4] = { 5,6,7,8 };
public:
	//Draw_art();
	void Restart();
	const char* FileScan() {
		const char* file = "C:\\Users\\doo71\\OneDrive\\����\\GitHub\\Game_System_Design\\�׽õ�������Ʈ�ڵ�\\duream\\txt_fold\\d_puzzle1.txt";
		ifstream fin(file);
		if (!fin) {
			cout << file << "���� ����" << endl;
			return 0;
		}

		while ((c = fin.get()) != EOF) {
			cout << (char)c;
		}
		fin.close();
	}
	void InputAnswer() {
		cout << "���� �ƽ�Ű ��Ʈ�� ���� �������� ������ ���� ���ڿ��� ã�Ƽ� ���ڸ� �Է��Ͻʽÿ�.[(1-�������ݾ�?!?!, 2-�罿, 3-�ٺ�ġ, 4-���� �̰� �� �˾ƾ� ����?) �� �ϳ� �Է�]" << endl;
		cout << "�Է� : ";
		cin >> c;
	}
	void Answer() {
		if (c == 1) {
			cout << "<�������ݾ�?!?!> �� ���̱���! ���� ������ �����̿���~~" << endl;
			cout << "������ ������ �Ͻ� �в� ������ ������ �帮�ڽ��ϴ�." << endl;
			cout << "ù ��°�� �� ��° ��й�ȣ�� " << key[0] << "��" << key[3] << "�Դϴ�." << endl;
			cout << "�׸��� �� ��°�� �� ��° ���ڴ� ����� �� �˰� �ִ� �����Դϴ�." << endl;
			
		}
		else if (c == 2) {
			cout << "<�罿> �� ���̱���! ���� Ź���� �����̿���~~" << endl;
			cout << "�׷����� Ʋ�Ƚ��ϴ�. ��й�ȣ�� ��� �����ôٸ� �ٽ� �����Ͻʽÿ�. " << endl;
			Restart();
		}
		else if (c == 3) {
			cout << "<�ٺ�ġ> �� ���̱���! ���� Ź���� �����̿���~~" << endl;
			cout << "�׷����� Ʋ�Ƚ��ϴ�. ��й�ȣ�� ��� �����ôٸ� �ٽ� �����Ͻʽÿ�. " << endl;
			Restart();
		}
		else if (c == 4) {
			cout << "<���� �̰� �� �˾ƾ� ����?> �� ���̱���! ���� ��Ȯ�� �����̿���~~" << endl;
			cout << " ��Ȯ�� ���� ���� �в� Ư���� ������ �帮�ڽ��ϴ�. " << endl;
			cout << " �� ������ ���� ��й�ȣ�� 5678 �Դϴ�. " << endl;
			
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�. �Է°��� Ȯ�����ֽñ� �ٶ��ϴ�." << endl;
			Restart();
		}
	}
	
};

void Draw_art::Restart() {
	cout << "�ٽ� ������ �Ͻ� �غ� �Ǽ̴ٸ� ���� 1�� �Է����ֽñ� �ٶ��ϴ�. ������ �����Ͻðڴٸ� ���� 2�� �Է����ֽñ� �ٶ��ϴ�." << endl;
	cout << "�Է� : ";
	cin >> num;
	if (num == 1) {
		InputAnswer();
		Answer();
	}
	else if(num==2) {
		cout << "������ �����մϴ�." << endl;
		
	}
}

class Scan_img : public Draw_art {
	int k;
	int a;
	int check_num = 0;
	bool ischeck_num = false;
	string str;
	string la;
public:
	//Scan_img();
	const char* FileScan() {
		cout << "������ ������ txt������ ���� �ȿ� �ִ� ������ ������ �Է��Ͻÿ�." << endl;
		str = "�丣�׺�ũ�� ���뱹 �̸���?";
		ofstream fout("C:\\Users\\doo71\\OneDrive\\���� ȭ��\\�׽õ�_����\\what_is_nation_name.txt");

		if (!fout) {
			cout << "" << endl;
			return 0;
		}
		fout << str << endl;

		fout.close();
		/*const char* srcfile = "C:\\Users\\doo71\\OneDrive\\���� ȭ��\\�����.png";
		const char* destfile = "C:\\Users\\doo71\\OneDrive\\���� ȭ��\\�丣�׺�ũ�� ���뱹 �̸���?.png";

		cout << "���� ������ ����� �̹��� ������ ã���ʽÿ�." << endl;

		ifstream fsrc(srcfile, ios::in | ios::binary);
		if (!fsrc) {
			cout << srcfile << " ���� ���� " << endl;
			return 0;
		}

		ofstream fdest(destfile, ios::out | ios::binary);
		if (!fdest) {
			cout << destfile << " ���� ���� " << endl;
			return 0;
		}

		
		while ((k = fsrc.get()) != EOF) {
			fdest.put(k);
		}

		fsrc.close();
		fdest.close();*/
	}
	void InputAnswer() {
		cout << "txt ������ ����� �� ��°�� �� ��° ��й�ȣ�� ��� ���� �����Դϴ�." << endl;
		cout << "������ ������ �Է��Ͻʽÿ�." << endl;
		cout << "�Է� : ";
		cin >> la;
	}
	void Answer() {
		if (la == "�󺣴Ͼ�") {
			cout << "�����Դϴ�!" << endl;
			cout << "�� ��°�� �� ��° ��й�ȣ�� 6�� 7 �Դϴ�." << endl;
		}
		else {
			cout << "Ʋ�Ƚ��ϴ�!" << endl;
			cout << "��й�ȣ�� ��� �����ôٸ� �ٽ� �����Ͻʽÿ�." << endl;
			Restart();
		}
	}
	void Restart() {
		cout << "�ٽ� ������ �Ͻ� �غ� �Ǽ̴ٸ� ���� 1�� �Է����ֽñ� �ٶ��ϴ�. ������ �����Ͻðڴٸ� ���� 2�� �Է����ֽñ� �ٶ��ϴ�." << endl;
		cout << "�Է� : ";
		cin >> a;
		if (a == 1) {
			InputAnswer();
			Answer();
		}
		else if (a == 2){
			cout << "������ �����մϴ�." << endl;
		}
	}
	void Check_Sol();
	int End_puzzle(bool ischeck_num);
};

void Scan_img::Check_Sol() {
	while (!ischeck_num) {
		cout << "��й�ȣ�� �Է��Ͻʽÿ�." << endl;
		cout << "�Է� : ";
		cin >> check_num;
		if (check_num == 5678) {
			cout << "�����Դϴ�!" << endl;
			ischeck_num = true;
			End_puzzle(ischeck_num);
		}
		else {
			cout << "Ʋ�Ƚ��ϴ�!" << endl;
			cout << "�ٽ� �Է����ֽñ� �ٶ��ϴ�." << endl;
		}
	}
}

int Scan_img::End_puzzle(bool ischeck_num) {
	if (ischeck_num) {
		return 0;
	}
}


int d_puzzle1() {

	int choice;
	bool playAgain = true;

	while (playAgain) {

		cout << "������ �����Ͻðڽ��ϱ�?(�����Ϸ��� ���� 1 �Է�" << endl;
		cout << "�Է� : ";
		cin >> choice;

		if (choice == 1) {
			Draw_art artGame;
			artGame.FileScan();
			artGame.InputAnswer();
			artGame.Answer();

			Scan_img imgGame;
			imgGame.FileScan();
			imgGame.InputAnswer();
			imgGame.Answer();
			imgGame.Check_Sol();

		}

		

		return 0;
	}
}