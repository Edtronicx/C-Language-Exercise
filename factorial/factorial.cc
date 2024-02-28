#include <stdio.h>


int array[] = {8,5,2,3,4};
int temp;
int main(){

for ( int x = 0; x < 5; x ++ ){
    for ( int y = 0; y <5; y++ ){
  if ( array[x] > array[y] ){
                    temp =  array[x];
                    array[x] = array[y];
                    array[y] = temp;
  }
}

}
        for (int i = 0; i < 5; ++i)
            printf("%d\n", array[i]);


}

    




