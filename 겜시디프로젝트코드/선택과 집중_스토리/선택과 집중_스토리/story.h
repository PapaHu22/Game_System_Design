#pragma once

class Game {
	int chapter;
	int retry_Num; //재도전 횟수
public:
	Game(int c = 0, int r = 0) { chapter = c; retry_Num = r; }
	void ready();
	void start();//게임 시작
	void prologue(); //프롤로그
	void Proglation(struct Country* P,  struct Country* L); //스토리 진행
	void Create_Mission_File(int c, int p, int l, int m); // 미션 파일 생성
	void Find_Clear_File(int ch);
	int Choice_Mission(); // 미션 선택
	void Ending(); // 엔딩
	void Epilogue(); // 에필로그
	void print_Line(); // 선 긋기
	void print_Story(int c, int p, int l, int m); // 스토리 출력
	void print_clear_Story(int c, int p, int l, int m); // 의뢰 수행 후 스토리 출력
	void PCFP(int c, int p, int l, int m);
};

class Country {
	int selected;
public:
	Country(int a = 0) { selected = a; }
	int Get_sd();
	void sd_Plus();
};