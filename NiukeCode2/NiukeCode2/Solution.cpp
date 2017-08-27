#include "head.h"

// 使用最大堆求最小的k个数
void GetLeastNumbers(vector<int> input,multiset<int,greater<int>> &maxHeap,int k){
	if(input.empty() || k<=0 || input.size()<k) return;

	for(auto it=input.begin();it != input.end();it++){
		if(maxHeap.size()<k){
			maxHeap.insert(*it);
		}
		else{
			multiset<int,greater<int>>::iterator itHeap=maxHeap.begin();
			if(*it < *itHeap){
				maxHeap.erase(itHeap);
				maxHeap.insert(*it);
			}
		}
	}
}

// 最小的k个数
vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
	int method =2; //1 partition，2 最大堆
	switch(method){
		case 1:{
			if(input.empty() || k<=0) return vector<int> ();
			if(input.size()< k) return vector<int> ();

			const int len= input.size();
			int left=0;
			int right=len-1;
			int ind_mid =partition(input,left,right);
			while(ind_mid != k-1){
				if(ind_mid>k-1){
					right=ind_mid-1;
					ind_mid=partition(input,left,right);
				}
				else{
					left=ind_mid+1;
					ind_mid=partition(input,left,right);
				}
			}
			vector<int> res(input.begin(), input.begin()+k);
			return res;
		}
		case 2:{
			if(input.empty() || k<=0) return vector<int> ();
			if(input.size()< k) return vector<int> ();

			multiset<int,greater<int>> maxHeap;
			GetLeastNumbers(input,maxHeap,k);
			vector<int> res;
			for(auto it=maxHeap.begin();it != maxHeap.end();it++){
				res.push_back(*it);
			}
			return res;
		}
		case 3:{
			
		}
	}
	
}

// 排序算法
vector<int> sortMethods(vector<int> &nums){
	int method=7;
	switch(method){
		case 1:{
			//插入排序
			const int len=nums.size();
			if(len==0) return vector<int> ();
			for(int i=1;i<len;i++){
				int key=nums[i];
				int j=0;
				for(j=i-1;j>=0;j--){
					if(key>=nums[j]) break;
					nums[j+1]=nums[j];
				}
				nums[j+1]=key;
			}
			return nums;
		}
		case 2:{
			// 冒泡排序
			if(nums.empty()) return vector<int> ();
			const int len=nums.size();
			for(int i=0;i<len-1;i++){
				int index_min=i;
				for(int j=len-1;j>i;j--){
					if(nums[j-1] > nums[j]){
						int tmp=nums[j-1];
						nums[j-1]=nums[j];
						nums[j]=tmp;
					}
				}
			}
			return nums;
		}
		case 3:{
			// 选择排序
			if(nums.size()==0) return vector<int> ();
			const int len=nums.size();
			for(int i=0;i<len-1;i++){
				int index_min=i;
				for(int j=i+1;j<len;j++){
					if(nums[index_min]>nums[j]){
						index_min=j;
					}
				}
				int tmp=nums[index_min];
				nums[index_min]=nums[i];
				nums[i]=tmp;
			}
			return nums;
		}
		case 4:{
			// 快排,随机选择
			if(nums.empty()) return vector<int> ();
			const int len=nums.size();
			quickSort(nums,0,len-1);
			return nums;
		}
		case 5:{
			// 归并排序
			if(nums.size()==0) return vector<int> ();
			mergeSort(nums,0,nums.size()-1);
			return nums;
		}
		case 6:{
			// 堆排序
			if(nums.size()==0) return vector<int> ();
			heapSort(nums);
			return nums;
		}
		case 7:{
			// 计数排序
			vector<int> res=countSort(nums);
			return res;
		}
	}
}

// 计数排序
vector<int> countSort(vector<int> &nums){
	// 只针对0-max的数据
	if(nums.size()<=1) return nums;
	auto largest=max_element(nums.begin(),nums.end());
	int maxVal=*largest;
	vector<int> C(maxVal+1);
	vector<int> res(nums.size());
	for(int i=0;i<nums.size();i++){
		C[nums[i]]++;
	}
	for(int i=1;i<C.size();i++){
		C[i]=C[i-1]+C[i];
	}
	int val,pos;
	for(int i=0;i<nums.size();i++){
		val=nums[i];
		pos=C[val];
		res[pos-1]=val;
		C[val]--;
	}
	return res;
}

