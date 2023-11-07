class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir = 100;
        int up = 0;
        int side = 0;
        for(int i = 0;i<instructions.length();i++){
            if(instructions[i]=='G'){
                if(dir%4==0){
                    up++;
                }
                else if(dir%4==1){
                    side++;
                }
                else if(dir%4==2){
                    up--;
                }
                else{
                    side--;
                }
            }
            else if(instructions[i]=='L'){
                dir--;
            }
            else{
                dir++;
            }
        }
        if((up==0 && side==0) || (dir%4!=0)){
            return true;
        }
        return false;
    }
};