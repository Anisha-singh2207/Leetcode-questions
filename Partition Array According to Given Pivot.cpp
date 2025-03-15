class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int countless  = 0;
        int countequal = 0;

        for(int &num : nums) {
            if(num < pivot)
                countless++;
            else if(num == pivot)
                countequal++;
        }

        int i = 0; //less than pivot
        int j = countless; //equal to pivot
        int k = countless + countequal; //more than pivot
        vector<int> result(n);

        for(int &num : nums) {
            if(num < pivot) {
                result[i] = num;
                i++;
            } else if(num == pivot) {
                result[j] = num;
                j++;
            } else {
                result[k] = num;
                k++;
            }
        }
        
        return result;

    }
};