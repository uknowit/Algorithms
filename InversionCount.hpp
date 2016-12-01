/*
 * InversionCount.hpp
 *
 *  Created on: 01-Dec-2016
 *      Author: shashkum
 */

#ifndef INV_COUNT_HPP_
#define INV_COUNT_HPP_
#include <iostream>
#include <string>
#include <algorithm>
#include <stdint.h>

static uint32_t gInversionCount = 0;
template<typename T> uint32_t mergeSortedArrays(T *inData, T *rightHalf, T *leftHalf, uint32_t size)
{
	uint32_t invCount = 0;
	uint32_t rightIndex = 0, leftIndex = 0;
	uint32_t midPoint = size/2;
	for(uint32_t index = 0 ; index < size; index++)
	{
		if((rightIndex < midPoint && leftIndex < (size - midPoint)))
		{
			if(rightHalf[rightIndex] < leftHalf[leftIndex])
			{
				inData[index] = rightHalf[rightIndex++];
			}
			else
			{
				inData[index] = leftHalf[leftIndex++];
				invCount += (midPoint - rightIndex);
			}
		}
		else
		{
			while(rightIndex < midPoint)
			{
				inData[index++] = rightHalf[rightIndex++];
			}
			while(leftIndex < (size - midPoint))
			{
				inData[index++] = leftHalf[leftIndex++];
			}
		}
	}
	return invCount;
}

template<typename T> uint32_t mergesortAndCountInversion(T* inData, uint32_t size)
{
	uint32_t inversionCount = 0;

	if(size == 1)
		return 0;
	uint32_t midPoint = size/2;
	T rightHalf[midPoint], leftHalf[size - midPoint];
	std::copy(&inData[0],  &inData[midPoint], &rightHalf[0]);
	std::copy(&inData[midPoint], &inData[size], &leftHalf[0]);
	mergesortAndCountInversion( rightHalf, midPoint);
	mergesortAndCountInversion( leftHalf, size-midPoint);
	inversionCount = mergeSortedArrays(inData, rightHalf, leftHalf, size);
	std::cout<<"Inversion count = "<<inversionCount<<std::endl;
	gInversionCount += inversionCount;
	return gInversionCount;
}


#endif /* INV_COUNT_HPP_ */