// 建立最大堆
void buildMaxHeap(vector<int> &nums){
	if(nums.empty()) return;
	const int len=nums.size();
	for(int i=len/2; i>=0;i--){
		keepMaxHeap(nums,i,len);
	}
	return;
}
//维护最大堆
void keepMaxHeap(vector<int> &nums,int ind,int len_heap){
	if(nums.empty()) return;
	int left=(ind+1)*2-1;
	int right=(ind+1)*2;
	int ind_max=ind;
	if(left<len_heap && nums[ind_max]<nums[left]){
		ind_max=left;
	}
	if(right<len_heap && nums[ind_max]<nums[right]){
		ind_max=right;
	}
	if(ind_max != ind){
		swap(nums[ind],nums[ind_max]);
		keepMaxHeap(nums,ind_max,len_heap);
	}
}

 // 堆排序
void heapSort(vector<int> &nums){
	if(nums.size()== 0) return;
	buildMaxHeap(nums);
	const int len=nums.size();
	int len_heap=len;
	for(int i=len-1;i>0;i--){
		swap(nums[0],nums[i]);
		len_heap--;
		keepMaxHeap(nums,0,len_heap);
	}
}

void merge(vector<int> &nums,int left,int mid,int right){
	int method=2;
	switch(method){
		case 1:{
			if(mid+1>right) return;
			vector<int> nums2(nums.begin()+mid+1,nums.begin()+right+1);
			vector<int> nums1(nums.begin()+left,nums.begin()+mid+1);
			int p=0;
			int q=0;
			int ind=left;
			while(p<nums1.size() && q<nums2.size()){
				if(nums1[p]<nums2[q]){
					nums[ind]=nums1[p];
					p++;
				}
				else{
					nums[ind]=nums2[q];
					q++;
				}
				ind++;
			}
			
			for (int j = ind; j <= right; j++) {
				if (p == nums1.size() && q != nums2.size()) {
					nums[j] = nums2[q++];
				}
				else if (p != nums1.size()) {
					nums[j] = nums1[p++];
				}
			}
		}
		case 2:{
			if(mid+1>right) return;
			vector<int> nums1(nums.begin()+left,nums.begin()+mid+1);
			vector<int> nums2(nums.begin()+mid+1,nums.begin()+right+1);
			nums1.push_back(INT_MAX);
			nums2.push_back(INT_MAX);

			int p=0;
			int q=0;
			for(int j=left;j<=right;j++){
				if(nums1[p]<nums2[q]){
					nums[j]=nums1[p++];
				}
				else{
					nums[j]=nums2[q++];
				}
			}
		}
	}
	
}
// 归并排序
void mergeSort(vector<int>& nums,int left,int right){
	if(left>=right) return;
	int mid=(right+left)/2;
	mergeSort(nums,left,mid);
	mergeSort(nums,mid+1,right);
	merge(nums,left,mid,right);
}

// 快排
void quickSort(vector<int> &nums,int left, int right){
	if(nums.size()==0) return;
	if(left>=right) return;
	int index_p=partition(nums,left,right);
	quickSort(nums,left,index_p-1);
	quickSort(nums,index_p+1,right);
}

int partition(vector<int> &nums,int left,int right){
	if(left>=right) return left;
	int ind_rand=left+rand()%(right-left+1);
	swap(nums[ind_rand],nums[right]);

	int p=left-1;
	int q=left;
	int partition=nums[right];

	for(q=left;q<right;q++){
		if(nums[q]<partition){
			swap(nums[p+1],nums[q]);
			p=p+1;
		}
	}
	swap(nums[right],nums[p+1]);
	return p+1;
}

//最小的k个数
// vector<int> GetLeastNumbers_Solution(vector<int> input, int k){

// }


// 连续子数组的和
int FindGreatestSumOfSubArray(vector<int> array) {
	if(array.empty()) return 0;
    vector<int> results;
    int maxSum=-0x7FFFFFFF;
    for(int i=0;i<array.size();i++){
        if(i==0 || results[i-1]<0){
            results.push_back(array[i]);
        }
        else{
            results.push_back(results[i-1]+array[i]);
        }
        if(maxSum<results[i]){
            maxSum=results[i];
        }
    }
    return maxSum;
}

