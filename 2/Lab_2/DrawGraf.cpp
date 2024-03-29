#include "DrawGraf.h"

// �������� ����
void DanilasGame::Create_Field(const short& Field_Width, const short& Field_Height)
{
	HIDE_CURSOR(false);

	this->Field_Width = Field_Width;
	this->Field_Height = Field_Height;

	Change_Symbol_Color(Colors::RED); // ������� ���� �� �������

	for (short i = 0; i < Field_Width + 2; i++)
	{
		GoToXY(i, 0, 'X');
		std::this_thread::sleep_for(std::chrono::microseconds(START_ANIMATION));
	}

	for (short i = 1; i < Field_Height + 2; i++)
	{
		GoToXY(Field_Width + 2 - 1, i, 'X');
		std::this_thread::sleep_for(std::chrono::microseconds(START_ANIMATION));
	}

	for (short i = Field_Width + 2 - 2; i >= 0; i--)
	{
		GoToXY(i, Field_Height + 2 - 1, 'X');
		std::this_thread::sleep_for(std::chrono::microseconds(START_ANIMATION));
	}

	for (short i = Field_Height + 2 - 2; i != 0; i--)
	{
		GoToXY(0, i, 'X');
		std::this_thread::sleep_for(std::chrono::microseconds(START_ANIMATION));
	}

	Change_Symbol_Color(Colors::WHITE); // ������� ���� �� �������

	HIDE_CURSOR(true);
}

// ��������� ������� ������
void DanilasGame::Create_Player()
{
	this->PlayerX = Field_Width / 2;
	this->PlayerY = Field_Height / 2;

	GoToXY(this->PlayerX, this->PlayerY, PLAYER_SYMBOL);
}
 
////////////////////////////////////////////������ ��� ���������� ������ �����/////////////////////////////////////////////////////////

// �������� ����� ����
void DanilasGame::Create_New_Node()
{
	// �������� ����� ����
	switch (path)
	{
	case 1:
	{
		if (Start_From_Existing == nullptr)
		{
			NodesStorage.back()->FirstNext = new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY);
			NodesStorage.push_back(NodesStorage.back()->FirstNext);
			return;
		}
		else
		{
			Start_From_Existing->FirstNext = new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY);
			NodesStorage.push_back(Start_From_Existing->FirstNext);
			return;
		}

	}

	case 2:
	{
		if (Start_From_Existing == nullptr)
		{
			NodesStorage.back()->SecondNext = new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY);
			NodesStorage.push_back(NodesStorage.back()->SecondNext);
			return;
		}
		else
		{
			Start_From_Existing->SecondNext = new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY);
			NodesStorage.push_back(Start_From_Existing->SecondNext);
			return;
		}
	}

	case 3:
	{
		if (Start_From_Existing == nullptr)
		{
			NodesStorage.back()->ThirdNext = new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY);
			NodesStorage.push_back(NodesStorage.back()->ThirdNext);
			return;
		}
		else
		{
			Start_From_Existing->ThirdNext = new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY);
			NodesStorage.push_back(Start_From_Existing->ThirdNext);
			return;
		}
	}

	case 4:
	{
		if (Start_From_Existing == nullptr)
		{
			NodesStorage.back()->FourthNext = new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY);
			NodesStorage.push_back(NodesStorage.back()->FourthNext);
			return;
		}
		else
		{
			Start_From_Existing->FourthNext = new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY);
			NodesStorage.push_back(Start_From_Existing->FourthNext);
			return;
		}
	}

	case 5:
	{
		if (Start_From_Existing == nullptr)
		{
			NodesStorage.back()->FifthNext = new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY);
			NodesStorage.push_back(NodesStorage.back()->FifthNext);
			return;
		}
		else
		{
			Start_From_Existing->FifthNext = new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY);
			NodesStorage.push_back(Start_From_Existing->FifthNext);
			return;
		}
	}

	case 6:
	{
		if (Start_From_Existing == nullptr)
		{
			NodesStorage.back()->SixthNext = new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY);
			NodesStorage.push_back(NodesStorage.back()->SixthNext);
			return;
		}
		else
		{
			Start_From_Existing->SixthNext = new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY);
			NodesStorage.push_back(Start_From_Existing->SixthNext);
			return;
		}
	}
	}
}

