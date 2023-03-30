#include<iostream>
using namespace std;
#include<conio.h>

int row = 0;
int column = 0;
bool check = true;
bool checkWin = true;
int winner_count = 0;
int score_count = 0;

#include "AllFunctions.h"


void main() {
    while (true) {
        cout << "Score: " << endl;
        cin >> winner_count;
        if (!(1 <= winner_count && winner_count <= 10)) {
            cout << "ERROR" << endl;
        }
        else {
            break;
        }
    }
    score_count = winner_count;
    srand(time(nullptr));
    int size = 17;
    char** area = createArr(size);
    fill_arr(area, size);
    obstacle(area);
    packmanSpan(area);
    show_score(area, size);
    int number;
    while (check) {
        if (winner_count == 0) {
            cout << "WON)";
            break;
        }
        number = _getch();
        if (checkWin) {
            prices(area);
        }
        checkWin = false;



        switch (number) {
        case 224:
            number = _getch();
            switch (number) {
            case 72:
                up_func(area);

                show_score(area, size);
                break;
            case 77:
                right_func(area);
                show_score(area, size);
                break;
            case 75:
                left_func(area);
                show_score(area, size);
                break;
            case 80:
                down_func(area);
                show_score(area, size);
            default:
                break;
            }
            break;
        default:
            cout << "Other Symbol" << endl;
            break;
        }

    }
    if (check == false) {
        cout << "Lose(" << endl;
        cout << "GAme Over" << endl;
    }

}