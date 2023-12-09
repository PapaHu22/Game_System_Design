#include "Puzzle.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void additionalFunction() {
    const string passwords[] = { "�󺣴Ͼ�", "666", "�Ƴ׸��" };
    const string hints[] = {
        "���� ��ŷ�� �õ��Ϸ��� ������ �̸�",
        "�Ǹ��� ����",
        "�ش� ���� �̸� �Ϻ� ����: ������ ���ȿ� �ڻ��ϴ� �̳����������� �Ĺ���, 4~5���� �Ǹ� �ٱ⸶�� �ϳ��� ���� 6~7cm�� ���� �ǿ��. ������ ���� ������, ���, ��ȫ��, ���ֻ�, �����, �ϴû� ������ �پ��ϴ�."
    };

    ofstream hintFile("C:\\Documents\\Hint.txt");//��ġ �߿�

    if (hintFile.is_open()) {
        for (int i = 0; i < 3; ++i) {
            hintFile << "[" << i + 1 << "�� hint]: " << hints[i] << "\n";
        }
        hintFile.close();
    }
    else {
        cout << "������ �� �� �����ϴ�. ��θ� Ȯ�����ּ���.\n";
    }

    string userInput;
    int attempts = 0;
    int miss = 0;

    while (attempts < 5) {
        cout << "��ȣ�� �Է��ϼ���: ";
        cin >> userInput;

        if (miss >= 5) {
            cout << "5�� �̻� Ʋ���̽��ϴ�. ����!\n";
            break;
        }

        if (userInput == passwords[attempts]) {
            cout << attempts + 1 << "�� ��ȣ Ȯ��!";
            attempts++;

            if (attempts == 3) {
                cout << " �����մϴ�. ��� ��ȣ�� ���߼̽��ϴ�!\n";
                cout << "���� ������ �Ͻ� �� �ֽ��ϴ�.\n";

                while (true) {
                    cout << "������ ���Ͻó���? ('�����Ȳ' �Ǵ� '�����λ�' �Է�): ";
                    cin >> userInput;

                    if (userInput == "�����Ȳ") {
                        cout << "���� �츮 ������ ������ ����� �ֳ׿�.\n";
                    }
                    else if (userInput == "�����λ�") {
                        cout << "A�� ���� ��ȸ�ǻ��, B�� ��ȸ��, C�� ���Ҹ��̴�.\n";
                    }
                    else {
                        cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n";
                        continue;
                    }

                    cout << "�� �ʿ��� ������ �ֳ���? (yes/no): ";
                    cin >> userInput;

                    if (userInput == "no") {
                        break;
                    }
                    else if (userInput == "yes") {
                        continue;
                    }
                    else
                    {
                        cout << "��/�ƴϿ��θ� ������ּ���" << endl;
                    }
                }
                break;
            }
        }
        else {
            cout << "��ȣ�� Ʋ�Ȱų� ������ Ʋ�Ƚ��ϴ�. �ٽ� �Է��ϼ���.\n";
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
        std::cout << "�̹� Ǭ �����Դϴ�!" << std::endl;
    }
}

void Puzzle3::solve() {
    if (!isSolved()) {
        std::cout << "���� 3�� �ذ��߽��ϴ�!" << std::endl;
    }
}
