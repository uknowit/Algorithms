#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP
#include <cstdio>
#include <iostream>
#include <new>
#include <string>

#define F_SAMPLE_SIZE 10
typedef struct integer_pairs 
{
    int first_number;
    int second_number;
}i__pair;

class UnionFind 
{
    public:
            UnionFind():m_data{new int[F_SAMPLE_SIZE]}
            {
                for(int index = 0; index < F_SAMPLE_SIZE; index++)
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
