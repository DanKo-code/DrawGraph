#include "DrawGraf.h"

#include <iostream>
#include <list>
#include <vector>

#include <windows.h>

#include <string>

//#define Lab_2
#define TEST

using namespace std;


/*
	class Node
	{
	public:
		Node(int data = 0, Node* FirstNext = nullptr, Node* SecondNext = nullptr, Node* ThirdNext = nullptr)
		{
			this->data = data;

			this->CurrentNodeAddress = this;

			this->FirstNext = FirstNext;
			this->SecondNext = SecondNext;
			this->ThirdNext = ThirdNext;
		}

		int data;

		Node* CurrentNodeAddress;

		Node* FirstNext;
		Node* SecondNext;
		Node* ThirdNext;


	};

	vector<Node> Search(Node* Start, string&& TypeOfSort)
	{

		list<Node> InQueue;
		vector<Node> VisitedNodes;

		InQueue.push_back(*Start);

		 //Проверка на совпадение с посещенными узлами и узлами в очереди(листе)
		auto Check_For_Repeat = [&](Node& test)
		{
			for (int i = 0; i < VisitedNodes.size(); i++)
			{
				if ( test.CurrentNodeAddress == VisitedNodes[i].CurrentNodeAddress) return true;
			}

			 //Проверка на совпадение с временным содержимым очереди(листа)
			for (auto j = InQueue.begin(); j != InQueue.end(); j++)
			{
				if (test.CurrentNodeAddress == (*j).CurrentNodeAddress) return true;
			}

			return false;
		};

		if (TypeOfSort == "Breadth")
		{
			Node temp;

			for (;;)
			{
				temp = InQueue.front();

				if ((temp.FirstNext != nullptr) && (!(Check_For_Repeat(*temp.FirstNext))))
				{
					InQueue.push_back(*temp.FirstNext);
				}

				if ((temp.SecondNext != nullptr) && (!(Check_For_Repeat(*temp.SecondNext))))
				{
					InQueue.push_back(*temp.SecondNext);
				}

				if ((temp.ThirdNext != nullptr) && (!(Check_For_Repeat(*temp.ThirdNext))))
				{
					InQueue.push_back(*temp.ThirdNext);
				}

				VisitedNodes.push_back(temp);
				InQueue.pop_front();

				if (InQueue.empty()) break;
			}
		}
		else if(TypeOfSort == "Depth")
		{
			Node temp;
			
			for (;;)
			{
				temp = InQueue.back();
				InQueue.pop_back();

				if ((temp.FirstNext != nullptr) && (!(Check_For_Repeat(*temp.FirstNext))))
				{
					InQueue.push_back(*(temp.FirstNext));
				}

				if ((temp.SecondNext != nullptr) && (!(Check_For_Repeat(*temp.SecondNext))))
				{
					InQueue.push_back(*temp.SecondNext);
				}

				if ((temp.ThirdNext != nullptr) && (!(Check_For_Repeat(*temp.ThirdNext))))
				{
					InQueue.push_back(*temp.ThirdNext);
				}

				VisitedNodes.push_back(temp);

				if (InQueue.empty()) break;
			}
		}
		
		return VisitedNodes;
	}

	void Print_Adjacency_List(vector<Node>* GrafNodes)
	{
		for (int i = 0; i < (*GrafNodes).size(); i++)
		{
			cout << (*GrafNodes)[i].CurrentNodeAddress << " " << (*GrafNodes)[i].data;
			
			if (((*GrafNodes)[i].FirstNext == nullptr) && ((*GrafNodes)[i].SecondNext == nullptr) && ((*GrafNodes)[i].ThirdNext == nullptr)) continue;
			cout<< "\n||\n||\n\\/\n";

			if ((*GrafNodes)[i].FirstNext != nullptr)
			{
				cout << (*GrafNodes)[i].FirstNext->CurrentNodeAddress << ", " << (*GrafNodes)[i].FirstNext->data << "\n";
			}
			if ((*GrafNodes)[i].SecondNext != nullptr)
			{
				cout << (*GrafNodes)[i].SecondNext->CurrentNodeAddress << ", " << (*GrafNodes)[i].SecondNext->data << "\n";
			}
			if ((*GrafNodes)[i].ThirdNext != nullptr)
			{
				cout << (*GrafNodes)[i].ThirdNext->CurrentNodeAddress << ", " << (*GrafNodes)[i].ThirdNext->data << "\n";
			}
	
			cout << "\n\n";
		}

		cout << "\n";
	}

	void Print_Ribs_List(vector<Node>* GrafNodes) 
	{
		for (int i = 0; i < (*GrafNodes).size(); i++)
		{
			if ((*GrafNodes)[i].FirstNext != nullptr)
			{
				cout << "{ " << (*GrafNodes)[i].CurrentNodeAddress << " " << (*GrafNodes)[i].data << ", " << (*GrafNodes)[i].FirstNext->CurrentNodeAddress<<" "<< (*GrafNodes)[i].FirstNext->data << " }\n";
			}

			if ((*GrafNodes)[i].SecondNext != nullptr)
			{
				cout << "{ " << (*GrafNodes)[i].CurrentNodeAddress << " " << (*GrafNodes)[i].data << ", " << (*GrafNodes)[i].SecondNext->CurrentNodeAddress << " " << (*GrafNodes)[i].SecondNext->data << " }\n";
			}

			if ((*GrafNodes)[i].ThirdNext != nullptr)
			{
				cout << "{ " << (*GrafNodes)[i].CurrentNodeAddress << " " << (*GrafNodes)[i].data << ", " << (*GrafNodes)[i].ThirdNext->CurrentNodeAddress << " " << (*GrafNodes)[i].ThirdNext->data << " }\n";
			}
		}
	}

	void Print_Adjacency_Matrix(vector<Node>* GrafNodes)
	{
		vector<int> StorageOf_X;
		CONSOLE_SCREEN_BUFFER_INFO info;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		auto GoToXY = [&](const short& x, const short& y)
		{
			COORD Axes = { x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Axes);

			SetConsoleTextAttribute(hConsole, 4);
			cout << "True";
			SetConsoleTextAttribute(hConsole, 7);
			
			Axes = { (short)(StorageOf_X.back()+10),y };

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Axes);
		};

		cout << "\t\t";
		for (int i = 0; i < (*GrafNodes).size(); i++)
		{
			GetConsoleScreenBufferInfo(hConsole, &info);
			StorageOf_X.push_back(info.dwCursorPosition.X);
			cout << (*GrafNodes)[i].CurrentNodeAddress << ", " << (*GrafNodes)[i].data << "\t";
		}
		

		for (int i = 0; i < (*GrafNodes).size(); i++)
		{
			cout << "\n\n";

			cout << (*GrafNodes)[i].CurrentNodeAddress << ", " << (*GrafNodes)[i].data;

			for (int j = 0; j < (*GrafNodes).size(); j++)
			{
				if ( ((*GrafNodes)[i].FirstNext == (*GrafNodes)[j].CurrentNodeAddress) || ((*GrafNodes)[i].SecondNext == (*GrafNodes)[j].CurrentNodeAddress) || ((*GrafNodes)[i].ThirdNext == (*GrafNodes)[j].CurrentNodeAddress))
				{
					GetConsoleScreenBufferInfo(hConsole, &info);

					GoToXY(StorageOf_X[j], info.dwCursorPosition.Y);
				}
			}
			
		}
	}
	
	void Print_Nodes_Address_Data(vector<Node>* GrafNodes)
	{
		for (int i = 0; i !=(*GrafNodes).size(); i++)
		{
			cout<<i<<". "<< (*GrafNodes)[i].CurrentNodeAddress<<", " << (*GrafNodes)[i].data << "\n";
		}
	}
	
*/

