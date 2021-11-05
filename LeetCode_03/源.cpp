#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

struct countNode								//Map��ͼ��Ϣ
{
	char key;
	int weizhi;
	countNode *next;
	countNode(char k, int wz) : key(k), weizhi(wz), next(nullptr) {}
};

int lengthOfLongestSubstring(string s)
{
	countNode* p;
	countNode Head('0',-1);
	
	int start = 0, end = 0, MaxLength = 0;
	char current;				//��ǰ���ַ�
	bool InNode;				//�Ƿ���������
	p = &Head;
	while (end<s.length())
	{
		InNode = false;
		current = s.at(end);
		for (int i = 0; i <= end; i++)		//��ѯ�Ƿ��д�������������
		{
			if (current == p->key)					//��ѯ���˴�����
			{
				start = start > (p->weizhi+1) ? start : (p->weizhi+1);					//�ڸ���λ����Ϣ֮ǰ������ start �ɵĵ�ַ
				p->weizhi = end;						//����λ����Ϣ
				InNode = true;
				break;
			}
			if (p->next == nullptr)
				break;
			p = p->next;
		}
		if (InNode == false)				//������û�д����ݣ����´�һ���ڵ����洢
		{
			p->next = new countNode(s.at(end), end);
		}
		MaxLength = MaxLength > (end - start+1) ? MaxLength : (end - start+1);
		p = Head.next;						//��p����ָ���ײ�
		end++;
	}
	return MaxLength;
}

int main()
{
	string str;
	//scanf_s("%s", &str);
	cin >> str;
	int length = lengthOfLongestSubstring(str);
	printf_s("%d", length);
	return 0;
}