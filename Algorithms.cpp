#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
static int iter=0;
static int iterSelect=0;
static int iterInsert=0;
int arrayDivide(int inputArr[],int leftArr[],int rightArr[],int arrSize)
{
	if(arrSize==1)
		return -1;
	int midPos = arrSize/2;
	for(int index=0;index<midPos;index++)
	{
		leftArr[index]=inputArr[index];
		//iter++;
	}
	int internalIndex=0;
	for(unsigned int index=midPos;index<arrSize;index++)
	{
		rightArr[internalIndex]=inputArr[index];
		internalIndex++;
		//iter++;
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
			iter++;
		}
		returnArr[mainIndex++]=leftArr[leftArrIndex];
	}
	for(int i=0;i<copyIndex;i++)
		returnArr[mainIndex++]=copyArr[i];
}

void invokeFunction(int inputArr[],int arrSize)
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
}

void selectionSortImplementation(int inputArr[],int arrSize)
{
	cout<<"Invoking arr size "<<arrSize<<endl;
	int loopIndex=0,sortIndex=0,maxPos=0;
	for(;loopIndex<arrSize;loopIndex++)
	{
		maxPos=loopIndex;
		sortIndex=loopIndex+1;
		for(;sortIndex<arrSize;sortIndex++)
		{
			if(inputArr[sortIndex]>inputArr[maxPos])
			{
				maxPos=sortIndex;
			}
			iterSelect++;
		}
		if(maxPos!=loopIndex)
		{
			inputArr[maxPos]=inputArr[loopIndex]+inputArr[maxPos];
			inputArr[loopIndex]=inputArr[maxPos]-inputArr[loopIndex];
			inputArr[maxPos]=inputArr[maxPos]-inputArr[loopIndex];
		}
	}
}

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
			iterInsert++;
		}
	}
}

int main()
{
	int inputArr[]={15,32,1,7,3,4,6,4,67,78,22,43,11};
	int inputArr1[]={15,32,1,7,3,4,6,4,67,78,22,43,11};
	int inputArr2[]={15,32,1,7,3,4,6,4,67,78,22,43,11};
	size_t arrSize = sizeof(inputArr)/sizeof(inputArr[0]);
	invokeFunction(inputArr,arrSize);
	for (int index=0;index<arrSize;index++)
		cout<<inputArr[index]<<endl;
	cout<<iter<<endl;
	cout<<"======================================="<<endl;
	selectionSortImplementation(inputArr1,10);
	for (int index=0;index<arrSize;index++)
		cout<<inputArr1[index]<<endl;
	cout<<iterSelect<<endl;
	cout<<"======================================="<<endl;
	insertionSortImplementation(inputArr2,arrSize);
	for(int index=0;index<arrSize;index++)
		cout<<inputArr2[index]<<endl;
	cout<<iterInsert<<endl;
}
