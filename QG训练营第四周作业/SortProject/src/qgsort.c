#include "qgsort.h"
#include "LinkStack.h"
#include "LinkStack.c"
#include <assert.h>
#include <time.h>

void insertSort(int *a,int n){
    assert(a);
    if (n < 2)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int end = i;
        int temp = a[end + 1];
        while (end >= 0 && a[end] > temp)
        {
            a[end + 1] = a[end];
            --end;
        }
        a[end + 1] = temp;
    }
}

void MergeArray(int *a,int begin,int mid,int end,int *temp){
    assert(a);
    int i,j,k;
    i = begin;
    j = mid + 1;
    k = begin;
    while(i <= mid && j <= end){
        if(a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }else{
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
}

void MergeSort(int* a, int begin, int end, int* temp) {
    assert(a);
    int mid;
    int t[1024];
    if (begin == end) {
        temp[begin] = a[end];
    }
    if (begin < end) {
        int mid = (begin + end) / 2;
        MergeSort(a, begin, mid, t);
        MergeSort(a, mid + 1, end, t);
        MergeArray(t, begin, mid, end, temp);
    }
    return;
}

void QuickSort_Recursion(int *a, int begin, int end){
    assert(a);
    int left;
    if(begin < end){
        left = Partition(a,begin,end);
        QuickSort_Recursion(a,begin,left - 1);
        QuickSort_Recursion(a,left + 1,end);
    }else{
        return;
    }
}

void QuickSort(int *a,int size){
    assert(a);
    if (a == NULL || size <= 0)
    {
        return;
    }
    LinkStack s;
    initLStack(&s);
    int begin = 0;
    int end = size - 1;
    if (begin < end)
    {
        int mid = Partition(a, begin, end);
        if (begin < mid - 1)
        {
            pushLStack(&s, begin);
            pushLStack(&s, mid - 1);
        }
        if (end > mid + 1)
        {
            pushLStack(&s, mid + 1);
            pushLStack(&s, end);
        }
        while (!isEmptyLStack(&s))
        {
            end = getTopLStack(&s);
            popLStack(&s);
            begin = getTopLStack(&s);
            popLStack(&s);
            int par = Partition(a, begin, end);
            if (begin < par - 1)
            {
                pushLStack(&s, begin);
                pushLStack(&s, par - 1);
            }
            if (end > par + 1)
            {
                pushLStack(&s, par + 1);
                pushLStack(&s, end);
            }
        }
    }
    destroyLStack(&s);
}

int Partition(int *a, int begin, int end)
{
    assert(a);
    int left = begin;
    int right = end;
    int temp = a[left];
    while (left < right)
    {
        while ((a[right] >= temp) && (left < right))
        {
            right--;
        }
        a[left] = a[right];
        while ((a[left] <= temp) && (left < right))
        {
            left++;
        }
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}

void CountSort(int *a, int size , int max){
    assert(a);
    int t[1024];
    int i,j = 0;
    for ( i = 0; i <= max; i++)
    {
        t[i] = 0;
    }
    for ( i = 0; i < size; i++)
    {
        t[a[i]]++;
    }
    for ( i = 0; i <= max; i++)
    {
        while ((t[i]--) > 0)
        {
            a[j++] = i;
        }
    }
}

void RadixCountSort(int *a,int size){
    assert(a);
    int exp;
    int max = GetMax(a,size);
    for ( exp = 1; max/exp > 0; exp *= 10)
    {
        CountSort(a,size,max);
    }
}

void ColorSort(int *a,int size){
    assert(a);
    int red = 0,blue = size - 1,temp;
    for (int i = 0; i <= blue; i++)
    {
        if (a[i] == 0)
        {
            temp = a[i];
            a[i] = a[red]; 
            a[red] = temp;
            red++;
        }else if(a[i] == 2){
            temp = a[i];
            a[i] = a[blue]; 
            a[blue] = temp;
            i--;
            blue--;
        }
    }
}

int FindKthMin(int *a,int begin,int end,int k){
    assert(a);
    int pos;
    if (k > 0 && k <= end)
    {
        pos = Partition(a,begin,end);
        if (pos - begin == k - 1)
        {
            return a[pos];
        }
        if (pos - begin > k - 1)
        {
            return FindKthMin(a,begin,pos - 1,k);
        }
        return FindKthMin(a,pos + 1,end,k - pos + begin - 1);
    }
    return GetMax(a,end + 1);
}

int GetMax(int *a,int size){
    assert(a);
    int i,max;
    max = a[0];
    for ( i = 0; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}