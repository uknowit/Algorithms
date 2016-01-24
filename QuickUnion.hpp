#ifndef QUICK_UNION_HPP
#define QUICK_UNION_HPP

#include <cstdio>
#include <iostream>
#include <new>
#include <string>

#define U_SAMPLE_SIZE 10

class QuickUnion 
{
    public:
        QuickUnion():m_data{ new int[U_SAMPLE_SIZE]},size_arr{new int[U_SAMPLE_SIZE]}
        {
            for(int index = 0; index < U_SAMPLE_SIZE; index++)
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
        int *m_data;
        int *size_arr;
};

#endif