void DanilasGame::Double_Connection_with_New()
{
	for (;;)
	{
		Draw_Or_Downloads();

		if (ButtonCod == 49)
		{
			switch (path)
			{
			case 1:
			{
				if (Start_From_Existing == nullptr)
				{
					NodesStorage.back()->FirstNext = NodesStorage[NodesStorage.size() - 2];
					NodesStorage.back()->FirstWeight = NodesStorage[NodesStorage.size() - 2]->FirstWeight;

					return;
				}
				else
				{
					NodesStorage.back()->FirstNext = Start_From_Existing;
					NodesStorage.back()->FirstWeight = Start_From_Existing->FirstWeight;

					return;
				}
			}

			case 2:
			{
				if (Start_From_Existing == nullptr)
				{
					NodesStorage.back()->SecondNext = NodesStorage[NodesStorage.size() - 2];
					NodesStorage.back()->SecondWeight = NodesStorage[NodesStorage.size() - 2]->SecondWeight;

					return;
				}
				else
				{
					NodesStorage.back()->SecondNext = Start_From_Existing;
					NodesStorage.back()->SecondWeight = Start_From_Existing->SecondWeight;

					return;
				}
			}

			case 3:
			{
				if (Start_From_Existing == nullptr)
				{
					NodesStorage.back()->ThirdNext = NodesStorage[NodesStorage.size() - 2];
					NodesStorage.back()->ThirdWeight = NodesStorage[NodesStorage.size() - 2]->ThirdWeight;

					return;
				}
				else
				{
					NodesStorage.back()->ThirdNext = Start_From_Existing;
					NodesStorage.back()->ThirdWeight = Start_From_Existing->ThirdWeight;

					return;
				}
			}

			case 4:
			{
				if (Start_From_Existing == nullptr)
				{
					NodesStorage.back()->FourthNext = NodesStorage[NodesStorage.size() - 2];
					NodesStorage.back()->FourthWeight = NodesStorage[NodesStorage.size() - 2]->FourthWeight;

					return;
				}
				else
				{
					NodesStorage.back()->FourthNext = Start_From_Existing;
					NodesStorage.back()->FourthWeight = Start_From_Existing->FourthWeight;

					return;
				}
			}

			case 5:
			{
				if (Start_From_Existing == nullptr)
				{
					NodesStorage.back()->FifthNext = NodesStorage[NodesStorage.size() - 2];
					NodesStorage.back()->FifthWeight = NodesStorage[NodesStorage.size() - 2]->FifthWeight;

					return;
				}
				else
				{
					NodesStorage.back()->FifthNext = Start_From_Existing;
					NodesStorage.back()->FifthWeight = Start_From_Existing->FifthWeight;

					return;
				}
			}

			case 6:
			{
				if (Start_From_Existing == nullptr)
				{
					NodesStorage.back()->SixthNext = NodesStorage[NodesStorage.size() - 2];
					NodesStorage.back()->SixthWeight = NodesStorage[NodesStorage.size() - 2]->SixthWeight;

					return;
				}
				else
				{
					NodesStorage.back()->SixthNext = Start_From_Existing;
					NodesStorage.back()->SixthWeight = Start_From_Existing->SixthWeight;

					return;
				}
			}
			}
		}
		if (ButtonCod == 50)
		{
			return;
		}
	}
}