//void postorder(TreeNode* t){
//	int method=1;
//	switch(method){
//		case 1:{
//			if(t==nullptr) return;
//			postorder(t->left);
//			postorder(t->right);
//			cout<<t->val<<endl;			
//		}
//		case 2:{
//			stack<TreeNode*> s;
//			TreeNode* t_cur=t;
//			TreeNode* t_pre=nullptr;
//
//			s.push(t);
//			while(!s.empty()){
//				t_cur=s.top();
//
//				if((t_cur->left == nullptr && t_cur->right==nullptr)|| (t_pre !=nullptr &&(t_cur->left==t_pre || t_cur->right==t_pre)){
//					cout<<t_cur->val<<endl;
//					s.pop();
//					t_pre=t_cur;
//				}
//				else{
//					if(t_cur->right != nullptr){
//						s.push(t_cur->right);
//					}
//					else if(t_cur->left != nullptr){
//						s.push(t_cur->left);
//					}
//				}
//			}
//		}
//	}
//}
void midorder(TreeNode* t){
	int method=3;
	switch(method){
		case 1:{
			if(t==nullptr) return;
			midorder(t->left);
			cout<<t->val<<endl;
			midorder(t->right);
			break;
		}
		case 2:{
			if(t==nullptr) return;
			TreeNode* t_cur=t;
			stack<TreeNode*> s;
			while(t_cur || !s.empty()){
				if(t_cur->left != nullptr){
					s.push(t_cur);
					t_cur=t_cur->left;
				}
				// 如果左节点为空
				else{
					cout<<t_cur->val<<endl;
					t_cur=t_cur->right;

					while(!t_cur && !s.empty()){
						t_cur=s.top();
						s.pop();

						cout<<t_cur->val<<endl;
						t_cur=t_cur->right;
					}
				}
			}
			return;
		}
		case 3:{
			if(t==nullptr) return;
			stack<TreeNode*> s;
			TreeNode* t_cur=t;
			while(!s.empty() || t_cur != nullptr){
				if(t_cur !=nullptr){
					s.push(t_cur);
					t_cur=t_cur->left;
				}
				else{
					t_cur=s.top();
					s.pop();
					cout<<t_cur->val<<endl;

					t_cur=t_cur->right;
				}
				
			}
			break;
		}
	}
}
void preorder(TreeNode* t){
	int method=3;
	switch(method){
		case 1:{
			if(t==nullptr) return;
			cout<<t->val<<endl;
			preorder(t->left);
			preorder(t->right);
			return;
		}
		case 2:{
			if(t==nullptr) return;
			stack<TreeNode*> s;
			TreeNode* t_cur=t;
			while(t_cur || !s.empty()){
				cout<<t_cur->val<<endl;
				s.push(t_cur);
				t_cur=t_cur->left;

				while(!t_cur && !s.empty()){
					t_cur=s.top();
					s.pop();
					t_cur=t_cur->right;
				}
			}
			return;
		}
		case 3:{
			if(t==nullptr) return;
			stack<TreeNode*> s;
			s.push(t);
			TreeNode* t_cur;
			while(!s.empty()){
				t_cur=s.top();
				s.pop();

				cout<<t_cur->val<<endl;
				if(t_cur->right != nullptr) s.push(t_cur->right);
				if(t_cur->left != nullptr) s.push(t_cur->left);
			}
			break;
		}
	}
	
}
// 树的子结构
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
	bool res=false;
	if(pRoot1  != nullptr && pRoot2 != nullptr){
		if(pRoot1->val ==pRoot2->val){
			res=DoesTreeHaveTree(pRoot1,pRoot2);
		}
		if(!res){
			res=HasSubtree(pRoot1->left,pRoot2);
		}
		if(!res){
			res=HasSubtree(pRoot1->right,pRoot2);
		}
	}
	return res;
}
bool DoesTreeHaveTree(TreeNode* pRoot1,TreeNode* pRoot2){
	if(pRoot2==nullptr) return true;
	if(pRoot1==nullptr) return false;
	if(pRoot1->val != pRoot2->val) return false;
	return DoesTreeHaveTree(pRoot1->left,pRoot2->left) && DoesTreeHaveTree(pRoot1->right,pRoot2->right);
}

