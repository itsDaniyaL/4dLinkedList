#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
public:
	char Data;
	Node* NextN;
	Node* Prev;
	Node* Up;
	Node* Bottom;
	Node()
	{
		NextN = nullptr;
		Prev = nullptr;
		Up = nullptr;
		Bottom = nullptr;
	}
	Node(char _data)
	{
		Data = _data;
		NextN = nullptr;
		Prev = nullptr;
		Up = nullptr;
		Bottom = nullptr;
	}
};

class StackUndoRedo
{
public:
	Node* Store;
	int IncrDecr;
	int Max;
	StackUndoRedo()
	{
		Max = 3;
	}
};

class LinkedList
{
	Node* Top;
	Node* Head;
	Node* MultiPur;
	Node* Replace;
	Node* HeadPrev;
	Node* HeadTemp;
	Node* Tail;
public:
	LinkedList()
	{
		Head = new Node;
		HeadTemp = Head;
	}
	LinkedList(int _Data)
	{
		Head = new Node(_Data);
		HeadTemp = Head;
	}

	void Add_HeadTemp()
	{
		HeadPrev = HeadTemp;
		HeadTemp = new Node;
		HeadTemp->Up = HeadPrev;
		HeadPrev->Bottom = HeadTemp;
	}

	void AddMultiPur()
	{
		MultiPur = new Node;
	}

	void AddReplace()
	{
		Replace = new Node;
	}

	//For adding nodes(Characters)
	void Add_Node(char Text, int Count)
	{
		//For the First Line Being Entered
		if (Count == 0)
		{
			Node* CurrentN = Head;
			while (CurrentN->NextN != nullptr)
			{
				CurrentN = CurrentN->NextN;
			}
			CurrentN->NextN = new Node(Text);
			CurrentN->NextN->Prev = CurrentN;
		}

		//For Searching Word
		else if (Count == 2)
		{
			Node* CurrentN = MultiPur;
			while (CurrentN->NextN != nullptr)
			{
				CurrentN = CurrentN->NextN;
			}
			CurrentN->NextN = new Node(Text);
			CurrentN->NextN->Prev = CurrentN;
		}

		//For Replace Word
		else if (Count == 3)
		{
			Node* CurrentN = Replace;
			while (CurrentN->NextN != nullptr)
			{
				CurrentN = CurrentN->NextN;
			}
			CurrentN->NextN = new Node(Text);
			CurrentN->NextN->Prev = CurrentN;
		}

		//For the rest of the lines
		else
		{
			Node* CurrentN = HeadTemp;
			Node* CurrentN1 = HeadPrev;
			while (CurrentN->NextN != nullptr)
			{
				CurrentN = CurrentN->NextN;
				if (CurrentN1->NextN != nullptr)
				{
					CurrentN1 = CurrentN1->NextN;
				}
			}
			CurrentN->NextN = new Node(Text);
			CurrentN->NextN->Prev = CurrentN;
			if (CurrentN1->NextN != nullptr)
			{
				CurrentN->NextN->Up = CurrentN1->NextN;
				CurrentN1->NextN->Bottom = CurrentN->NextN;
			}
		}
	}

	//For displaying the Note Pad
	void Display()
	{
		Node* HeadTemp1 = Head;
		Node* CurrentN = Head->NextN;
		while (CurrentN->NextN != nullptr || CurrentN->Bottom != nullptr)
		{
			if (CurrentN->NextN != nullptr)
			{
				cout << CurrentN->Data;
			}
			else if (CurrentN->Bottom != nullptr)
			{
				HeadTemp1 = HeadTemp1->Bottom;
				cout << endl;
				CurrentN = HeadTemp1;
			}
			CurrentN = CurrentN->NextN;
		}
	}

	//For the searching a word's location in the whole Note Pad
	void Searchfunc()
	{
		cout << "Hi Im Cortana" << endl;
		Node* HeadTemp1 = Head;
		int X = 0, Y = 0;
		Node* CurrentN = Head;
		Node* CurrentN1 = MultiPur->NextN;
		while (CurrentN->NextN != nullptr || CurrentN->Bottom != nullptr)
		{
			if (CurrentN->Data == CurrentN1->Data)
			{
				while (CurrentN->Data == CurrentN1->Data)
				{
					CurrentN = CurrentN->NextN;
					CurrentN1 = CurrentN1->NextN;
				}
				if (CurrentN->Data == CurrentN1->Data || CurrentN1->NextN == nullptr)
				{
					cout << endl << "X :" << X << " and Y :" << Y << endl;
					CurrentN1 = MultiPur->NextN;
				}
			}
			if (CurrentN->NextN == nullptr)
			{
				CurrentN = HeadTemp1->Bottom;
				X = 0;
				Y++;
			}
			CurrentN = CurrentN->NextN;
			X++;
		}

		Node* OldN;
		CurrentN1 = MultiPur->NextN;
		while (CurrentN1->NextN != nullptr)
		{
			OldN = CurrentN1;
			CurrentN1 = CurrentN1->NextN;
			delete OldN;
		}
	}

