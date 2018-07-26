# -*- coding: utf-8 -*-
"""
Created on Thu Jul 26 08:17:50 2018

@author: shashkum
"""

def quickpartition(mylist):
    pivot = mylist[-1]
    index = 0;
    low = index - 1;
    high = len(mylist)-1;
    while index < high:
        if mylist[index] < pivot:
            low = low + 1
            temp = mylist[low]
            mylist[low] = mylist[index]
            mylist[index] = temp
        index =  index + 1
    mylist[-1] = mylist[low + 1]
    mylist[low + 1] = pivot
    return low
    
def main():
    mylist = [4, 3, 5, 2, 6, 1, 9 , 7 , 8]
    partion_list = mylist[:]
    position = len(partion_list)    
    while position > 1:
        position = len(partion_list)
        position = quickpartition(mylist)
        partion_list = mylist[:position]
        print(position)
        print(partion_list)
        
    
if __name__ == '__main__':
    main() 
