#include <iostream>
using namespace std;

/* List down the two numbers that once added will equal to P2 */
int main(){
    int P1[] = {1,2,3,4,5,7,8,9,10,11,12};
    int P2 = 8;

    int i;
    int j;

   for(i = 0; i < sizeof(P1)/sizeof(P1[0]); i++){
    for(j = (sizeof(P1)/sizeof(P1[0])) - 1; j >= 0; j--){
        int sum = P1[i] + P1[j]; 
        if(sum == P2){
            cout << "(" << P1[i] << "," << P1[j] << ")" << endl;
            }
        }
    }
}