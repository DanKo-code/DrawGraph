#include <iostream>
using namespace std;

void hanoi(int a, int b, int c); //n - высота пирамиды, i - столбец с которого перекладываем
//k - на который

int main()
{
    setlocale(0, "rus");

   /* int a, b, c;
    cout << "¬ведите кол-во кубиков: "; cin >> a;
    cout << "¬ведите столбец с которого перекладываем: "; cin >> b;
    cout << "¬ведите столбец на который перекладываем: "; cin >> c;

    hanoi(a, b, c);*/

    
    return 0;
}

void hanoi(int a, int b, int c)
{
    if (a == 1)
    {
        printf("Move disk 1 from pin %d to %d.\n", b, c);
    } 
    else
    {
        int tmp = 6 - b - c; 
        hanoi(a - 1, b, tmp); 
        printf("Move disk %d from pin %d to %d.\n", a, b, c); 
        hanoi(a - 1, tmp, c); 
    }
}