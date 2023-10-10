class Solution {
public:
    int maxProfit(vector<int>& prices) {

      //phele min nikal ke 
      // fir max se minus kar sakte hai

      int maxProfit=0;
      int minSofar=prices[0];

      for(int i=0;i<prices.size();i++){
          minSofar=min(minSofar,prices[i]);
          int profit=prices[i]-minSofar;
          maxProfit=max(maxProfit,profit);
      }
         
   return maxProfit;
          
        }

    
};