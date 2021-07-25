#include <iostream>
#include <vector>
#include <unordered_map>
#include "./Solutions.hpp"

using namespace std;

int main() {
    Solutions solns;

    //TWO SUM
    std::vector<int> numbers;
    numbers.push_back(3);
    numbers.push_back(5);
    numbers.push_back(10);
    numbers.push_back(13);
    numbers.push_back(11);

    std::vector<int> solution = solns.twoSum(numbers, 23);

    cout << solution[0] << " " << solution[1] << endl;

    //////////////////////////////////////////////////

    //ROBOT CIRCLE
    string instrs = "GGLLGG";

    cout << solns.isRobotBounded(instrs) << std::endl;


    return 0;
}



