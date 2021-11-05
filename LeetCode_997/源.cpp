#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

	vector<int> sortedSquares(vector<int>& A) {
		int Size = A.size();
		for (int i = 0; i < Size; i++)
		{
			A[i] = pow(A[i], 2);
		}

		int j = 0, temp=0;

		//ÅÅÐò
		while (A[0] > A[1])
		{
			for ( ; j < Size; j++)
			{
				if (A[j] <= A[j + 1])
				{
					break;
				}
				else
				{
					temp = A[j + 1];
					A[j + 1] = A[j];
					A[j] = temp;
				}
			}
		}
		return A;
	}


void main()
{
	vector <int> nums1;
	//vector <int> nums2;

	nums1 = {-9 ,-6,-5,-3,-2,0,5,6,9,10 };
	//nums2 = { 2 };
	vector <int> result = sortedSquares(nums1);
	int length = result.size();
	for (int i = 0; i < length; i++)
	{
		printf_s("%d ", result[i]);
	}
	//printf_s("%f", result);
}