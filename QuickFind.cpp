#include "QuickFind.hpp"
#include "QuickUnion.hpp"
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
    for(int index = 0; index < F_SAMPLE_SIZE; index++)
    {
        if(m_data[index] == value_to_be_replaced)
            m_data[index] = new_value;
    }
    return 0;
}

void UnionFind::printData()
{
    for(int index = 0; index <F_SAMPLE_SIZE; index++)
    {
        std::cout<<m_data[index]<<" ";
    }
    std::cout<<std::endl;
}

void QuickUnion::printData()
{
    for(int index = 0; index < U_SAMPLE_SIZE; index++)
    {
        std::cout<<m_data[index]<<" ";
    }
    std::cout<<std::endl;
}

void QuickUnion::printSizeArray()
{
    for(int index = 0; index < 10; index++)
    {
        std::cout<<size_arr[index]<<" ";
    }
    std::cout<<std::endl;
}
int QuickUnion::find_root_value(int n_index)
{
    int root_value = m_data[n_index];
    int index = n_index;
    while(root_value != index)
    {
        index = root_value;
        root_value = m_data[index];
    }
    return root_value;
}

bool QuickUnion::is_connected(int first, int second)
{
    int first_root_value = find_root_value(first);
    int second_root_value = find_root_value(second);
    if(first_root_value == second_root_value)
        return true;
    else
        return false;
}

int QuickUnion::m_createUnion(int first, int second)
{
    int second_root_value = find_root_value(second);
    int first_root_value = find_root_value(first);
    //m_data[first_root_value] = second_root_value;
    if(first_root_value == second_root_value)
        return 0;
     if(size_arr[first_root_value] <= size_arr[second_root_value])
    {
        m_data[first_root_value] = second_root_value;
        size_arr[second_root_value]+=size_arr[first_root_value];
    }
    else
    {
        m_data[second_root_value] = first_root_value;
        size_arr[first_root_value]+=size_arr[second_root_value];
    }
    return 0;
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
        UnionFind *uFind = new UnionFind();
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

QuickUnion* create_quick_union(const std::string& file_name)
{
    int size = 0;
    i__pair *int_list = nullptr;

    parse_input_file(file_name,size,&int_list);
    if(int_list != nullptr && size != 0)
    {
        QuickUnion *uFind = new QuickUnion();
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
    QuickUnion *unionPtr = nullptr;
    if(argc !=2)
        std::cout<<"Usage::QuickFInd <input_file>"<<std::endl;
    
    if(argv[1])
    {
        file_name = std::string(argv[1]);
        std::cout<<"File name to be parsed ::"<<file_name<<std::endl;
        uFind = crete_union_find(file_name);
        unionPtr = create_quick_union(file_name);

    }
    if(uFind != nullptr )
    {
        uFind->printData();
    }
    std::cout<<"========================="<<std::endl;
    if(unionPtr != nullptr)
    {
        unionPtr->printData();
        unionPtr->printSizeArray();
    }
    delete uFind;
    return 0;
}
