#include<iostream>

using namespace std;

struct Node
{
	int   data;//store weight
	char  c;//store vertice name
	Node* link;
	Node* next;
};

int main()
{
	char ch = 'Y';

	Node *cc, *pp, *ff;
	Node *cc1, *pp1, *ff1;
	cc = pp =  ff = NULL;
	while (true)
	{
		cc = new Node;
		cc->next = NULL;
		cout << "Enter Name of vertice: ";
		cin >> cc->c;

		cc1 = pp1 = ff1 = NULL;
		while (true)
		{
			cin.ignore(10, '\n');
			cout << "Do You Have Another Connection (y/n): ";
			cin >> ch;

			if (toupper(ch) != 'Y')
				break;

			cc1 = new Node;
			cc1->next = NULL;
			
			cout << "Enter Name To which Connected: ";
			cin >> cc1->c;
			cout << "Enter Weight: ";
			cin >> cc1->data;

			if (ff1 == NULL)
				ff1 = pp1 = cc1;
			else
			{
				pp1->next = cc1;
				pp1 = cc1;
			}
			
			
		}
		cc->link = ff1;

		if (ff == NULL)
			ff = pp = cc;
		else
		{
			pp->next = cc;
			pp = cc;
		}
		cin.ignore(10, '\n');
		cout << "\n\nDo You Have Another vertice (y/n): ";
		cin >> ch;

		if (toupper(ch) != 'Y')
			break;
	}
	cc = ff;
	cout << "\nDisplay...\n";
	while (cc)
	{
		cout << cc->c ;
		cc1 = cc->link;
		while (cc1)
		{
			cout << " -> " << cc1->c << " " << cc1->data;
			cc1 = cc1->next;
		}
		cout << "\n";
		cc = cc->next;
	}

	system("pause");
}