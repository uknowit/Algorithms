import random
import time

def bottoms_up_sort(mylist):
    list_len = len(mylist)
    step_size = 2;
    while step_size <= list_len:
        index = 0
        sorted_list = []
        result_list = []
        while index < list_len:
            midpoint = (int)(step_size/2);
            sorted_list = sort_and_merge_array(mylist[index:index+midpoint], mylist[index+midpoint:index+step_size])
            index = index + step_size
            result_list.extend(sorted_list)
        mylist = result_list
        step_size = 2*step_size
    return mylist
    
def sort_and_merge_array(rightHalf, leftHalf):
    sortedList = []
    rightIndex = 0
    leftIndex = 0
    while (rightIndex < len(rightHalf) and leftIndex < len(leftHalf)):
        if rightHalf[rightIndex] < leftHalf[leftIndex]:
            sortedList.append(rightHalf[rightIndex])
            rightIndex += 1
        else:
            sortedList.append(leftHalf[leftIndex])
            leftIndex = leftIndex + 1
    if (rightIndex < len(rightHalf)):
        sortedList.extend(rightHalf[rightIndex:])
    elif (leftIndex < len(leftHalf)):
        sortedList.extend(leftHalf[leftIndex:])
    return sortedList

def merge_sort_array(mylist):
    midpoint  = int(len(mylist)/2);
    if(midpoint < 1):
        return mylist
    rightHalf = mylist[0:midpoint]
    leftHalf  = mylist[midpoint:len(mylist)]
    sortedRight = merge_sort_array(rightHalf)
    sortedLeft  = merge_sort_array(leftHalf)
    return sort_and_merge_array(sortedRight, sortedLeft)
         
    
def main():
    random_list = random.sample(range(1, pow(2, 22)), pow(2,20))
    print(len(random_list))
    start_time = time.time()
    #newlist = merge_sort_array(random_list)
    #mylist = [4, 3, 5, 2, 6, 1, 9 , 7 , 8]
    newlist = bottoms_up_sort(random_list)
    #print((newlist))
    end_time = time.time()
    print(all(newlist[i] <= newlist[i+1] for i in range(len(newlist)-1)))
    print(end_time - start_time)     
    #for item in newlist:
    #    print(item, end=" ")

if __name__=='__main__':
    main()
