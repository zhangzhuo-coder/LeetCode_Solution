// LeetCode_Temp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


#define NUM 30

int N1 = 0;
int N2 = 0;

//递归斐波拉契数列
long long Fibnacci(long long n)
{
	N2++;
	if (n == 0 || n == 1)
		return 1;
	else
	{
		return Fibnacci(n - 1) + Fibnacci(n - 2);
	}
}

//动态规划斐波拉契数列
long long fastFib(long long n, long long (&memo)[NUM+1])
{
	N1++;
	if (n == 0 || n == 1)
		return 1;
	if (memo[n] != 0)
	{
		return memo[n];
	}
	else
	{
		memo[n] = fastFib(n - 1, memo) + fastFib(n - 2, memo);
		return memo[n];
	}
}


int main()
{
	long long arry[NUM+1];
	memset(arry, 0, (NUM+1)*sizeof(long long));
	std::cout << "Hello World!\n";
	cout << fastFib(NUM, arry) << endl;
	cout<< "计数：" << N1 << endl;
	cout << Fibnacci(NUM) << endl;
	cout << "计数：" << N2 << endl;
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
