#include <iostream>
using namespace std;

void hanoi(int a, int b, int c); //n - ������ ��������, i - ������� � �������� �������������
//k - �� �������

int main()
{
    setlocale(0, "rus");

   /* int a, b, c;
    cout << "������� ���-�� �������: "; cin >> a;
    cout << "������� ������� � �������� �������������: "; cin >> b;
    cout << "������� ������� �� ������� �������������: "; cin >> c;

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