#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream file;
    file.open("input.txt");

    std::string file_str;
    int32_t temp;
    int32_t distance_sum; // answer for part 1

    std::vector<int32_t> first_list;
    std::vector<int32_t> second_list;
    std::vector<int32_t> diff_list;


    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> file_str;
            temp = std::stoi(file_str);
            first_list.push_back(temp);

            file >> file_str;
            temp = std::stoi(file_str);
            second_list.push_back(temp);

        }
    }
    else
    {
        std::cout << "File failed to open" << std::endl;
    }
    file.close();

    std::sort(first_list.begin(), first_list.end());
    std::sort(second_list.begin(), second_list.end());

    for (int i=0;i<first_list.size();i++){
        int32_t temp = abs(first_list.at(i) - second_list.at(i));
        diff_list.push_back(temp);

    }
    for (auto& n : diff_list){
        distance_sum += n;
    }
    std::cout << distance_sum << std::endl;


    return 0;
    }