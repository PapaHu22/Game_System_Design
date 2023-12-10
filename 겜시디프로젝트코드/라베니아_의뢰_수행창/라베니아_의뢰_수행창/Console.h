#pragma once

class Console {
	int reTry;
public:
	Console(int a = 0) { reTry = a; };
	void Open();
	void Wait();
	int Find_File(int ch, int p, int l);
	void Puzzle(int ch);
	void create_Clear_File(int ch, int p, int l);

};

