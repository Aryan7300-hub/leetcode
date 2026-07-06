class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n= arr.size();
        int s=0, e= n-1;
        while(s<=e){
            int mid = s + (e-s)/2; 
            if(arr[mid] == target){
                return mid;
            }else if(arr[mid]>=arr[0] ){
                if(arr[s]<=target && arr[mid]>=target){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }else{
               if(arr[mid]<=target && arr[e]>= target){
                s = mid+1;
               }else{
                e = mid-1;
               }
            }
        }
        return -1;
    }
};