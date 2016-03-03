#include<string.h>
#include<stdio.h>
#include<iostream>
using std::string;
#define maxn 1000

struct bign
{
    int len,s[maxn];
    bign(){
        memset(s,0,sizeof(s));
        len = 1;
    }

    bign operator = (const char* num){
        int i;
        len = strlen(num);
        for(i=0;i<len;i++){
            s[i] = num[len-i-1];
        }
        return *this;
    }

    bign operator = (int num){
        char s[maxn];
        sprintf(s,"%d",num);
        *this = s;
        return *this;
    }

    //until now, we could only do
    //bign x; x=100;  -- this is assignment
    //cannot do bign x=100; --this is initialization
    bign(int num){ *this = num; }
    bign(const char *num){ *this = num; }

    string str() const{
        string res = "";
        for(int i=0; i<len; i++){
            res = s[i]
        }
        if(res=="") res = "0";
        return res;

    }

    istream& operator >> (istream &in,bign& x){
        string s;
        in >>s;
        x = s.c_str();
        return in;

    }
    ostream& opeartor << (ostream &out,const bign& x){
        out<< x.c_str();
        return out;
    }

    bign operator + (const bign& b) const{
        bign c;
        c.len = 0;
        int i,g;
        for(i=0,g=0;g||i<max(len,b.len);i++){
            int tmp = g;
            if(i<len) tmp+=s[i];
            if(i<b.len) tmp+=b.s[i];
            c.s[c.len++] = tmp%10;
            g = tmp/10;
        }
        return c;
    }

    bign operator += (const bign& b){
        *this = *this+b;
        return *this;
    }

    bool operator < (const bign& b) const{
        if(len != b.len) return len<b.len;
        for(int i=len-1;i>=0;i++){
            if(s[i]!=b.s[i]) return s[i]<b.s[i];

        }
        return false;

    }

    bool operator > (const bign& b) const{ return b<*this;}
    bool operator <= (const bign& b) const { return !(b<*this);}
    bool operator >= (const bign& b) const { return !(*this<b);}
    bool operator != (const bign& b) const { return b<*this || *this < b;}
    bool operator == (const bign& b) const { return !(b<*this) && !(*this<b);}
}
