#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//��������ڵ�ṹ��
typedef struct ListNode//struct�ṹ�壬��ʹ��typedef
{
	int val;
	struct ListNode* next;
}LinkNode;
//���쵥������ĺ���
ListNode* newListNode(int val)
{
	ListNode* node;/*һ���ṹ��ָ�룬�����������Ŀռ�
	���û��typedefҪʹ��struct LinkNode*/
	node = (ListNode*)malloc(sizeof(ListNode));//����һ���ṹ��ռ�
	node->val = val;
	node->next = NULL;
	return node;//��ָ��ָ���´���������ڵ�
}
/*
//˫������ڵ�ṹ��
typedef struct ListNode
{
	int val;			  //�ڵ�ֵ
	struct LinkNode* next;//ָ���ڵ��ָ��
	struct LinkNode* prev;//ָ��ǰ�ڵ��ָ��
};

//˫�������캯��
LinkNode* newListNode(int val)
{
	ListNode* node;
	node = (LinkNode*)malloc(sizeof(LinkNode));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
*/



//����ڵ�
void insert(ListNode* n0, ListNode* p)
{
	ListNode* n1 = n0->next;
	n0->next = p;
}

//ɾ���ڵ�
/*ɾ��n0�ڵ��ĵ�һ���ڵ�*/
void remove(ListNode* n0)
{
	if (!n0->next)
		return;//����ýڵ�Ϊ���Ľڵ㣬��ɾ��
	ListNode* p = n0->next;
	ListNode* n1 = p->next;
	n0->next = n1;
	//�ͷ��ڴ�
	free(p);
}

//���ҽڵ�
/*����������ֵΪtarget���׸��ڵ�*/
int find(ListNode* head, int target)
{
	int index = 0;
	while (head)
	{
		if (head->val == target)
			return index;
		head = head->next;
		index++;
	}
	return -1;
}




int main()
{
	//��ʼ�������ڵ�
	LinkNode* n0 = newListNode(1);
	LinkNode* n1 = newListNode(3);
	LinkNode* n2 = newListNode(2);
	LinkNode* n3 = newListNode(5);
	LinkNode* n4 = newListNode(4);
	//�������֮�������
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	return 0;
}


