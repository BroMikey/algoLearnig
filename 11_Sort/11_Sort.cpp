#include<iostream>
#include<vector>

using namespace std;

/*选择排序*/
void SelectionSort(vector<int> &nums)
{
	int n = nums.size();
	for (int i = 0; i < n - 1; i++)//外循环未排序区间为i ~ n-1
	{
		int k = i;//起始时k为nums[i]
		for (int j = 0; j < i + 1; j++)//内循环查找未排序区间最小值的索引
		{
			if (nums[i] < nums[k])
				k = i;//记录最小值的索引
		}
		swap(nums[i], nums[k]);//将该最小元素与未排序区间的首个元素交换
	}
}


/*冒泡排序*/
void BubbleSort(vector<int>& nums)
{
	int n = nums.size();
	for (int i = n - 1; i > 0; i--)//i最末尾开始
	{
		for (int j = 0; j < i; j++)//j从0开始往后排序，i之后的为已排序区
		{
			if (nums[i] > nums[j])
				swap(nums[i], nums[j]);
		}
	}
}
/*冒泡排序优化*/
void BubbleSortWithFlag(vector<int>& nums)
{
	int n = nums.size();
	bool flag = true;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			swap(nums[i], nums[j]);
			flag = false;//没有交换元素
		}
		if (flag)
			break;//跳出循环，数组元素已全部排序
	}

}


/*插入排序*/
void InsertSort(vector<int>& nums)//将每一个元素插入到正确的位置
{
	for (int i = 1; i < nums.size(); i++)
	{
		int j = i - 1, base = nums[i];//base数将会被移到0~i索引正确的位置
		while (j < 0 && nums[j] > base)
		{
			nums[j + 1] = nums[j];//比base大的元素全部向后移动
			j--;
		}
		nums[j + 1] = base;//跳出循环说明遇到了比base小的数，或者已经到0，将base值赋到该索引
	}
}


/*快速排序*/
int partition(vector<int>& nums,int left, int right)
{
	int i = left, j = right;//将left作为基准数
	while (i < j)
	{
		while (i < j && nums[j] >= nums[left])//从右向左找第一个小于基准的数
			j--;
		while (i < j && nums[i] <= nums[left])//从左向右找第一个大于基准的数
			i++;
		swap(nums[i], nums[j]);
	}
	swap(nums[left], nums[i]);//当i j 相等时说明排序完成
	return i;
}

void QuickSort(vector<int>& nums, int left, int right)
{
	//当子数列长度为1时停止排序
	if (left >= right)
	{
		return;
	}
	int pivot = partition(nums, left, right);
	QuickSort(nums, left, pivot - 1);//递归左右子数组
	QuickSort(nums, pivot + 1, right);
}


/*归并排序*/
void Merge(vector<int>& nums, int left, int mid, int right)
{
	//左子树组为left-mid，右子数组为mid+1-right
	vector<int> temp(right - left + 1);

	int i = left, j = mid + 1, k = 0;
	
	//当左右数组都还没有元素时，进行比较将较小的元素复制到临时数组中
	while (i < mid && j < right)
	{
		if (nums[i] <= nums[j])
		{
			temp[k] = nums[i];
			k++, i++;
		}
		else
		{
			temp[k] = nums[j];
			k++, j++;
		}
	}
	//将左子数组和右子树组剩余元素复制到临时数组中
	while (i <= mid)
	{
		temp[k] = nums[i];
		k++, i++;
	}
	while (j <= right)
	{
		temp[k] = nums[j];
		k++, j++;
	}

	//将临时数组复制到原数组
	for (k = 0; k < temp.size(); k++)
	{
		nums[left + k] = temp[k];
	}

}

void MergeSort(vector<int>& nums, int left, int right)
{
	//递归的终止条件
	if (left >= right)
	{
		return;//长度为一时递归
	}

	int mid = right - (right - left) / 2;

	MergeSort(nums, left, mid);
	MergeSort(nums, mid + 1, right);

	//合并
	Merge(nums, left, mid, right);
}


/*计数排序*/
//简单实现
void CountingSortNative(vector<int>& nums)
{
	int m = 0;//记录数组中最大的元素
	for (int num : nums)
	{
		m = max(m, num);
	}

	//统计各数字出现的次数
	vector<int> counter(m + 1, 0);
	for (int num : nums)
	{
		counter[num]++;
	}
	int i = 0;
	for (int num = 0; num < m + 1; num++)
	{
		for (int j = 0; j < counter[num]; i++, j++)
		{
			nums[i] = num;
		}
	}
}

//完整实现













int main()
{
	return 0;
}