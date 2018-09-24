#include <stdio.h>
#include <stdlib.h>

//选择排序
void SelectSort(int *a,int n)
{
    int i,j,k;
    int tmp;
    for(i=0;i<=n-1;++i)
    {
        k = i;
        //从无序元素中挑出最小的一个元素
        for(j=i+1;j<=n-1;++j)
        {
            if(a[k]>a[j])
                //k是最小元素的下标
                k = j;
            tmp = a[i];
            a[i] = a[k];
            a[k] = tmp;
        }

    }
}

//冒泡排序 循环n-1次
void BubbleSort(int *a,int n)
{
    int i,j,tmp;
    int flag;
    for (i=n-1;i>=1;--i)
    {
        flag = 0;
        for(j=1;j<=i;++j)
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            flag = 1;
        }
        //没有交换说明已经有序
        if(flag==1)
            return;
    }
}

//直接插入排序
void InsertSort(int *a,int n)
{
    int i,j;
    int tmp;
    for(i=1;i<n;++i)
    {
        tmp = a[i];
        j = i -1;
        while(j>=0 && tmp<a[j])
        {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = tmp;
    }
}


int main()
{
    int arr[] = {7,6,4,5,3,2,1,0,9,8};

    int length = sizeof(arr) / sizeof(arr[0]);
    //SelectSort(arr,length);
    //BubbleSort(arr,length);
    InsertSort(arr,length);
    for(int i=0;i<length;++i)
    {
        printf("%d ",arr[i]);
    }
}

