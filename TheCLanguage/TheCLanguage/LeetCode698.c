//
//  LeetCode698.c
//  TheCLanguage
//
//  Created by Yuke on 2018/8/31.
//  Copyright © 2018年 Yuke. All rights reserved.
//

#include "LeetCode698.h"

/**
 给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
 
 示例 1：
 
 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 输出： True
 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
 
 {4, 3, 2, 3, 5, 2, 1,19, 45, 20, 50 ,20, 1, 45, 29, 15}
 
 注意:
 
 1 <= k <= len(nums) <= 16
 0 < nums[i] < 10000
 **/

//从大到小排序
int descending(const void * a, const void * b)
{
    return  *(int *)b -  *(int *)a;
}


int left = 0;

bool findSubSet(int * nums, int numsSize, int target, bool * status)
{
    if (0 == target)
    {
        return 0;
    }

    left = target;

    for (int i = 0; i < numsSize; i++)
    {
        if (true == status[i])
        {
            continue;
        }

        int num = nums[i];
        
        if (left == 0)
        {
            return true;
        }
        if (left - num < 0)
        {
            continue;
        }

        if (left - num == 0)
        {
            status[i] = true;
            left = 0;
            return true;
        }

        status[i] = true;

        bool res = findSubSet(nums, numsSize, left - num, status);

        if (false == res)
        {
            status[i] = false;
            left = left+num;
        }
        else
        {
            left = 0;
            return true;
        }

    }

    return false;
}


bool canPartitionKSubsets(int* nums, int numsSize, int k) {


    if (nums == NULL || k < 1 || numsSize < 1) return false;

    if (1 == k) return true;

    int sum = 0;

    for (int i = 0; i < numsSize; i++) sum += nums[i];

    if (sum % k != 0) return false;

    qsort(nums, numsSize, sizeof(int), descending);

    int  avg = sum / k;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > avg) return false;
    }

    bool status[numsSize];

    for (int i = 0; i < numsSize; i++) status[i] = false;

    for (int i = 0; i < k; i++)
    {

        if (false == findSubSet(nums, numsSize, avg, status)) return false;
    }

    return true;

}



