#include "QuickFind.hpp"
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

bool UnionFind::is_connected(int first, int second)
{
    if(m_data[first] == m_data[second])
        return true;
    else
        return false;
}

int UnionFind::m_createUnion(int first, int second)
{
    int value_to_be_replaced = m_data[first];
    int new_value = m_data[second];
    for(int index = 0; index < m_size; index++)
    {
        if(m_data[index] == value_to_be_replaced)
            m_data[index] = new_value;
    }
    return 0;
}

void UnionFind::printData()
{
    for(int index = 0; index < m_size; index++)
    {
        std::cout<<m_data[index]<<" ";
    }
    std::cout<<std::endl;
}

void parse_input_file(const std::string& file_name,int& m_size, i__pair **ipairs)
{
    std::fstream fs ;
    std::string line;
    std::vector<std::string> tokens;
    int ipair_index = 0;
    fs.open(file_name,std::fstream::in);
    while(std::getline(fs,line))
    {
        std::istringstream iss(line);
        copy(std::istream_iterator<std::string> (iss),
                std::istream_iterator<std::string> (),
                back_inserter(tokens));
        if(tokens.size() == 1)
        {
            m_size = std::stoi(tokens[0]);
            if(*ipairs == nullptr)
                *ipairs = new i__pair[m_size];
        }
        else if (tokens.size() == 2)
        {
            (*ipairs)[ipair_index].first_number = std::stoi(tokens[0]);
            (*ipairs)[ipair_index].second_number = std::stoi(tokens[1]);
            ipair_index++;
        }
        else
        {
            std::cout<<"ERROR::Invalid line in input file:"<<line<<std::endl;
            std::cout<<"Tokens size "<<tokens.size()<<std::endl;
        }
        tokens.clear();
    }
    fs.close();
}


UnionFind* crete_union_find(const std::string& file_name)
{
    int size = 0;
    i__pair *int_list = nullptr;

    parse_input_file(file_name,size,&int_list);
    if(int_list != nullptr && size != 0)
    {
        UnionFind *uFind = new UnionFind(size);
        uFind->printData();
        for(int index = 0; index < size ; index++)
        {
            if(!uFind->is_connected(int_list[index].first_number, int_list[index].second_number))
            {
                uFind->m_createUnion(int_list[index].first_number, int_list[index].second_number);
            }
        }
        delete[] int_list;
        return uFind;
    }
    return nullptr;
}

int main(int argc, char **argv)
{
    std::string file_name;
    UnionFind *uFind = nullptr;
    if(argc !=2)
        std::cout<<"Usage::QuickFInd <input_file>"<<std::endl;
    
    if(argv[1])
    {
        file_name = std::string(argv[1]);
        std::cout<<"File name to be parsed ::"<<file_name<<std::endl;
        uFind = crete_union_find(file_name);
    }
    if(uFind != nullptr)
    {
        uFind->printData();
    }
    std::cout<<std::endl;
    delete uFind;
    return 0;
}
