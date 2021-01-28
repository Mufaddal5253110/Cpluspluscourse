#include <iostream>
using namespace std;

void getPrimeNumbers(int n)
/*
Algorithm: We start from 2, and on each encounter of a prime number, we mark
its multiples as composite.
Time Complexity: O(n log log n)
Space Complexity: O(n)

ExplanationDesi:
note : value zero means prime and 1 means not prime
1. pehle hum ek array define karenge jisme saari value ko zero kardenge.
2. Pure array me loop lagayenge and check karenge ke kya value zero he starting me to ye true
   hi honga but after first loop apan apn kuch values ko 1 kardenge
3. now suppose pehle aaya 2 to 2 ke saare multiples ko 1 karedenge and start karenge 2 se nahi
   2 ke square se i.e 4 because hamesha kya honga ke i ke squre ki pehli waali values ko apan 
   already check kar chuke he
4. ye chalenge n tak means jab tak i ka sqaure n se kam rahenga
5. and last hum phir loop lagayenge and print karedenge use indexes ko jisti value 0 hongi jo
   ki hamare n ke primes honge

*/
{

    int arr[100] = {0}; // initialing giving all position to 0(means prime)


    for (int i = 2; i <= n; i++) // loop from 2 to n
    {
        if (arr[i] == 0) // checking wheter we have marked it  as 1 (means not prime) or not
        {

            for (int j = i * i; j <= n; j += i) // loop from i square till and n and also checking i square is less than n or not
            {
                arr[j] = 1; // giving one means not prime
            }
        }
    }

    for (int i = 2; i <= n; i++) // loop through whole array
    {
        if (arr[i] == 0) // if prime means havng 0 then print
        {
            cout << i << " ";
        }
    }

}

void getPrimeFactors(int n){
/*
Explanation:
while( m ! = 1 ):

We keep on dividing it with its smallest prime factor.

The smallest prime factor is pre-calculated using a slightly modified prime sieve.
Since we start from 2 and go on, we mark the first multiple as the spf.

Preprocessing for Sieve: O(n log log n)
Time Complexity for factorization: O(log n)
Space Complexity: O(n)

Explanation desi:
1. Pehle hum ek array initialize karenge size equal to or greater than n
2. ha to phir ek hum loop lagaynge and saare indexes ko value dedenge equal to index
3. kk to ise hame karna kya he jese prime numbers me kiya tha wese loop lagana he sirf diff
   itna he ki i ke multiple ko  1 ki jagah i as a value dena he kyo ki agar wo i ke multiples he 
   to sabse smallest prime multiple un sabka i hi honga
4. aur isme for ke under for loop lagenga and dono for loop me pehle ye check karna he kya value
   at index equal to index he then proccedd karna he nai to humne koi factor already pradan kardiya 
   he
5. final ek while loop lagayenge jo hamare prime factors of n print karenga
6. usme hum n se chalu karenge and at position n prime factor print kardenge 
   and than n ko update kardenge as n divide by prime factor jo abhi apne ko mila 
   . aur kaha tak jaha tak n 1 nahi ho jata he
*/

    int arr[100]={0}; //initializing array

    for(int i=2;i<=n;i++){ // loop thorugh array and giving value same as index
        arr[i]=i;
    }

    for(int i=2;i<=n;i++){
        if(arr[i]==i){ // checking whether value of position =position then going forward else we have given the samallest prime factor of that number
            for(int j=i*i;j<=n;j+=i){
                if(arr[j]==j) // again checking for multiple of i whether we gave smallest prime or not
                arr[j]=i; // giving samllest prime i.e i to the multiple of i
            }
        }
    }
    cout<<endl;

    int m=n;
    while(m!=1){
        cout<<arr[m]<<" ";
        m=m/arr[m];
    }


}

int main()
{
    getPrimeNumbers(30);
    getPrimeFactors(30);
    return 0;
}

/*OUTPUT
PS E:\C++ course> cd "e:\C++ course\" ; if ($?) { g++ sieveOfEratosthenes.cpp -o sieveOfEratosthenes } ; if ($?) { .\sieveOfEratosthenes }
2 3 5 7 11 13 17 19 23 29 
2 3 5
*/