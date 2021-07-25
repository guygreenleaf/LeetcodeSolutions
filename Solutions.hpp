//
// Created by Guy on 7/24/2021.
//

#ifndef LEETCODESOLUTIONS_SOLUTIONS_HPP
#define LEETCODESOLUTIONS_SOLUTIONS_HPP
#include <vector>

class Solutions {

public:
    std::vector<int> twoSum(std::vector<int>& nums, int target);

    bool isRobotBounded(std::string instructions);

    class LRUCache;

    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals);

    int maxProfit(std::vector<int>& prices);

};


#endif //LEETCODESOLUTIONS_SOLUTIONS_HPP
