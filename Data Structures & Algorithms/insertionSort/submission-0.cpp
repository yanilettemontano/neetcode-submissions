// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        //get length
        size_t len = pairs.size();
        //result array for intermediate states
        vector<vector<Pair>> res;
        if(len == 0) return res; // if the vector is empty
        //loop/iterate through the vector to go from unsorted to sorted
        for(int i = 0; i < len; ++i){
            // sets key iteratively
            Pair key = pairs[i]; 
            int j = i - 1; //prev pointer

            //move elements greater than key one position ahead
            while(j >= 0 && pairs[j].key > key.key){
                pairs[j+1] = pairs[j];
                --j;
            }
            pairs[j+1] = key; //moves key to the next value in the vector
            res.push_back(pairs);
        }
        return res;
    }
};
