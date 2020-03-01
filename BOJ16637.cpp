//
// Created by 전형진 on 2020-03-01.
//
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <climits>


using namespace std;

vector<char> ar;
vector<int> num;

long long ans = LLONG_MIN;

long long cal(char op, long long n1, long long n2){
    if(op == '+')
        return n1+n2;
    else if(op == '-')
        return n1-n2;
    else
        return n1*n2;
}
void solve(long long result, int idx){
    if(idx >= ar.size()){
        if(ans < result)
            ans = result;
        return;
    }
    long long temp1 = cal(ar[idx],result,num[idx+1]);
    solve(temp1,idx+1);

    if(idx+1<ar.size()){
        long long temp2 = cal(ar[idx+1],num[idx+1],num[idx+2]);
        solve(cal(ar[idx],result,temp2),idx+2);
    }
}


int main(){
    int N;
    string str;
    scanf("%d",&N);
    cin>>str;
    for (int i = 0; i < str.length(); ++i) {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*'){
            ar.push_back(str[i]);
        }
        else{
            num.push_back(str[i] - '0');
        }
    }
    solve(num[0],0);
    cout<<ans<<endl;

}