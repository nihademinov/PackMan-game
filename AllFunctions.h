#pragma once



char** createArr(int size) {
    char** area = new char* [size];
    for (int i = 0; i < size; i++)
    {
        area[i] = new char[size] {};
    }
    return area;
}



void show_score(char** area, int size) {
    system("cls");
    cout << "Your Score:" << score_count - winner_count << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << area[i][j] << " ";
        }
        cout << endl;
    }
}



void fill_arr(char** area, int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                area[i][j] = 220;
            }
            else {
                area[i][j] = ' ';
            }
        }
        cout << endl;
    }
}



void obstacle(char** area) {
    for (int i = 0; i < 12; i++) {
        int random_1 = 1 + rand() % 14;
        int random_2 = 1 + rand() % 14;
        if (area[random_1][random_2] == ' ' && area[random_1 + 2][random_2] == ' ' && area[random_1 + 1][random_2 + 1] && area[random_1 - 1][random_2] == ' ' && area[random_1][random_2 - 1] == ' ' && area[random_1][random_2 + 2] == ' ') {
            area[random_1][random_2] = '&';
            area[random_1 + 1][random_2] = '&';
            area[random_1 + 1][random_2 + 1] = '&';



        }
        else {
            i--;
        }
    }
}



void packmanSpan(char** area) {
    while (true)
    {
        int random = 1 + rand() % 16;
        int random_2 = 1 + rand() % 16;
        if (area[random][random_2] == ' ') {
            area[random][random_2] = 64;
            row = random;
            column = random_2;
            break;
        }
    }
}



void prices(char** area) {
    while (true) {
        int random_1 = 1 + rand() % 14;
        int random_2 = 1 + rand() % 14;
        if (area[random_1][random_2] == ' ' && area[random_1 + 1][random_2] == ' ' && area[random_1 + 1][random_2 + 1] == ' ' && area[random_1 - 1][random_2] == ' ' && area[random_1][random_2 - 1] == ' ' && area[random_1][random_2 + 2] == ' ' && area[random_1 + 2][random_2] == ' ') {
            area[random_1][random_2] = '*';
            break;
        }



    }



}



void left_func(char** area) {
    if (area[row][column - 1] == ' ') {
        area[row][column] = ' ';
        area[row][column - 1] = 64;
        column--;
    }
    else {
        if (area[row][column - 1] == '*') {
            area[row][column] = ' ';
            area[row][column - 1] = 64;
            column--;
            checkWin = true;
            winner_count--;
        }
        else {
            check = false;
        }
    }
}



void right_func(char** area) {
    if (area[row][column + 1] == ' ') {
        area[row][column] = ' ';
        area[row][column + 1] = 64;
        column++;
    }
    else {
        if (area[row][column + 1] == '*') {
            area[row][column] = ' ';
            area[row][column + 1] = 64;
            column++;
            checkWin = true;
            winner_count--;
        }
        else {
            check = false;
        }
    }
}



void down_func(char** area) {
    if (area[row + 1][column] == ' ') {
        area[row][column] = ' ';
        area[row + 1][column] = 64;
        row++;
    }
    else {
        if (area[row + 1][column] == '*') {
            area[row][column] = ' ';
            area[row + 1][column] = 64;
            row++;
            checkWin = true;
            winner_count--;
        }
        else {
            check = false;
        }
    }
}



void up_func(char** area) {
    if (area[row - 1][column] == ' ') {
        area[row][column] = ' ';
        area[row - 1][column] = 64;
        row--;
    }
    else {
        if (area[row - 1][column] == '*') {
            area[row][column] = ' ';
            area[row - 1][column] = 66;
            row--;
            checkWin = true;
            winner_count--;
        }
        else {
            check = false;
        }
    }
}
