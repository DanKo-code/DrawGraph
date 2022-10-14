#pragma once

#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <thread>

#include <vector>
#include <list>

#include <fstream>
#include <string>


#define PLAYER_SYMBOL '*' // ����������� ������ �� �����
#define START_ANIMATION 0 //��������� ���� � ����� ������ (������� �������� - ������� ��������) 
#define DRAW_GRAPH_ANIMATION 100

using namespace std;

class DanilasGame
{
public:

	void Create_Field(const short& Field_Width, const short& Field_Height); // �������� ����

	void Create_Player(); // ��������� ������� ������

//private:

	class Node
	{
	public:
		
		Node(int data = 0, char symbol = char(), short X = short(), short Y = short())
		{
			this->data = data;

			this->symbol = symbol;

			this->X = X;
			this->Y = Y;

			this->CurrentNodeAddress = this;
		}

		int data = int();

		char symbol = char();

		short X = short();
		short Y = short();

		Node* CurrentNodeAddress;

		Node* FirstNext = nullptr;
		Node* SecondNext = nullptr;
		Node* ThirdNext = nullptr;
		Node* FourthNext = nullptr;
		Node* FifthNext = nullptr;
		Node* SixthNext = nullptr;
	};

	////////////////////////////////////////////������ ��� ���������� ������ �����/////////////////////////////////////////////////////////

	////////////////////////////////////////////���������� ����� �� �����/////////////////////////////////////////////////////////

	vector<short> From_File;
	vector<short> EventsBuffer;

	short Event;

	ofstream ToFile;
	ifstream FromFile;

	bool DownloadFromFileFlag = false;
	int EventIndex = 0;

	void Draw_Or_Downloads();

	void GraphSaveORRquest();
	
	void Print_Message_5()
	{
		GoToMessagePosition();
		cout << "������ ��������� ����?(1 - ��, 2 - ���)";
	}

public:

	Node* Move_Player(string FileName);
	
private:

	//���������� ���������
	void Print_Messge_1();
	void Print_Messge_2()
	{
		GoToMessagePosition();
		cout << "������ ������� ����?(1 - ��, 2 - ���)";
	}
	void Print_Message_3()
	{
		GoToMessagePosition();
		cout << "������ ������� ������� �����?(1 - ��, 2 - ���)";
	}

	void Print_Message_4()
	{
		GoToMessagePosition();
		cout << "���������� ������� ������� ����� - ��� ���� ������!";
	}

	void GoToMessagePosition()
	{ 
		GoToXY(0, (this->Field_Height + 5), ' '); 
	}
	void EraseMessage()
	{
		GoToMessagePosition();

		cout << "                                                                                  \n\n";
		cout << "                                                                                      ";
	}

	//���������� � ������������� ������

	//��� ������� b
	void Create_New_Node();

	void Double_Connection_with_New();

	void Double_Connection_with_Existing(Node*, Node*);

	void Handle_Node_�reation();

	//��� ���������� � ����������� �����
	void Input_to_Existing_Node(int&, int);

	//��� � �������, ������ ������ � ��������
	void ConnectWithExisting(Node**, int&, Node* previous);

	///////////////////////////////����������//////////////////////////////////////
	short ButtonCod = 0;                                                         //
																				 //
	//�������� || �� �������� 												     //
	bool penDown = false;														 //
																				 //
	//������� �����(��������� A)												 //
	char NodeSymbol = 65;														 //
																				 //
	//����� ��������� ������� ����												 //
	short path = 1;																 //
																				 //
	//����������, ��� ������� ����, ��� ����� �� ������������					 //	
	Node* Start_From_Existing = nullptr;										 //
																				 //
	vector<Node*> NodesStorage;													 //
																				 //
	//��� ������ Double_Connection_with_New, ���� �� ��� ������ �� �������� � Start_From_Existing												     //
																				 //
	bool Flag = false;														     //
	///////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////���������� ��� �������� ����//////////////////////////////////////////////////////////////

	int Field_Width = 0;
	int Field_Height = 0;

	short PlayerX = 0;
	short PlayerY = 0;

	//������ � ��������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // ������ ���������� ����	
	CONSOLE_CURSOR_INFO MyCursor = { 25,true }; // �������� ������ �������

	void Change_Symbol_Color(const int& color);
	void HIDE_CURSOR(const bool& visability);
	void GoToXY(const short& x, const short& y, const char& symbol); // ����������� ������ �� �����������

	enum Colors
	{
		BLACK, BLUE, GREEN, CLOUDY_BLUE, RED, PURPLE, YELLOW, WHITE, GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CLOUDY_BLUE, LIGHT_RED, LIGHT_YELLOW, BRIGHT_WHITE
	};

	////////////////////////////////////////////////////��������� ������/////////////////////////////////////////////////////////////////

public:
	vector<Node> Search_Breadth_or_Depth(Node* Start, string&& TypeOfSort)
	{

		list<Node> InQueue;
		vector<Node> VisitedNodes;

		InQueue.push_back(*Start);

		// �������� �� ���������� � ����������� ������ � ������ � �������(�����)
		auto Check_For_Repeat = [&](Node& test)
		{
			for (int i = 0; i < VisitedNodes.size(); i++)
			{
				if (test.CurrentNodeAddress == VisitedNodes[i].CurrentNodeAddress) return true;
			}

			// �������� �� ���������� � ��������� ���������� �������(�����)
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

				if ((temp.FourthNext != nullptr) && (!(Check_For_Repeat(*temp.FourthNext))))
				{
					InQueue.push_back(*temp.FourthNext);
				}

				if ((temp.FifthNext != nullptr) && (!(Check_For_Repeat(*temp.FifthNext))))
				{
					InQueue.push_back(*temp.FifthNext);
				}

				if ((temp.SixthNext != nullptr) && (!(Check_For_Repeat(*temp.SixthNext))))
				{
					InQueue.push_back(*temp.SixthNext);
				}

				VisitedNodes.push_back(temp);
				InQueue.pop_front();

				if (InQueue.empty()) break;
			}
		}
		else if (TypeOfSort == "Depth")
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

