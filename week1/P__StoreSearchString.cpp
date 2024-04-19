#include <bits/stdc++.h>
using namespace std;
int main()
{       set<string>se;
        string s;


        while(1){
                cin>>s;
            if(s=="*")break;
            se.insert(s);
        }
        while(1){
                cin>>s;
        if(s=="***")break;
            if(s[0]=='f'){
                cin>>s;
                if (se.find(s)!=se.end())cout<<1<<endl;
                else cout<<0<<endl;
            }
            else if(s[0]=='i')
           {
            cin>>s;
            if(se.find(s)==se.end()){cout<<1<<endl;se.insert(s);}
                else cout<<0<<endl;
            }

        }
    return 0;
}
