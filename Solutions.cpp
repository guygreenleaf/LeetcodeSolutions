//
// Created by Guy on 7/24/2021.
//
#include <vector>
#include <unordered_map>
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
