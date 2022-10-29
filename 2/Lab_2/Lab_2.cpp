#include "DrawGraf.h"

#include <iostream>
#include <list>
#include <vector>

#include <windows.h>

#include <string>

//#define Lab_2
#define TEST

using namespace std;

#ifdef Lab_2

	int main()
	{
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		// ������� ���� ��� 1
		Node* Start = new Node(1);
		Start->FirstNext = new Node(5);
		Start->SecondNext = new Node(9);

		// ������� ���� ��� 9
		Start->SecondNext->FirstNext = Start;
		Start->SecondNext->SecondNext = new Node(4);
		Start->SecondNext->ThirdNext = new Node(6);

		// ������� ���� ��� 5
		Start->FirstNext->FirstNext = Start;
		Start->FirstNext->SecondNext = Start->SecondNext->ThirdNext;

		// ������� ���� ��� 6
		Start->SecondNext->ThirdNext->FirstNext = Start->SecondNext->SecondNext;
		Start->SecondNext->ThirdNext->SecondNext = Start->FirstNext;
		Start->SecondNext->ThirdNext->ThirdNext = Start->SecondNext;

		// ������� ���� ��� 4
		Start->SecondNext->SecondNext->FirstNext = Start->SecondNext->ThirdNext;
		Start->SecondNext->SecondNext->SecondNext = Start->SecondNext;
		Start->SecondNext->SecondNext->ThirdNext = new Node(4);


		//////////////////////////////////��� �����////////////////////////////////////////////////////////////////////////////////////////////////////////

		// ������� ���� ��� 1
		Node* Shiman = new Node(1);
		Shiman->FirstNext = new Node(2);
		Shiman->SecondNext = new Node(4);

		// ������� ���� ��� 2
		Shiman->FirstNext->FirstNext = Shiman;
		Shiman->FirstNext->SecondNext = new Node(6);
		Shiman->FirstNext->ThirdNext = new Node(7);

		// ������� ���� ��� 4
		Shiman->SecondNext->FirstNext = Shiman;
		Shiman->SecondNext->SecondNext = new Node(5);

		// ������� ���� ��� 6
		Shiman->FirstNext->SecondNext->FirstNext = Shiman->FirstNext;
		Shiman->FirstNext->SecondNext->SecondNext = Shiman->FirstNext->ThirdNext;

		// ������� ���� ��� 7
		Shiman->FirstNext->ThirdNext->FirstNext = Shiman->FirstNext;
		Shiman->FirstNext->ThirdNext->SecondNext = new Node(3);
		Shiman->FirstNext->ThirdNext->ThirdNext = Shiman->FirstNext->SecondNext;

		// ������� ���� ��� 3
		Shiman->FirstNext->ThirdNext->SecondNext->FirstNext = Shiman->FirstNext->ThirdNext;

		// ������� ���� ��� 5
		Shiman->SecondNext->SecondNext->FirstNext = Shiman->SecondNext;
		Shiman->SecondNext->SecondNext->SecondNext = new Node(8);

		// ������� ���� ��� 8
		Shiman->SecondNext->SecondNext->SecondNext->FirstNext = Shiman->SecondNext->SecondNext;



		///////////////////////////////////����� ������///////////////////////////////////////////////////////////////////////////////////////////////////////


		vector<Node> TestList = Search(Shiman, "Depth");

		Print_Nodes_Address_Data(&TestList);
		cout << "\n\n";

		Print_Adjacency_List(&TestList);
		cout << "\n\n";

		Print_Ribs_List(&TestList);
		cout << "\n\n";

		Print_Adjacency_Matrix(&TestList);
		cout << "\n\n";


	}

#endif // Lab_2

#ifdef TEST

	int main()
	{
		system("mode con cols=300 lines=300");

		string FileName = "Lab_3";

		DanilasGame Graf;

		//Graf.Floyd_Warshall_Algorithm();

		auto test = Graf.Move_Player(FileName);

		cout << "\n\n";

		//Graf.Floyd_Warshall_Algorithm();

		auto buf = Graf.Search_Breadth_or_Depth(test[0], "Breadth");

		auto res = Graf.Dijkstras_Algorithm(test[0], buf);

		Graf.Print_Dijkstras_Algorithm(res);

		cout << "\n\n";

		Graf.Print_Adjacency_List(Graf.Search_Breadth_or_Depth(test[0], "Breadth"));
		cout << "\n\n";

		Graf.Print_Ribs_List(Graf.Search_Breadth_or_Depth(test[0], "Breadth"));
		cout << "\n\n";

		Graf.Print_Adjacency_Matrix(Graf.Search_Breadth_or_Depth(test[0], "Breadth"));
		cout << "\n\n";

		Graf.Print_Nodes_Address_Symbol(Graf.Search_Breadth_or_Depth(test[0], "Breadth"));

		system("pause");
	}

#endif // TEST

	
