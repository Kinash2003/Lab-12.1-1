#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int inform;

struct Spusok
{
	Spusok* link1,
		* link2;
	inform inf;
};

void Creata(Spusok*& first, Spusok*& last, inform inf);
void COUT(Spusok*& T);
void Process(Spusok*& T, inform L1, Spusok*& last);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* first = NULL;
	Spusok* last = NULL;

	int x = 0;
	for (int i = 0; i < 4; i++)
	{
		x = rand() % 6;
		Creata(first, last, x);
	}

	Spusok* T = first;
	COUT(T);


	int L1;
	
	cout << "Введіть L1: ";	cin >> L1;
	cout << endl;
	

	T = first;
	Process(T, L1,last);
	T = first;
	COUT(T);

	return 0;
}

void Creata(Spusok*& first, Spusok*& last, inform inf)
{
	Spusok* tmp = new Spusok;

	tmp->inf = inf;
	tmp->link1 = NULL;
	tmp->link2 = NULL;
	if (first == NULL)
		first = tmp;
	else
	{
		last->link1 = tmp;
		tmp->link2 = last;
	}
	last = tmp;
}

void COUT(Spusok*& T)
{
	
	inform inf;
	cout << "L2: " << endl;
	while (T != NULL)
	{
		inf = T->inf;
		cout << inf << "   ";
		T = T->link1;
	}
	cout << endl;
}

void Process(Spusok*& T,inform L1,Spusok*& last)
{
	while (T != NULL)
	{
		if (T->inf == L1)
		{
			Spusok* tmp = new Spusok;  
			tmp->inf = L1;            
			tmp->link1 = T->link1;    
			if (T->link1 != NULL)
				T->link1->link2 = tmp;
			else
				last = tmp;           
			T->link1 = tmp;          
			tmp->link2 = T;           
			T = T->link1->link1;       
		}
		else
			T = T->link1;            
	}
}