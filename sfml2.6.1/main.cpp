#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace sf;

void updatepole(int**& pole, const int rows, const int cols, int N, int maxcolor)
{
    int count = 0;
    bool** dataArr = new bool* [rows];
    for (int i = 0; i < rows; i++)
    {
        dataArr[i] = new bool[cols];
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            dataArr[i][j] = false;
            if (i == 0)
            {
                if (j == 0)
                {
                    if (pole[i][j] + 1 == pole[i + 1][j] || pole[i][j] + 1 - maxcolor == pole[i + 1][j])
                        count++;
                    if (pole[i][j] + 1 == pole[i][j + 1] || pole[i][j] + 1 - maxcolor == pole[i][j + 1])
                        count++;
                    if (pole[i][j] + 1 == pole[i + 1][j + 1] || pole[i][j] + 1 - maxcolor == pole[i + 1][j + 1])
                        count++;
                    if (count >= N)
                    {
                        dataArr[i][j] = true;
                    }
                    count = 0;
                }
                else if (j == cols - 1)
                {
                    if (pole[i][j] + 1 == pole[i + 1][j] || pole[i][j] + 1 - maxcolor == pole[i + 1][j])
                        count++;
                    if (pole[i][j] + 1 == pole[i][j - 1] || pole[i][j] + 1 - maxcolor == pole[i][j - 1])
                        count++;
                    if (pole[i][j] + 1 == pole[i + 1][j - 1] || pole[i][j] + 1 - maxcolor == pole[i + 1][j - 1])
                        count++;
                    if (count >= N)
                    {
                        dataArr[i][j] = true;
                    }
                    count = 0;
                }
                else
                {
                    if (pole[i][j] + 1 == pole[i][j + 1] || pole[i][j] + 1 - maxcolor == pole[i][j + 1])
                        count++;
                    if (pole[i][j] + 1 == pole[i][j - 1] || pole[i][j] + 1 - maxcolor == pole[i][j - 1])
                        count++;
                    if (pole[i][j] + 1 == pole[i + 1][j] || pole[i][j] + 1 - maxcolor == pole[i + 1][j])
                        count++;
                    if (pole[i][j] + 1 == pole[i + 1][j + 1] || pole[i][j] + 1 - maxcolor == pole[i + 1][j + 1])
                        count++;
                    if (pole[i][j] + 1 == pole[i + 1][j - 1] || pole[i][j] + 1 - maxcolor == pole[i + 1][j - 1])
                        count++;
                    if (count >= N)
                    {
                        dataArr[i][j] = true;
                    }
                    count = 0;
                }


            }
            else if (i == rows - 1)
            {
                if (j == 0)
                {
                    if (pole[i][j] + 1 == pole[i - 1][j] || pole[i][j] + 1 - maxcolor == pole[i - 1][j])
                        count++;
                    if (pole[i][j] + 1 == pole[i][j + 1] || pole[i][j] + 1 - maxcolor == pole[i][j + 1])
                        count++;
                    if (pole[i][j] + 1 == pole[i - 1][j + 1] || pole[i][j] + 1 - maxcolor == pole[i - 1][j + 1])
                        count++;
                    if (count >= N)
                    {
                        dataArr[i][j] = true;
                    }
                    count = 0;
                }
                else if (j == cols - 1)
                {
                    if (pole[i][j] + 1 == pole[i - 1][j] || pole[i][j] + 1 - maxcolor == pole[i - 1][j])
                        count++;
                    if (pole[i][j] + 1 == pole[i][j - 1] || pole[i][j] + 1 - maxcolor == pole[i][j - 1])
                        count++;
                    if (pole[i][j] + 1 == pole[i - 1][j - 1] || pole[i][j] + 1 - maxcolor == pole[i - 1][j - 1])
                        count++;
                    if (count >= N)
                    {
                        dataArr[i][j] = true;
                    }
                    count = 0;
                }
                else
                {
                    if (pole[i][j] + 1 == pole[i][j + 1] || pole[i][j] + 1 - maxcolor == pole[i][j + 1])
                        count++;
                    if (pole[i][j] + 1 == pole[i][j - 1] || pole[i][j] + 1 - maxcolor == pole[i][j - 1])
                        count++;
                    if (pole[i][j] + 1 == pole[i - 1][j] || pole[i][j] + 1 - maxcolor == pole[i - 1][j])
                        count++;
                    if (pole[i][j] + 1 == pole[i - 1][j + 1] || pole[i][j] + 1 - maxcolor == pole[i - 1][j + 1])
                        count++;
                    if (pole[i][j] + 1 == pole[i - 1][j - 1] || pole[i][j] + 1 - maxcolor == pole[i - 1][j - 1])
                        count++;
                    if (count >= N)
                    {
                        dataArr[i][j] = true;
                    }
                    count = 0;
                }
            }
            else if (j == 0)
            {
                if (pole[i][j] + 1 == pole[i - 1][j] || pole[i][j] + 1 - maxcolor == pole[i - 1][j])
                    count++;
                if (pole[i][j] + 1 == pole[i - 1][j + 1] || pole[i][j] + 1 - maxcolor == pole[i - 1][j + 1])
                    count++;
                if (pole[i][j] + 1 == pole[i][j + 1] || pole[i][j] + 1 - maxcolor == pole[i][j + 1])
                    count++;
                if (pole[i][j] + 1 == pole[i + 1][j] || pole[i][j] + 1 - maxcolor == pole[i + 1][j])
                    count++;
                if (pole[i][j] + 1 == pole[i + 1][j + 1] || pole[i][j] + 1 - maxcolor == pole[i + 1][j + 1])
                    count++;
                if (count >= N)
                {
                    dataArr[i][j] = true;
                }
                count = 0;
            }
            else if (j == cols - 1)
            {
                if (pole[i][j] + 1 == pole[i - 1][j] || pole[i][j] + 1 - maxcolor == pole[i - 1][j])
                    count++;
                if (pole[i][j] + 1 == pole[i - 1][j - 1] || pole[i][j] + 1 - maxcolor == pole[i - 1][j - 1])
                    count++;
                if (pole[i][j] + 1 == pole[i][j - 1] || pole[i][j] + 1 - maxcolor == pole[i][j - 1])
                    count++;
                if (pole[i][j] + 1 == pole[i + 1][j] || pole[i][j] + 1 - maxcolor == pole[i + 1][j])
                    count++;

                if (pole[i][j] + 1 == pole[i + 1][j - 1] || pole[i][j] + 1 - maxcolor == pole[i + 1][j - 1])
                    count++;
                if (count >= N)
                {
                    dataArr[i][j] = true;
                }
                count = 0;
            }
            else
            {
                if (pole[i][j] + 1 == pole[i - 1][j] || pole[i][j] + 1 - maxcolor == pole[i - 1][j])
                    count++;
                if (pole[i][j] + 1 == pole[i - 1][j - 1] || pole[i][j] + 1 - maxcolor == pole[i - 1][j - 1])
                    count++;
                if (pole[i][j] + 1 == pole[i - 1][j + 1] || pole[i][j] + 1 - maxcolor == pole[i - 1][j + 1])
                    count++;
                if (pole[i][j] + 1 == pole[i][j - 1] || pole[i][j] + 1 - maxcolor == pole[i][j - 1])
                    count++;
                if (pole[i][j] + 1 == pole[i][j + 1] || pole[i][j] + 1 - maxcolor == pole[i][j + 1])
                    count++;
                if (pole[i][j] + 1 == pole[i + 1][j] || pole[i][j] + 1 - maxcolor == pole[i + 1][j])
                    count++;
                if (pole[i][j] + 1 == pole[i + 1][j - 1] || pole[i][j] + 1 - maxcolor == pole[i + 1][j - 1])
                    count++;
                if (pole[i][j] + 1 == pole[i + 1][j + 1] || pole[i][j] + 1 - maxcolor == pole[i + 1][j + 1])
                    count++;
                if (count >= N)
                {
                    dataArr[i][j] = true;
                }
                count = 0;
            }
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (dataArr[i][j])
            {
                if (pole[i][j] == maxcolor)
                    pole[i][j] = 0;
                pole[i][j] = pole[i][j] + 1;
            }
        }
    }

    for (int i = 0; i < rows; i++)
        delete[] dataArr[i];
    delete[] dataArr;
}

