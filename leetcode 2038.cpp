class Solution {
public:
    bool winnerOfGame(string colors) {
        int aliceScore=0;
        int bobScore=0;
        int maxi=-1;
      
        for(int i=1;i<colors.size()-1;i++){

             char currentColor=colors[i];
        char previousColor=colors[i-1];
        char nextColor=colors[i+1];

            if( currentColor=='A' &&previousColor=='A' && nextColor=='A'){
                aliceScore++;
            }
           
           else if( currentColor=='B' && previousColor=='B' && nextColor=='B'){
             bobScore++;
            }



        }

          return ali;
        
    }
};