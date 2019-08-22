# -*- coding: utf-8 -*-
"""
Created on Fri Jul 19 19:12:37 2019

@author: shashitth
"""
import time

def fib_memoization(n , memo):
    if memo.get(n) is not None:
        return memo.get(n)
    if n <= 2:
        f = 1
        memo[n] = f
    else:
        f = fib_memoization(n - 1, memo) + fib_memoization(n - 2, memo)
        memo[n] = f
    return memo[n]
    
def fib_bottom_up(n):
    fib = []
    fib.insert(0, -1)
    fib.insert(1, 1)
    fib.insert(2, 1)  
    for i in range(3, n+1):
        f = fib[i - 1] + fib [i - 2]
        fib.insert(i, f)
    return fib[n]

def main():
    start= time.time()    
    print(fib_bottom_up(400))
    end = time.time()
    print("Time taken::", end - start)
    memo = {}
    print(fib_memoization(400, memo))
    new_end = time.time()
    print("Time taken::", new_end - end )
    print((new_end - end) - ( end - start))
if __name__ == '__main__':
    main()
#1, ,1 ,2, 3, 5, 8