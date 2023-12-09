#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include "Puzzle.h"

// E Ű �Է��� �����ϴ� ������ �Լ�
void CheckForKeyInput(int& eCount, bool& escape) {
    while (!escape) {
        for (int i = 0; i < 256; ++i) {
            if (GetAsyncKeyState(i) & 0x8000) {
                if (i == 'E') {
                    eCount++; // E Ű �Է��̸� ī��Ʈ ����
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// ���� ��ŷ �ùķ��̼� �Լ�
void Hack(bool& escape) {
    int eCount = 0;
    int bombTimer = 60; // 1�� Ÿ�̸�
    const int maxECount = 100;
    bool puzzleSolved = false; // ���� �Ϸ� ���� �÷���

    // E Ű �Է��� �����ϴ� ������
    std::thread keyThread(CheckForKeyInput, std::ref(eCount), std::ref(escape));

    while (bombTimer > 0 && eCount < maxECount && !escape) {
        system("cls"); // ȭ�� �����

        std::cout << R"(
  +-----------------+
  |  .------.       |
  | |        |      |
  | |  .-""""-.    |
  | |  |      |    |
  | |  '-....-'    |
  | |              |
  | '--------------' 
  +-----------------+
)" << std::endl;

        std::cout << "���� �ð�: " << bombTimer << "��" << std::endl;
        std::cout << "E ���� Ƚ��: " << eCount << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        bombTimer--;

        if (eCount >= maxECount) {
            puzzleSolved = true;
            break;
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            escape = true;
        }
    }

    system("cls");

    // �Է� ���� ����
    INPUT_RECORD inRec;
    DWORD numRead;
    while (PeekConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &inRec, 1, &numRead) && numRead) {
        ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &inRec, 1, &numRead);
    }

    // ������ Ż��
    if (keyThread.joinable()) {
        escape = true; // Ż���� ���� escape �÷��� ����
        keyThread.join(); // ������ ���� ���
    }

    // ���� �ذ� ��� ���
    if (puzzleSolved) {
        std::cout << "��ź ��ü ����!" << std::endl;
    }
    else {
        if (!escape) {
            std::cout << "�ð� �ʰ�! ��ź�� �������!" << std::endl;
        }
    }
}

// ���� �÷��� �Լ�
void Puzzle4::play() {
    if (!isSolved()) {
        bool escape = false; // Ż�� �÷���
        Hack(escape);
        std::cout << "�̼� ����" << std::endl;
        setSolved(); // ���� �ذ� ǥ��
        std::cout << "�������� �����Ϸ��� ���� Ű�� ��������." << std::endl;
        std::cin.ignore(); // ���� Ű �Է� ���
    }
    else {
        std::cout << "�̹� Ǭ �����Դϴ�!" << std::endl;
    }
}

// ���� �ֺ� �Լ�
void Puzzle4::solve() {
    if (!isSolved()) {
        std::cout << "���� 4 �ذ��߽��ϴ�!" << std::endl;
    }
}
