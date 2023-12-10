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
		const char* file = "C:\\Users\\doo71\\OneDrive\\문서\\GitHub\\Game_System_Design\\겜시디프로젝트코드\\duream\\txt_fold\\d_puzzle1.txt";
		ifstream fin(file);
		if (!fin) {
			cout << file << "열기 오류" << endl;
			return 0;
		}

		while ((c = fin.get()) != EOF) {
			cout << (char)c;
		}
		fin.close();
	}
	void InputAnswer() {
		cout << "다음 아스키 아트를 보고 떠오르는 생각을 보기 숫자에서 찾아서 숫자를 입력하십시오.[(1-수뭉이잖아?!?!, 2-사슴, 3-다빈치, 4-내가 이걸 왜 알아야 하지?) 중 하나 입력]" << endl;
		cout << "입력 : ";
		cin >> c;
	}
	void Answer() {
		if (c == 1) {
			cout << "<수뭉이잖아?!?!> 를 고르셨군요! 정말 현명한 선택이에요~~" << endl;
			cout << "현명한 선택을 하신 분께 현명한 보상을 드리겠습니다." << endl;
			cout << "첫 번째와 네 번째 비밀번호는 " << key[0] << "와" << key[3] << "입니다." << endl;
			cout << "그리고 두 번째와 세 번째 숫자는 당신이 잘 알고 있는 숫자입니다." << endl;
			
		}
		else if (c == 2) {
			cout << "<사슴> 을 고르셨군요! 정말 탁월한 선택이에요~~" << endl;
			cout << "그렇지만 틀렸습니다. 비밀번호를 얻고 싶으시다면 다시 도전하십시오. " << endl;
			Restart();
		}
		else if (c == 3) {
			cout << "<다빈치> 를 고르셨군요! 정말 탁월한 선택이에요~~" << endl;
			cout << "그렇지만 틀렸습니다. 비밀번호를 얻고 싶으시다면 다시 도전하십시오. " << endl;
			Restart();
		}
		else if (c == 4) {
			cout << "<내가 이걸 왜 알아야 하지?> 를 고르셨군요! 정말 정확한 선택이에요~~" << endl;
			cout << " 정확한 답을 고르신 분께 특별한 보상을 드리겠습니다. " << endl;
			cout << " 이 퍼즐의 답인 비밀번호는 5678 입니다. " << endl;
			
		}
		else {
			cout << "잘못 입력하셨습니다. 입력값을 확인해주시기 바랍니다." << endl;
			Restart();
		}
	}
	
};

void Draw_art::Restart() {
	cout << "다시 도전을 하실 준비가 되셨다면 숫자 1을 입력해주시기 바랍니다. 도전을 포기하시겠다면 숫자 2를 입력해주시기 바랍니다." << endl;
	cout << "입력 : ";
	cin >> num;
	if (num == 1) {
		InputAnswer();
		Answer();
	}
	else if(num==2) {
		cout << "도전을 포기합니다." << endl;
		
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
		cout << "폴더에 생성된 txt파일을 열어 안에 있는 퀴즈의 정답을 입력하시오." << endl;
		str = "페르테부크의 적대국 이름은?";
		ofstream fout("C:\\Users\\doo71\\OneDrive\\바탕 화면\\겜시디_팀플\\what_is_nation_name.txt");

		if (!fout) {
			cout << "" << endl;
			return 0;
		}
		fout << str << endl;

		fout.close();
		/*const char* srcfile = "C:\\Users\\doo71\\OneDrive\\바탕 화면\\세계관.png";
		const char* destfile = "C:\\Users\\doo71\\OneDrive\\바탕 화면\\페르테부크의 적대국 이름은?.png";

		cout << "폴더 내에서 복사된 이미지 파일을 찾으십시오." << endl;

		ifstream fsrc(srcfile, ios::in | ios::binary);
		if (!fsrc) {
			cout << srcfile << " 열기 오류 " << endl;
			return 0;
		}

		ofstream fdest(destfile, ios::out | ios::binary);
		if (!fdest) {
			cout << destfile << " 열기 오류 " << endl;
			return 0;
		}

		
		while ((k = fsrc.get()) != EOF) {
			fdest.put(k);
		}

		fsrc.close();
		fdest.close();*/
	}
	void InputAnswer() {
		cout << "txt 파일의 퀴즈는 두 번째와 세 번째 비밀번호를 얻기 위한 퀴즈입니다." << endl;
		cout << "퀴즈의 정답을 입력하십시오." << endl;
		cout << "입력 : ";
		cin >> la;
	}
	void Answer() {
		if (la == "라베니아") {
			cout << "정답입니다!" << endl;
			cout << "두 번째와 세 번째 비밀번호는 6과 7 입니다." << endl;
		}
		else {
			cout << "틀렸습니다!" << endl;
			cout << "비밀번호를 얻고 싶으시다면 다시 도전하십시오." << endl;
			Restart();
		}
	}
	void Restart() {
		cout << "다시 도전을 하실 준비가 되셨다면 숫자 1을 입력해주시기 바랍니다. 도전을 포기하시겠다면 숫자 2를 입력해주시기 바랍니다." << endl;
		cout << "입력 : ";
		cin >> a;
		if (a == 1) {
			InputAnswer();
			Answer();
		}
		else if (a == 2){
			cout << "도전을 포기합니다." << endl;
		}
	}
	void Check_Sol();
	int End_puzzle(bool ischeck_num);
};

void Scan_img::Check_Sol() {
	while (!ischeck_num) {
		cout << "비밀번호를 입력하십시오." << endl;
		cout << "입력 : ";
		cin >> check_num;
		if (check_num == 5678) {
			cout << "정답입니다!" << endl;
			ischeck_num = true;
			End_puzzle(ischeck_num);
		}
		else {
			cout << "틀렸습니다!" << endl;
			cout << "다시 입력해주시기 바랍니다." << endl;
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

		cout << "퍼즐을 시작하시겠습니까?(시작하려면 숫자 1 입력" << endl;
		cout << "입력 : ";
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