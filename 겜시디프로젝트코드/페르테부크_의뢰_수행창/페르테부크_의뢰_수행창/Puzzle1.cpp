//미로찾기는 언제나 옳다 -202211083송태환

#include "Puzzle.h"
#include <iostream>
#include <vector>
#include <stdexcept>

class MazeEscape {
private:
    std::vector<std::string> maze;
    int playerX, playerY;
    bool isPuzzleSolved;

public:
    MazeEscape() {
        maze = {
            "###########",
            "#         #",
            "# ####### #",
            "#  #      #",
            "# #  ## # #",
            "# ##  ### #",
            "##      # #",
            "##### #####"
        };
        playerX = 1;
        playerY = 1;
        isPuzzleSolved = false;
    }

    void displayMaze() {
        system("cls");
        for (int i = 0; i < maze.size(); ++i) {
            for (int j = 0; j < maze[i].size(); ++j) {
                if (i == playerX && j == playerY) {
                    std::cout << "O";
                }
                else {
                    std::cout << maze[i][j];
                }
            }
            std::cout << std::endl;
        }
    }

    bool isSolved() {
        return isPuzzleSolved;
    }

    void movePlayer(char direction) {
        int newX = playerX, newY = playerY;
        if (direction == 'w') {
            newX--;
        }
        else if (direction == 's') {
            newX++;
        }
        else if (direction == 'a') {
            newY--;
        }
        else if (direction == 'd') {
            newY++;
        }

        if (newX >= 0 && newX < maze.size() && newY >= 0 && newY < maze[0].size() && maze[newX][newY] != '#') {
            playerX = newX;
            playerY = newY;

            if (playerX == 7 && playerY == 5) {
                std::cout << "미로를 탈출했습니다!" << std::endl;
                isPuzzleSolved = true;
            }
        }
    }

    void play() {
        char movement;
        while (!isSolved()) {
            displayMaze();
            std::cout << "움직일 방향을 선택하세요 (wasd): ";
            std::cin >> movement;

            movePlayer(movement);
        }
        isPuzzleSolved = true;

    }
};

void Puzzle1::solve() {
    if (!isSolved()) {
        std::cout << "퍼즐 1을 해결했습니다!" << std::endl;
    }
}

void Puzzle1::play() {
    if (!isSolved()) {
        MazeEscape game;
        game.play();
        if (game.isSolved()) {
            setSolved();
        }
        else {
            throw std::runtime_error("퍼즐 실패로 인한 프로그램 종료");
        }
    }
    else {
        std::cout << "이미 푼 퍼즐입니다!" << std::endl;
    }
}
