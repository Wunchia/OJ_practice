#include <sstream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;
        for(auto word:words){
            std::stringstream ss(word);
            string w;
            while(getline(ss,w,separator)){
                if(!w.empty()){
                    result.push_back(w);
                }
            }
        }
        return result;
    }
};
