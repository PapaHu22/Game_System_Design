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
		cout << "의뢰 수행을 위한 콘솔이 준비되었는지 확인합니다." << endl;

		fin1.open("./P_Console_check.txt");
		fin2.open("./L_Console_check.txt");

		Sleep(1000);
		

		if (!fin1) {
			cout << "페르테부크 의뢰 수행용 콘솔이 켜지지 않았습니다" << endl;
		}
		else {
			fin1_check = true;
		}

		if (!fin2) {
			cout << "라베니아 의뢰 수행용 콘솔이 켜지지 않았습니다" << endl;
		}
		else {
			fin2_check = true;
		}

		Sleep(1000);

		if (fin1_check && fin2_check) {
			cout << "준비가 완료되었습니다" << endl;
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
	cout << "\t\t프롤로그" << endl << endl << endl;
	cout << "\t\t1년전 '페르테부크'의 알루시아 공주가 '라베니아'에서 테러 당해 죽은" << endl;
	cout << "\t\t'알루시아 공주 테러 살해 사건'을 명분으로 '페르테부크'의 선전포고를 한다" << endl << endl;
	cout << "....다음(아무키 입력)" << endl << endl << endl;
	//print_Line();
	char keyPressed = _getch();
	system("cls");
	//print_Line();
	cout << "\t\t프롤로그" << endl << endl << endl;
	cout << "중립군 르벤(Reven) 출신의 뛰어난 실력을 가진 해커 이명 '시카'" << endl;
	cout << "현시점 전쟁 중인 두 국가는 서로의 기밀 정보를 빼오기 위해 뛰어난 해커 '시카'에게 의뢰를 넣는다" << endl << endl;
	cout << "....다음(아무키 입력)" << endl << endl << endl;
	//print_Line();
	keyPressed = _getch();
	system("cls");
}

int Game::Choice_Mission() {
	int m;
	//print_Line();
	cout << "의뢰 선택" << endl;
	cout << "페르테부크와 라베니아 두 국가에서 의뢰가 들어왔다" << endl;;
	cout << "어느 국가 의뢰를 수행할까? 페르테부크(1) or 라베니아(2) >> ";
	while (true) {
		cin >> m;
		if (m == 1 || m == 2) {
			break;
		}
		else {
			cout << "잘못된 입력입니다. 다시 입력해주세요 >> ";
		}
	}

	if (m == 1) {
		cout << "페르테부크의 의뢰를 선택했다" << endl;
	}
	else {
		cout << "라베니아의 의뢰를 선택했다" << endl;
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
		cout << "파일생성 오류";
		break;
	}

	if (!fout) {
		cout << "파일생성 오류";
	}

	fout.close();
}

void Game::print_Story(int c , int p, int l, int m) {
	switch (c) {
	case 0:
		if (m == 1) {
			cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
			cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
		}
		else {
			cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
			cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
		}
		break;
	case 1:
		if (p == 1 && l == 0) {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		break;
	case 2:
		if (p == 2 && l == 0) {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		else if (p == 1 && l == 1) {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		break;
	case 3:
		if (p == 3) {
			cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
			cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
		}
		else if (p == 2 && l == 1) {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		else if (p == 1 && l == 2) {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		else {
			cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
			cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
		}
	}
}

void Game::print_clear_Story(int c, int p, int l, int m) {
	switch (c) {
	case 0:
		if (m == 1) {
			cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
			cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
		}
		else {
			cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
			cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
		}
		break;
	case 1:
		if (p == 1 && l == 0) {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		break;
	case 2:
		if (p == 2 && l == 0) {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		else if (p == 1 && l == 1) {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		break;
	case 3:
		if (p == 3) {
			cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
			cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
		}
		else if (p == 2 && l == 1) {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		else if (p == 1 && l == 2) {
			if (m == 1) {
				cout << "우리들의 의뢰를 받아들여줘서 고맙네, 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
				cout << "그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
			}
			else {
				cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
				cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
			}
		}
		else {
			cout << "자네가 의뢰를 받아들여 주니 든든하군.. 페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
			cout << "서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
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
				cout << "아직 의뢰를 완료하지 않았습니다." << endl;
			}
			else {
				clear_check = true;
			}
			break;
		case 1:
			fin.open("./ch2_clear");
			if (!fin) {
				cout << "아직 의뢰를 완료하지 않았습니다." << endl;
			}
			else {
				clear_check = true;
			}
			break;
		case 2:
			fin.open("./ch3_clear");
			if (!fin) {
				cout << "아직 의뢰를 완료하지 않았습니다." << endl;
			}
			else {
				clear_check = true;
			}
			break;
		case 3:
			fin.open("./ch4_clear");
			if (!fin) {
				cout << "아직 의뢰를 완료하지 않았습니다." << endl;
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
	print_Story(chapter, p, l, m); // 스토리
	char keyPressed = _getch();
	Create_Mission_File(chapter, p, l, m); // 의뢰 파일 만들기
	Find_Clear_File(chapter); // 클리어 파일 찾기
	print_clear_Story(chapter, p, l, m);// 완료 후 스토리
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
		cout << "오류" << endl;
	}
	

	chapter++;
}

void Game::start() {
	Country Perteburk;
	Country Lavenia;

	prologue(); // 프롤로그

	ready(); //페르테부크와 라베니아 의뢰 수행 창이 켜졌는지 확인

	Proglation(&Perteburk, &Lavenia); // 스토리진행 1
	Proglation(&Perteburk, &Lavenia); // 스토리진행 2
	Proglation(&Perteburk, &Lavenia); // 스토리진행 3
	Proglation(&Perteburk, &Lavenia); // 스토리진행 4


}