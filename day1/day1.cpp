/* Solved 1 Dec 2024

Had to use python for part 2 as im getting the wrong answer in c++ somehow.

TODO - fix part 2

part 1 answer: 3508942
part 2 answer: 26593248

Correct Python code:
    left_list = []
    right_list = []
    count_list = []
    similarity_list = []
    with open("input.txt", 'r') as f:
        while data := f.readline():
            left, right = data.split()
            left_list.append(left)
            right_list.append(right)

    for left_num in left_list:
        count = 0
        for right_num in right_list:
            if left_num == right_num:
                count=count+1
        count_list.append(count)

    for left, right, count in zip(left_list, right_list, count_list):
        similarity_list.append(int(left) * count)

    print(sum(similarity_list))

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

    // for (int i=0;i<first_list.size();i++){
    //     std::cout << first_list.at(i) << " " << second_list.at(i) << " " << distance_list.at(i) << " " << count_list.at(i) << " " << similarity_list.at(i) << std::endl;
    // }
    // for (int i=0;i<first_list.size();i++){
    //     std::cout << first_list.at(i) << " " << count_list.at(i) << " " << similarity_list.at(i) << std::endl;
    // }
    
    return 0;
    }