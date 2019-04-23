#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};

void createList(ListNode* head)
{
	ListNode* pre = head;
	int temp;
	while (cin >> temp)
	{
		ListNode* node = new ListNode(temp);
		pre->next = node;
		pre = node;
	}
}

void printL(ListNode* head)
{
	if (head == nullptr)
		return;

	ListNode* node = head;
	while (node->next != nullptr)
	{
		cout << node->val << "->";
		node = node->next;
	}
	cout <<node->val<< endl;
}

//k��һ�鷭ת����
ListNode*  reverseKGroup(ListNode* head, int k)
{
	ListNode* cur = head;
	ListNode* pre = nullptr;
	ListNode* next = nullptr;
	ListNode* check = head;
	int canProcess = 0;
	int count = 0;
	// ����������Ƿ����㷭ת
	while (canProcess<k && check != nullptr)
	{
		check = check->next;
		canProcess++;
	}
	// �������������з�ת
	if (canProcess == k)
	{
		while (count < k && cur != nullptr)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
			count++;
		}
		if (next != nullptr)
			head->next = reverseKGroup(next, k); // head Ϊ����ת���β�ڵ�
		
			return pre; // prev Ϊ����ת���ͷ���
	}
	else {
		return head; // ����ס��ת������ֱ�ӷ��� head ����
	}
}

//��ת����
ListNode* reverseAll(ListNode* head)
{
	ListNode* pRHead = nullptr;
	ListNode* pCur = head;
	ListNode* pNext = nullptr;
	ListNode* pPre = nullptr;

	while (pCur != nullptr)
	{
		pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	
	pRHead = pPre;

	return pRHead;
}

//���ص�����K���ڵ�
ListNode* findLastKthNode(ListNode* head, int k)
{
	if (head == nullptr || k == 0)
		return nullptr;
	ListNode*pTail = head, *pHead = head;
	for (int i = 1; i<k; ++i)
	{
		if (pHead->next != nullptr)
			pHead = pHead->next;
		else
			return nullptr;
	}
	while (pHead->next != nullptr)
	{
		pHead = pHead->next;
		pTail = pTail->next;
	}
	return pTail;
}

//����ɾ�������ڵ�
ListNode* deleteNode(ListNode* head, ListNode* todelete)
{
	todelete->val = todelete->next->val;
	todelete->next = todelete->next->next;

	return head;
}

int main()
{
	ListNode* head = new ListNode(0);
	createList(head);
	printL(head);

	head = reverseKGroup(head, 2);
	printL(head);

	head = reverseAll(head);
	printL(head);

	ListNode* kNode;
	kNode = findLastKthNode(head, 2);
	printL(kNode);

	head = deleteNode(head, kNode);
	printL(head);
}