// 进队
void enter_queue(seqqueue* q,TreeNode* t)
{
	if(q->rear == MAX_QUEUE)
	{
		printf("the queue is full\n");
	}
	else
	{
		q->data[q->rear]=t;
		q->rear++;
	}
}
// 出队
TreeNode* delete_queue(seqqueue* q)
{
	if(q->front == q->rear)
		return NULL;
	else
	{
		q->front++;
		return q->data[q->front-1];
	}
}


// 层次遍历法生成二叉树
TreeNode* createTreeLevel(vector<int> nums)
{
	TreeNode* t=nullptr;
	if(nums.size()==0)
		return t;
	int len_level=1; // 满二叉树的层结点数
	const int len_nums=nums.size();
	int cnt=1;
	seqqueue q;
	q.front = q.rear = 0;
	t=(TreeNode*)malloc(sizeof(TreeNode));
	t->val=nums[0];
	t->left=t->right=nullptr;
	enter_queue(&q,t);
	while(cnt<len_nums)
	{
		for(int i=0;i<len_level && cnt<len_nums;i++)
		{
			TreeNode* tmp2;
			tmp2=delete_queue(&q);
			if(!tmp2)
			{
				i += 2;
				cnt+=2;
				enter_queue(&q,nullptr);
				enter_queue(&q,nullptr);
				continue;
			}

			if(cnt<len_nums)
			{
				TreeNode* lchild=nullptr;
				if(nums[cnt]!=INT_MIN)
				{
					lchild = (TreeNode*)malloc(sizeof(TreeNode));
					lchild->val=nums[cnt++];
					lchild->left = lchild->right = nullptr;
					tmp2->left=lchild;
				}
				else if(nums[cnt]=INT_MIN)
				{
					tmp2->left=nullptr;
					cnt++;
				}
				enter_queue(&q,lchild);
			}
			if(cnt<len_nums)
			{
				TreeNode* rchild=nullptr;
				if(nums[cnt]!=INT_MIN)
				{
					rchild=(TreeNode*)malloc(sizeof(TreeNode));
					rchild->val=nums[cnt++];
					rchild->left = rchild->right = nullptr;
					tmp2->right=rchild;
				}
				else if(nums[cnt]=INT_MIN)
				{
					tmp2->right=nullptr;
					cnt++;
				}
				enter_queue(&q,rchild);
			}	
		}
		len_level *= 2;
	}
	return t;
}



// 反转链表
ListNode* ReverseList(ListNode* pHead) {
	int method=2;
	switch(method){
		case 1:{
			if(pHead==nullptr) return nullptr;
			stack<ListNode*> s;
			ListNode* p=pHead;
			while(p){
				s.push(p);
				p=p->next;
			}
			ListNode* pHeadNew=s.top();
			p=pHeadNew;
			while(!s.empty()){
				ListNode* t=s.top();
				s.pop();

				p->next=t;
				p=p->next;
				p->next=nullptr;
			}
			return pHeadNew;
		}
		case 2:{
			if(pHead==nullptr) return nullptr;
			ListNode* pHeadNew = (ListNode*)malloc(sizeof(ListNode));
			*pHeadNew = *pHead;
			pHeadNew->next = nullptr;
	        pHead=pHead->next;
	        while(pHead){
	            ListNode* p=new ListNode(pHead->val);
	            p->next=pHeadNew;
	            pHeadNew=p;

				pHead = pHead->next;
	        }
	        return pHeadNew;
		}
		case 3:{
			ListNode* pReversedHead=nullptr;
			ListNode* pNode=pHead;
			ListNode* pPrev=nullptr;
			
			while(pNode){
				ListNode* pNext=pNode->next;
				if(pNext==nullptr){
					pReversedHead=pNode;
				}
				pNode->next=pPrev;
				pPrev=pNode;
				pNode=pNext;
			}			
			return pReversedHead;
		}
	}
}

// 链表中倒数第k个节点
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
	ListNode* pLastNode;
    if(pListHead == nullptr || k<=0) return nullptr;
    pLastNode=pListHead;
    while(k>1){
        pLastNode=pLastNode->next;
        k--;
        if(pLastNode==nullptr) return nullptr;
    }
    ListNode* pPreNode=pListHead;
    while(pLastNode->next){
        pLastNode=pLastNode->next;
        pPreNode=pPreNode->next;
    }
    return pPreNode;
}