int main()
{
    int rows, cols, squarpole, N;
    cout << "Виберіть розмір клітин (1 - малі, 2 - середні, 3 - великі): ";
    cin >> squarpole;
    switch (squarpole) {
    case 1:
        squarpole = 20;
#ifndef DEBUG
        rows = 40;
        cols = 60;
#endif
        break;
    case 2:
        squarpole = 30;
#ifndef DEBUG
        rows = 30;
        cols = 40;
#endif
        break;
    case 3:
        squarpole = 40;
#ifndef DEBUG
        rows = 20;
        cols = 30;
#endif
        break;
    default:
        squarpole = 30;
#ifndef DEBUG
        rows = 30;
        cols = 40;
#endif
    }

    int maxcolor;
    cout << "Введіть максимальну кількість кольорів (від 2 до 4): ";
    cin >> maxcolor;
    if (maxcolor < 2 || maxcolor>4)
    {
        cout << "Помилка діапазону кольорів..." << endl;
        return 1;
    }

    cout << "Введіть N — кількість сусідніх клітин, які мають колір на одиницю більший, що потрібна для зміни кольору поточної клітинки: ";
    cin >> N;
    if (N < 1 || N > 10)
    {
        cout << "Помилка введення N..." << endl;
        return 1;
    }

    RenderWindow window(VideoMode(cols * squarpole, rows * squarpole), "Kissi Missi");

    vector<RectangleShape> squares;
    int** Memory = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        Memory[i] = new int[cols];
        for (int j = 0; j < cols; ++j)
        {
            Memory[i][j] = rand() % maxcolor + 1;
        }
    }



    bool Finish = false;
    while (window.isOpen()) {
        updatepole(Memory, rows, cols, N, maxcolor);


        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                RectangleShape square(Vector2f(squarpole, squarpole));
                square.setPosition(j * squarpole, i * squarpole);

                Color customColor(2, 65, 0);
                switch (Memory[i][j]) {
                case 1: {
                    Color customColor(252, 239, 238);
                    square.setFillColor(customColor);
                    squares.push_back(square);
                    break;
                }
                case 2: {
                    Color customColor(252, 205, 226);
                    square.setFillColor(customColor);
                    squares.push_back(square);
                    break;
                };
                case 3: {
                    Color customColor(252, 92, 156);
                    square.setFillColor(customColor);
                    squares.push_back(square);
                    break;
                };
                case 4: {
                    Color customColor(197, 227, 246);
                    square.setFillColor(customColor);
                    squares.push_back(square);
                    break;
                };
                default:
                {
                    Color customColor(2, 65, 32);
                    square.setFillColor(customColor);
                    squares.push_back(square);
                }
                }
            }
        }

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        for (const auto& square : squares)
        {
            window.draw(square);
        }

        window.display();
        this_thread::sleep_for(chrono::milliseconds(150));
    }

    for (int i = 0; i < rows; i++)
        delete[] Memory[i];
    delete[] Memory;
    return 0;
}
лол