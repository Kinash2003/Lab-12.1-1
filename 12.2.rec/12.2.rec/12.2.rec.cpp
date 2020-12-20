#include <iostream>
#include <Windows.h>

using namespace std;

typedef int inform;

struct Spusok
{
	Spusok* link1;
	inform inf;
};

int Creata(Spusok*& first, Spusok*& last, int index, int x);
int COUT(Spusok*& T, inform inf, int x, int index);
int Process(Spusok*& T, int z, inform inf);

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* first = NULL;
	Spusok* last = NULL;
	Spusok* T;

	int index = 0, x = 5;
	Creata(first, last, index, x);

	T = first;
	cout << "Вивід інформації про створені елементи: " << endl << endl;
	COUT(T, 0, x, index);
	cout << endl << endl;

	int z;
	cout << "Введіть певне значення, для вилучиння інформаційного поля кожного елемента: ";
	cin >> z;

	T = first;
	cout << endl;
	cout << "Вивід інформації про модифікований елемент" << endl << endl;
	Process(T, z, 0);
	cout << endl;

	return 0;
}

int Creata(Spusok*& first, Spusok*& last, int index, int x)
{
	Spusok* tmp = new Spusok;

	tmp->inf = index;
	tmp->link1 = NULL;
	if (first == NULL)
		first = tmp;
	else
		last->link1 = tmp;
	last = tmp;

	if (index < x - 1)
		return Creata(first, last, index + 1, x);
	else
		return 0;
}

int COUT(Spusok*& T, inform inf, int x, int index)
{
	if (T != NULL)
	{
		inf = T->inf;
		cout << inf << "   ";
	}

	if (T != NULL)
		return COUT(T->link1, inf, x, index + 1);
	else
		return 0;
}

int Process(Spusok*& T, int z, inform inf)
{
	if (T != NULL)
	{
		inf = T->inf;                         
		T->inf = inf + z;                     
		cout << T->inf << "   ";
	}
	if (T != NULL)
		return Process(T->link1, z, inf);      
	else
		return 0;
}