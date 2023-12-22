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
	cout << "프롤로그" << endl << endl << endl;
	cout << "\t1년전 '페르테부크'의 알루시아 공주가 '라베니아'에서 테러 당해 죽은" << endl;
	cout << "\t'알루시아 공주 테러 살해 사건'을 명분으로 '페르테부크'의 선전포고를 한다" << endl << endl;
	cout << "....다음(아무키 입력)" << endl << endl << endl;
	//print_Line();
	char keyPressed = _getch();
	system("cls");
	//print_Line();
	cout << "프롤로그" << endl << endl << endl;
	cout << "\t중립군 르벤(Reven) 출신의 뛰어난 실력을 가진 해커 이명 '아네모네'" << endl;
	cout << "\t현시점 전쟁 중인 두 국가는 서로의 기밀 정보를 빼오기 위해 뛰어난 해커 '아네모네'에게 의뢰를 넣는다" << endl << endl;
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
		ClearLineFromReadBuffer();
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
			cout << "페르테부크" << endl << endl << endl;
			cout << "\t우리들의 의뢰를 받아들여줘서 고맙네," << endl;
			cout << "\t 현재 라베니아가 은밀하게 새 전진 기지를 만든다는 정보을 얻었으나" << endl;
			cout << "\t그 위치를 알아내지는 못했네 자네가 그 정보를 빼네와주게" << endl;
		}
		else {
			cout << "라베니아" << endl << endl << endl;
			cout << "\t자네가 의뢰를 받아들여 주니 든든하군..." << endl;
			cout << "\t페트레부크 이 전쟁광 놈들이 우리는 평화를 바란다고 말해왔것만 결국 전쟁을 선포했어." << endl;
			cout << "\t서론이 있었군. 우리 의뢰는 페르테부크 국경 부근의 군수 창고 위치를 알아내줬으면 하네. 부탁하네" << endl;
		}
		break;
	case 1:
		if (p == 1) {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "\t다시 한번 우리들의 의뢰를 받아줘서 고맙네." << endl;
				cout << "\t라베니아가 국경 근처 소도시 '스모르'를 요새화 한다는 모양이군." << endl;
				cout << "\t이번 의뢰는 '스모르' 요새화 계획도나 설계도 등 요새화와 관련된 기밀 정보를 갖고와주게." << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t후우...자네가 지금이라도 우리 의뢰를 받아주다니 고맙네." << endl;
				cout << "\t이미 알고있을지 모르겠지만 우리가 비밀로 만들던 전진 기지가 완성되자마자 괴멸당했네." << endl;
				cout << "\t그들이 어떻게 알아냈는지 모르겠지만...일단, 우리의 의뢰는 페트레부크의 공격 목표와 공격로를 알아와주게. 부디 빠르고 신속하게 알아와주게" << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "\t저번 의뢰는 거절하더니 이번에는 의뢰를 받아주는군 마음이 바꼈나? 아 이런 미안하군, 지금 군수창고 포격과 어디서 갑자기 튀어나온 전진 기지에 당한 거 때문에 나를 포함 군부 상층부가 예민해져 있거든," << endl;
				cout << "\t의뢰만 빠르게 말하지. 라베니아의 군대 배치 현황과 이동 계획을 알아와주게.. 빠르고 정확하면 좋을거야" << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t자네 덕분에 페르테부크놈들에게 크게 한방 먹였어, 분위기가 좋아 이번에도 의뢰를 부탁하지" << endl;
				cout << "\t보급에 영향이 생긴 페르테부크 놈들의 다음 작전 지령을 알아와주게" << endl;
			}
		}
		break;
	case 2:
		if (p == 2) {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "\t이번에도 의뢰를 부탁하지" << endl;
				
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t이번에도 의뢰를 부탁하지" << endl;
			}
		}
		else if (p == 1) {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "\t이번에도 의뢰를 부탁하지" << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t이번에도 의뢰를 부탁하지" << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "\t이번에도 의뢰를 부탁하지" << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t이번에도 의뢰를 부탁하지" << endl;
			}
		}
		break;
	case 3:
		if (p == 3) {
			cout << "페르테부크" << endl << endl << endl;
			cout << "\t자네 덕분에 모든 작전을 성공시키고 거의 모든 전투를 승리할 수 있었어. 사실상 전쟁은 우리의 승리네." << endl;
			cout << "\t이번이 마지막 의뢰다. 이번 의뢰까지 성공시키면 자네에게 한자리를 약속하도록하지. 기대해도 좋네" << endl;
		}
		else if (p == 2) {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "\t그때한 번 크게 어긋나서 손쉽게 전쟁을 승리할 수 있었는데, 전황이 늘어졌어" << endl;
				cout << "\t그래서 의뢰를 하도록하지. 어느정보든 좋네 전황을 우리 쪽으로 확실하게 가져올 수 있는 정보를 얻어와주게" << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t밀리고 있는 상황에서 자네가 한 번 의뢰를 수행해준 덕분에 버티고 있지만 이대로는 더 밀릴 수는 없네" << endl;
				cout << "\t역전은 불가능하더라도 적어도 우리 영토은 되찾아와야되네. 상황이 안좋은 만큼 그들에게 치명적인 정보를 얻어와 주게" << endl;
			}
		}
		else if (p == 1) {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "\t우리가 건 전쟁에서 우리가 밀리고 있다니 이보다 치욕적일수 없어. 이러다간 페르테부크의 국" << endl;
				cout << "\t적어도 전황을 반반으로 만들어 페르테부크의 명예를 살리고 군사들의 사기를 올려야되네. 라베니아에게 치명적인 정보를 얻어와 주게" << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t자네덕분에 전황이 우리에게 기울었지만 이대로 전쟁을 끝낼수는 없지, 페르테부크 그들이 다시는 라베니아를 넘보지 못하게 해야하네 " << endl;
				cout << "\t그래서 의뢰를 하도록하지. 어느정보든 좋네 전황을 우리 쪽으로 확실하게 가져올 수 있는 정보를 얻어와주게" << endl;
			}
		}
		else {
			cout << "라베니아" << endl << endl << endl;
			cout << "\t자네 덕분에 페르테부크놈들이 건 전쟁에서 역으로 우리가 승리를 앞두고 페르테부크를 멸망시킬수 기회를 앞두고 있네" << endl;
			cout << "\t비록 보상을 걸고 의뢰를 한거지만 자네가 얻어와준 정보 덕분에 큰 피해없이 올 수 있었네." << endl;
			cout << "\t마지막 의뢰일세. 이 의뢰가 끝나면 자네를 라베니아의 귀빈으로 초대할 예정이네 기대하게" << endl;
		}
	}

	Sleep(5000);
}

