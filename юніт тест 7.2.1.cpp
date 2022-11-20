#include "pch.h"
#include "CppUnitTest.h"
#include "../лаба 7_2_1/лаба 7_2_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace юніттест721
{
	TEST_CLASS(юніттест721)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int s[1] = { 1 };
			int** a = new int* [1];
			for (int i = 0; i < 1; i++)
				a[i] = new int[1];
			Create(a, 1, 1,1,1);
			int minEven = 1;
			int maxEven = 1;
			int t = SearchMinEven(a, 1, minEven);
			int t2 = SearchMaxEven(a, 1, maxEven);
			Assert::AreEqual(t, 0);
		}
	};
}
