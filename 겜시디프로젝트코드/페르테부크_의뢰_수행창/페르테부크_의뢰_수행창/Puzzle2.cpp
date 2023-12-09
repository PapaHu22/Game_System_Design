// 뱀뱀뱀뱀뱀 - 202211083송태환
#include "Puzzle.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

bool HackFail;
static const int width = 20;
static const int height = 20;
int x, y, KeyX, KeyY, SuccesRate;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Setup() {
    HackFail = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    SuccesRate = 0;
    KeyX = rand() % width;
    KeyY = rand() % height;
}

void Draw() {
    system("cls");
    for (int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#";
            }
            if (i == y && j == x) {
                SetColor(10);
                cout << "0";
                SetColor(15);
            }
            else if (i == KeyY && j == KeyX) {

                SetColor(12);
                cout << "K";
                SetColor(15);
            }
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        SetColor(10);
                        cout << "o";
                        SetColor(15);
                        print = true;
                    }
                }
                if (!print) {
                    cout << " ";
                }

            }

            if (j == width - 1) {
                cout << "#";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;
    cout << "해킹성공까지: " << 100 - SuccesRate << "%" << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'p':
            HackFail = true;
            break;
        }
    }
}

void Logic() {

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x > width || x<0 || y>height || y < 0) {
        HackFail = true;
    }
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            HackFail = true;
    }
    if (x == KeyX && y == KeyY) {

        SuccesRate += 10;
        KeyX = rand() % (width - 1);
        KeyY = rand() % (height - 1);
        nTail++;
    }
}

void Puzzle2::play() {
    if (!isSolved()) {
        Setup();
        while (!HackFail && (SuccesRate < 100)) {
            Draw();
            Input();
            Logic();
            Sleep(100);
        }
        Draw();
        if (SuccesRate >= 100) {
            Puzzle2::setSolved();
        }
        else {
            exit(1);
            //또는 메인 가서 미션 실패 반환해야함
        }
    }
    else {
        std::cout << "이미 푼 퍼즐입니다!" << std::endl;
    }
}

void Puzzle2::solve() {
    if (!isSolved()) {
        std::cout << "퍼즐 2을 해결했습니다!" << std::endl;
    }
}