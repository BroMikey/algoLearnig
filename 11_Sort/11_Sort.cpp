#include<iostream>
#include<vector>

using namespace std;

/*ѡ������*/
void SelectionSort(vector<int> &nums)
{
	int n = nums.size();
	for (int i = 0; i < n - 1; i++)//��ѭ��δ��������Ϊi ~ n-1
	{
		int k = i;//��ʼʱkΪnums[i]
		for (int j = 0; j < i + 1; j++)//��ѭ������δ����������Сֵ������
		{
			if (nums[i] < nums[k])
				k = i;//��¼��Сֵ������
		}
		swap(nums[i], nums[k]);//������СԪ����δ����������׸�Ԫ�ؽ���
	}
}


/*ð������*/
void BubbleSort(vector<int>& nums)
{
	int n = nums.size();
	for (int i = n - 1; i > 0; i--)//i��ĩβ��ʼ
	{
		for (int j = 0; j < i; j++)//j��0��ʼ��������i֮���Ϊ��������
		{
			if (nums[i] > nums[j])
				swap(nums[i], nums[j]);
		}
	}
}
/*ð�������Ż�*/
void BubbleSortWithFlag(vector<int>& nums)
{
	int n = nums.size();
	bool flag = true;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			swap(nums[i], nums[j]);
			flag = false;//û�н���Ԫ��
		}
		if (flag)
			break;//����ѭ��������Ԫ����ȫ������
	}

}


/*��������*/
void InsertSort(vector<int>& nums)//��ÿһ��Ԫ�ز��뵽��ȷ��λ��
{
	for (int i = 1; i < nums.size(); i++)
	{
		int j = i - 1, base = nums[i];//base�����ᱻ�Ƶ�0~i������ȷ��λ��
		while (j < 0 && nums[j] > base)
		{
			nums[j + 1] = nums[j];//��base���Ԫ��ȫ������ƶ�
			j--;
		}
		nums[j + 1] = base;//����ѭ��˵�������˱�baseС�����������Ѿ���0����baseֵ����������
	}
}


/*��������*/
int partition(vector<int>& nums,int left, int right)
{
	int i = left, j = right;//��left��Ϊ��׼��
	while (i < j)
	{
		while (i < j && nums[j] >= nums[left])//���������ҵ�һ��С�ڻ�׼����
			j--;
		while (i < j && nums[i] <= nums[left])//���������ҵ�һ�����ڻ�׼����
			i++;
		swap(nums[i], nums[j]);
	}
	swap(nums[left], nums[i]);//��i j ���ʱ˵���������
	return i;
}

void QuickSort(vector<int>& nums, int left, int right)
{
	//�������г���Ϊ1ʱֹͣ����
	if (left >= right)
	{
		return;
	}
	int pivot = partition(nums, left, right);
	QuickSort(nums, left, pivot - 1);//�ݹ�����������
	QuickSort(nums, pivot + 1, right);
}


/*�鲢����*/
void Merge(vector<int>& nums, int left, int mid, int right)
{
	//��������Ϊleft-mid����������Ϊmid+1-right
	vector<int> temp(right - left + 1);

	int i = left, j = mid + 1, k = 0;
	
	//���������鶼��û��Ԫ��ʱ�����бȽϽ���С��Ԫ�ظ��Ƶ���ʱ������
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
	//�������������������ʣ��Ԫ�ظ��Ƶ���ʱ������
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

	//����ʱ���鸴�Ƶ�ԭ����
	for (k = 0; k < temp.size(); k++)
	{
		nums[left + k] = temp[k];
	}

}

void MergeSort(vector<int>& nums, int left, int right)
{
	//�ݹ����ֹ����
	if (left >= right)
	{
		return;//����Ϊһʱ�ݹ�
	}

	int mid = right - (right - left) / 2;

	MergeSort(nums, left, mid);
	MergeSort(nums, mid + 1, right);

	//�ϲ�
	Merge(nums, left, mid, right);
}


/*��������*/
//��ʵ��
void CountingSortNative(vector<int>& nums)
{
	int m = 0;//��¼����������Ԫ��
	for (int num : nums)
	{
		m = max(m, num);
	}

	//ͳ�Ƹ����ֳ��ֵĴ���
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

//����ʵ��













int main()
{
	return 0;
}