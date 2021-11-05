// LeetCode_1317.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/********[将整数转换为两个无零整数的和]
	「无零整数」是十进制表示中 不含任何 0 的正整数。

	给你一个整数 n，请你返回一个 由两个整数组成的列表 [A, B]，满足：

	A 和 B 都是无零整数
	A + B = n
	题目数据保证至少有一个有效的解决方案。

	如果存在多个有效解决方案，你可以返回其中任意一个。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

using namespace std;

#define NUM 105

bool isExist0(int num)
{
		for (int i = 1; num / 10; i++)
		{
			if ((num % 10) == 0)
				return true;
			num = num / 10;
		}
		return false;
}

vector<int> getNoZeroIntegers(int n) {
	for (int i = 1; i < n; i++)
	{
		if (!isExist0(i))
		{
			if (!isExist0(n - i))
			{
				return vector<int> {i, n - i};
			}
		}
	}
}

int main()
{

    std::cout << "Hello World!\n";
	cout << getNoZeroIntegers(NUM).at(0)<<","<< getNoZeroIntegers(NUM).at(1) << endl;
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
