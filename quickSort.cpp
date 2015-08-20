//
//  main.cpp
//  tmp
//
//  Created by 周祺华 on 15/8/10.
//  Copyright (c) 2015年 周祺华. All rights reserved.
//

#include <iostream>

int a[101],n;//global array a

void quickSort(int left, int right)
{
    if (left > right)
    {
        return;
    }
    int position = a[left];//positon number
    int i = left;
    int j = right;
    
    while (i != j)
    {
        while (a[j] >= position && i<j)//stop while a[j] < position 一定要确保i<j的前提下移动指针
        {
            j--;
        }
        while (a[i] <= position && i<j)//stop while a[i] > position
        {
            i++;
        }
        if (i < j)//swap a[i] and a[j]
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    a[left] = a[i];//swap positon number
    a[i] = position;
    
    quickSort(left, i-1);//recur
    quickSort(i+1, right);
}

int main(int argc, const char * argv[])
{
    printf("Please input number count: ");
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    quickSort(0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
