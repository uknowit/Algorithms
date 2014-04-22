/*
 * InsertionSort.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: shashi
 */

#include "CommonHeader.h"

void insertionSortImplementation(int inputArr[],int arrSize)
{
	int loopIndex=1,sortIndex=0;
	for(;loopIndex<arrSize;loopIndex++)
	{
		sortIndex=loopIndex;
		for(;sortIndex>0;sortIndex--)
		{

			if(inputArr[sortIndex-1]<inputArr[sortIndex])
			{
				inputArr[sortIndex-1]=inputArr[sortIndex-1]+inputArr[sortIndex];
				inputArr[sortIndex]=inputArr[sortIndex-1]-inputArr[sortIndex];
				inputArr[sortIndex-1]=inputArr[sortIndex-1]-inputArr[sortIndex];
			}
		}
	}
}