void DanilasGame::Double_Connection_with_Existing(Node* existing, Node* previous)
{
	Print_Message_3();

	Draw_Or_Downloads();

	if (ButtonCod == 49)
	{
		if (existing->FirstNext == nullptr)
		{
			existing->FirstNext = previous;

			//////////////////////////////////////////////////////////
			switch(path)
			{
			case 1:
			{
				existing->FirstWeight = previous->FirstWeight;
				return;
			}

			case 2:
			{
				existing->FirstWeight = previous->SecondWeight;
				return;
			}

			case 3:
			{
				existing->FirstWeight = previous->ThirdWeight;
				return;
			}

			case 4:
			{
				existing->FirstWeight = previous->FourthWeight;
				return;
			}

			case 5:
			{
				existing->FirstWeight = previous->FifthWeight;
				return;
			}

			case 6:
			{
				existing->FirstWeight = previous->SixthWeight;
				return;
			}
			}
			//////////////////////////////////////////////////////////
		}
		if (existing->SecondNext == nullptr)
		{
			existing->SecondNext = previous;

			//////////////////////////////////////////////////////////
			switch (path)
			{
			case 1:
			{
				existing->SecondWeight = previous->FirstWeight;
				return;
			}

			case 2:
			{
				existing->SecondWeight = previous->SecondWeight;
				return;
			}

			case 3:
			{
				existing->SecondWeight = previous->ThirdWeight;
				return;
			}

			case 4:
			{
				existing->SecondWeight = previous->FourthWeight;
				return;
			}

			case 5:
			{
				existing->SecondWeight = previous->FifthWeight;
				return;
			}

			case 6:
			{
				existing->SecondWeight = previous->SixthWeight;
				return;
			}
			}
			//////////////////////////////////////////////////////////		
		}
		if (existing->ThirdNext == nullptr)
		{
			existing->ThirdNext = previous;

			//////////////////////////////////////////////////////////
			switch (path)
			{
			case 1:
			{
				existing->ThirdWeight = previous->FirstWeight;
				return;
			}

			case 2:
			{
				existing->ThirdWeight = previous->SecondWeight;
				return;
			}

			case 3:
			{
				existing->ThirdWeight = previous->ThirdWeight;
				return;
			}

			case 4:
			{
				existing->ThirdWeight = previous->FourthWeight;
				return;
			}

			case 5:
			{
				existing->ThirdWeight = previous->FifthWeight;
				return;
			}

			case 6:
			{
				existing->ThirdWeight = previous->SixthWeight;
				return;
			}
			}
			//////////////////////////////////////////////////////////
		}
		if (existing->FourthNext == nullptr)
		{
			existing->FourthNext = previous;

			//////////////////////////////////////////////////////////
			switch (path)
			{
			case 1:
			{
				existing->FourthWeight = previous->FirstWeight;
				return;
			}

			case 2:
			{
				existing->FourthWeight = previous->SecondWeight;
				return;
			}

			case 3:
			{
				existing->FourthWeight = previous->ThirdWeight;
				return;
			}

			case 4:
			{
				existing->FourthWeight = previous->FourthWeight;
				return;
			}

			case 5:
			{
				existing->FourthWeight = previous->FifthWeight;
				return;
			}

			case 6:
			{
				existing->FourthWeight = previous->SixthWeight;
				return;
			}
			}
			//////////////////////////////////////////////////////////
		}
		if (existing->FifthNext == nullptr)
		{
			existing->FifthNext = previous;

			//////////////////////////////////////////////////////////
			switch (path)
			{
			case 1:
			{
				existing->FifthWeight = previous->FirstWeight;
				return;
			}

			case 2:
			{
				existing->FifthWeight = previous->SecondWeight;
				return;
			}

			case 3:
			{
				existing->FifthWeight = previous->ThirdWeight;
				return;
			}

			case 4:
			{
				existing->FifthWeight = previous->FourthWeight;
				return;
			}

			case 5:
			{
				existing->FifthWeight = previous->FifthWeight;
				return;
			}

			case 6:
			{
				existing->FifthWeight = previous->SixthWeight;
				return;
			}
			}
			//////////////////////////////////////////////////////////
		}
		if (existing->SixthNext == nullptr)
		{
			existing->SixthNext = previous;

			//////////////////////////////////////////////////////////
			switch (path)
			{
			case 1:
			{
				existing->SixthWeight = previous->FirstWeight;
				return;
			}

			case 2:
			{
				existing->SixthWeight = previous->SecondWeight;
				return;
			}

			case 3:
			{
				existing->SixthWeight = previous->ThirdWeight;
				return;
			}

			case 4:
			{
				existing->SixthWeight = previous->FourthWeight;
				return;
			}

			case 5:
			{
				existing->SixthWeight = previous->FifthWeight;
				return;
			}

			case 6:
			{
				existing->SixthWeight = previous->SixthWeight;
				return;
			}
			}
			//////////////////////////////////////////////////////////
		}
	}
	if (ButtonCod == 50)
	{
		return;
	}

	Print_Message_4();
}

