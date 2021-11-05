// LeetCode_1646.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

int getMaximumGenerated(int n) {
	if (n < 1)
		return 0;
	if (n < 2)
		return 1;
	int* Array = new int[n + 1];
	int MaxNum = 1;
	Array[0] = 0;
	Array[1] = 1;

	for (int i = 1; i <= (n / 2) + 1; i++)
	{
		if (2 * i <= n)
		{
			Array[2 * i] = Array[i];
			MaxNum = MaxNum < Array[2 * i] ? Array[2 * i] : MaxNum;
		}
		if ((2 * i) + 1 <= n)
		{
			Array[2 * i + 1] = Array[i] + Array[i + 1];
			MaxNum = MaxNum < Array[2 * i + 1] ? Array[2 * i + 1] : MaxNum;
		}
	}
	return MaxNum;
}


int main()
{
	cout << "Hello World!\n";
	cout << getMaximumGenerated(2) << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
