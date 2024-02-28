/* Write a function that accepts an array of 10 integers 
(between 0 and 9), that returns a string of those numbers 
in the form of a phone number.


createPhoneNumber(int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}) // => returns "(123) 456-7890"

*/
#include <iostream>
#include <string>
using namespace std;

string str;

string createPhoneNumber(const int arr [10]){
  //your code here

      string str = "(";
    for (int i = 0; i < 3; i++) {

        str += to_string(arr[i]);
    }
         str +=  ") ";

    for (int i = 3; i <6 ; i++) {

        str += to_string(arr[i]);
    }
        str +=  "-";
    for (int i = 6; i <10 ; i++) {

        str += to_string(arr[i]);
    }

 
    cout << str;
 
    return str;
  
}

int main(){
    const int contact[] = {9,2,3,3,4,8,9,5,3,2};
    createPhoneNumber(contact);
    
    
}