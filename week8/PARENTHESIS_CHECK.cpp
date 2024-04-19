#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000000;
int main(){
    stack<char> st;
    char c;
    while( cin >> c){
        if(c == '(' ||c == '[' || c == '{')st.push(c);
        else if(c == '}'){
            if(st.empty()||st.top()!='{'){cout<<0;
                return 0;
            }
            else {
                st.pop();
            }
        }
        else if(c == ']'){
            if(st.empty()||st.top()!='['){cout<<0;
                return 0;
            }
            else {
                st.pop();
            }
        }
        else if(c == ')'){
            if(st.empty()||st.top()!='('){cout<<0;
                return 0;
            }
            else {
                st.pop();
            }
        }
    }
    if(st.empty())cout<<1;
    else cout<<0;
    return 0;
}
