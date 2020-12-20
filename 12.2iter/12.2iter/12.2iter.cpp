#include <iostream>
#include <Windows.h>

using namespace std;

typedef int inform;

struct Spusok
{
	Spusok* link1;
	inform inf;
};

void Creata(Spusok*& first, Spusok*& last, inform inf);
void COUT(Spusok*& T);
void Process(Spusok*& T, int z);

void Creata(Spusok*& first, Spusok*& last, inform inf)
{
	Spusok* tmp = new Spusok;

	tmp->inf = inf;
	tmp->link1 = NULL;
	if (first == NULL)
		first = tmp;
	else
		last->link1 = tmp;
	last = tmp;
}

void COUT(Spusok*& T)
{
	inform inf;

	cout << "Вивід інформації про створені елементи: " << endl << endl;
	while (T != NULL)
	{
		inf = T->inf;
		cout << inf << "   ";
		T = T->link1;
	}
	cout << endl << endl;
}

void Process(Spusok*& T, int z)
{
	inform inf;

	cout << endl;
	cout << "Вивід інформації про модифікований елемент " << endl << endl;
	while (T != NULL)
	{
		inf = T->inf;            
		
		T->inf = inf + z;						
		cout << T->inf << "   ";
		T = T->link1;
		                  
	}
	cout << endl;
}



int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* first = NULL;
	Spusok* last = NULL;

	for (int i = 0; i < 5; i++)
		Creata(first, last, i);

	Spusok* T = first;
	COUT(T);
	T = first;

	int z;
	cout << "Введіть певне значення, для вилучиння інформаційного поля кожного елемента: ";
		
		
	cin >> z;
	Process(T, z);

	return 0;
}