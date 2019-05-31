#include "stdafx.h"
#include "CppUnitTest.h"
#include"../Graphyv.1.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestGraphy
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Fineway)
		{
			int a = 1;
			int b = 7;
			int actual = ways(a,b);
			
			Assert::AreEqual(actual, 8);
		}

		TEST_METHOD(OneEmptyVertex)
		{
			char a = ' ';
			int b = 7;
			int actual = ways(a, b);

			Assert::AreNotEqual(actual, 8);
		}

		TEST_METHOD(OneDoubleVertex)
		{
			double a = 2.5;
			int b = 7;
			int actual = ways(a, b);

			Assert::AreNotEqual(actual, 8);
		}

		TEST_METHOD(TwoUnrealVertex)
		{
			int a = 20;
			int b = 30;
			int actual = ways(a, b);

			Assert::AreNotEqual(actual, 8);
		}

		TEST_METHOD(OneWordVertex)
		{
			char a = 'rer';
			int b = 30;
			int actual = ways(a, b);
			int c;
			
			Assert::AreNotEqual(actual, 8);
		}
	};
}