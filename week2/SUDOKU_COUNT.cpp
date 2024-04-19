//CPP
#include <bits/stdc++.h>
using namespace std;
int a[9][9];
int s=0;
bool markr[9][10],markc[9][10],markm[3][3][10];
bool check(int v,int r,int c){
    return markr[r][v]==false && markc[c][v]==false && markm[r/3][c/3][v]==false;
}
void Try(int r,int c){
    if(a[r][c]>0){
        if(r==8 && c==8) {s++;}
        else{
            if(c==8)Try(r+1,0);
            else Try(r,c+1);
        }
        return;
    }
    for(int v=1;v<=9;v++){
        if(check(v,r,c)){
            a[r][c]=v;
            markr[r][v]=true;
            markc[c][v]=true;
            markm[r/3][c/3][v]=true;
            if(r==8 && c==8) {s++;}
            else {
                if(c<8)Try(r,c+1);
                else Try(r+1,0);
            }
            markr[r][v]=false;
            markc[c][v]=false;
            markm[r/3][c/3][v]=false;
a[r][c]=0;
        }
    }
}
int main()
{
    for(int v=1;v<=9;v++){
        for(int r=0;r<=8;r++)markr[r][v]=false;
        for(int c=0;c<=8;c++)markc[c][v]=false;
        for(int x=0;x<=2;x++)
            for(int c=0;c<=2;c++)
                markm[x][c][v]=false;
    }
for(int r=0;r<=8;r++)
    for(int c=0;c<=8;c++)
    {
    cin>>a[r][c];
    int v=a[r][c];
        if(v>0){
        markr[r][v]=true;
        markc[c][v]=true;
        markm[r/3][c/3][v]=true;}
    }
    Try(0,0);
    cout<<s;
    return 0;
}
