#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
std::string printBinary(string n){

    size_t pos = n.find('.');
    int intPart;
    double decPart;
    if(pos!=std::string::npos){
        sscanf(n.substr(0,pos).c_str(),"%d",&intPart);
        sscanf(n.substr(pos).c_str(),"%lf",&decPart);
    }else{
        printf("Error in the input.No decimal point");
        return 0;
    }

    string int_string = "";
    stringstream tmp;
    while (intPart>0){
        tmp<<(intPart%2);
        int_string.insert(0,tmp.str());
        intPart>>=1;
    }
    ostringstream ss;
    while(decPart>0){
        if(ss.str().length()>32) return "ERROR";
        if(decPart==1){
            ss<<"1";
            break;
        }
        double r = decPart*2;
        if(r>=1){
            ss<<"1";
            decPart = r-1;
        }else{
            ss<<"0";
            decPart = r;
        }



    }

    return int_string+"."+ss.str();

}

int main(){

    string s = "1.732";
    string res = printBinary(s);
    cout << res;

    return 0;
}


