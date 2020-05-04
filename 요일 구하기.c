#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(sizeof(char)*3);
    
    char * which_day[7]={"THU","FRI","SAT","SUN","MON","TUE","WED"};
    int day_of_month[]={31,29,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    char fail[5]="FAIL";
    
    if(a>12||a<1){
        
        strcpy(answer,fail);
    }
    else{
        switch(a){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                   if(b<1||b>31){
                       strcpy(answer,fail);
                   }
                break;
            case 2:
                if(b<1||b>28){
                     strcpy(answer,fail);
                }break;
            case 4: case 6: case 9: case 11:
                if(b<1||b>30){
                    strcpy(answer,fail);
                }
                break;
        }
      
    }
    if(strcmp(answer,fail)){
    for(int i=0; i<a-1; i++){
        sum+=day_of_month[i];
    }
    sum+=b;
    sum=sum%7;
    
    strcpy(answer,which_day[sum]);
    
    }
    return answer;
}
