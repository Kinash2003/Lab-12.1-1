#include "pch.h"
#include "CppUnitTest.h"
#include "../12.3.rec/12.3.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My123rectest
{
	TEST_CLASS(My123rectest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Spusok* first = NULL;
			Spusok* last = NULL;

			int index = 5, N = 2, i = 0;
			Creata(first, last, index, N, i);

			Spusok* T = first;

			int v1 = 5;

			T = first;
			Process(T, v1,last);
			T = first;

			int l = T->link1->inf;
			Assert::AreEqual(l, 5);
		}
	};
}
