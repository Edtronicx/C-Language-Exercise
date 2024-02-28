/* Write a function, persistence, that takes in 
a positive parameter num and returns its multiplicative 
persistence, which is the number of times you must multiply 
the digits in num until you reach a single digit.*/


#include <iostream>
using namespace std;

int u,t,h,th,values;
int count  = 1;

int eachdigit(int y){
  u = y%10;
  t = ((y%100) - u)/10;
  h = (y - (u+(t*10)))/100;
  return u,t,h;
  }

int multiplication(){
    if( h == 0){
      values = t * u;
    }
    else{
      values = h * t * u;
    }
    return values;
 }

int main(){
 // your code here
  int n;
  cin >> n;
  eachdigit(n);
 if(n < 10){
    cout << "0";
  }
  else{
    //cout << "values are: " << h << t << u << endl;
    multiplication();
    cout << "product : " << values << endl;
    while(values > 9){
      eachdigit(values);
      multiplication();
      cout << "product : " << values << endl;
      count++;
    }
    cout << count;
    }
    return 0;
    }


