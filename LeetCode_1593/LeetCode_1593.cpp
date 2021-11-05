// LeetCode_1593.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*[拆分字符串使唯一子字符串的数目最大]
	给你一个字符串 s ，请你拆分该字符串，并返回拆分后唯一子字符串的最大数目。

	字符串 s 拆分后可以得到若干 非空子字符串 ，这些子字符串连接后应当能够还原为原字符串。但是拆分出来的每个子字符串都必须是 唯一的 。

	注意：子字符串 是字符串中的一个连续字符序列。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/split-a-string-into-the-max-number-of-unique-substrings
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
using namespace std;


bool isRepeat(string* src, string tag)
{
	int i = 0;
	while (src[i].length() != 0)
	{
		if (src[i++] == tag)
			return true;
	}
	return false;
}

int maxUniqueSplit(string s) {
	//假设第一个字符串长度为1
	if (s.length() < 0)
		return 0;
	if (s.length() == 1)
		return 1;

	char* end1;
	int i, j;
	int start, len;
	int resTemp, Result = 0;
	string* Segmentation = new string[s.length()];
	for (i = 0; i < s.length(); i++)
	{
		for (j = 0; j < s.length(); j++)
			Segmentation[j].clear();
		Segmentation[0] = s.substr(0, i + 1);
		resTemp = 1;

		start = i + 1;
		len = 1;
		j = 1;
		while ((start + len - 1) < s.length())
		{
			if (!isRepeat(Segmentation, s.substr(start, len)))
			{
				Segmentation[j++] = s.substr(start, len);
				resTemp++;
				start = start + len;
				len = 1;
			}
			else
				len++;
		}
		Result = (resTemp > Result) ? resTemp : Result;
	}
	return Result;
}



int main()
{
	std::cout << "Hello World!\n";
	cout << maxUniqueSplit("sddddfffff") << endl;
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
