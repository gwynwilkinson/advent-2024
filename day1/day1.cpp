/* Solved 1 Dec 2024

Briefly had a problem with c++ file reading as on the final iteration
the line file >> file_str didnt do anything, so it added the last value to both lists.
This caused the part 2 answer to be out by about 500,000.

This just seems like ifstream jank so i just deleted the last line, but we need
a robust pattern to deal with that next time.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ifstream file;
    file.open("input.txt");

    std::string file_str;
    int32_t distance_sum = 0; // answer for part 1
    int32_t similarity_sum = 0; // answer for part 2

    std::vector<int32_t> first_list;
    std::vector<int32_t> second_list;
    std::vector<int32_t> distance_list;
    std::vector<int32_t> count_list;
    std::vector<int32_t> similarity_list;


    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> file_str;
            auto first = std::stoi(file_str);
            first_list.push_back(first);

            file >> file_str;
            auto second = std::stoi(file_str);
            second_list.push_back(second);

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
        auto distance = abs(first_list.at(i) - second_list.at(i));
        distance_list.push_back(distance);
    }

    for (auto& n : distance_list){
        distance_sum += n;
    }
    std::cout << "The answer to Part 1 is: " << distance_sum << std::endl;

    for (int i=0;i<first_list.size();i++){
        auto count = 0;
        for (int j=0;j<second_list.size();j++){
            if (first_list.at(i) == second_list.at(j)){
                count += 1;
            }
        }
        count_list.push_back(count);
        
    }

    for (int i=0;i<first_list.size();i++){
        auto similarity = first_list.at(i) * count_list.at(i);
        similarity_list.push_back(similarity);
    }

    for (auto& n : similarity_list){
        similarity_sum = std::accumulate(similarity_list.begin(), similarity_list.end(), 0);
    }

    std::cout << "The answer to Part 2 is: " << similarity_sum << std::endl;
    return 0;
    }