//��������� ������ ������ ����, ���� �������� �� ������������ ����
void DanilasGame::Handle_Node_�reation()
{
	Print_Messge_1();

	for (;;)
	{
	RESTART:

		Draw_Or_Downloads();

		//////////////////����/////////////////////
		switch (ButtonCod)
		{
		case 49:
		{
			//��������, ����� �� ���������� ������������ �����
			if (Start_From_Existing == nullptr)
			{
				if (NodesStorage.back()->FirstNext != nullptr) goto RESTART;
			}
			else if (Start_From_Existing->FirstNext != nullptr) goto RESTART;
			

			penDown = true;
			path = 1;
			EraseMessage();
			return;
		}

		case 50:
		{
			if (Start_From_Existing == nullptr)
			{
				if (NodesStorage.back()->SecondNext != nullptr) goto RESTART;
			}
			else if (Start_From_Existing->SecondNext != nullptr) goto RESTART;

			penDown = true;
			path = 2;
			EraseMessage();
			return;
		}

		case 51:
		{
			if (Start_From_Existing == nullptr)
			{
				if (NodesStorage.back()->ThirdNext != nullptr) goto RESTART;
			}
			else if (Start_From_Existing->ThirdNext != nullptr) goto RESTART;

			penDown = true;
			path = 3;
			EraseMessage();
			return;
		}

		case 52:
		{
			if (Start_From_Existing == nullptr)
			{
				if (NodesStorage.back()->FourthNext != nullptr) goto RESTART;
			}
			else if (Start_From_Existing->FourthNext != nullptr) goto RESTART;

			penDown = true;
			path = 4;
			EraseMessage();
			return;
		}

		case 53:
		{
			if (Start_From_Existing == nullptr)
			{
				if (NodesStorage.back()->FifthNext != nullptr) goto RESTART;
			}
			else if (Start_From_Existing->FifthNext != nullptr) goto RESTART;

			penDown = true;
			path = 5;
			EraseMessage();
			return;
		}

		case 54:
		{
			if (Start_From_Existing == nullptr)
			{
				if (NodesStorage.back()->SixthNext != nullptr) goto RESTART;
			}
			else if (Start_From_Existing->SixthNext != nullptr) goto RESTART;

			penDown = true;
			path = 6;
			EraseMessage();
			return;
		}
		//////////////////����/////////////////////

		default:
		{
			for (size_t i = 0; i < NodesStorage.size(); i++)
			{
				if (ButtonCod == NodesStorage[i]->symbol)
				{
					this->PlayerX = NodesStorage[i]->X;
					this->PlayerY = NodesStorage[i]->Y;

					Start_From_Existing = NodesStorage[i];

					EraseMessage();

					//
					Handle_Node_�reation();

					EraseMessage();

					return;
				}
			}
		}

		}
	}
}

//��������� ������ ������� � ���������� �����
void DanilasGame::Input_to_Existing_Node(int i, int buttonCode)
{
	for (;;)
	{
		Draw_Or_Downloads();

		if (ButtonCod == 49)
		{
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			switch (path)
			{
			case 1:
			{
						if (Start_From_Existing == nullptr)
						{
							ConnectWithExisting(&NodesStorage.back()->FirstNext, i, NodesStorage.back());
							break;
						}
						else
						{
							ConnectWithExisting(&Start_From_Existing->FirstNext, i, Start_From_Existing);
							break;
						}

					}

			case 2:
			{
						if (Start_From_Existing == nullptr)
						{
							ConnectWithExisting(&NodesStorage.back()->SecondNext, i, NodesStorage.back());
							break;
						}
						else
						{
							ConnectWithExisting(&Start_From_Existing->SecondNext, i, Start_From_Existing);
							break;
						}
					}

			case 3:
			{
						if (Start_From_Existing == nullptr)
						{
							ConnectWithExisting(&NodesStorage.back()->ThirdNext, i, NodesStorage.back());
							break;
						}
						else
						{
							ConnectWithExisting(&Start_From_Existing->ThirdNext, i, Start_From_Existing);
							break;
						}
					}

			case 4:
			{
						if (Start_From_Existing == nullptr)
						{
							ConnectWithExisting(&NodesStorage.back()->FourthNext, i, NodesStorage.back());
							break;
						}
						else
						{
							ConnectWithExisting(&Start_From_Existing->FourthNext, i, Start_From_Existing);
							break;
						}
					}

			case 5:
			{
						if (Start_From_Existing == nullptr)
						{
							ConnectWithExisting(&NodesStorage.back()->FifthNext, i, NodesStorage.back());
							break;
						}
						else
						{
							ConnectWithExisting(&Start_From_Existing->FifthNext, i, Start_From_Existing);
							break;
						}
					}

			case 6:
			{
						if (Start_From_Existing == nullptr)
						{
							ConnectWithExisting(&NodesStorage.back()->SixthNext, i, NodesStorage.back());
							break;
						}
						else
						{
							ConnectWithExisting(&Start_From_Existing->SixthNext, i, Start_From_Existing);
							break;
						}
					}
			}

			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				
			Handle_Node_�reation();

			return;
		}
		if (ButtonCod == 50)
		{
			EraseMessage();

			//UP
			if(buttonCode == 119) GoToXY(this->PlayerX, ++(this->PlayerY), PLAYER_SYMBOL);
			//DOWN
			if(buttonCode == 115) GoToXY(this->PlayerX, --(this->PlayerY), PLAYER_SYMBOL);
			//LEFT
			if(buttonCode == 97) GoToXY(++(this->PlayerX), this->PlayerY, PLAYER_SYMBOL);
			//RIGHT
			if(buttonCode == 100) GoToXY(--(this->PlayerX), this->PlayerY, PLAYER_SYMBOL);

			return;
		}
	}
}

