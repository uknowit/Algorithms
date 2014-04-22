#include "CommonHeader.h"

using namespace std;

int main()
{
	int inputArr[]={15,32,1,7,3,4,6,4,67,78,22,43,11};
	int inputArr1[]={15,32,1,7,3,4,6,4,67,78,22,43,11};
	int inputArr2[]={15,32,1,7,3,4,6,4,67,78,22,43,11};
	size_t arrSize = sizeof(inputArr)/sizeof(inputArr[0]);
	cout<<"========"<<"Merge Sort"<<"============"<<endl;
	invokeFunction(inputArr,arrSize);
	for (int index=0;index<arrSize;index++)
		cout<<inputArr[index]<<endl;
	cout<<"========"<<"Selection Sort"<<"=================="<<endl;
	selectionSortImplementation(inputArr1,10);
	for (int index=0;index<arrSize;index++)
		cout<<inputArr1[index]<<endl;
	cout<<"========="<<"Insertion Sort"<<"=============="<<endl;
	insertionSortImplementation(inputArr2,arrSize);
	for(int index=0;index<arrSize;index++)
		cout<<inputArr2[index]<<endl;
}
