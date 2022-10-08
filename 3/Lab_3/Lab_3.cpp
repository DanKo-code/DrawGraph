#include <iostream>

using namespace std;

class Node
{
public:
	Node(char data = 0, Node* FirstNext = nullptr, Node* SecondNext = nullptr, Node* ThirdNext = nullptr)
	{
		this->data = data;

		this->CurrentNodeAddress = this;

		this->FirstNext = FirstNext;
		this->SecondNext = SecondNext;
		this->ThirdNext = ThirdNext;
	}

	char data;

	int FirstLength = 0;
	int SecondLength = 0;
	int ThirdLength = 0;

	Node* CurrentNodeAddress;

	Node* FirstNext;
	Node* SecondNext;
	Node* ThirdNext;


};

int main()
{
	//A
	Node* Start = new Node('A');
	Start->FirstNext = new Node('B');
	//Start->SecondNext = new Node('C');

	////B
	//Start->FirstNext->FirstNext = Start;
	//Start->FirstNext->SecondNext = new Node('F');
	//Start->FirstNext->ThirdNext = new Node('G');

	////C
	//Start->SecondNext->FirstNext = Start;
	//Start->SecondNext->SecondNext = Start->FirstNext->SecondNext;
	//Start->SecondNext->ThirdNext = new Node('E');

	////G
	//Start->FirstNext->ThirdNext->FirstNext = Start->FirstNext;
	//Start->FirstNext->ThirdNext->SecondNext = new Node('I');

	////F
	//Start->FirstNext->SecondNext->FirstNext = Start->FirstNext;
	//Start->FirstNext->SecondNext->SecondNext = Start->SecondNext;
	//Start->FirstNext->SecondNext->ThirdNext = new Node('H');

	////H
	//Start->FirstNext->SecondNext->ThirdNext->FirstNext = Start->FirstNext->SecondNext;
	//Start->FirstNext->SecondNext->ThirdNext->SecondNext = new Node('D');
	//Start->FirstNext->SecondNext->ThirdNext->ThirdNext = Start->FirstNext->ThirdNext->SecondNext;

	////E
	//Start->SecondNext->ThirdNext->FirstNext = Start->SecondNext;
	//Start->SecondNext->ThirdNext->SecondNext = Start->FirstNext->SecondNext->ThirdNext->SecondNext;
	//
	////D
	//Start->FirstNext->SecondNext->ThirdNext->SecondNext->FirstNext = Start->SecondNext->ThirdNext;
	//Start->FirstNext->SecondNext->ThirdNext->SecondNext->SecondNext = Start->FirstNext->SecondNext->ThirdNext;
	//Start->FirstNext->SecondNext->ThirdNext->SecondNext->ThirdNext = Start->FirstNext->ThirdNext->SecondNext;

	////I
	//Start->FirstNext->ThirdNext->SecondNext->FirstNext = Start->FirstNext->ThirdNext;
	//Start->FirstNext->ThirdNext->SecondNext->SecondNext = Start->FirstNext->SecondNext->ThirdNext;
	//Start->FirstNext->ThirdNext->SecondNext->ThirdNext = Start->FirstNext->SecondNext->ThirdNext->SecondNext;


}

