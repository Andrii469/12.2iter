#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void Enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* first);
void Process(Elem* L, Info req_item);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Elem* first = NULL,
		* last = NULL;

	Info info, N;

	do
	{
		cout << "������ ������� �������� ������: "; cin >> N;
	} while (N < 0);

	for (int i = 0; i < N; i++)
	{
		cout << "������ ����: "; cin >> info;
		Enqueue(first, last, info);
	}

	cout << "�������� �����: "; Print(first); cout << endl;
	cout << "������ ���� ������� ������� ������������: "; cin >> info;
	cout << "������������� ������: ";
	Process(first, info);
	Print(first);

	return 0;
}
void Enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
}
void Print(Elem* L)
{
	while (L != NULL)
	{
		cout << L->info << " ";
		L = L->link;
	}
}
void Process(Elem* L, Info req_item)
{
	while (L != NULL)
	{
		if (L->info == req_item)
		{
			Elem* tmp = new Elem;   //1 - ��������� ������ ����������� ��������
			tmp->info = req_item;   //2 - ��������� �������� ������ info
			tmp->link = L->link;    //3 - �� � �������� ������� ������������
			L->link = tmp;          //4 - ���������� ����������� �������� � ������ 

			L = L->link;            //5 - ��������� ���������� �� ������
		}
		L = L->link;                //6 - ��������� ���������� �� ������
	}
}