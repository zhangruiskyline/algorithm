//https://leetcode.com/problems/two-sum-iii-data-structure-design/
/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,

add(1); add(3); add(5);
find(4) -> true
find(7) -> false

*/

class TwoSum {
private:
  unordered_map<int,int> m;
public:

  // Add the number to an internal data structure.
void add(int number) {
    m[number]++;
}

  // Find if there exists any pair of numbers which sum is equal to the value.
bool find(int value) {
    for(auto dig:m){
        int i = dig.first;
        int j = value-i;
        if((i == j && dig.second>1) || (i!=j && m.find(j)!=m.end()))  //same number added together
            return true;
    }
    return false;
}
};
