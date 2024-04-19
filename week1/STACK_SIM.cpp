#include <bits/stdc++.h>
using namespace std;
int main()
{     stack<int>st;
    string q;
    while(1){
        cin>>q;
        if(q=="#")break;

        if(q[1]=='U'){
        int tmp;
        cin>>tmp;
        st.push(tmp);
        }
        else if(q[1]=='O'){
            if(st.empty())cout<<"NULL"<<endl;
            else {
                cout<<st.top()<<endl;
                st.pop();
            }
        }
    }
    return 0;
}
