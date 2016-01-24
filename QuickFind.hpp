#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP
#include <cstdio>
#include <iostream>
#include <new>
#include <string>


typedef struct integer_pairs 
{
    int first_number;
    int second_number;
}i__pair;

class UnionFind 
{
    public:
            UnionFind(int size):m_size{size},m_data{new int[size]}
            {
                for(int index = 0; index < size; index++)
                    m_data[index] = index;
            }
            ~UnionFind(){delete[] m_data;}
            bool is_connected(int first, int second);
            int  m_createUnion(int first, int second);
            void printData();
    private:
            int m_size;
            int *m_data;

};
#endif
