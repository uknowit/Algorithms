/*
 * CommonHeader.h
 *
 *  Created on: Apr 22, 2014
 *      Author: shashi
 */

#ifndef COMMONHEADER_H_
#define COMMONHEADER_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
extern "C" {
	int arrayDivide(int inputArr[],int leftArr[],int rightArr[],int arrSize);
	void sortAndMergeArray(int returnArr[],int leftArr[],int rightArr[],int arrSize,int leftArrSize,int rightArrSize);
	int invokeFunction(int inputArr[],int arrSize);
	int selectionSortImplementation(int inputArr[],int arrSize);
	int insertionSortImplementation(int inputArr[],int arrSize);
	int quickSortImplementation(int inputArr[],int arrSize);
}



#endif /* COMMONHEADER_H_ */
