//
//  main.cpp
//  BOJ
//
//  Created by 전형진 on 10/03/2019.
//  Copyright © 2019 전형진. All rights reserved.
//

#include <stdio.h>

int main() {
    // insert code here...
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int a;
    int b;
    int sum = 0;
    int date;
    
    scanf("%d %d",&a,&b);
    
    for(int i = 0 ; i < a-1 ; i++){
        sum+=month[i];
    }
    date = sum+b;
    if(date%7 == 0)
        printf("SUN");
    else if(date%7 == 1)
        printf("MON");
    else if(date%7 == 2)
        printf("TUE");
    else if(date%7 == 3)
        printf("WED");
    else if(date%7 == 4)
        printf("THU");
    else if(date%7 == 5)
        printf("FRI");
    else if(date%7 == 6)
        printf("SAT");
    
    return 0;
}
