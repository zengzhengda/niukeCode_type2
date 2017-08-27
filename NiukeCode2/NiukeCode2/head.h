#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <numeric>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <sstream>
#include <stdlib.h>
#include <multiset>

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define SIZE_STACK 100
#define MAX_QUEUE 1000
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

// �������
typedef struct seqqueue
{
	TreeNode* data[MAX_QUEUE];
	int front;
	int rear;// β�����һ��Ԫ�ص���һ��λ��
};
void enter_queue(seqqueue* q,TreeNode* t);// ����
TreeNode* delete_queue(seqqueue* q); //����

class Solution {
public:  // ��ָoffer
	bool Find(int target, vector<vector<int> > array); //��ά�����еĲ���
	void replaceSpace(char *str, int length); // �滻�ո�
	vector<int> printListFromTailToHead(ListNode* head);// ��β��ͷ��ӡ����
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin);//  �ؽ�������

	void pushOfStack2Queue(int node);
	int popOfStack2Queue();

	int minNumberInRotateArray(vector<int> rotateArray); // ��ת��С������
private:
	TreeNode* buildTree(vector<int>::iterator pre_first,vector<int>::iterator pre_last,vector<int>::iterator in_first,vector<int>::iterator in_last);// ����������

	// define stack
	stack<int> stack1;
	stack<int> stack2;
	int minInorder(vector<int> nums, int left,int right);
};

int Fibonacci(int n); // 쳲���������
int jumpFloor(int number); // ��̨��
int jumpFloorII(int number); // ��̬��̨��
int  NumberOf1(int n);// ��������1�ĸ���
double Power(double base, int exponent); // ��֬�������η�
void reOrderArray(vector<int> &array); // ��������˳��ʹ������λ��ż��ǰ��

// �����е�����k���ڵ�
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
// ��ת����
ListNode* ReverseList(ListNode* pHead) ;
// �����ӽṹ
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
bool DoesTreeHaveTree(TreeNode* pRoot1,TreeNode* pRoot2);
int FindGreatestSumOfSubArray(vector<int> array);// ����������ĺ�
vector<int> GetLeastNumbers_Solution(vector<int> input, int k);//��С��k����
void GetLeastNumbers(vector<int> input,multiset<int,greater<int>> &maxHeap,int k); // ʹ����������С��k����

//------- �������------
// ͷ��������
ListNode* linkListInsertH(ListNode* L,int x);
// β��������
ListNode* linkListInsertT(ListNode* L,int x);
// ������Ľ�����ͷ�巨����������  
ListNode* linkListCreatH(vector<int> nums);
///������Ľ�����β�巨����������  
ListNode* linkListCreatT(vector<int> nums);

//---------������---------
// ��α��������ɶ�����
TreeNode* createTreeLevel(vector<int> nums);
void preorder(TreeNode* t);// ǰ�����
void midorder(TreeNode* t); // �������
void postorder(TreeNode* t); // ������� 
void leveloder(TreeNode* t); // ��α���

// �����㷨
vector<int> sortMethods(vector<int> &nums);
void quickSort(vector<int> &nums,int left, int right);// ����
int partition(vector<int> &nums,int left,int right); 
void mergeSort(vector<int>& nums,int left,int right); // �鲢����
void merge(vector<int> &nums,int left,int mid,int right); //�ϲ�
void heapSort(vector<int> &nums); // ������
void buildMaxHeap(vector<int> &nums);// ��������
void keepMaxHeap(vector<int> &nums,int ind,int len_heap); //ά������
vector<int> countSort(vector<int> &nums); // ��������