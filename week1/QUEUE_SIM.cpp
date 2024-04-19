//CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{ queue <int> qu;
    while(1){
        string q;
        cin>>q;
        if(q=="#")return 0;
        if(q=="PUSH"){
            int x;cin>>x;
            qu.push(x);
        }
        else if(q=="POP"){
            if(qu.empty())cout<<"NULL\n";
            else{cout<<qu.front()<<endl;
            qu.pop();}
        }
    }
}
