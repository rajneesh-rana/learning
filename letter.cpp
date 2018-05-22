#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    void dfs(string digits, string r, map<char,vector<char> > &mp, vector<string> &res){
        if (digits.empty()){
            res.push_back(r);
        }else{
            vector<char> vec = mp[digits[0]];
            for(int i=0;i<vec.size();i++){
                dfs(digits.substr(1),r+vec[i],mp,res);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char,vector<char> > mp;

        vector<char> v;
        v.push_back('1');
        mp['1']=v;
        v.clear();
        v.push_back('0');
        mp['0']=v;
        v.clear();
    
        int n=2;
        for (char i='a';i<='z';i++){
            v.push_back(i);
            if (i=='c' || i=='f'|| i=='i'|| i=='l'|| i=='o'|| i=='s'|| i=='v'|| i=='z'){
                mp[char(n+'0')]=v;
                n++;
                v.clear();
            }
        }
         
        vector<string> res;
        dfs(digits,"",mp,res);
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution abc;
    vector<string> ans=abc.letterCombinations(argv[1]);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}
