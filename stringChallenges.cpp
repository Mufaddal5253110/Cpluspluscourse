/*
convert whole string to either upercase or lower case
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    
    string str="mufaDdal";
    string str1="MUfADdAL";

    // // to convert whole string in upper case letters (Manually)
    // for(int i=0;i<str.length();i++){
    //     if(str[i]>='a' && str[i]<='z'){
    //         str[i]-=32;
    //     }
    //     cout<<str[i];
    // }

    // to convert whole string in upper case letters (with inbuild func)
    transform(str.begin(),str.end(),str.begin(),::toupper);
    cout<<endl<<str;

    cout<<endl;

    // // to convert whole string in lower case letters (Manually)
    // for(int i=0;i<str1.length();i++){
    //     if(str1[i]>='A' && str1[i]<='Z'){
    //         str1[i]+=32;
    //     }
    //     cout<<str1[i];
    // }

    // to convert whole string in lower case letters (with inbuild func)
    transform(str1.begin(),str1.end(),str1.begin(),::tolower);
    cout<<endl<<str1;

    return 0;
}