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

int Creata(Spusok*& first, Spusok*& last, int index, int N, int i);
int COUT(Spusok*& T, inform inf, int N, int index);
void Process(Spusok*& T, inform L1, Spusok*& last);

int main(void)
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* first = NULL;
	Spusok* last = NULL;

	int index = rand() % 6, N = 4, i = 0;
	Creata(first, last, index, N, i);

	Spusok* T = first;
	cout << "L2: " << endl << endl;
	COUT(T, 0, N, index);
	cout << endl << endl;

	int L1;
	
	cout << "Введіть L1: ";	cin >> L1;
	cout << endl;
	

	T = first;
	Process(T, L1,last);
	T = first;
	COUT(T, 0, N, index);

	return 0;
}

int Creata(Spusok*& first, Spusok*& last, int index, int N, int i)
{
	Spusok* tmp = new Spusok;

	tmp->inf = index;
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

	if (i < N - 1)
		return Creata(first, last, rand() % 6, N, i + 1);
	else
		return 0;
}

int COUT(Spusok*& T, inform inf, int N, int index)
{
	if (T != NULL)
	{
		inf = T->inf;
		cout << inf << "   ";
	}

	if (T != NULL)
		return COUT(T->link1, inf, N, index + 1);
	else
		return 0;
}

void Process(Spusok*& T, inform L1, Spusok*& last)
{
	if (T != NULL)
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
			return Process(T->link1->link1, L1, last);  
		}
		else
			return Process(T->link1, L1,  last);         
	}
}