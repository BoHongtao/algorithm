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
    //第一个元素是有序的，从第二个元素开始排序
    for(i=1;i<n;++i)
    {
        tmp = a[i];
        //j是有序元素的最大下表
        j = i -1;
        //为将要插入的元素腾位置
        while(j>=0 && tmp<a[j])
        {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = tmp;
    }
}

//快速排序，对a数组的l-r段内的元素进行排序
void QuickSort(int *a,int L,int R)
{
    int tmp;
    int i = L;
    int j = R;
    if (L < R)
    {
        //选择第一个元素为枢轴
        tmp = a[L];
        while(i!=j)
        {
            while(j>i && a[j]>tmp)
                --j;
            if(i<j)
            {
                a[i] = a[j];
                ++i;
            }
            while(i<j && a[i]<tmp)
                ++i;
            if(i<j)
            {
                a[j] = a[i];
                --j;
            }
        }
        a[i] = tmp;
        QuickSort(a,L,i-1);
        QuickSort(a,i+1,R);
    }

}


int main()
{
    int arr[] = {7,6,4,5,3,2,1,0,9,8};

    int length = sizeof(arr) / sizeof(arr[0]);
    //SelectSort(arr,length);
    //BubbleSort(arr,length);
    //InsertSort(arr,length);
    QuickSort(arr,0,9);
    for(int i=0;i<length;++i)
    {
        printf("%d ",arr[i]);
    }
}

