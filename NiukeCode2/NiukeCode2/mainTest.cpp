#include "head.h"

void main()
{
	//1. ��������Ϊһ�����߶������
	//2. ��������Ϊ�������
	//3. �ַ�������
	//4. ��������Ϊ��������
	//5. ��������Ϊ����
	//6. ��������Ϊ������
	//7. ��������Ϊ�ַ���������
	//8. ��������Ϊ������
	int testCondition = 2;

	switch (testCondition)
	{
	case 1:
	{
		//��������Ϊһ�����߶������
		double x = 1;
		int y = 2;

		double res = Power(x,y);


		break;
	}
	case 2:
	{
		// ��������Ϊ�������
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
		// �ַ�������
		string str1 = "23";
		string str2 = "-86+72i";
		Solution sol;
		break;
	}
	case 4:
	{
		// ��������Ϊ��������
		int nums_arr1[] = { 1,2,4,5,3,6,7 };
		int nums_arr2[] = { 4,2,5,1,6,3,7 };
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));
		vector<int> nums2(nums_arr2, nums_arr2 + sizeof(nums_arr2) / sizeof(nums_arr2[0]));
		Solution sol;
		break;
	}
	case 5:
	{
		// ��������Ϊ����
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
		//6. ��������Ϊ������ ָ���Ӧ��ʵ����̫�鷳��
		int nums_arr1[] = { 1,2,3,4,5 };
		vector<int> nums1(nums_arr1, nums_arr1 + sizeof(nums_arr1) / sizeof(nums_arr1[0]));
		ListNode* L=linkListCreatT(nums1);
		int k=0;
		ListNode* pK= ReverseList(L);

		break;
	}
	case 7:
	{
		//7. ��������Ϊ�ַ���������
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
		//8. ��������Ϊ������
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
