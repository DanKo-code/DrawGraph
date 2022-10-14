#include "DrawGraf.h"

// Создание поля
void DanilasGame::Create_Field(const short& Field_Width, const short& Field_Height)
{
	HIDE_CURSOR(false);

	this->Field_Width = Field_Width;
	this->Field_Height = Field_Height;

	Change_Symbol_Color(Colors::RED); // изменил цвет на красный

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

	Change_Symbol_Color(Colors::WHITE); // изменил цвет на обычный

	HIDE_CURSOR(true);
}

// Стартовая позиция игрока
void DanilasGame::Create_Player()
{
	this->PlayerX = Field_Width / 2;
	this->PlayerY = Field_Height / 2;

	GoToXY(this->PlayerX, this->PlayerY, PLAYER_SYMBOL);
}
 
////////////////////////////////////////////Методы для построения самого графа/////////////////////////////////////////////////////////

// Объявляю новые узлы
void DanilasGame::Create_New_Node()
{
	// Объявляю новые узлы
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
					return;
				}
				else
				{
					NodesStorage.back()->FirstNext = Start_From_Existing;
					return;
				}
			}

			case 2:
			{
				if (Start_From_Existing == nullptr)
				{
					NodesStorage.back()->SecondNext = NodesStorage[NodesStorage.size() - 2];
					return;
				}
				else
				{
					NodesStorage.back()->SecondNext = Start_From_Existing;
					return;
				}
			}

			case 3:
			{
				if (Start_From_Existing == nullptr)
				{
					NodesStorage.back()->ThirdNext = NodesStorage[NodesStorage.size() - 2];
					return;
				}
				else
				{
					NodesStorage.back()->ThirdNext = Start_From_Existing;
					return;
				}
			}

			case 4:
			{
				if (Start_From_Existing == nullptr)
				{
					NodesStorage.back()->FourthNext = NodesStorage[NodesStorage.size() - 2];
					return;
				}
				else
				{
					NodesStorage.back()->FourthNext = Start_From_Existing;
					return;
				}
			}

			case 5:
			{
				if (Start_From_Existing == nullptr)
				{
					NodesStorage.back()->FifthNext = NodesStorage[NodesStorage.size() - 2];
					return;
				}
				else
				{
					NodesStorage.back()->FifthNext = Start_From_Existing;
					return;
				}
			}

			case 6:
			{
				if (Start_From_Existing == nullptr)
				{
					NodesStorage.back()->SixthNext = NodesStorage[NodesStorage.size() - 2];
					return;
				}
				else
				{
					NodesStorage.back()->SixthNext = Start_From_Existing;
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

//Убрать!!!
void DanilasGame::Double_Connection_with_Existing(Node* existing, Node* previous)
{
	Print_Message_3();

	Draw_Or_Downloads();

	if (ButtonCod == 49)
	{
		if (existing->FirstNext == nullptr)
		{
			existing->FirstNext = previous;
			return;
		}
		if (existing->SecondNext == nullptr)
		{
			existing->SecondNext = previous;
			return;
		}
		if (existing->ThirdNext == nullptr)
		{
			existing->ThirdNext = previous;
			return;
		}
		if (existing->FourthNext == nullptr)
		{
			existing->FourthNext = previous;
			return;
		}
		if (existing->FifthNext == nullptr)
		{
			existing->FifthNext = previous;
			return;
		}
		if (existing->SixthNext == nullptr)
		{
			existing->SixthNext = previous;
			return;
		}

	}
	if (ButtonCod == 50)
	{
		return;
	}

	Print_Message_4();
}

//Обработка выбора номера пути, либо перехода на существующуй узел
void DanilasGame::Handle_Node_Сreation()
{
	Print_Messge_1();

	for (;;)
	{
	RESTART:

		Draw_Or_Downloads();

		//////////////////Пути/////////////////////
		switch (ButtonCod)
		{
		case 49:
		{
			//Проверка, чтобы не переписать существующие связи
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
		//////////////////Пути/////////////////////

		default:
		{
			for (int i = 0; i < NodesStorage.size(); i++)
			{
				if (ButtonCod == NodesStorage[i]->symbol)
				{
					this->PlayerX = NodesStorage[i]->X;
					this->PlayerY = NodesStorage[i]->Y;

					Start_From_Existing = NodesStorage[i];

					EraseMessage();

					//
					Handle_Node_Сreation();

					EraseMessage();

					return;
				}
			}
		}

		}
	}
}

//Обработка выбора связать с попавщимся узлом
void DanilasGame::Input_to_Existing_Node(int& i, int buttonCode)
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
				
			Handle_Node_Сreation();

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

//Связываем с попавшимся
void DanilasGame::ConnectWithExisting(Node** buffer, int& i, Node* previous)
{
	//Убрать!!!
	(*buffer) = NodesStorage[i];
	Start_From_Existing = *buffer;

	this->PlayerX = Start_From_Existing->X;
	this->PlayerY = Start_From_Existing->Y;
	
	Double_Connection_with_Existing(Start_From_Existing, previous);
	
}

///////////////////////////////////////////Распечатка сообщений////////////////////////////////////////////////////////////////////////

//Распечатать Сообщение - Обработка выбора номера пути, либо перехода на существующуй узел
void DanilasGame::Print_Messge_1()
{
	GoToMessagePosition();
	if (Start_From_Existing == nullptr)
	{
		cout << "Если хотит продолжить на текущем узле (" << NodesStorage.back()->symbol << "), укажите номер пути: ";

		if (NodesStorage.back()->FirstNext == nullptr) cout << "1 ";
		if (NodesStorage.back()->SecondNext == nullptr) cout << "2 ";
		if (NodesStorage.back()->ThirdNext == nullptr) cout << "3 ";
		if (NodesStorage.back()->FourthNext == nullptr) cout << "4 ";
		if (NodesStorage.back()->FifthNext == nullptr) cout << "5 ";
		if (NodesStorage.back()->SixthNext == nullptr) cout << "6 ";
	}
	else
	{
		cout << "Если хотит продолжить на текущем узле (" << Start_From_Existing->symbol << "), укажите номер пути: ";

		if (Start_From_Existing->FirstNext == nullptr) cout << "1 ";
		if (Start_From_Existing->SecondNext == nullptr) cout << "2 ";
		if (Start_From_Existing->ThirdNext == nullptr) cout << "3 ";
		if (Start_From_Existing->FourthNext == nullptr) cout << "4 ";
		if (Start_From_Existing->FifthNext == nullptr) cout << "5 ";
		if (Start_From_Existing->SixthNext == nullptr) cout << "6 ";
	}

	cout << "\n\n";

	cout << "Если хотите перейти в другой узел, введите его символ. ";
}

///////////////////////////////////////////Работа с сохраненными графами////////////////////////////////////////////////////////////////////////

//Ждать ввода пользователя, либо считывание событий из файла
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

//Сохранять ли граф пользователя в файл
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
				ToFile.open("Graph.txt", ios::binary);

				for (short temp : EventsBuffer)
				{
					ToFile.write((char*)&temp, sizeof(short));
				}
				ToFile.close();

				return;
			}
			if (ButtonCod == 50) return;
		}
	}
}

/////////////////////////////////////////////////Работа с консолью/////////////////////////////////////////////////////////////////////

// Поменять цвет символа
void DanilasGame::Change_Symbol_Color(const int& color)
{
	SetConsoleTextAttribute(hConsole, color);
}

// Спрятать курсор
void DanilasGame::HIDE_CURSOR(const bool& visability)
{
	GetConsoleCursorInfo(hConsole, &MyCursor);
	MyCursor.bVisible = visability;
	SetConsoleCursorInfo(hConsole, &MyCursor);
}

// Переместить курсор по координатам
void DanilasGame::GoToXY(const short& x, const short& y, const char& symbol)
{
	COORD Axes = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Axes);
	cout << symbol;
}