				if ((temp.FourthNext != nullptr) && (!(Check_For_Repeat(*temp.FourthNext))))
				{
					InQueue.push_back(*temp.FourthNext);
				}

				if ((temp.FifthNext != nullptr) && (!(Check_For_Repeat(*temp.FifthNext))))
				{
					InQueue.push_back(*temp.FifthNext);
				}

				if ((temp.SixthNext != nullptr) && (!(Check_For_Repeat(*temp.SixthNext))))
				{
					InQueue.push_back(*temp.SixthNext);
				}

				VisitedNodes.push_back(temp);

				if (InQueue.empty()) break;
			}
		}

		return VisitedNodes;
	}

	void Print_Adjacency_List(const vector<Node>& GrafNodes)
	{
		for (int i = 0; i < (GrafNodes).size(); i++)
		{
			cout << (GrafNodes)[i].CurrentNodeAddress << " " << (GrafNodes)[i].data;

			if (((GrafNodes)[i].FirstNext == nullptr) && ((GrafNodes)[i].SecondNext == nullptr) && ((GrafNodes)[i].ThirdNext == nullptr)) continue;
			cout << "\n||\n||\n\\/\n";

			if ((GrafNodes)[i].FirstNext != nullptr)
			{
				cout << (GrafNodes)[i].FirstNext->CurrentNodeAddress << ", " << (GrafNodes)[i].FirstNext->data << "\n";
			}
			if ((GrafNodes)[i].SecondNext != nullptr)
			{
				cout << (GrafNodes)[i].SecondNext->CurrentNodeAddress << ", " << (GrafNodes)[i].SecondNext->data << "\n";
			}
			if ((GrafNodes)[i].ThirdNext != nullptr)
			{
				cout << (GrafNodes)[i].ThirdNext->CurrentNodeAddress << ", " << (GrafNodes)[i].ThirdNext->data << "\n";
			}

			cout << "\n\n";
		}

		cout << "\n";
	}

	void Print_Ribs_List(const vector<Node>& GrafNodes)
	{
		for (int i = 0; i < (GrafNodes).size(); i++)
		{
			if ((GrafNodes)[i].FirstNext != nullptr)
			{
				cout << "{ " << (GrafNodes)[i].CurrentNodeAddress << " " << (GrafNodes)[i].data << ", " << (GrafNodes)[i].FirstNext->CurrentNodeAddress << " " << (GrafNodes)[i].FirstNext->data << " }\n";
			}

			if ((GrafNodes)[i].SecondNext != nullptr)
			{
				cout << "{ " << (GrafNodes)[i].CurrentNodeAddress << " " << (GrafNodes)[i].data << ", " << (GrafNodes)[i].SecondNext->CurrentNodeAddress << " " << (GrafNodes)[i].SecondNext->data << " }\n";
			}

			if ((GrafNodes)[i].ThirdNext != nullptr)
			{
				cout << "{ " << (GrafNodes)[i].CurrentNodeAddress << " " << (GrafNodes)[i].data << ", " << (GrafNodes)[i].ThirdNext->CurrentNodeAddress << " " << (GrafNodes)[i].ThirdNext->data << " }\n";
			}
		}
	}

	void Print_Adjacency_Matrix(const vector<Node>& GrafNodes)
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

			Axes = { (short)(StorageOf_X.back() + 10),y };

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Axes);
		};

		cout << "\t\t";
		for (int i = 0; i < (GrafNodes).size(); i++)
		{
			GetConsoleScreenBufferInfo(hConsole, &info);
			StorageOf_X.push_back(info.dwCursorPosition.X);
			cout << (GrafNodes)[i].CurrentNodeAddress << ", " << (GrafNodes)[i].data << "\t";
		}


		for (int i = 0; i < (GrafNodes).size(); i++)
		{
			cout << "\n\n";

			cout << (GrafNodes)[i].CurrentNodeAddress << ", " << (GrafNodes)[i].data;

			for (int j = 0; j < (GrafNodes).size(); j++)
			{
				if (((GrafNodes)[i].FirstNext == (GrafNodes)[j].CurrentNodeAddress) || ((GrafNodes)[i].SecondNext == (GrafNodes)[j].CurrentNodeAddress) || ((GrafNodes)[i].ThirdNext == (GrafNodes)[j].CurrentNodeAddress))
				{
					GetConsoleScreenBufferInfo(hConsole, &info);

					GoToXY(StorageOf_X[j], info.dwCursorPosition.Y);
				}
			}

		}
	}

	void Print_Nodes_Address_Data(const vector<Node>& GrafNodes)
	{
		for (int i = 0; i != (GrafNodes).size(); i++)
		{
			cout << i << ". " << (GrafNodes)[i].CurrentNodeAddress << ", " << (GrafNodes)[i].data << "\n";
		}
	}
};