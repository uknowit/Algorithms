/*
 * QuickSort.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: shashi
 */
#include "CommonHeader.h"
using namespace std;

static int iter=0;

int quickSortImplementation(int inputArr[],int arrSize)
{
	int loopIndex=0,pivotElement=arrSize-1;
	if(pivotElement<=0)
		return iter;
	for(;loopIndex<arrSize;loopIndex++)
	{
		iter++;
		if(inputArr[loopIndex]<inputArr[pivotElement])
		{
			inputArr[loopIndex]=inputArr[loopIndex]+inputArr[pivotElement];
			inputArr[pivotElement]=inputArr[loopIndex]-inputArr[pivotElement];
			inputArr[loopIndex]=inputArr[loopIndex]-inputArr[pivotElement];
			if((pivotElement-1)!=loopIndex)
			{
				inputArr[pivotElement-1]=inputArr[pivotElement-1]+inputArr[loopIndex];
				inputArr[loopIndex]=inputArr[pivotElement-1]-inputArr[loopIndex];
				inputArr[pivotElement-1]=inputArr[pivotElement-1]-inputArr[loopIndex];
			}
			else
			{
				pivotElement-=1;
				break;
			}
			pivotElement-=1;
			loopIndex--;
		}
	}
	cout<<"Pivot Element::"<<pivotElement<<endl;
	int leftArr[pivotElement+1],rightArr[arrSize-(pivotElement+1)];
	int leftArrIndex=0,rightArrIndex=0,arrIndex=0;
	for(int index=0;index<arrSize;index++)
	{
		if(index<pivotElement)
			leftArr[leftArrIndex++]=inputArr[index];
		else if (index>pivotElement)
			rightArr[rightArrIndex++]=inputArr[index];
		else
			continue;
	}
	quickSortImplementation(leftArr,leftArrIndex);
	quickSortImplementation(rightArr,rightArrIndex);
	for(int index=0;index<leftArrIndex;index++)
		inputArr[arrIndex++]=leftArr[index];
	arrIndex+=1;
	for(int index=0;index<rightArrIndex;index++)
		inputArr[arrIndex++]=rightArr[index];
	return iter;
}



