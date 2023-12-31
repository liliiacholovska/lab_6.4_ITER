﻿#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.4(1)/lab6.4(1).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			double arr[n] = { -6.0, -2.0, 1.0, 3.0, 4.0 };

			Assert::AreEqual(findMaxAbsIndex(arr, n), 0);
			Assert::AreEqual(sumAfterFirstPositive(arr, n), 7.0);
		}
	};
}
