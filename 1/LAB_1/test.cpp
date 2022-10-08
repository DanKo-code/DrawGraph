//#include <iostream>
//using namespace std;
//void hanoi(int i, int k, int n);
//int num = 1;
//int main()
//{
//	int choosen, choosek;
//	setlocale(0, "rus");
//	cout << "(N)¬ведите количеcтво дисков(2-5): ";
//	cin >> choosen;
//	if (choosen <= 1 || choosen > 5) {
//		cout << "¬ведены неверные значени€ 'k'\n¬ведите N повторно(2-5): ";
//		cin >> choosen;
//	}
//	cout << "\n(k)¬ведите куда надо переместить(2-3): ";
//	cin >> choosek;
//	if (choosek <= 1 || choosek > 3) {
//		cout << "¬ведены неверные значени€ 'k'\n¬ведите k повторно(2-3): ";
//		cin >> choosek;
//	}
//
//
//	hanoi(1, choosek, choosen);
//	return 0;
//}
//void hanoi(int i, int k, int n)
//{
//
//	if (n == 1) {
//
//		cout << num++ << ") ѕереместить диск 1 со стержн€ " << i << " на стержень " << k << ".\n";
//
//	}
//	else {
//
//		int tmp = 6 - i - k;
//		hanoi(i, tmp, n - 1);
//
//		cout << num++ << ") ѕереместить диск " << n << " со стержн€ " << i << " на стержень " << k << ".\n";
//		hanoi(tmp, k, n - 1);
//
//	}
//}
