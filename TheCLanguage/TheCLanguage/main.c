//
//  main.c
//  TheCLanguage
//
//  Created by Yuke on 2018/8/31.
//  Copyright © 2018年 Yuke. All rights reserved.
//

#include <stdio.h>

#include "LeetCode698.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    int nums[16] = {4, 3, 2, 3, 5, 2, 1,19, 45, 20, 50 ,20, 1, 45, 29, 15}, k = 4;
    
    
    printf("能否被划分为k个相等的子集%d", canPartitionKSubsets(nums, 16, k));
    
    
    return 0;
}
