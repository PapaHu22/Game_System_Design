#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include "Puzzle.h"

// E 키 입력을 감지하는 스레드 함수
void CheckForKeyInput(int& eCount, bool& escape) {
    while (!escape) {
        for (int i = 0; i < 256; ++i) {
            if (GetAsyncKeyState(i) & 0x8000) {
                if (i == 'E') {
                    eCount++; // E 키 입력이면 카운트 증가
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// 퍼즐 해킹 시뮬레이션 함수
void Hack(bool& escape) {
    int eCount = 0;
    int bombTimer = 60; // 1분 타이머
    const int maxECount = 100;
    bool puzzleSolved = false; // 퍼즐 완료 여부 플래그

    // E 키 입력을 감지하는 스레드
    std::thread keyThread(CheckForKeyInput, std::ref(eCount), std::ref(escape));

    while (bombTimer > 0 && eCount < maxECount && !escape) {
        system("cls"); // 화면 지우기

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

        std::cout << "남은 시간: " << bombTimer << "초" << std::endl;
        std::cout << "E 누른 횟수: " << eCount << std::endl;

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

    // 입력 버퍼 비우기
    INPUT_RECORD inRec;
    DWORD numRead;
    while (PeekConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &inRec, 1, &numRead) && numRead) {
        ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &inRec, 1, &numRead);
    }

    // 스레드 탈출
    if (keyThread.joinable()) {
        escape = true; // 탈출을 위해 escape 플래그 설정
        keyThread.join(); // 스레드 종료 대기
    }

    // 퍼즐 해결 결과 출력
    if (puzzleSolved) {
        std::cout << "폭탄 해체 성공!" << std::endl;
    }
    else {
        if (!escape) {
            std::cout << "시간 초과! 폭탄이 터졌어요!" << std::endl;
        }
    }
}

// 퍼즐 플레이 함수
void Puzzle4::play() {
    if (!isSolved()) {
        bool escape = false; // 탈출 플래그
        Hack(escape);
        std::cout << "미션 종료" << std::endl;
        setSolved(); // 퍼즐 해결 표시
        std::cout << "다음으로 진행하려면 엔터 키를 누르세요." << std::endl;
        std::cin.ignore(); // 엔터 키 입력 대기
    }
    else {
        std::cout << "이미 푼 퍼즐입니다!" << std::endl;
    }
}

// 퍼즐 솔브 함수
void Puzzle4::solve() {
    if (!isSolved()) {
        std::cout << "퍼즐 4 해결했습니다!" << std::endl;
    }
}
