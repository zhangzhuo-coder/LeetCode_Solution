// LeetCode_048.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int temp;
void swap(int * pNum1,int * pNum2)
{
	temp = *pNum1;
	*pNum1 = *pNum2;
	*pNum2 = temp;
}

int main()
{
	vector<vector<int>> matrix;
	matrix =
	{ {5, 1, 9, 11},
	{2, 4, 8, 10},
	{13, 3, 6, 7},
	{15, 14, 12, 16} };

	//首先确定矩阵 有多少行 有多少列
	int row = matrix.size();
	int col = matrix[0].size();

	short loop = col / 2;
	if (loop == 0)
	{
		return 0;
	}

	int r, c, l/*当前层数*/, offset/*每层的偏移量*/;
	for (l = 0; l < loop; l++)
	{
		for (offset = l; offset < row - 1 - l ; offset++)
		{
			//swap(&matrix[loop][offset], &matrix[loop + offset][col - l * 2]);

			//交换反转需要逆向思维，以第1层来说
			//1.先交换 matrix[0][0] 和 matrix[row][0]
			swap(&matrix[l][offset], &matrix[row - offset - 1][l]);
			//2.再交换 matrix[row][0] 和 matrix[row][col]
			swap(&matrix[row - offset - 1][l], &matrix[row - l - 1][col - offset - 1]);
			//3.再交换 matrix[row][col] 和 matrix[0][col]
			swap(&matrix[row - l - 1][col - offset - 1], &matrix[offset][col - l - 1]);

		}
	}
    cout << "Hello World!\n";
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
