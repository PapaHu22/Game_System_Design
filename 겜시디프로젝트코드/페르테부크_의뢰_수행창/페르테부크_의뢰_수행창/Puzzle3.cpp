#include "Puzzle.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void additionalFunction() {
    const string passwords[] = { "라베니아", "666", "아네모네" };
    const string hints[] = {
        "현재 해킹을 시도하려는 국가의 이름",
        "악마의 숫자",
        "해당 꽃의 이름 일부 발췌: 지중해 연안에 자생하는 미나리아재비과의 식물로, 4~5월이 되면 줄기마다 하나씩 지름 6~7cm의 꽃을 피운다. 꽃잎의 색은 붉은색, 흰색, 분홍색, 자주색, 노란색, 하늘색 등으로 다양하다."
    };

    ofstream hintFile("C:\\Documents\\Hint.txt");//위치 중요

    if (hintFile.is_open()) {
        for (int i = 0; i < 3; ++i) {
            hintFile << "[" << i + 1 << "번 hint]: " << hints[i] << "\n";
        }
        hintFile.close();
    }
    else {
        cout << "파일을 열 수 없습니다. 경로를 확인해주세요.\n";
    }

    string userInput;
    int attempts = 0;
    int miss = 0;

    while (attempts < 5) {
        cout << "암호를 입력하세요: ";
        cin >> userInput;

        if (miss >= 5) {
            cout << "5번 이상 틀리셨습니다. 실패!\n";
            break;
        }

        if (userInput == passwords[attempts]) {
            cout << attempts + 1 << "번 암호 확인!";
            attempts++;

            if (attempts == 3) {
                cout << " 축하합니다. 모든 암호를 맞추셨습니다!\n";
                cout << "이제 질문을 하실 수 있습니다.\n";

                while (true) {
                    cout << "무엇을 원하시나요? ('현재상황' 또는 '고위인사' 입력): ";
                    cin >> userInput;

                    if (userInput == "현재상황") {
                        cout << "현재 우리 국가는 광산을 만들고 있네요.\n";
                    }
                    else if (userInput == "고위인사") {
                        cout << "A는 현재 국회의사당, B는 집회실, C는 행방불명이다.\n";
                    }
                    else {
                        cout << "잘못된 입력입니다. 다시 입력하세요.\n";
                        continue;
                    }

                    cout << "더 필요한 정보가 있나요? (yes/no): ";
                    cin >> userInput;

                    if (userInput == "no") {
                        break;
                    }
                    else if (userInput == "yes") {
                        continue;
                    }
                    else
                    {
                        cout << "네/아니오로만 대답해주세요" << endl;
                    }
                }
                break;
            }
        }
        else {
            cout << "암호가 틀렸거나 순서가 틀렸습니다. 다시 입력하세요.\n";
            miss++;
        }
    }

}

void Puzzle3::play() {
    if (!isSolved()) {
        additionalFunction();
        setSolved();
    }
    else {
        std::cout << "이미 푼 퍼즐입니다!" << std::endl;
    }
}

void Puzzle3::solve() {
    if (!isSolved()) {
        std::cout << "퍼즐 3을 해결했습니다!" << std::endl;
    }
}
