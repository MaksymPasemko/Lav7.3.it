#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.3.it/pr7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            {
                int n = 3;
                int matrix[MAX_SIZE][MAX_SIZE] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, -8, 9}
                };

                int result = sumOfRowsWithoutNegatives(matrix, n);
                Assert::AreEqual(21, result);
            }
        }

            TEST_METHOD(TestFindMinOfParallelDiagonalSums)
            {
                int n = 3;
                int matrix[MAX_SIZE][MAX_SIZE] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, -8, 9}
                };

                int result = findMinOfParallelDiagonalSums(matrix, n);
                Assert::AreEqual(3, result);
            }
		
	};
}