void Game::print_clear_Story(int c, int p, int l, int m) {
	switch (c) {
	case 0:
		if (m == 1) {
			cout << "페르테부크" << endl << endl << endl;
			cout << "\t고맙네, 자네 덕분에 라베니아 놈들의 새로 만들어질 전진 기지 위치를 알아냈어. 그 놈들은 우리가 전진 기지 위치를 알아낸것도 모른체 신나게 기지를 만들고 있겠지..." << endl;
			cout << "\t다 완성됐을 때를 노리면... 아. 아닐세 의뢰 보상은 자네 비밀계좌로 넣어놓도록하지..." << endl;

			cout << "르벤 국제 뉴스" << endl << endl << endl;
			cout << "\t페르테부크가 선전 포고 후 본격적인 전쟁이 시작되었습니다. 페르테부크의 군대는 라베니아의 국경을 넘기 시작했으면 라베니아는 저항중이라 합니다..." << endl;
			cout << "\t속보입니다! 페르테부크가 라베니아의 국경 근처 전진 기지를 발견하고 괴멸시켰다고 합니다..." << endl;
		}
		else {
			cout << "라베니아" << endl << endl << endl;
			cout << "\t고맙네, 덕분에 페르테부크 놈들의 군수 창고를 포격하고 놈들이 쳐들어 오는 시간을 줄일 수 있었어." << endl;
			cout << "\t우리 나름대로 페르테부크를 막기 위해 방비를 준비해두고 있었지만 덕분에 한시름 놓았네. 보상은 보내놓았네." << endl;

			cout << "르벤 국제 뉴스" << endl << endl << endl;
			cout << "\t페르테부크가 선전 포고 후 본격적인 전쟁이 시작되었습니다. 현재 페르테부크의 전방의 군수 창고 일부가 포격당하면서 페르테부크의 전진 속도가 늦춰진 가운데..." << endl;
		}
		break;
	case 1:
		if (p == 1) {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "\t고맙군 자네 덕분에 '스모르'를 공략할 때 매우 유용하겠어. 자네가 같은 해커의 귀재가 우리 국가에도 있었으면 얼마나 좋았을까 싶군." << endl;
				cout << "\t보상은 약속한 것 보다 많이 보내놨네. 다음에 또 연락하길 바라지." << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t페르테부크-라베니아 전쟁은 한창 중이며 현재 중요 전선은 요새화된 '스모르'입니다." << endl;
				cout << "\t현재 전문가들은 페르테부크도 요새화된 '스모르'를 뚫는 것은 어렵다고 예상되었으나 의외로 페르테부크의 군대는 최소한의 손실로 '스모르'를 공략 중인 것으로 확인됬으며..." << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t이렇게 빨리 정보를 얻어와 주다니 대단하군... 덕분에 작전을 세울때 유용하겠어." << endl;
				cout << "\t보상은 게좌로 보냈네, 아마 다시 자네에게 의뢰를 할 가능성이 높네. 그때도 부디 좋은 선택을 해주길 바라네..." << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t전쟁 초반부부터 전진 기지 하나가 파괴되면서 페르테부크의 군대의 전진 속도가 가속화할뻔했지만 라베니아 군대의 적재적소의 기습이 성공하면서 라베니아의 전선이 밀리지 않고 있다고 합니다." << endl << endl;

				cout << "경고 : 페르테부크가 의심을 하기 시작합니다." << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "이렇게 빨리 알아와주다니, 확실히 실력은 대단한것 같군. 보상은 준비해놓지" << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t주춤하던 페르테부크 군의 움직임이 다시 빠르게 움직이기 시작하면서 라베니아 군에게 유효타를 넣고 있다고 합니다." << endl << endl;

				cout << "경고 : 라베니아가 의심을 하기 시작합니다." << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t보상은 게좌로 보냈네, 다음에도 부탁하지" << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t라베니아가 X 전투에서 승전보를 울렸습니다." << endl << endl;
			}
		}
		break;
	case 2:
		if (p == 2) {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "여전히 대단한 실력이군. 보상은 준비해놓지" << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t페르테부크가 X 작전을 성공시키고 사기가 올랐습니다." << endl << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t보상은 게좌로 보냈네, 다음에도 부탁하지" << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t라베니아가 X 전투에서 승전보를 울렸습니다." << endl << endl;

				cout << "경고 : 페르테부크가 의심을 하기 시작합니다." << endl;
			}
		}
		else if (p == 1) {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "여전히 대단한 실력이군. 보상은 준비해놓지" << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t페르테부크가 X 작전을 성공시키고 사기가 올랐습니다." << endl << endl;

				cout << "경고 : 라베니아가 당신을 경계하기 시작합니다." << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t보상은 게좌로 보냈네, 다음에도 부탁하지" << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t라베니아가 X 전투에서 승전보를 울렸습니다." << endl << endl;

				cout << "경고 : 페르테부크가 당신을 경계하기 시작합니다." << endl;
			}
		}
		else {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "대단한 실력이군. 보상은 준비해놓지" << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t페르테부크가 X 작전을 성공시키고 사기가 올랐습니다." << endl << endl;

				cout << "경고 : 라베니아가 당신을 경계하기 시작합니다." << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t보상은 게좌로 보냈네, 다음에도 부탁하지" << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t라베니아가 X 전투에서 승전보를 울렸습니다." << endl << endl;
			}
		}
		break;
	case 3:
		if (p == 3) {
			cout << "페르테부크" << endl << endl << endl;
			cout << "\t드디어 페르테부크의 염원이 이루어졌네. 라베니아를 점령했어. 이제 약속을 이행해야겠지" << endl;
			cout << "\t자 우리나라로 귀화하게 이미 자네를 위한 부와 권력을 누릴수 있는 고위직을 준비해뒀네" << endl << endl << endl;

			cout << "르벤 국제 뉴스" << endl << endl << endl;
			cout << "\t페르테부크가 결국 라베니아를 멸망시키고 그 영토를 차지하였습니다. " << endl;
			cout << "\t현재 프르테부크가 르벤까지 공격하는건 아닌지 르벤 국민들의 불안이 커지고 있습니다." << endl << endl;
		}
		else if (p == 2) {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "\t덕분에 전황이 확실하게 우리쪽을 붙었군. 진작에 이렇게 됬어야 했는데 어디서 정보가 흘러갔는지..." << endl;
				cout << "\t이대로 가면 우리가 전쟁에서 승리가 확실하지. 자네 공이 커, 그만큼 커다란 보상을 보내뒀네. 잘지내게" << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t전쟁의 판도가 페르테부크로 기운 가운데 라베니아에서 르벤에게 지원을 요청하고 있다고 합니다." << endl << endl;

				cout << "라베니아가 당신의 행보를 알아챘습니다" << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t자네가 가져와준 정보 덕분에 전투에서 승리하고 우리 영토를 거의다 되찾아왔네." << endl;
				cout << "\t이번에 자네의 공이 정말 큰만큼 보상을 배로 보내놨네. 특별한 선물도 같이 갈 예정이니 기대하게..." << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t라베니아가 여러 승전보를 울리며 원래 영토의 90% 수복한 가운데 곧 겨울이 오면서 전쟁이 장기화될 수 있다는 전문가의 판단이..." << endl << endl;

				cout << "경고 : 페르테부크가 당신을 경계하기 시작합니다." << endl;
			}
		}
		else if (p == 1) {
			if (m == 1) {
				cout << "페르테부크" << endl << endl << endl;
				cout << "\t이번에 얻어와준 정보로 뺏겼던 영토를 수복했어. 덕분에 치욕은 면했군" << endl;
				cout << "\t이번에 자네의 공이 정말 큰만큼 보상을 배로 보내놨네. 특별한 선물도 같이 갈 예정이니 기대하게..." << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t페르테부크가 다시 사기를 올리며 밀려있던 전선을 빠르게 복구해가기 시작했습니다" << endl;
				cout << "\t곧 겨울이 오면서 전쟁이 장기화될 수 있다는 전문가의 판단이..." << endl << endl;

				cout << "경고 : 라베니아가 당신을 경계하기 시작합니다." << endl;
			}
			else {
				cout << "라베니아" << endl << endl << endl;
				cout << "\t보상은 게좌로 보냈네, 다음에도 부탁하지" << endl << endl << endl;

				cout << "르벤 국제 뉴스" << endl << endl << endl;
				cout << "\t라베니아가 X 전투에서 승전보를 울렸습니다." << endl << endl;

				cout << "페르테부크가 당신의 행보를 눈치챘습니다." << endl;
			}
		}
		else {
			cout << "라베니아" << endl << endl << endl;
			cout << "\t결국 페르테부크가 우리의 손에 멸망했네. 같이 손잡고 평화를 유지할 수 있는데 그들 스스로 멸망을 자초한거지" << endl;
			cout << "\t자네 라베니아로 귀화할 생각 없나? 라베니아는 언제나 자네같은 인재를 필요로 하네." << endl;
			cout << "\t나머지 이야기는 얼굴을 보고 얘기하도록 하지. VIP 초대장을 자네에게 보내놨네. 그대 얼굴을 볼날이 기대되는 군" << endl;

			cout << "르벤 국제 뉴스" << endl << endl << endl;
			cout << "\t페르테부크는 자신들이 선전포고를 한 라베니아에게 멸망당했습니다. 르벤 수뇌부는 라베니아와의 교역 정책 방향에 대해..." << endl << endl;
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
		cout << "오류" << endl;
	}
	

	chapter++;
}