// 单链表的建立，头插法建立单链表  
ListNode* linkListCreatH(vector<int> nums){
	ListNode* pListHead = (ListNode*)malloc(sizeof(ListNode));
	if(nums.empty()){
		return nullptr;
	}
	for(int i=0;i<nums.size();i++){
		pListHead=linkListInsertH(pListHead,nums[i]);
	}
	return pListHead;
}
///单链表的建立，尾插法建立单链表  
ListNode* linkListCreatT(vector<int> nums){
	if(nums.empty()) return nullptr;
	ListNode* pListHead = new ListNode(nums[0]);
	if (nums.size() == 1) return pListHead;
	ListNode* pListLast = pListHead;

	for(int i=1;i<nums.size();i++){
		pListLast=linkListInsertT(pListLast,nums[i]);
	}
	return pListHead;
}

// 尾插入链表
ListNode* linkListInsertT(ListNode* L,int x){
	if(L==nullptr) {
		L=(ListNode*) malloc(sizeof(ListNode));
		L->val=x;
		L->next=nullptr;
		return L;
	}
	ListNode* p = new ListNode(x);

	ListNode* list_cur=L;
	while(list_cur->next){
		list_cur=list_cur->next;
	}
	list_cur->next=p;
	return p;
}
ListNode* linkListInsertH(ListNode* L,int x){
	if(!L){
		L=(ListNode*) malloc(sizeof(ListNode));
		L->val=x;
		L->next=nullptr;
		return L;
	}
	ListNode* p = new ListNode(x);
	p->next=L;
	L=p;
	return L;
}

// 调整数组顺序使得奇数位于偶数前面
void reOrderArray(vector<int> &array){
	vector<int> res;
	if(array.empty()) return;

	for(int i=0;i<array.size();i++){
		if(array[i] & 1){
			res.push_back(array[i]);
		}
	}
	for(int i=0;i<array.size();i++){
		if(!(array[i] & 1)){
			res.push_back(array[i]);
		}
	}
	array=res;
}

// 数值的整数次方
double Power(double base, int exponent){
	if(base==0) return 0;
	double res=1;
	int tmp=abs(exponent);
	while(tmp){
		res=base*res;
		tmp--;
	}
	if(exponent<0) res=1/res;
	return res;
}

// 二进制中1的个数
int  NumberOf1(int n){
 	return 0;
}

// 变态跳台阶
int jumpFloorII(int number){
	if(number<0){
		return -1;
	}
	if(number==0) return 0;
	vector<int> res={1};
	for(int i=1;i<=number;i++){
		if(i==1){
			res.push_back(1);
		}
		else{
			res.push_back(2*res[i-1]);
		}
	}
	return res[number];
}

// 跳台阶
int jumpFloor(int number){
	if(number<0){
		return -1;
	}
	if(number==0) return 0;
	vector<int> res={0};
	for(int i=1;i<=number;i++){
		if(i==1){
			res.push_back(1);
		}
		else if(i ==2){
			res.push_back(2);
		}
		else{
			res.push_back(res[i-1]+res[i-2]);
		}
	}
	return res[number];
}

 // 斐波拉契数列
int Fibonacci(int n){
	int method =1; // 1 非递归
	switch(method){
		case 1:{
			if(n<0) return -1;
			if(n==0) return 0;
			vector<int> fNums={0};
			for(int i=1;i <=n; i++){
				if(i==1 || i==2){
					fNums.push_back(1);
				}
				else{
					fNums.push_back(fNums[i - 2] + fNums[i - 1]);
				}			
			}
			return fNums[n];
		}
		case 2:{
		/*	if(n<0) return -1;
			if(n==0) return 0;

			vector<int> fNums={0};
			Fibonacci(n,fNums);
			return fNums[n];*/
		}
	}
}

// void Fibonacci(int n,vector<int> &fNums){
// 	if(n==1 || n==2){
// 		fNums.push_back(1);
// 	}
// 	if(n)
// 	fNums.push_back(fNums[n-1]+fNums[n-2]);
// }

