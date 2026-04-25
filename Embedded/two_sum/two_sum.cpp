#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;

        // iterate thru input array
        for(int i = 0; i < nums.size(); i++) {
            // calculate complement (target - current num)
            int complement = target - nums[i];

            // if complement exists in the map
            if(numMap.find(complement) != numMap.end()) {
                // return the indicies of the two numbers that add up to target
                return {
                    numMap[complement], i
                };
            }

            // add the current number and its index to the map
            numMap[nums[i]] = i;
        }

        // if no solution found, return empty vector
        return {};
    }
};