	//For replacing word with another word
	void Replacefunc()
	{
		Node* HeadTempRe;
		Node* HeadTemp1 = Head;
		Node* HeadTemp2 = nullptr;
		Node* CurrentN = Head;
		Node* CurrentN1 = MultiPur->NextN;
		Node* CurrentN2 = Replace->NextN;
		while (CurrentN->NextN != nullptr || CurrentN->Bottom != nullptr)
		{
			if (CurrentN->Data == CurrentN1->Data)
			{
				while (CurrentN->Data == CurrentN1->Data)
				{
					HeadTemp2 = CurrentN;
					CurrentN = CurrentN->NextN;
					CurrentN1 = CurrentN1->NextN;
				}
				if (CurrentN->Data == CurrentN1->Data && CurrentN1->NextN == nullptr)
				{
					CurrentN1 = MultiPur->NextN;
					HeadTempRe = HeadTemp2;
					while (CurrentN1->NextN != nullptr)
					{
						HeadTempRe->Data = CurrentN2->Data;
						CurrentN2 = CurrentN2->NextN;
						HeadTempRe = HeadTempRe->NextN;
						CurrentN1 = CurrentN1->NextN;
					}
					CurrentN2 = Replace->NextN;
				}
			}
			if (CurrentN->NextN == nullptr)
			{
				CurrentN = HeadTemp1->Bottom;
			}
			CurrentN = CurrentN->NextN;
		}
		Node* OldN;
		CurrentN1 = MultiPur->NextN;
		while (CurrentN1->NextN != nullptr)
		{
			OldN = CurrentN1;
			CurrentN1 = CurrentN1->NextN;
			delete OldN;
		}
	}

	//For changing the color of the Note Pad
	void ChangeFont()
	{
		int Pick;
		cout << "Pick your Desirable Color :\n0)Black\n1)BLue\n2)Green\n3)Aqua\n4)Red\n5)Purple\n6)Yellow\n7)White\n8)Gray\n9)Light Blue\n" << endl;
		cin >> Pick;
		if (Pick == 0)
		{
			system("color 0");
		}
		else if (Pick == 1)
		{
			system("color 1");
		}
		else if (Pick == 2)
		{
			system("color 2");
		}
		else if (Pick == 3)
		{
			system("color 3");
		}
		else if (Pick == 4)
		{
			system("color 4");
		}
		else if (Pick == 5)
		{
			system("color 5");
		}
		else if (Pick == 6)
		{
			system("color 6");
		}
		else if (Pick == 7)
		{
			system("color 7");
		}
		else if (Pick == 8)
		{
			system("color 8");
		}
		else if (Pick == 9)
		{
			system("color 9");
		}
		else
		{
			cout << "Wrong Input!\n" << endl;
			system("pause");
		}
	}

	//For Backspacing characters being entered
	void BackSpace()
	{
		Node* CurrentN = HeadTemp;
		while (CurrentN->NextN != nullptr)
		{
			CurrentN = CurrentN->NextN;
		}

		if (CurrentN->Up)
		{
			CurrentN->Up->Bottom = nullptr;
		}
		if (CurrentN->Bottom)
		{
			CurrentN->Bottom->Up = nullptr;
		}
		CurrentN = nullptr;
	}

	//For destroying the Nodes at the end of the Program
	~LinkedList()
	{
		Node* CurrentN = Head;
		while (CurrentN == nullptr)
		{
			while (CurrentN->NextN != nullptr)
			{
				CurrentN = CurrentN->NextN;
			}
			while (CurrentN->Prev == Head)
			{
				Node* OldN = CurrentN;
				delete OldN;
				CurrentN = CurrentN->Prev;
			}
			CurrentN = CurrentN->Bottom;
		}
	}
};

int main()
{
	char Text;
	int Count = 0;
	bool Condi = true;
	LinkedList List;
	int Pick;
	while (Condi)
	{
		cout << "Pick One :" << endl;
		cout << "1)Enter Data\n2)Search\n3)Replace Data\n4)Delete\n5)Undo\n6)Redo\n7)Change Font\n8)Exit" << endl;
		cin >> Pick;
		system("cls");
		if (Pick == 1)
		{
			cout << "To Exit press *" << endl;
			do
			{
				Text = _getch();

				if (Text != '*')
				{
					if (Text == '\r')
					{
						Count = 1;
						cout << endl;
						List.Add_HeadTemp();
					}
					else if (Text == '\b')
					{
						List.BackSpace();
						system("cls");
						List.Display();
					}
					else if (Text != '\0')
					{
						List.Add_Node(Text, Count);
						cout << Text;
					}
				}
			} while (Text != '*');
			cout << endl;
			cout << "Press any key to go the Menu!" << endl;
			system("pause");
			cout << endl;
		}

		else if (Pick == 2)
		{
			List.AddMultiPur();
			cout << "Enter the Word :" << endl;
			do
			{
				Text = _getch();
				if (Text != '\0')
				{
					List.Add_Node(Text, 2);
					cout << Text;
				}
				if (Text == '\r')
				{
					break;
				}
			} while (Text != '\n' || Text != '\r');
			List.Searchfunc();
		}

		else if (Pick == 3)
		{
			List.AddMultiPur();
			cout << "Enter the Word you want to replace :" << endl;
			do
			{
				Text = _getch();
				cout << Text;
				List.Add_Node(Text, 2);
			} while (Text == '\n');
			cout << endl;
			List.AddReplace();
			cout << "Enter the word that you want to replace it with :" << endl;
			do
			{
				Text = _getch();
				cout << Text;
				List.Add_Node(Text, 3);
			} while (Text == '\n');
			List.Replacefunc();
		}

		else if (Pick == 4)
		{
			List.AddMultiPur();
			cout << "Enter the word you would like to delete :" << endl;
			do
			{
				Text = _getch();
				cout << Text;
				List.Add_Node(Text, 2);
			} while (Text == '\n');
		}

		else if (Pick == 7)
		{
			List.ChangeFont();
			system("cls");
		}

		else if (Pick == 8)
		{
			Condi = false;
		}
		else
		{
			cout << "Wrong Input!" << endl;
		}
	}
	system("pause");
}