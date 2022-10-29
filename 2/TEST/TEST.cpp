#include <iostream>
#include <Windows.h>
#include <vector>

#include <conio.h>
using namespace std;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

enum Colors
{
    BLACK, BLUE, GREEN, CLOUDY_BLUE, RED, PURPLE, YELLOW, WHITE, GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CLOUDY_BLUE, LIGHT_RED, LIGHT_YELLOW, BRIGHT_WHITE
};

void Change_Symbol_Color(const int& color)
{
    SetConsoleTextAttribute(hConsole, color);
}

int main()
{
    short ButtonCod_1 = '!';

    short ButtonCod = _getch();

   

    /*vector<vector<int>> GrafWeightsBuffer;

    for (size_t i = 0; i < 6; i++)
    {
        vector<int> temp;
        for (size_t j = 0; j < 6; j++)
        {
            temp.push_back(j);           
        }

        GrafWeightsBuffer.push_back(temp);
    }

    int a = 1;*/

    //setlocale(LC_ALL, "ru");

    //int d[6][6] =
    //{ {0, 28, 21, 59, 12, 27},
    // {7, 0, 24, 1000, 21, 9},
    // {9, 32, 0, 13, 11, 1000},
    // {8, 1000, 5, 0, 16, 1000},
    // {14, 13, 15, 10, 0, 22},
    // {15, 18, 1000, 1000, 6, 0} };

    //int s[6][6] =
    //{ {0, 2, 3, 4, 5, 6},
    // {1, 0, 3, 4, 5, 6},
    // {1, 2, 0, 4, 5, 6},
    // {1, 2, 3, 0, 5, 6},
    // {1, 2, 3, 4, 0, 6},
    // {1, 2, 3, 4, 5, 0} };

    //cout << "Матрица кратчайших путей между вершинами без промежуточных вершин: \n";

    //Change_Symbol_Color(RED);
    //cout << "  ";
    //for (size_t i = 0; i < 6; i++)
    //{
    //    cout << i << "\t";
    //}
    //Change_Symbol_Color(WHITE);

    //cout << "\n";

    //for (int i = 0; i < 6; i++)
    //{
    //    Change_Symbol_Color(RED);
    //    cout << i << " ";
    //    Change_Symbol_Color(WHITE);

    //    for (int j = 0; j < 6; j++)
    //    {
    //        cout << d[i][j] << "\t";
    //    }
    //    cout << "\n";
    //}


    //cout << "\nМатрица последовательности вершин: \n";

    //Change_Symbol_Color(RED);
    //cout << "  ";
    //for (size_t i = 0; i < 6; i++)
    //{
    //    cout << i << "\t";
    //}
    //Change_Symbol_Color(WHITE);

    //cout << "\n";

    //for (int i = 0; i < 6; i++)
    //{
    //    Change_Symbol_Color(RED);
    //    cout << i << " ";
    //    Change_Symbol_Color(WHITE);

    //    for (int j = 0; j < 6; j++)
    //    {
    //        cout << s[i][j] << "\t";
    //    }
    //    cout << "\n";
    //}


    ////Непосредственно алгоритм Флойда-Уоршелла
    //for (int m = 0; m < 6; ++m)
    //{
    //    for (int i = 0; i < 6; ++i)
    //    {
    //        for (int j = 0; j < 6; ++j)
    //        {
    //            if (d[i][j] > d[i][m] + d[m][j])
    //            {
    //                d[i][j] = d[i][m] + d[m][j];
    //                s[i][j] = m + 1;
    //                //s[i][j] = s[i][m];

    //            }
    //        }
    //    }
    //}


    //cout << "\nМатрица d после вычислений: \n";

    //Change_Symbol_Color(RED);
    //cout << "  ";
    //for (size_t i = 0; i < 6; i++)
    //{
    //    cout << i << "\t";
    //}
    //Change_Symbol_Color(WHITE);

    //cout << "\n";

    //for (int i = 0; i < 6; i++)
    //{
    //    Change_Symbol_Color(RED);
    //    cout << i << " ";
    //    Change_Symbol_Color(WHITE);

    //    for (int j = 0; j < 6; j++)
    //    {
    //        cout << d[i][j] << "\t";
    //    }
    //    cout << "\n";
    //}

    //cout << "\nМатрица s после вычислений: \n";

    //Change_Symbol_Color(RED);
    //cout << "  ";
    //for (size_t i = 0; i < 6; i++)
    //{
    //    cout << i << "\t";
    //}
    //Change_Symbol_Color(WHITE);

    //cout << "\n";

    //for (int i = 0; i < 6; i++)
    //{
    //    Change_Symbol_Color(RED);
    //    cout << i << " ";
    //    Change_Symbol_Color(WHITE);

    //    for (int j = 0; j < 6; j++)
    //    {
    //        cout << s[i][j] << "\t";
    //    }
    //    cout << "\n";
    //}


}