class Solution {
public:
    int maxProduct(int n) {
        int max1 = -1 , max2 = -1;
        while(n !=0){
            int k = n%10;
            if(k>max1){
                max2 = max1;
                max1 = k;
            }else if(k > max2){
                max2 = k;
            }
            n/=10;
        }
        return max1*max2;
    }
};