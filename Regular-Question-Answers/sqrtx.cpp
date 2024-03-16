//Author: Ecem Özkul
//Question Link: https://leetcode.com/problems/sqrtx/
//Time Complexity: O(log(N))
class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return x; 
        } 
        //Special case of x=0
        else if (x==1){
            return x;
        } 
        //Special case of x=1
        int first=1; 
        int last=x;
        double central; 
        while(first <= last){
            central=first+(last-first)/2; //Finding the center of the number
            /*
            If square of center equals x, sqrt(x) is already central variable
            In other cases if the square of center is less or more than x,
            We must change the interval of first and last in order to find sqrt(x)
            */
            if(central*central == x){
                return (int)central;
            }
            else if(central*central>(double)x){
                last=central-1; 
            }
            else{
                first=central+1;
            }
        }
        return (int) last; //Returning last as the sqrt(x) because this is the case first>last


        
    }
};