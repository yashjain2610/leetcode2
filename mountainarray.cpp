class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low = 0;
        int high = mountainArr.length() - 1;
        int mid = (low + high)/2;
        while(low < high){
            mid = (low + high)/2;
            int x = mountainArr.get(mid);
            int xr = mountainArr.get(mid+1);
            int xl = mountainArr.get(mid - 1);
            if(x > xr && x > xl){
                break;
            }
            if(x > xr){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        int peak = mid;
        if(target == mountainArr.get(mid)){
            return mid;
        }
        low = 0;
        high = peak;
        while(low <= high){
            mid = (low + high)/2;
            int x = mountainArr.get(mid);
            if(target == x){
                return mid;
            }
            if(target < x){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        low = peak;
        high = mountainArr.length() - 1;
        while(low <= high){
            mid = (low + high)/2;
            int x = mountainArr.get(mid);
            if(target == x){
                return mid;
            }
            if(target < x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
Console