//��������� � ����������
void DanilasGame::ConnectWithExisting(Node** buffer, int& i, Node* previous)
{
	SetRibsWeights(previous, path);

	(*buffer) = NodesStorage[i];
	Start_From_Existing = *buffer;

	this->PlayerX = Start_From_Existing->X;
	this->PlayerY = Start_From_Existing->Y;
	
	Double_Connection_with_Existing(Start_From_Existing, previous);
	
}

///////////////////////////////////////////���������� ���������////////////////////////////////////////////////////////////////////////

//����������� ��������� - ��������� ������ ������ ����, ���� �������� �� ������������ ����
void DanilasGame::Print_Messge_1()
{
	GoToMessagePosition();
	if (Start_From_Existing == nullptr)
	{
		cout << "���� ����� ���������� �� ������� ���� (" << NodesStorage.back()->symbol << "), ������� ����� ����: ";

		if (NodesStorage.back()->FirstNext == nullptr) cout << "1 ";
		if (NodesStorage.back()->SecondNext == nullptr) cout << "2 ";
		if (NodesStorage.back()->ThirdNext == nullptr) cout << "3 ";
		if (NodesStorage.back()->FourthNext == nullptr) cout << "4 ";
		if (NodesStorage.back()->FifthNext == nullptr) cout << "5 ";
		if (NodesStorage.back()->SixthNext == nullptr) cout << "6 ";
	}
	else
	{
		cout << "���� ����� ���������� �� ������� ���� (" << Start_From_Existing->symbol << "), ������� ����� ����: ";

		if (Start_From_Existing->FirstNext == nullptr) cout << "1 ";
		if (Start_From_Existing->SecondNext == nullptr) cout << "2 ";
		if (Start_From_Existing->ThirdNext == nullptr) cout << "3 ";
		if (Start_From_Existing->FourthNext == nullptr) cout << "4 ";
		if (Start_From_Existing->FifthNext == nullptr) cout << "5 ";
		if (Start_From_Existing->SixthNext == nullptr) cout << "6 ";
	}

	cout << "\n\n";

	cout << "���� ������ ������� � ������ ����, ������� ��� ������. ";
}

///////////////////////////////////////////������ � ������������ �������////////////////////////////////////////////////////////////////////////

//����� ����� ������������, ���� ���������� ������� �� �����
void DanilasGame::Draw_Or_Downloads()
{
	if (DownloadFromFileFlag)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(DRAW_GRAPH_ANIMATION));
		ButtonCod = From_File[EventIndex];
		++EventIndex;
	}
	else
	{
		ButtonCod = _getch();
		EventsBuffer.push_back(ButtonCod);
	}
}

//��������� �� ���� ������������ � ����
void DanilasGame::GraphSaveORRquest()
{
	if (!DownloadFromFileFlag)
	{
		Print_Message_5();

		ButtonCod = _getch();

		for (;;)
		{
			if (ButtonCod == 49)
			{
				for (;;)
				{
					EraseMessage();

					Print_Message_7();

					string fileName;

					getline(cin, fileName);

					ToFile.open(fileName, ios::binary);

					if (!ToFile.is_open())  continue;
					
					break;
				}

				for (short temp : EventsBuffer)
				{
					ToFile.write((char*)&temp, sizeof(short));
				}
				ToFile.close();

				EraseMessage();

				return;
			}
			if (ButtonCod == 50) return;
		}
	}
}

/////////////////////////////////////////////////������ � ��������/////////////////////////////////////////////////////////////////////

// �������� ���� �������
void DanilasGame::Change_Symbol_Color(const int& color)
{
	SetConsoleTextAttribute(hConsole, color);
}

// �������� ������
void DanilasGame::HIDE_CURSOR(const bool& visability)
{
	GetConsoleCursorInfo(hConsole, &MyCursor);
	MyCursor.bVisible = visability;
	SetConsoleCursorInfo(hConsole, &MyCursor);
}

// ����������� ������ �� �����������
void DanilasGame::GoToXY(const short& x, const short& y, const char& symbol)
{
	COORD Axes = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Axes);
	cout << symbol;
}