// 旋转最小的数字
int Solution::minNumberInRotateArray(vector<int> rotateArray){
	int method=1;
	switch(method){
		case 1:{
			if(rotateArray.empty()){
				return -1;
			}
			int minNum=0x7FFFFFFF;
			for(int i=0;i<rotateArray.size();i++){
				if(rotateArray[i]<minNum){
					minNum=rotateArray[i];
				}
			}
			return minNum;
		}
		case 2:{
			if(rotateArray.empty()){
				return -1;
			}
			int index1=0;
			int index2=rotateArray.size()-1;
			int midIndex=index1;

			while(rotateArray[index1]>=rotateArray[index2]){
				if(index2-index1<=1){
					midIndex=index2;
				}
				midIndex=(index1+index2)/2;
				if(rotateArray[index1]==rotateArray[midIndex] && rotateArray[midIndex]==rotateArray[index2]){
					return minInorder(rotateArray,index1,index2);
				}
				if(rotateArray[midIndex] >= rotateArray[index1]){
					index1=midIndex;
				}
				else if(rotateArray[midIndex] <= rotateArray[index2]){
					index2=midIndex;
				}
			}
			return rotateArray[midIndex];

		}
	}
}

int Solution::minInorder(vector<int> nums, int left,int right){
	int minNum=0x7FFFFFFF;
	for(int i= left; i<= right; i++){
		if(nums[i] < minNum) minNum=nums[i];
	}
	return minNum;
}

// 用两个栈实现队列
void Solution::pushOfStack2Queue(int node){
	stack1.push(node);
}
int Solution::popOfStack2Queue(){
	int res=-1;

	if(!stack2.empty()){
		res=stack2.top();
		stack2.pop();
		return res;
	}
	if(stack1.empty()){
		return res;
	}
	while(!stack1.empty()){
		int tmp=stack1.top();
		stack2.push(tmp);
		stack1.pop();
	}
	res=stack2.top();
	stack2.pop();
	return res;
}

// 建立二叉树
TreeNode* Solution::buildTree(vector<int>::iterator pre_first,vector<int>::iterator pre_last,vector<int>::iterator in_first,vector<int>::iterator in_last)
{
	if(pre_first==pre_last) return nullptr;
	if(in_first==in_last) return nullptr;

	TreeNode* root = new TreeNode(*pre_first);

	auto inRootPos=find(in_first,in_last,root->val);
	auto leftSize=distance(in_first,inRootPos);

	root->left=buildTree(next(pre_first),next(pre_first,leftSize+1),in_first,next(in_first,leftSize));
	root->right=buildTree(next(pre_first,leftSize+1),pre_last,next(inRootPos),in_last);
	return root;
}


//  重建二叉树
TreeNode* Solution::reConstructBinaryTree(vector<int> pre,vector<int> vin)
{
	TreeNode* result= buildTree(begin(pre),end(pre),begin(vin),end(vin));
	return result;
}

// 从尾到头打印链表
vector<int> printListFromTailToHead(ListNode* head)
{
	stack<ListNode*> nodes;
	ListNode * pNode = head;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->next;
	}
	vector<int> res;
	while (!nodes.empty())
	{
		pNode = nodes.top();
		nodes.pop();
		res.push_back(pNode->val);
	}
	return res;
}

// 替换空格
void Solution::replaceSpace(char *str, int length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (*(str + i) == ' ')
		{
			count++;
		}
	}
	int length2 = length + 2 * count;
	char *p1 = str + length-1;
	char *p2 = str + length2 - 1;

	for (int i = length - 1; i >= 0; i--)
	{
		if (*(str + i) != ' ')
		{
			*p2 = *p1;
			p2--;
			p1--;
		}
		else
		{
			*(p2 - 2) = '%';
			*(p2 - 1) = '2';
			*(p2) = '0';
			p1--;
			p2 -= 3;
		}
	}
}

//二维数组中的查找
bool Solution::Find(int target, vector<vector<int> > array)
{
	const int rows = array.size();
	const int cols = array[0].size();

	int row = 0;
	int col = cols - 1;
	while(row<rows-1 && col>=0)
	{
		if (target > array[row][col])
		{
			row++;
		}
		else if (target < array[row][col])
		{
			col--;
		}
		else
		{
			return true;
		}
		
	}
	return false;
}