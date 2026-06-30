#include <vector>
#include <climits>
using std::vector;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum=0;
        for(auto e:nums){
            xorsum^=e;
        }
        int lsb=(xorsum==INT_MIN?xorsum:xorsum&(-xorsum));
        int type1=0,type2=0;
        for(auto e:nums){
            if(e&lsb){
                type1^=e;
            }else{
                type2^=e;
            }
        }
        return {type1,type2};
    }
};