#ifdef Lab_2

	int main()
	{
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		// ОбЪявил узлы для 1
		Node* Start = new Node(1);
		Start->FirstNext = new Node(5);
		Start->SecondNext = new Node(9);

		// ОбЪявил узлы для 9
		Start->SecondNext->FirstNext = Start;
		Start->SecondNext->SecondNext = new Node(4);
		Start->SecondNext->ThirdNext = new Node(6);

		// ОбЪявил узлы для 5
		Start->FirstNext->FirstNext = Start;
		Start->FirstNext->SecondNext = Start->SecondNext->ThirdNext;

		// ОбЪявил узлы для 6
		Start->SecondNext->ThirdNext->FirstNext = Start->SecondNext->SecondNext;
		Start->SecondNext->ThirdNext->SecondNext = Start->FirstNext;
		Start->SecondNext->ThirdNext->ThirdNext = Start->SecondNext;

		// ОбЪявил узлы для 4
		Start->SecondNext->SecondNext->FirstNext = Start->SecondNext->ThirdNext;
		Start->SecondNext->SecondNext->SecondNext = Start->SecondNext;
		Start->SecondNext->SecondNext->ThirdNext = new Node(4);


		//////////////////////////////////Мой варик////////////////////////////////////////////////////////////////////////////////////////////////////////

		// ОбЪявил узлы для 1
		Node* Shiman = new Node(1);
		Shiman->FirstNext = new Node(2);
		Shiman->SecondNext = new Node(4);

		// ОбЪявил узлы для 2
		Shiman->FirstNext->FirstNext = Shiman;
		Shiman->FirstNext->SecondNext = new Node(6);
		Shiman->FirstNext->ThirdNext = new Node(7);

		// ОбЪявил узлы для 4
		Shiman->SecondNext->FirstNext = Shiman;
		Shiman->SecondNext->SecondNext = new Node(5);

		// ОбЪявил узлы для 6
		Shiman->FirstNext->SecondNext->FirstNext = Shiman->FirstNext;
		Shiman->FirstNext->SecondNext->SecondNext = Shiman->FirstNext->ThirdNext;

		// ОбЪявил узлы для 7
		Shiman->FirstNext->ThirdNext->FirstNext = Shiman->FirstNext;
		Shiman->FirstNext->ThirdNext->SecondNext = new Node(3);
		Shiman->FirstNext->ThirdNext->ThirdNext = Shiman->FirstNext->SecondNext;

		// ОбЪявил узлы для 3
		Shiman->FirstNext->ThirdNext->SecondNext->FirstNext = Shiman->FirstNext->ThirdNext;

		// ОбЪявил узлы для 5
		Shiman->SecondNext->SecondNext->FirstNext = Shiman->SecondNext;
		Shiman->SecondNext->SecondNext->SecondNext = new Node(8);

		// ОбЪявил узлы для 8
		Shiman->SecondNext->SecondNext->SecondNext->FirstNext = Shiman->SecondNext->SecondNext;



		///////////////////////////////////Варик Шимана///////////////////////////////////////////////////////////////////////////////////////////////////////


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

		DanilasGame Graf;

		Graf.Create_Field(200, 50);

		string FileName = "Graph.txt";

		Graf.Create_Player();

		auto test = Graf.Move_Player(FileName);

		cout << "\n\n";

		Graf.Print_Adjacency_List(Graf.Search_Breadth_or_Depth(test, "Breadth"));
		cout << "\n\n";

		Graf.Print_Ribs_List(Graf.Search_Breadth_or_Depth(test, "Breadth"));
		cout << "\n\n";

		Graf.Print_Adjacency_Matrix(Graf.Search_Breadth_or_Depth(test, "Breadth"));
		cout << "\n\n";

		Graf.Print_Nodes_Address_Data(Graf.Search_Breadth_or_Depth(test, "Breadth"));

		system("pause");
	}

#endif // TEST


