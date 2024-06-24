class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int window = k;
        queue<int> q;
        int parity = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(!q.empty() && q.front() == i){
                parity ^= 1;
                q.pop();
            }
            if((nums[i]^parity) == 0){
                if(i< (nums.size() - window +1)){
                    parity ^= 1;
                    q.push(i + window);
                    ans++;
                }else{
                    return -1;
                }
            }
        }
        return ans;
    }
};