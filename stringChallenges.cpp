#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

/*
convert whole string to either upercase or lower case---------------------------------------
*/
    
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
/*
-------------------------------------------------------------------------------------
*/


/*
form gretest number from string------------------------------------------------------
*/

    string str2="27189";
    sort(str2.begin(),str2.end(),greater<int>());
    cout<<endl<<str2;
/*
-------------------------------------------------------------------------------------
*/


/*
get gretest count charachter from string------------------------------------------------------
*/

    string str3="akahjlslhsjs";
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
    for(int i=0;i<str3.length();i++){
        arr[str3[i]-'a']++;
    }
    cout<<endl;
    int freq = *max_element(arr,arr+26);
    char charachter;
    for(int i=0;i<26;i++){
        if(arr[i]==freq){
            charachter = 'a'+i;
            break;
        }
    }
    cout<<"Charachter "<<charachter<<" occurs "<<freq<<" times.";
/*
-------------------------------------------------------------------------------------
*/





    return 0;
}