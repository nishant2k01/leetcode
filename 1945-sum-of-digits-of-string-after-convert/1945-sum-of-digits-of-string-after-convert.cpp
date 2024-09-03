class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        for(auto it: s){
            int temp = it-'a'+1;
            while(temp>0){
                num += temp%10;
                temp/=10;
            }
        }
        k-=1;
        while(k--){
            int sum = 0;
            while(num>0){
                sum += num%10;
                num/=10;
            }
            num = sum;
        }

        return num; 
    }
};