#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    int len;
    long int pin;
    char username[20];

    printf("\t\tCreate or Change your Credentials Here\n\n");
    printf("\t\tEnter New Username(max 20 characters) : ");

    scanf("%s", username);
    len = strlen(username);
    printf("\t\tEnter new 4 digit Pin : ");
    scanf("%d", &pin);

    FILE *ptr;
    ptr = fopen("credentials.txt", "w");
    fprintf(ptr, "%d\n%s\n%d", len, username, pin);
    fclose(ptr);
    
    printf("\n\n\t\tYour Credentials have changed. Thank You!\n\n");
    printf("\t\tPress Any key to exit. ");
    
    getch();
    return 0;
}