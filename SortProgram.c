#include <stdio.h>

//冒泡排序函数
void BubbleSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }  
}

//插入排序函数
void InertSort(int *arr, int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

//选择排序函数
void SelectionSort(int *arr,int n)
{
    int i,j,min_idx;
    for(i=0;i<n;i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx=j;
            }
        }

        int temp=arr[min_idx];
        arr[min_idx]=arr[i];
        arr[i]=temp;

    }
}


// 交换数组中的两个元素
void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 分治函数
int partition(int *arr, int low, int high) {
    // 取第一个元素作为基准元素
    int pivot = arr[low];
    int i = low + 1, j = high;
    while (1) {
        // 从左往右找到第一个大于等于基准元素的元素
        while (i <= j && arr[i] < pivot) {
            i++;
        }
        // 从右往左找到第一个小于等于基准元素的元素
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (i > j) {
            break;
        }
        // 交换左右两个元素
        swap(arr, i, j);
        i++;
        j--;
    }
    // 将基准元素与j处的元素交换
    swap(arr, low, j);
    // 返回基准元素的位置
    return j;
}

// 快速排序函数
void QuickSort(int *arr,int low,int high)
{
        if (low < high) {
        int pivotIndex = partition(arr, low, high); // 分治
        QuickSort(arr, low, pivotIndex - 1); // 对左半部分进行快速排序
        QuickSort(arr, pivotIndex + 1, high); // 对右半部分进行快速排序
    }

}


void MergeSort(int *arr,int left ,int right)
{
    
}

int main()
{
    int intarray[10] = {3, 4, 1, 6, 8, 9, 2, 5, 10, 7};
    int n = sizeof(intarray) / sizeof(intarray[0]);
    int i, j;
    printf("no sort print\n");

    for (i = 0; i < n; i++)
    {
        printf("%d", intarray[i]);
        if (i < n - 1)
        {
            printf("%s", ",");
        }
    }

    printf("%s", "\n");
    // BubbleSort(intarray, n);
    // InertSort(intarray, n);
    // SelectionSort(intarray,n);
    QuickSort(intarray,0,n-1);
    printf("sort print\n");

    for (i = 0; i < n; i++)
    {
        printf("%d", intarray[i]);
        if (i < n - 1)
        {
            printf("%s", ",");
        }
    }
}
