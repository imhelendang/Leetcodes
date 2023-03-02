// Best Time to Buy and Sell Stock

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

int maxProfit(vector<int>& prices) {
    int day = 0;

    // find when should buy the stock
    auto min = min_element(prices.begin(), prices.end());   
    cout << "Min is: " << *min << endl;

    // 
    for(int i = 0; i < (int)prices.size(); i++){
        if(prices[i] == *min){
        
            // find when should sell the stock
            for(int j = i; j < (int)prices.size(); j++){
                if(prices[j] > *min){
                    if(prices[j] - *min > day){
                        day = prices[j] - *min;
                    }
                }
            }
        }
    }


    return day;
}


// write an main program use the function above
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;
    return 0;
}

