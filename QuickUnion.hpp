#ifndef QUICK_UNION_HPP
#define QUICK_UNION_HPP

#include <cstdio>
#include <iostream>
#include <new>
#include <string>


class QuickUnion 
{
    public:
        QuickUnion(int size):m_size(size),m_data{ new int[size]},size_arr{new int[size]}
        {
            for(int index = 0; index < size; index++)
            {
                m_data[index] = index;
                size_arr[index] = 1; 
            }
        }
        ~QuickUnion()
        { 
            delete[] m_data;
            delete[] size_arr;
        }
        bool is_connected(int first, int second);
        int m_createUnion(int first, int second);
        int find_root_value(int n_index);
        void printData();
        void printSizeArray();

    private:
        int m_size;
        int *m_data;
        int *size_arr;
};

#endif
