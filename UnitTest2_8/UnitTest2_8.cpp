#include "pch.h"
#include "CppUnitTest.h"
#include "../oop2.8/Date.cpp"
#include "D:\Student\oop2.8\oop2.8\Date.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest28
{
	TEST_CLASS(UnitTest28)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Date a;
			bool t;
			t = a.GetGoods().Init(111, 222, 333);
			Assert::AreEqual(t, true);
		}
	};
}
