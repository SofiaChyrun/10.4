#include "pch.h"
#include "CppUnitTest.h"
#include "../ChyrunSofialab10.4/ChyrunSofialab10.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest104
{
	TEST_CLASS(UnitTest104)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			char str[12] = "sabhhd hkv.";
			t = MinLength(str);
			Assert::AreEqual(t, 6);
		}
	};
}
