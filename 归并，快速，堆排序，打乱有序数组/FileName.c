#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 7
#define SWAP(arr,i,j){\
int t=arr[i];\
arr[i]=arr[j];\
arr[j]=t;\
}

void printarr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int temp[N];
void merge(int arr[], int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;
	
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else 
		{
			temp[k++] = arr[j++];
		}
	 }
	while (i <= mid)
	{
		temp[k++] = arr[i++];
	}
	while (j<=right)
	{
		temp[k++] = arr[j++];
	}
	for (int m =left; m <= right; m++)
	{
		arr[m] = temp[m];
	}

}
void msort(int arr[], int left, int right)
{
	if (left >= right)return;

	int mid = left + (right - left >> 1);
	msort(arr, left, mid);
	msort(arr, mid + 1, right);

	merge(arr, left, mid, right);
	printarr(arr, N);
}
/*归并排序*/
void merge_sort(int arr[], int n)
{
	msort(arr, 0, n - 1);
}
/*快速排序*/
int partition(int arr[], int left, int right)
{
	int pivot = arr[left];

	int i = left, j = right;
	while (i < j)
	{
		while (i < j && arr[j] >= pivot)
		{
			j--;
		}
		arr[i] = arr[j];
		while (i < j && arr[i] <= pivot)
		{
			i++;
		}
		arr[j] = arr[i];
	}
	arr[i] = pivot;
	return i;

}
void qsort(int arr[], int left, int right)
{
	if (left >= right)return;
	
	int indx = partition(arr, left, right);
	qsort(arr, left, indx - 1);
	qsort(arr, indx + 1, right);

	printarr(arr, 9);
}
void quick_sort(int arr[], int n)
{
	qsort(arr, 0, n - 1);
}
/*堆排序*/
void heapify(int arr[], int i, int n)
{
	while (i < n)
	{
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;
		int maxindx = i;
		if (lchild<n && arr[lchild]>arr[maxindx])
		{
			maxindx = lchild;
		}
		if (rchild<n && arr[rchild]>arr[maxindx])
		{
			maxindx = rchild;
		}
		if (maxindx == i)
			return;
		SWAP(arr, i, maxindx);
		i = maxindx;
	}
}
void build_heap(int arr[], int n)
{
	for (int i = (n - 1 >> 1); i >= 0; i--)
	{
		heapify(arr, i, n);
	}
}
void heap_sort(int arr[], int n)
{
	build_heap(arr, n);
	int len = n;
	while (len > 1)
	{
		SWAP(arr, 0, len - 1);
		len--;
		heapify(arr, 0, len);
	}
	printarr(arr, n);
}
/*打乱有序数组*/

void shuffle(int arr[], int n)
{
	int inhand[9] = { 0 }; // 初始化为0，表示位置未被使用
	int tmp[9]; // 临时数组用于存储打乱后的元素

	for (int i = 0; i < n; i++)
	{
		int j = rand() % n;

		while (inhand[j])
		{
			j = (j + 1) % n; // 循环查找下一个可用位置
		}

		inhand[j] = 1; // 标记位置j已被使用
		tmp[j] = arr[i]; // 将元素存入临时数组的对应位置
	}

	for (int i = 0; i < n; i++)
	{
		arr[i] = tmp[i]; // 将打乱后的元素复制回原数组
	}
}


int main(void)
{
	/*int arr[N] = { 78,32,43,52,1,38,43 };
	int arr1[N] = {38,27,43,3,9,82,10};
	printarr(arr, N);
	merge_sort(arr, N);
	printf("-------------------\n");
	printarr(arr1, N);
	merge_sort(arr1, N);*/

	int arr[] = { 3,7,8,4,2,1,9,5,5 };
	int arr1[] = { 3,7,8,4,2,1,9,5,5 };
	printarr(arr, 9);
	heap_sort(arr,9);
	printf("-------------------\n");
	heap_sort(arr1, 9);
	printf("-------------------\n");
	srand(time(NULL));
	printf("1.");
	shuffle(arr, 9);
	printarr(arr, 9);
	printf("2.");
	shuffle(arr, 9);
	printarr(arr, 9);
	printf("3.");
	shuffle(arr, 9);
	printarr(arr, 9);
	printf("4.");
	shuffle(arr, 9);
	printarr(arr, 9);

	/*quick_sort(arr, 9);*/
	
	return 0;
}