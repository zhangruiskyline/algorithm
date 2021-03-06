//https://leetcode.com/problems/zigzag-iterator/
/*
Given two 1d vectors, implement an iterator to return their elements alternately.
For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:
[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].
*/

class ZigzagIterator {
    queue<int> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int start1 = 0;
        int start2 = 0;
        int counter = 0;
        //alternatively push into queue
        while(start1<v1.size() || start2<v2.size()){
            if(counter%2==0){
                if(start1<v1.size()){
                    q.push(v1[start1]);
                    start1++;
                }
            }else{
                if(start2<v2.size()){
                    q.push(v2[start2]);
                    start2++;
                }                
            }
            counter++;
        }
    }

    int next() {
        int ret = q.front();
        q.pop();
        return ret;
    }

    bool hasNext() {
        return !q.empty();
    }
};
