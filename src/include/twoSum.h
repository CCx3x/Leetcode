// Created by cc on 2019-04-10.
/********************************************************************************
 *  File Name       ：   twoSum.h
 *  Founder         ：   cc
 *  Creation Date   ：   2019-04-10
 *  Description     ：   leetcode--Two Sum--Only class code
 *  Modifier        ：   cc
 *  Modified Date   ：   2019-04-10
 *  Version         ：   1.0.0
 *  CMakeLists(cpp) ：   add_executable(twoSum.h, "./twoSum.h")
 ********************************************************************************/
#ifndef LEETCODE_TWOSUM_H
#define LEETCODE_TWOSUM_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


//class twoSum {
//private:
//
//public:
//    twoSum();
//
//    ~twoSum();
//
//    vector<int> nums = {};
//    int target;
//    vector<int> TwoSum(vector<int>& , int);
//
//
//protected:
//
//};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result_vec = {0, 1};
        int* copy_vec = new int[nums.size()];
        copy(nums.begin(), nums.end(), copy_vec);
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        while(start < end)
        {
            if(nums[start] + nums[end] == target)
            {
                break;
            }
            else if(nums[start] + nums[end] < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[start] == copy_vec[i] || nums[end] == copy_vec[i] && index < 2)
            {
                result_vec[index++] = i;
            }
        }
        delete[] copy_vec;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = nums.size() - 1; j > i; j--)
//             {
//                 if(target == (nums[i] + nums[j]))
//                 {
//                     result_vec[0] = i;
//                     result_vec[1] = j;
//                     break;
//                 }

//             }
//         }
        return result_vec;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}




#endif //LEETCODE_TWOSUM_H
