#include "CommonHeader.h"

using namespace std;

int main()
{
	int inputArr[]={15,32,1,7,3,4,6,4,67,78,22,43,11};
	int inputArr1[]={15,32,1,7,3,4,6,4,67,78,22,43,11};
	int inputArr2[]={15,32,1,7,3,4,6,4,67,78,22,43,11};
	int inputArr3[]={15,32,1,7,3,4,6,4,67,78,22,43,11};
	int inputArr4[]={5,1,3,4,2};
	size_t arrSize = sizeof(inputArr)/sizeof(inputArr[0]);
	cout<<"========"<<"Merge Sort"<<"============"<<endl;
	int rep=invokeFunction(inputArr,arrSize);
	for (int index=0;index<arrSize;index++)
		cout<<inputArr[index]<<endl;
	cout<<"Iterations::"<<rep<<endl;
	cout<<"========"<<"Selection Sort"<<"=================="<<endl;
	rep=selectionSortImplementation(inputArr1,arrSize);
	for (int index=0;index<arrSize;index++)
		cout<<inputArr1[index]<<endl;
	cout<<"Iterations::"<<rep<<endl;
	cout<<"========="<<"Insertion Sort"<<"=============="<<endl;
	rep=insertionSortImplementation(inputArr2,arrSize);
	for(int index=0;index<arrSize;index++)
		cout<<inputArr2[index]<<endl;
	cout<<"Iterations::"<<rep<<endl;
	cout<<"========="<<"Quick Sort"<<"=============="<<endl;
	rep=quickSortImplementation(inputArr3,arrSize);
	for(int index=0;index<arrSize;index++)
			cout<<inputArr3[index]<<endl;
	cout<<"Iterations::"<<rep<<endl;
	cout<<"========="<<"Quick Sort"<<"=============="<<endl;
	rep=quickSortImplementation(inputArr4,5);
	for(int index=0;index<5;index++)
		cout<<inputArr4[index]<<endl;
	cout<<"Iterations::"<<rep<<endl;
}
