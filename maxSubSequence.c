int maxSubSeqSum(int a[], int n)
{
    int sum, max;
    sum = max = 0;
    int i;
    
    for(i = 0; i < n; i++)
    {
        sum += a[i];    //向右累加
        if(sum > max)
            max = sum;  //发现有更大的子列和则更新max
        else if(sum < 0)
            sum = 0;    //当前子列和为负，负数添加到后面的子列时，只会使子列和变小，并不能构造更大的，故可以舍弃。
                        // sum重新归0，继续向后找算的子列。
    }
    return max;
}    

//分析：相比于一般思路的二重for循环，这里只用了一次，有效降低时间复杂度，此处为O(n)，这应该是近乎于最有效的方法了。
