/*
Advent of Code 2024 - Day 2
by Gwyn Wilkinson

Compile & run with g++ day2.cpp -o day2 -Wall && ./day2
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ifstream file;
    file.open("input.txt");

    std::string buf;
    std::vector<std::vector<int32_t>> values; 

    if (file.is_open() ) {
        while ( file ) { // equivalent to myfile.good()
            std::getline (file, buf, '\n');
            std::stringstream ss(buf);
            std::string token;
            std::vector<int> v;
            while (std::getline(ss, token, ' ')){
                int32_t val = std::stoi(token);
                v.push_back(val);
            }
            values.push_back(v);
        }
    }
    
    for (int i = 0; i < 3; i++) { 
        for (auto it = values[i].begin(); it != values[i].end(); it++) {
            std::cout << *it << " ";
         }
         std::cout << std::endl;

    } 
  
    return 0;
}