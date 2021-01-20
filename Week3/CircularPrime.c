#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

//Function to check a number is prime or not
bool isPrime(int n)
{
   //Smallest prime is 2
   //Even number >2, not a prime
   if ( n > 2 && n%2 == 0 ) 
       return false;
   //Check prime for each odd number>=3
   //If a number is divisible by any odd number not a prime
   for(int i = 3; i*i <= n ; i+=2)
   {
       if(n % i == 0)
           return false;
   }
   return true;
}

//Function to check if the number is circular prime 
bool isCircularPrime(int n)
{
    //For counting no of digits of a number
     int cnt = 0, tmp = n;
     //For positive number,digit is counted
    while (tmp>0) 
    {
        cnt++;
        tmp /= 10;
    }

    int num = n;
    while(isPrime(num))
    {
        //Generate circular permuation of a number
        //Last digit is moved to 1st digit
        int rem = num % 10; 
        int div = num / 10; 
        num = (pow(10, cnt - 1)) * rem + div;
        //If original number is obtained for the circular permutation
        //That number has circular prime
        if(num==n)
            return true;
    }
return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    if(n<=0)
    {
        printf("-1\n");
        return 0;
    }
    else 
    {
        if(isCircularPrime(n))
            printf("1\n");
        else
            printf("0\n");
    }
    
return 0;
}
