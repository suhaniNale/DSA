#include <iostream>
#include <queue>
#include <unordered_map> 
using namespace std;

class Solution {
    public:
        string FirstNonRepeating(string & s){
            unordered_map<char, int> count;
            queue<char>q;
            string ans ="";

            for(int i= 0; i<s.length(); i++){
                char ch = s[i];

                //increasing count
                count[ch]++;

                //push into q
                q.push(ch);

                while(!q.empty()){
                    if(count[q.front()] > 1){
                        //repeating char
                        q.pop();
                    }
                    else{
                        ans.push_back(q.front());
                        break;
                    }
                }
                if(q.empty()){
                    ans.push_back('#');
                }
            }
            return ans;
        }
};

int main() {
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>> s;
        Solution obj;

        string ans = obj.FirstNonRepeating(s);
        cout<< ans <<"\n";
    }
    
    return 0;
}