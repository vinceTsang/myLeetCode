//#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hash; //unordered_map is a hashmap, unordered, which isn't like to map
        vector<int> ans;
        for(int i = 0; i < numbers.size(); i++){
            int numberToFind = target - numbers[i];
            //if numbersToFind is found in map, return them
            if(hash.find(numberToFind) != hash.end()){
                ans.push_back(hash[numberToFind]+1);
                ans.push_back(i+1);
                return ans;
            }
            //because the answer is unique, firstNum + secondNum = target
            //number was not found, means the secondNum still on behind
            //put the current num in the map, it could be the firstNum
            hash[numbers[i]]=i;
        }
        return ans;
    }
};
