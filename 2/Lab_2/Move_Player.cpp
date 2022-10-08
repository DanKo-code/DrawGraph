#include "DrawGraf.h"

DanilasGame::Node* DanilasGame::Move_Player(string FileName)
{
	if (FileName != "VOID")
	{
		FromFile.open(FileName);

		if (FromFile.is_open())
		{
			while (FromFile.read((char*)&Event, sizeof(short)))
			{
				From_File.push_back(Event);
			}

			FromFile.close();

			DownloadFromFileFlag = true;
		}
		else
		{
			cout << "Open error!!!";
			return nullptr;//////////////////////////////////////////////////////////////!&&&&&&&&&&&&&&&&&&&&&&
		}

	}

	HIDE_CURSOR(false);
	for (;;)
	{
		//ButtonCod = _getch();
		//EventsBuffer.push_back(ButtonCod);

		Draw_Or_Downloads();

		switch (ButtonCod)
		{
		//Drow node (b)
		case 98:
		{
			setlocale(0, "rus");

			Change_Symbol_Color(Colors::YELLOW);
			GoToXY(this->PlayerX, this->PlayerY, NodeSymbol);

			// Стартовый случай
			if (NodesStorage.empty())
			{
				NodesStorage.push_back(new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY));
			}
			else
			{
				// Объявляю новые узлы
				Create_New_Node();

				Print_Message_3();
					
				Double_Connection_with_New();

				EraseMessage();
			}

			Start_From_Existing = nullptr;
			Change_Symbol_Color(Colors::WHITE);

			Handle_Node_Сreation();

			break;
		}

		//Pen up down (p)
		case 112:
		{
			penDown = !penDown;
			break;
		}

		//UP
		case 119:
		{
			if (!penDown)
			{
				GoToXY(this->PlayerX, this->PlayerY, ' ');
			}

			this->PlayerY--;

			//Выход за предел поля
			if (!this->PlayerY)
			{
				GoToXY(this->PlayerX, ++(this->PlayerY), PLAYER_SYMBOL);
				break;
			}

			// Чтобы, при рисовании ребер не стереть существующий узел
			for (int i = 0; i < NodesStorage.size(); i++)
			{
				if (this->PlayerX == NodesStorage[i]->X && this->PlayerY == NodesStorage[i]->Y)
				{
					Print_Messge_2();
	
					Input_to_Existing_Node(i, ButtonCod);

					Flag = true;
					break;
				}
			}

			if (Flag)
			{
				Flag = false;
				break;
			}

			//Случай обычного передвижения
			GoToXY(this->PlayerX, this->PlayerY, PLAYER_SYMBOL);
			break;
		}

		//DOWN
		case 115:  
		{
			if (!penDown)
			{
				GoToXY(this->PlayerX, this->PlayerY, ' ');
			}

			this->PlayerY++;

			if (this->PlayerY == this->Field_Height + 2 - 1)
			{
				GoToXY(this->PlayerX, --(this->PlayerY), PLAYER_SYMBOL);
				break;
			}

			for (int i = 0; i < NodesStorage.size(); i++)
			{
				if (this->PlayerX == NodesStorage[i]->X && this->PlayerY == NodesStorage[i]->Y)
				{
					Print_Messge_2();

					Input_to_Existing_Node(i, ButtonCod);

					Flag = true;
					break;
				}
			}

			if (Flag)
			{
				Flag = false;
				break;
			}

			GoToXY(this->PlayerX, this->PlayerY, PLAYER_SYMBOL);
			break;
		}

		//LEFT
		case 97:
		{
			if (!penDown)
			{
				GoToXY(this->PlayerX, this->PlayerY, ' ');
			}

			this->PlayerX--;

			if (!PlayerX)
			{
				GoToXY(++(this->PlayerX), this->PlayerY, PLAYER_SYMBOL);
				break;
			}

			for (int i = 0; i < NodesStorage.size(); i++)
			{
				if (this->PlayerX == NodesStorage[i]->X && this->PlayerY == NodesStorage[i]->Y)
				{
					Print_Messge_2();

					Input_to_Existing_Node(i, ButtonCod);

					Flag = true;
					break;
				}
			}

			if (Flag)
			{
				Flag = false;
				break;
			}

			GoToXY(this->PlayerX, this->PlayerY, PLAYER_SYMBOL);
			break;
		}

		//RIGHT
		case 100:
		{
			if (!penDown)
			{
				GoToXY(this->PlayerX, this->PlayerY, ' ');
			}

			this->PlayerX++;

			if (this->PlayerX == this->Field_Width + 2 - 1)
			{
				GoToXY(--(this->PlayerX), this->PlayerY, PLAYER_SYMBOL);
				break;
			}

			for (int i = 0; i < NodesStorage.size(); i++)
			{
				if (this->PlayerX == NodesStorage[i]->X && this->PlayerY == NodesStorage[i]->Y)
				{
					Print_Messge_2();

					Input_to_Existing_Node(i, ButtonCod);

					Flag = true;
					break;
				}
			}

			if (Flag)
			{
				Flag = false;
				break;
			}

			GoToXY(this->PlayerX, this->PlayerY, PLAYER_SYMBOL);
			break;
		}

		//END
		case 239:
		{
			GraphSaveORRquest();

			return NodesStorage[0];
		}
		}
	}
	HIDE_CURSOR(true);

}