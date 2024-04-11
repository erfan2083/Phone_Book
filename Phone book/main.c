#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Informations{
    char firstName[100];
    char lastName[100];
    char phoneNumber[100];
};

void addContact(char f[], char l[], char n[]){
    system("cls");

    printf("Enter first name: ");
    scanf("%s", f);
    printf("Enter last name: ");
    scanf("%s", l);
    printf("Enter Phone number: ");
    scanf("%s", n);

    printf("\nContact successfully added !\n ");
    printf("\nPress any key to get back to menu");
    getch();
}


void searchContact(struct Informations p[], int c){
    system("cls");
    if(c == 0){
        printf("Please first add a user");
    }
    else{
    printf("Choose search type\n");
    printf("\n1.Search by first name   \n2.Search by last name   \n3.Search by phone number\n\n");
    char temp[100];
    int flag = 0;
    nullInitializer(temp);

switch(getch()){

    case '1':
    printf("Enter a first name to search: ");
    scanf("%s", temp);

    for(int i=0 ; i<c ; i++){
        if(strstr(temp, p[i].firstName) != NULL){
           flag = 1;
           printf("User found : \n\n");
           printf("First name = %s\n", p[i].firstName);
           printf("Last name = %s\n", p[i].lastName);
           printf("Phone number = %s\n", p[i].phoneNumber);
           }
    }
    if(flag == 0)
        printf("User not found");
    break;

    case '2':
    printf("Enter a last name to search: \n");
    scanf("%s", temp);

    for(int i=0 ; i<c ; i++){
        if(strstr(temp, p[i].lastName) != NULL){
           flag = 1;
           printf("User found : \n\n");
           printf("First name = %s\n", p[i].firstName);
           printf("Last name = %s\n", p[i].lastName);
           printf("Phone number = %s\n", p[i].phoneNumber);
           }
    }
    if(flag == 0)
        printf("User not found");
    break;


    case '3':
    printf("Enter a phone number to search: \n");
    scanf("%s", temp);

    for(int i=0 ; i<c ; i++){
        if(strstr(temp, p[i].phoneNumber) != NULL){
           flag = 1;
           printf("User found : \n\n");
           printf("First name = %s\n", p[i].firstName);
           printf("Last name = %s\n", p[i].lastName);
           printf("Phone number = %s\n", p[i].phoneNumber);
           }
    }
    if(flag == 0)
        printf("\nUser not found !!!");
    break;

  }
 }
 printf("\n\nPress any key to get back to menu");
    getch();

}


void deleteContact(struct Informations p[], int *c){
    system("cls");

    if(*c == 0){
        printf("Please first add a user");
    }
    else{
    char temp[100];
    nullInitializer(temp);

    printf("Enter a first name to delete: ");
    scanf("%s", temp);

    int flag = 0;
    for(int i=0 ; i<*c ; i++){
        if(strstr(temp, p[i].firstName) != NULL){
           flag = 1;
           for(i ; i<*c ; i++){
                p[i] = p[i + 1];
           }
           *c--;
           printf("\nUser successfully deleted");
        }
    }
    if(flag == 0)
        printf("\nUser not exist!!!");
  }

  printf("\n\nPress any key to get back to menu");
    getch();
}


void listContact(struct Informations p[], int c){
    system("cls");

    if(c == 0){
        printf("Please first add a user");
    }
    else{
    for(int i=0 ; i<c ; i++){
        printf("%d_\n\n", i+1);
        printf("First name = %s\n", p[i].firstName);
        printf("Last name = %s\n", p[i].lastName);
        printf("Phone number = %s\n\n", p[i].phoneNumber);
     }
    }

    printf("\n\nPress any key to get back to menu");
    getch();
}


void nullInitializer(char a[]){
    for(int i=0; i<100; i++){
        a[i] = '\0';
    }
}


int main()
{
    struct Informations persons[20];

    for(int i=0 ; i<20 ; i++){
        nullInitializer(persons[i].firstName);
        nullInitializer(persons[i].lastName);
        nullInitializer(persons[i].phoneNumber);
    }
    int userCount = 0;

  mainhome:
  system("cls");

  printf("**********WELCOME TO PHONEBOOK*************");

printf("\n\n\t\t MENU\t\t\n\n");
printf("\t1.Add contact   \n\t2.delete contact   \n\t3.Search contact  \n\t4.Contact list\n");

switch(getch()){

    case '1':
    addContact(persons[userCount].firstName, persons[userCount].lastName, persons[userCount].phoneNumber);
    userCount++;
    goto mainhome;

    case '2':
    deleteContact(persons, &userCount);
    goto mainhome;

    case '3':
    searchContact(persons, userCount);
    goto mainhome;

    case '4':
    listContact(persons, userCount);
    goto mainhome;

    default:
    goto mainhome;
  }
}
