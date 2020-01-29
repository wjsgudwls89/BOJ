//
// Created by 전형진 on 2020-01-29.
//
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int n,m;
string str[1001];

int table[51][4];

int main(){
    scanf("%d %d",&n,&m);

    for (int i = 0; i < n; ++i)
        cin>>str[i];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(str[j][i] == 'A'){table[i][0]++;}
            if(str[j][i] == 'C'){table[i][1]++;}
            if(str[j][i] == 'G'){table[i][2]++;}
            if(str[j][i] == 'T'){table[i][3]++;}
       }
    }
    string ans;
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int max = -1;
        int maxidx =0;
        for (int j = 0; j < 4; ++j) {
            if(table[i][j] > max){
                max = table[i][j];
                maxidx = j;
            }
            sum+=table[i][j];
        }
        sum -= table[i][maxidx];
        if(maxidx == 0){ans+='A';}
        else if(maxidx == 1){ans+='C';}
        else if(maxidx == 2){ans+='G';}
        else if(maxidx == 3){ans+='T';}
    }
    cout<<ans<<endl;
    printf("%d",sum);
}