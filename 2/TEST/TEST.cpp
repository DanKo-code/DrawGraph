#include <iostream>
#include <vector>
//#include <pair>
#include <conio.h>


#include <fstream>

using namespace std;

/*class Node
{
public:

	Node(int data = 0, char symbol = char(), short X = short(), short Y = short(), Node* FirstNext = nullptr, Node* SecondNext = nullptr, Node* ThirdNext = nullptr, Node* FourthNext = nullptr, Node* FifthNext = nullptr)
	{
		this->data = data;

		this->symbol = symbol;

		this->X = X;
		this->Y = Y;

		this->FirstNext = FirstNext;
		this->SecondNext = SecondNext;
		this->ThirdNext = ThirdNext;
		this->FourthNext = FourthNext;
		this->FifthNext = FifthNext;

		this->CurrentNodeAddress = this;
	}

	int data = int();

	char symbol = char();

	short X = short();
	short Y = short();

	Node* CurrentNodeAddress;

	Node* FirstNext;
	Node* SecondNext;
	Node* ThirdNext;
	Node* FourthNext;
	Node* FifthNext;

};
*/


class DanilasGame
{
public:

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

	vector<Node*> NodesStorage;
	char NodeSymbol = 65;

	short PlayerX = 10;
	short PlayerY = 20;

	void TestMemory()
	{
		NodesStorage.push_back(new Node(rand() % 100, NodeSymbol++, this->PlayerX, this->PlayerY));
	}
};


int main()
{
	//Работа с файлами
	/*
	int a = 1;
	short Short_buffer;

	vector<short> From_File;

	vector<short> buffer = { 1,2,23,4,7 };
	ofstream tfile("Moves.txt", ios::binary);

	for (short temp : buffer)
	{
		tfile.write((char*)&temp, sizeof(short));
	}
	tfile.close();

	ifstream ffile("C:/2курс, 1 сем/СД/2/TEST/Moves.txt");

	if (ffile.is_open())
	{
		while (ffile.read((char*)&Short_buffer, sizeof(short)))
		{
			From_File.push_back(Short_buffer);
		}
	}
	else
	{
		cout << "Open error!!!";
	}

	for (int i = 0; i < From_File.size(); i++)
	{
		cout << From_File[i] << endl;
	}

	ffile.close();
	*/

	////////////////////////////////////////////////////////////////

	/*DanilasGame Graf;

	Graf.TestMemory();*/
	
	////////////////////////////////////////////////////////////////

	short test = _getch();

	pair<char, int> pair_1('A',2);
	pair<char, int> pair_2('B',2);

	bool res = pair_1 == pair_2;

	//pair_1.swap(pair_2);

	//map.

	vector<int> a = { 1,2,3,4 };

	for (auto iter = a.cbegin(); iter != a.cend(); iter++)
	{
		if (*iter == 3)
		{
			int temp = *iter;

			a.erase(iter);

			a.push_back(temp);

			

			break;
		}


	}

	cout << endl;

	for (int temp : a)
	{
		cout << temp << " ";
	}

	



	
}