#include "utilities.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>


int find_peak(std::vector<int>& numbers, int& iteration)
{
    iteration++;
    if(numbers.size() == 1)
        return numbers[0];

    if(numbers.size() == 2)
    {
        if(numbers[0] > numbers[1])
        {
            return numbers[0];
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int midpoint = numbers.size()/2;
        if((numbers[midpoint] >= numbers[midpoint-1]) && (numbers[midpoint] >= numbers[midpoint+1]))
        {
            return numbers[midpoint];
        }
        else
        {
            if(numbers[midpoint] < numbers[midpoint-1])
            {
                std::vector<int>::const_iterator begin = numbers.begin();
                std::vector<int>::const_iterator end_iter = numbers.begin()+midpoint+1;
                std::vector<int> reduced_numbers(begin, end_iter);
                return find_peak(reduced_numbers, iteration);
            }
            else
            {
                std::vector<int>::const_iterator begin = numbers.begin()+midpoint;
                std::vector<int>::const_iterator end_iter = numbers.end();
                std::vector<int> reduced_numbers(begin, end_iter);
                return find_peak(reduced_numbers, iteration);
            }
        }
    }
}

void parse_input_file(const std::string& file_name, std::vector<std::string>& tokens)
{
    std::fstream fs ;
    std::string line;
    int ipair_index = 0;
    fs.open(file_name,std::fstream::in);
    while(std::getline(fs,line))
    {
        std::istringstream iss(line);
        copy(std::istream_iterator<std::string> (iss),
                std::istream_iterator<std::string> (),
                back_inserter(tokens));
    }
    fs.close();
}

int main(int argc, char** argv)
{
    std::vector<std::string> numbers;
    std::vector<int> trans_numbers;
    std::string file_name;
    int iteration = 0;

    if(argc != 2)
    {
        std::cout<<"Usage::peak_finder <file_name>"<<std::endl;
        exit(0);
    }

    file_name = std::string(argv[1]);
    parse_input_file(file_name, numbers); 
    for(auto number: numbers)
        trans_numbers.push_back(std::stoi(number));
    
    if(trans_numbers.size() != 0)
    {
        std::cout<<"Peak:: "<<find_peak(trans_numbers, iteration)<<std::endl;
        std::cout<<"Iterations:: "<<iteration<<std::endl;
    }   
}
