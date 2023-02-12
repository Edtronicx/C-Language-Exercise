#include <stdio.h>

void addrecord();
void printing();
void auto_user(int);
void check_id(int);
int check_duplicate(int);

struct info {
	char employid[6]; 
	char firstname[20];
    char lastname[20];
    char username[20];
    char password[20];
    char dept[20];
    int age; 
};
struct info a[25];
int i;
int arr[25][2]; //[index][total]
char exit1;

int main(){
    addrecord();
    printing();


system("pause");


}

void addrecord(){
    char choice = 'y';
    while(choice == 'y'){
        for (i = 0; i < 25; i++){
            printf("*** Enter user information ***\n");
          //  printf("ID %d\n", i);
            printf("EmployeeID: ");
            scanf("%s", &a[i].employid);
            check_id(i);
            check_duplicate(i);
            //printf("Result %d\n", check_duplicate(i));  
            int again = check_duplicate(i);
            while(again == 1){
                printf("Enter again EmployeeID :");
                scanf("%s", &a[i].employid);
                check_id(i);
                again = check_duplicate(i);
            }
            
            printf("First Name: ");
            fflush(stdin);
            gets(a[i].firstname); 
            
           // scanf("%s", &a[i].firstname);
            printf("Last Name : ");
            fflush(stdin); 
            gets(a[i].lastname); 
            // scanf("%s", &a[i].lastname);
            auto_user(i);
            printf("Username  : %s \n",a[i].username);
            printf("Password  : ");
            fflush(stdin);
            scanf(" %s", &a[i].password);
            printf("Department: ");
            fflush(stdin);
            scanf(" %s", &a[i].dept);
            printf("Age       : ");
            fflush(stdin);
            scanf(" %d", &a[i].age);
            printf("\n");
            printf("\nEnter another? (y/n) ");
            fflush(stdin);
            scanf(" %c", &choice);  //careful in pressing ENTER
            printf("\n");
            printf("\n");
            printf("\n");
            if(choice != 'y'){
            break;  }
            
        }
    }   

}

void printing(){
    int temp1,temp2;
//sorting the ID number
    for(int j = 0; j <= i; j++){
        for(int k = j+1; k <= i; k++)

	        if(arr[j][1] > arr[k][1]){

                temp1 =  arr[k][1];
                arr[k][1] = arr[j][1];
                arr[j][1] = temp1;

                temp2 =  arr[k][0];
                arr[k][0] = arr[j][0];
                arr[j][0] = temp2;

	    }
    }


    printf("\n");
    printf("The following informmation were entered:\n");
    printf("-------------------------------------------------------------------------------------\n");
    int k;
    for(int l = 0 ; l <= i; l ++){

            k = arr[l][0];  //get index 
    
        printf("%d) %s : %s  %s : %s : %d : %s : %s\n",l+1, a[k].employid, a[k].firstname, a[k].lastname, a[k].dept, a[k].age, a[k].username, a[k].password);

    }
    printf("Total of %d information\n", i+1); 
    printf("\n");
    printf("*** End of Program ***");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("ThroNickxs\n");

}
    

int check_duplicate(int i){ 
     
//temporary storage for index and id number
    for (int j = 0; j <= i; j++)
    {
            int total = ((a[j].employid[0] -48)*10000) + ((a[j].employid[1]-48)*1000) + ((a[j].employid[2]-48)*100) + ((a[j].employid[3]-48)*10) + (a[j].employid[4]-48);
            arr[j][1] = total;
            arr[j][0] = j;
        
    }
//check if there is duplicate or same employid
    if(i == 0){
        return 0;
    }
    else{ 
        for(int j = 0; j < i; j++){
                    if(arr[i][1] == arr[j][1]){
                        return 1;

                    }
  
            }
            return 0;
        } 
} 

void check_id(int i){
    int mode = 0;

    while (mode == 0) {
        int  length = 0;
        while (a[i].employid[length] != '\0') {
                ++length;
            }

        if(length == 5){
            for (int j = 0; j < length; j++){
            char b = a[i].employid[j];
            if((b >= 48) && (b <= 57)){
                if(j == 4){
                    mode = 1;
                }
            }
            else {
     //           printf("Only digit\n");
                printf("Enter again EmployeeID: ");
                scanf("%s", &a[i].employid);    
            }
        }
        }
        else {
         //       printf("Size is EmployeeID: %d\n", length);
                printf("Enter again EmployeeID: ");
                scanf("%s", &a[i].employid);
        }  
    }
}

void auto_user(int i){

    char f_letter = a[i].firstname[0];
    //printf("f_letter %d\n", f_letter);
    ((f_letter >= 65) && (f_letter <= 90))?(f_letter = (a[i].firstname[0]) + 32): (f_letter);
        a[i].username[0] = f_letter;
        //printf("username first %d\n", f_letter);
       
    char modify_lastname[20]; //tempoary storage for lastname
    int  length = 0;
     while (a[i].lastname[length] != '\0') {   //length of lastname
            ++length;
        }

     modify_lastname[length + 1] = '\0';

    for(int j = 0; j <= length; j++ ){   //transfer lastname data to temp storage
        modify_lastname[j] = a[i].lastname[j];
        }  
     

      int k = 0;
    //Checks for whitespace in lastname and remove 
    for(int j = 0; modify_lastname[j] != '\000'; j++){  
        

        modify_lastname[j] = a[i].lastname[j+k];

        if((modify_lastname[j] == ' ')|| (modify_lastname[j] == '\t')){


            k++;
            j--;
        }
    } 
        int new_length = 0; //length of lastname after removing spaces
     while (modify_lastname[new_length] != '\0') {
            ++new_length;
        }

    for(int j = 0; j < new_length; j++ ){ //convert to lpwer case lastname
        ((modify_lastname[j] >= 65) && (modify_lastname[j] <= 90))?(modify_lastname[j] = modify_lastname[j] + 32): (modify_lastname[j]);
    } 

    for(int j = 1; j < new_length + 1; j++ ){ //add to username
        
        a[i].username[j] = modify_lastname[j-1];
    } 
}