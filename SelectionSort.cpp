/*
 * SelectionSort.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: shashi
 */
#include "CommonHeader.h"
using namespace std;
static int iter=0;
int selectionSortImplementation(int inputArr[],int arrSize)
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
			iter++;
		}
		if(maxPos!=loopIndex)
		{
			inputArr[maxPos]=inputArr[loopIndex]+inputArr[maxPos];
			inputArr[loopIndex]=inputArr[maxPos]-inputArr[loopIndex];
			inputArr[maxPos]=inputArr[maxPos]-inputArr[loopIndex];
		}
	}
	return iter;
}



