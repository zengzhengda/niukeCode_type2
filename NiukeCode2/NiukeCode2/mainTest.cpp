#include "head.h"

void main()
{
	//1. 测试数据为一个或者多个整数
	//2. 测试数据为数组和数
	//3. 字符串测试
	//4. 测试数据为两个数组
	//5. 测试数据为矩阵
	//6. 测试数据为单链表
	//7. 测试数据为字符串向量组
	//8. 测试数据为二叉树
	int testCondition = 2;

	switch (testCondition)
	{
	case 1:
	{
		//测试数据为一个或者多个整数
		double x = 1;
		int y = 2;

		double res = Power(x,y);


		break;
	}
	case 2:
	{
		// 测试数据为数组和数
		vector<int> in={ 3,1,6,4,8,5,9,10,2,4,5,6 };
		int k = 6;
		vector<int> res = GetLeastNumbers_Solution(in,k);
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}		
		break;
	}
	case 3:
	{
		// 字符串测试
		string str1 = "23";
		string str2 = "-86+72i";
		Solution sol;
		break;
	}
	case 4:
	{
		// 测试数据为两个数组
		int nums_arr1[] = { 1,2,4,5,3,6,7 };
		int nums_arr2[] = { 4,2,5,1,6,3,7 };
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));
		vector<int> nums2(nums_arr2, nums_arr2 + sizeof(nums_arr2) / sizeof(nums_arr2[0]));
		Solution sol;
		break;
	}
	case 5:
	{
		// 测试数据为矩阵
		vector<vector<int>> matrix;
		matrix.push_back({ 1,2,3,4 });
		matrix.push_back({ 3,4,5,6 });
		matrix.push_back({ 4,5,6,7 });
		matrix.push_back({ 5,6,7,8 });
		matrix.push_back({ 7,8,9,10 });
		int target = 7;
		Solution sol;
		bool res=sol.Find(target, matrix);
		break;
	}
	case 6:
	{
		//6. 测试数据为单链表 指针的应用实在是太麻烦了
		int nums_arr1[] = { 1,2,3,4,5 };
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));
		ListNode* L=linkListCreatT(nums1);
		int k=0;
		ListNode* pK= ReverseList(L);

		break;
	}
	case 7:
	{
		//7. 测试数据为字符串向量组
		vector<string> strs({ "hot","dot","dog","lot","log","cog" });
		string str1 = "hit";
		string str2 = "cog";
		// strs.push_back(str1);
		// strs.push_back(str2);
		Solution sol;

		break;
	}
	case 8:
	{
		//8. 测试数据为二叉树
		vector<int> nums1={8,8,7,9,2,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,7};
		vector<int> nums2={8,9,2};
		TreeNode* t1=createTreeLevel(nums1);
		TreeNode* t2=createTreeLevel(nums2);
		midorder(t1);
		break;
	}

	default:
		break;
	}
}