void Game::Ending(int p) {
	switch (p) {
	case 0:
		//라베니아 엔딩
		cout << "\t라베니아에 선전포고를 걸었던 페르테부크는 오히려 라베니아의 손에 멸망의 길을 걸었다." << endl;
		cout << "\t라베니아의 승리에 큰 기여를 '아네모네'는 초대받고간 라베니아에서 막대한 부와 함꼐 귀화를 권유했지만" << endl;
		cout << "\t'아네모네'는 이를 거절하고 귀빈의 직위만을 받으며 향후 '르벤'과 '라베니아'교역의 중역을 맡는다" << endl;
		cout << "ending3(평화의 라베니아)" << endl << endl << endl;
		break;
	case 1:
		//bed 엔딩2(페르테부크의 복수)
		cout << "\t페르테부크와 라베니아 사이에서 간을 보며 의뢰를 수행한 '아네모네'" << endl;
		cout << "\t라베니아 의뢰를 수행하다 결국 페르테부크에게 그들의 정보를 라베니아에게 판 것을 들키고 만다." << endl;
		cout << "\t자신의 행보를 들킨 '아네모네'는 페르테부크가 보낸 암살자에게 목숨을 잃는다." << endl;
		cout << "ending1(페르테부크의 칼날)" << endl << endl << endl;
		break;
	case 2:
		// true ending
		cout << "\t페르테부크와 라베니아 사이에서 간을 보며 의뢰를 수행한 '아네모네'" << endl;
		cout << "\t'아네모네'를 의심하던 두 국가는 결국 '아네모네'가 이중 첩자짓을 한다는 것을 눈치챈다" << endl;
		cout << "\t두 국가 모두 '아네모네'를 위험분자로 판단, 각 국가의 요원(암살자)를 보내 처리하려 했으나" << endl;
		cout << "\t요원(암살자)들이 '아네모네'의 거처를 쳐들어갔을때, 이미 '아네모네'는 지금까지  받았던 보상을 챙기고 종적을 감추었다." << endl;
		cout << "\t'아네모네'의 이중 첩자 행동으로 두 국가의 모두 승기를 잡지 못한채 전선은 고착화되며 겨울이 다가오며 전쟁은 장기전에 돌입한다." << endl;
		cout << "true ending" << endl << endl << endl;
		break;
	case 3:
		// bed 엔딩1
		cout << "\t페르테부크와 라베니아 사이에서 간을 보며 의뢰를 수행한 '아네모네'" << endl;
		cout << "\t페르테부크 의뢰를 수행하다 결국 라베니아에게 그들의 정보를 페르테부크에게 판 것을 들키고 만다." << endl;
		cout << "\t자신의 행보를 들킨 '아네모네'는 라베니아가 보낸 암살자에게 목숨을 잃는다." << endl;
		cout << "ending2(라베니아의 가시)" << endl << endl << endl;
		break;
	case 4:
		//페르테부크 엔딩
		cout << "\t페르테부크는 바람대로 라베니아를 멸망시키며 그들의 영토를 차지한다" << endl;
		cout << "\t페르테부크의 승리에 커다란 기여를한 '아네모네'는 조국 르벤을 뒤로한채 페르테부크로 귀하하고 고위직에 앉는다" << endl;
		cout << "\t라베니아를 차지하며 막대한 이익을 얻은 페르테부크는 야욕을 멈추지 않고 르벤까지 집어삼킬려고 한다." << endl;
		cout << "ending4(철혈의 페르테부크)" << endl << endl << endl;
		break;
	}

	Sleep(5000);
	char keyPressed = _getch();
}

void Game::start() {
	Country Perteburk;
	Country Lavenia;

	prologue(); // 프롤로그

	ready(); //페르테부크와 라베니아 의뢰 수행 창이 켜졌는지 확인

	Proglation(&Perteburk, &Lavenia); // 스토리진행 1
	system("cls");
	Proglation(&Perteburk, &Lavenia); // 스토리진행 2
	system("cls");
	Proglation(&Perteburk, &Lavenia); // 스토리진행 3
	system("cls");
	Proglation(&Perteburk, &Lavenia); // 스토리진행 4
	system("cls");

	Ending(Perteburk.Get_sd());
}