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

// 定义队列
typedef struct seqqueue
{
	TreeNode* data[MAX_QUEUE];
	int front;
	int rear;// 尾是最后一个元素的下一个位置
};
void enter_queue(seqqueue* q,TreeNode* t);// 进队
TreeNode* delete_queue(seqqueue* q); //出队

class Solution {
public:  // 剑指offer
	bool Find(int target, vector<vector<int> > array); //二维数组中的查找
	void replaceSpace(char *str, int length); // 替换空格
	vector<int> printListFromTailToHead(ListNode* head);// 从尾到头打印链表
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin);//  重建二叉树

	void pushOfStack2Queue(int node);
	int popOfStack2Queue();

	int minNumberInRotateArray(vector<int> rotateArray); // 旋转最小的数字
private:
	TreeNode* buildTree(vector<int>::iterator pre_first,vector<int>::iterator pre_last,vector<int>::iterator in_first,vector<int>::iterator in_last);// 建立二叉树

	// define stack
	stack<int> stack1;
	stack<int> stack2;
	int minInorder(vector<int> nums, int left,int right);
};

int Fibonacci(int n); // 斐波拉契数列
int jumpFloor(int number); // 跳台阶
int jumpFloorII(int number); // 变态跳台阶
int  NumberOf1(int n);// 二进制中1的个数
double Power(double base, int exponent); // 树脂的整数次方
void reOrderArray(vector<int> &array); // 调整数组顺序使得奇数位于偶数前面

// 链表中倒数第k个节点
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
// 反转链表
ListNode* ReverseList(ListNode* pHead) ;
// 树的子结构
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
bool DoesTreeHaveTree(TreeNode* pRoot1,TreeNode* pRoot2);
int FindGreatestSumOfSubArray(vector<int> array);// 连续子数组的和
vector<int> GetLeastNumbers_Solution(vector<int> input, int k);//最小的k个数
void GetLeastNumbers(vector<int> input,multiset<int,greater<int>> &maxHeap,int k); // 使用最大堆求最小的k个数

//------- 链表操作------
// 头插入链表
ListNode* linkListInsertH(ListNode* L,int x);
// 尾插入链表
ListNode* linkListInsertT(ListNode* L,int x);
// 单链表的建立，头插法建立单链表  
ListNode* linkListCreatH(vector<int> nums);
///单链表的建立，尾插法建立单链表  
ListNode* linkListCreatT(vector<int> nums);

//---------树操作---------
// 层次遍历法生成二叉树
TreeNode* createTreeLevel(vector<int> nums);
void preorder(TreeNode* t);// 前序遍历
void midorder(TreeNode* t); // 中序遍历
void postorder(TreeNode* t); // 后序遍历 
void leveloder(TreeNode* t); // 层次遍历

// 排序算法
vector<int> sortMethods(vector<int> &nums);
void quickSort(vector<int> &nums,int left, int right);// 快排
int partition(vector<int> &nums,int left,int right); 
void mergeSort(vector<int>& nums,int left,int right); // 归并排序
void merge(vector<int> &nums,int left,int mid,int right); //合并
void heapSort(vector<int> &nums); // 堆排序
void buildMaxHeap(vector<int> &nums);// 建立最大堆
void keepMaxHeap(vector<int> &nums,int ind,int len_heap); //维护最大堆
vector<int> countSort(vector<int> &nums); // 计数排序