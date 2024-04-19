#include <bits/stdc++.h>
using namespace std;

int main()
{
   /* ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    map<string,int> m;
    string text;
    while(getline(cin,text)){
        string w="";
        for(char c:text){
            if(isalnum(c)){
                w+=c;
            }
            else if(w!=""){ m[w]+=1;
                w="";

            }
        }
    }
    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    return 0;
}
