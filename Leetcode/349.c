//
//  349.c
//  Leetcode
//
//  Created by 胡星宇 on 2018/8/1.
//  Copyright © 2018年 胡星宇. All rights reserved.
//

#include "349.h"

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int32_t n1 = nums1Size, n2 = nums2Size, rs = 0, i;
    int32_t min = INT_MAX, max = INT_MIN;
    for (i = 0; i < n1; i++) {
        min = min > nums1[i] ? nums1[i] : min;
        max = max < nums1[i] ? nums1[i] : max;
    }
    char* tmp = calloc(max - min + 1, 1);
    int * re = malloc((max - min + 1) * sizeof(int));
    
    for (i = 0; i < n1; i++)
        tmp[nums1[i] - min] = 1;
    for (i = 0; i < n2; i++)
        if (nums2[i] <= max && nums2[i] >= min && tmp[nums2[i] - min]) {
            tmp[nums2[i] - min] = 0;
            re[rs++] = nums2[i];
        }
    *returnSize = rs;
    free(tmp);
    return realloc(re, rs * sizeof(int));
}
void ut_349(void)
{
    printf("unit test 349...\n");
    int rs, i;
    int* re;
    int t1[] = {1, 2, 2, 1};
    int t11 = 4;
    int t2[] = {2, 2};
    int t22 = 2;
    re = intersection(t1, t11, t2, t22, &rs);
    for (i = 0; i < rs; i++)
        printf("%d,", re[i]);
    printf("\n");
    int t3[] = \
    { 61,24,20,58,95,53,17,32,45,85,70,20,83,62,35,89,5,95,12,86,58,77,30,64,46,13,5,92,67,40,20,38,31,18,89,85,7,30,67,34,62,35,47,98,3,41,53,26,66,40,54,44,57,46,70,60,4,63,82,42,65,59,17,98,29,72,1,96,82,66,98,6,92,31,43,81,88,60,10,55,66,82,0,79,11,81};
    int t4[] = \
    {5,25,4,39,57,49,93,79,7,8,49,89,2,7,73,88,45,15,34,92,84,38,85,34,16,6,99,0,2,36,68,52,73,50,77,44,61,48};
    re = intersection(t3, sizeof(t3)/sizeof(int), t4, sizeof(t4)/sizeof(int), &rs);
    for (i = 0; i < rs; i++)
        printf("%d,", re[i]);
    printf("\n");
 
}
