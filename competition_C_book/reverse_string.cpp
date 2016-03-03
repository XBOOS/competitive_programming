#include<stdio.h>
#include<string.h>
#include<string>
//#include<stdlib.h>
#include<iostream>
using std::string;
int main(){


    string res = "";
    char num[20] = "12343529898789";
    int len = strlen(num);
    int i;
    for(i=0;i<len;i++){
        res = (char)(num[i]+'0')+res;
    }
    //printf("%s",res.c_str());
    std::cout<<res<<std::endl;
    return 0;
}
