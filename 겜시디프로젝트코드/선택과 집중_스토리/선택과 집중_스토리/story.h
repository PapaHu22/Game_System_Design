#pragma once

class Game {
	int chapter;
	int retry_Num; //�絵�� Ƚ��
public:
	Game(int c = 0, int r = 0) { chapter = c; retry_Num = r; }
	void ready();
	void start();//���� ����
	void prologue(); //���ѷα�
	void Proglation(struct Country* P,  struct Country* L); //���丮 ����
	void Create_Mission_File(int c, int p, int l, int m); // �̼� ���� ����
	void Find_Clear_File(int ch);
	int Choice_Mission(); // �̼� ����
	void Ending(); // ����
	void Epilogue(); // ���ʷα�
	void print_Line(); // �� �߱�
	void print_Story(int c, int p, int l, int m); // ���丮 ���
	void print_clear_Story(int c, int p, int l, int m); // �Ƿ� ���� �� ���丮 ���
	void PCFP(int c, int p, int l, int m);
};

class Country {
	int selected;
public:
	Country(int a = 0) { selected = a; }
	int Get_sd();
	void sd_Plus();
};