//
// Created by Guy on 7/24/2021.
//
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Solutions.hpp"

//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//You can return the answer in any order.

//BRUTE FORCE - just scan one by one and compare with every other element. O(n^2)

//FAST - use a map and check for complements of each value!
//     [
//       value -> index
//       value -> index
//     ]

std::vector<int> Solutions::twoSum(std::vector<int>& nums, int target) {
    std::vector<int> solution;

    std::unordered_map<int, int> map;
    //Iterate through vector and for every element:
    for(int i = 0; i < nums.size(); i++){
        //Get the current element
        int cur = nums[i];
        //Get the complement of that number - ie complement = target - cur

        int complement = target - cur;
        //Check the map for the complement. If we find it, get that index AND the complement
        if (map.find(complement) != map.end()){
            solution.push_back(map[complement]);
            solution.push_back(i);
            return solution;
        }
        //Otherwise, we didn't find a complement so record the value -> index for the element we're at
        map[nums[i]] = i;
    }
    return solution;
}

/////////////////////////////////////////////////////////////////////////////////////////////

//On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:
//
//"G": go straight 1 unit;
//"L": turn 90 degrees to the left;
//"R": turn 90 degrees to the right.
//
//The robot performs the instructions given in order, and repeats them forever.
//
//Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

//EXAMPLE:
// Input: instructions = "GGLLGG"
//Output: true
//Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
//When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.

bool Solutions::isRobotBounded(std::string instructions){

    std::vector<std::pair<int, int>> directions;
    std::pair<int, int> north = std::make_pair(0, 1);
    std::pair<int, int> east = std::make_pair(1, 0);
    std::pair<int, int> south = std::make_pair(0, -1);
    std::pair<int, int> west = std::make_pair(-1, 0);
    directions.push_back(north);
    directions.push_back(east);
    directions.push_back(south);
    directions.push_back(west);


    std::vector<char> instrs(instructions.begin(), instructions.end());

    //init position
    int x = 0;
    int y = 0;
    //facing NORTH
    int idx = 0;

    for(char i : instrs){
        if(i == 'L'){idx = (idx + 3) % 4;}

        else if(i == 'R'){idx = (idx + 1) % 4;}

        else{
            x += directions[idx].first;
            y += directions[idx].second;
        }
    }

    //AFTER ONE CYCLE
    //Is robot in original position? (0,0)
    //OR does it NOT face north? (consequence of the plane symmetry for the repeated cycles)
    return (x == 0 && y == 0) || (idx != 0);

}

///////////////////////////////////////////////////////////////////////////////////////////////

//Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
//
//Implement the LRUCache class:
//
//LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//int get(int key) Return the value of the key if the key exists, otherwise return -1.
//void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
//The functions get and put must each run in O(1) average time complexity.

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
class LRUCache {

    int size;
    list<int> lru;                              // MRU ... LRU
    unordered_map<int, list<int>::iterator> mp; // key -> iterator
    unordered_map<int, int> kv;                 // key -> value


public:
    LRUCache(int capacity){
        size = capacity;
    }


    int get(int key) {
        if (kv.count(key) == 0) return -1;
        updateLRU(key);
        return kv[key];
    }

    void put(int key, int value) {
        if (kv.size() == size && kv.count(key) == 0)
            evict();
        updateLRU(key);
        kv[key] = value;
    }

    void updateLRU(int key) {
        if (kv.count(key))
            lru.erase(mp[key]);
        lru.push_front(key);
        mp[key] = lru.begin();
    }

    void evict() {
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }

};
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//MERGE INTERVALS
//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
//
//EXAMPLE:
//Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

std::vector<std::vector<int>> Solutions::merge(std::vector<std::vector<int>>& intervals) {
    //Edge case: If `intervals` only contains one interval.
    if(intervals.size()<=1) return intervals;
    //Sort the intervals
    std::sort(intervals.begin(), intervals.end());
    //create vector that will be our output
    std::vector<std::vector<int>> output;
    //Push the first interval into the output vector
    output.push_back(intervals[0]);
    //Loop over `intervals` and:
    for(int i=1; i<intervals.size(); i++) {
        //if the last interval in the `output` vector has a 2nd value that's greater than or equal to the 1st value at the i'th interval in `intervals`,
        if(output.back()[1] >= intervals[i][0]){
            //Set 2nd value in last interval of output vector to the max between itself and the 2nd value at the i'th interval in intervals
            output.back()[1] = std::max(output.back()[1] , intervals[i][1]);
        }
        //otherwise just push the current interval in `intervals` into the `output` vector
        else output.push_back(intervals[i]);
    }
    return output;
}

/////////////////////////////////////////////////////////////////////////////////////////////////



//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
//
//Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
//
//EXAMPLES:
//Input: prices = [7,1,5,3,6,4]
//Output: 5
//Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
//
//Input: prices = [7,6,4,3,1]
//Output: 0
//Explanation: In this case, no transactions are done and the max profit = 0.

int Solutions::maxProfit(std::vector<int>& prices) {

    if(prices.empty()) {return 0;}

    int minPrice = prices[0];
    int maxProfit = 0;

    for(int price: prices){
        if(price < minPrice){
            minPrice = price;
        }
        else{
            maxProfit = std::max(maxProfit, price - minPrice);
        }
    }
    return maxProfit;
}
