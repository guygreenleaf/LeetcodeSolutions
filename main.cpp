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


    //////////////////////////////////////////////////

    //MERGE INTERVALS
    vector<int> interval1 = {1, 3};
    vector<int> interval2 = {2, 6};
    vector<int> interval3 = {8, 10};
    vector<int> interval4 = {15, 18};
    vector<vector<int>> intervals = {interval1, interval2, interval3, interval4};

    vector<vector<int>> mergedInterval = solns.merge(intervals);
    for(auto & i : mergedInterval){
            cout << i[0] << ", " << i[1] << endl;
    }



    //BUY/SELL STOCKS

    std::vector<int> stockPrices = {7, 1, 5, 3, 6, 4};

    cout << solns.maxProfit(stockPrices) << endl;

    return 0;
}



