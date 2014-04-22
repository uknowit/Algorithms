/*
 * MergeSort.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: shashi
 */

#include "CommonHeader.h"
static int iter=0;
int arrayDivide(int inputArr[],int leftArr[],int rightArr[],int arrSize)
{
	if(arrSize==1)
		return -1;
	int midPos = arrSize/2;
	for(int index=0;index<midPos;index++)
	{
		leftArr[index]=inputArr[index];
	}
	int internalIndex=0;
	for(unsigned int index=midPos;index<arrSize;index++)
	{
		rightArr[internalIndex]=inputArr[index];
		internalIndex++;
	}
}


void sortAndMergeArray(int returnArr[],int leftArr[],int rightArr[],int arrSize,int leftArrSize,int rightArrSize)
{
	int mainIndex=0;
	int copyIndex=0;
	int startIndex=0;
	int copyArr[rightArrSize];
	for(int leftArrIndex=0;leftArrIndex<leftArrSize;leftArrIndex++)
	{
		for(int index=startIndex;index<rightArrSize;index++)
		{
			iter++;
			if(leftArr[leftArrIndex] < rightArr[index])
			{
				returnArr[mainIndex++]=rightArr[index];
				startIndex=index+1;
			}
			else if(leftArrIndex==leftArrSize-1)
			{
				copyArr[copyIndex++]=rightArr[index];
			}
			else
				continue;
		}
		returnArr[mainIndex++]=leftArr[leftArrIndex];
	}
	for(int i=0;i<copyIndex;i++)
		returnArr[mainIndex++]=copyArr[i];
}

int invokeFunction(int inputArr[],int arrSize)
{
	int midPos = arrSize/2;
	int otherSize=arrSize-midPos;
	int leftArr[midPos],rightArr[otherSize];
	int retValue=arrayDivide(inputArr,leftArr,rightArr,arrSize);
	if(retValue!=-1)
	{
		int leftRetArr[midPos],rightRetArr[otherSize];
		invokeFunction(leftArr,midPos);
		invokeFunction(rightArr,otherSize);
	}
	sortAndMergeArray(inputArr,leftArr,rightArr,arrSize,midPos,otherSize);
	return iter;
}




