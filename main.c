#include <stdio.h>
#include <stdlib.h>

//—°‘Ò≈≈–Ú
void choice(int *a,int n)
{
    int i ,j ,tmp
    for (i = 0 ; i < n - 1; i++)
    {
        for (j = i + 1 ; j < n ; j++)
        {
            if(a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}


int main()
{
    int a[10] = {2,4,7,1,6,9,8,3,0,5};
    int i;
    choice(a,10);
    for (i = 0 ; i < 10 ; i++)
    {
        printf("%d ",a[i]);
    }

}

