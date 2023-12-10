#pragma once
#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;

class Findtext {
	string str;
	string ra;
public:
	const char* FileScan();
	void InputAnswer();
	void Answer();
};

class Draw_art {
	int c;
	int num = 0;
	int key[4] = { 5,6,7,8 };
public:
	//Draw_art();
	void Restart();
	const char* FileScan();
	void InputAnswer();
	void Answer();
};

class Scan_img : public Draw_art {
	int k;
	int a;
	int check_num = 0;
	bool ischeck_num = false;
	string str;
	string la;
public:
	//Scan_img();
	const char* FileScan();
	void InputAnswer();
	void Answer();
	void Restart();
	void Check_Sol();
	int End_puzzle(bool ischeck_num);
};

int d_puzzle1();
int d_puzzle2();