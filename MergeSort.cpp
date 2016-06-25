/*
 * MergeSort.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: shashi
 */

#include "CommonHeader.h"
#include <cstring>

static int iter=0;

void merge_arrays(int *arr, int *left, int *right,int size)
{
    int mid_point = size/2;
    int left_index = 0, right_index = 0, arr_index =0;
    while( left_index < mid_point && right_index < size - mid_point)
    {
        if(left[left_index] < right[right_index])
        {
            arr[arr_index++] = left[left_index++];
        }
        else
        {
            arr[arr_index++] = right[right_index++];
        }
        iter++;
    }
    
    while(left_index < mid_point)
    {
        arr[arr_index++] = left[left_index++];
        iter++;
    }
    
    while(right_index < size - mid_point)
    {
    	iter++;
        arr[arr_index++] = right[right_index++];
    }
}

int invokeFunction(int inputArr[],int arrSize)
{   
    int mid_point = size / 2 ;
    int left[mid_point], right[size - mid_point];

    if(size == 1 || size == 0)
        return;
    memcpy(left, arr, sizeof(left));
    memcpy(right, arr+mid_point, sizeof(right));

    merge_sort(left, mid_point);
    merge_sort(right, size - mid_point);

    merge_arrays(arr, left, right, size);

    return iter;
}




