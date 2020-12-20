#include "pch.h"
#include "CppUnitTest.h"
#include "../12.2.rec/12.2.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My122rectest
{
	TEST_CLASS(My122rectest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Spusok* first = NULL;
			Spusok* last = NULL;
			Spusok* T;

			int index = 4, x = 6;
			Creata(first, last, index, x);

			T = first;
			COUT(T, 0, x, index);

			T = first;
			int z = 6;
			Process(T, z, 0);
			T = first;
			int l = T->inf;
			Assert::AreEqual(l, 10);
		}
	};
}
