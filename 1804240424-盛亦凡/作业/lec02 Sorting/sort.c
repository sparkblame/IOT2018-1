#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sort.h"


bool isSorted(int a[], int n)                                                   //判断是否为已排序数组。
{
    for (int i = 1; i < n; i++)
    {
        if(a[i] < a[i-1])
            return false;        
    }
    return true;
}
void exch(int a[], int i, int j)                                                //交换
{
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void printArray(int a[], int n)                                                 //输出数组
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void mergeSort(int a[], int n)                                                  //归并排序  
{
    int *tmpArray = malloc(sizeof(int) * n); 
    if(tmpArray == NULL){
        printf("Memory error!\n");
        exit(-1);
    }
    mSort(a, tmpArray, 0, n - 1);
}

void mSort(int a[], int *tmpArray, int left, int right)                         
{
    if(left < right){
        int center = (left + right) / 2;
        mSort(a, tmpArray, left, center);
        mSort(a, tmpArray, center + 1, right);
        merge(a, tmpArray, left, center + 1, right);
    }
}

void merge(int a[], int *tmpArray, int leftPos, int rightPos, int rightEnd)                     //总结只有两个的情况，处理递归的基础条件和最后两个的排序
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    while (leftPos <= leftEnd && rightPos <= rightEnd)
    {
        if (a[leftPos] <= a[rightPos])
        {   
            tmpArray[tmpPos++] = a[leftPos++];
        }
        else
        {
            tmpArray[tmpPos++] = a[rightPos++];
        }

        while(leftPos <= leftEnd)
            tmpArray[tmpPos++] = a[leftPos++];
        while(rightPos <= rightEnd)
            tmpArray[tmpPos++] = a[rightPos++];
        for (int i = 0; i < numElements; i++, rightEnd--)
        {
            a[rightEnd] = tmpArray[rightEnd];
        }  
    }
}


void insertSort(int a[], int n)                                                                             //插入排序
{
    for (int i = 1; i < n; i++)                                                                            
    {
        int j = i - 1, key = a[i];
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}



int partition(int a[], int left, int right)                 //定位元素，返回元素位置，可以找到元素的次序， 以第一个为开始分界
{
    int i = left;
    int j = right + 1;
    int v = a[left];
    while (true)
    {
        while(a[++i] <= v){
            if(i == right) break;
        }

        while(a[--j] >= v){
            if(j == left) break;
        }
        if(i >= j) break;
        exch(a, i, j);
    }
    exch(a, left, a[j]);
    
    return j;    
}
void qSort(int a[], int left, int right)
{
    if(left <= right) 
        return;
    int j = partition(a, left, right);
    qSort(a, left, j-1);
    qSort(a, j+1, right);
}

void quickSort(int a[], int n)
{
    qSort(a, 0, n - 1);
    assert(isSorted(a, n));
}


void BInsertSort (int a[],int n)
{
    int low,high,m,x;
    for (int  i = 1; i < n; ++i)
    {
        x=a[i];
        low=1;high=i-1;
        while(low<=high)
        {
            m=(low+high)/2;
            if (x<a[m])
            {
                high=m-1;
            }
            else
            {
                low=m+1;
            }           
        }
       for (int  j = i-1; j >=low;--j)
        {
             a[j+1]=a[j];
        }
        a[low]=x;
    }
    
}