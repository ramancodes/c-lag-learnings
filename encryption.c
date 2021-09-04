#include <stdio.h>
#include <conio.h>
#include <string.h>

void password(int c_pin, char *c_username)
{
    int i, k = 0, l = 2, cu, len;
    float cp;
    long int pass;
    len = strlen(c_username); // length of the username 
    char username[len];
    
    while (i == 0 || l == 0)
    {
        printf("Enter Username : ");
        scanf("%s", username); //username enter from user
        cu = strcmp(username, c_username);

        printf("Enter 4 Digit Pin : ");
        scanf("%d", &pass); //pin enter from user
        cp = (float)c_pin / pass;

        if (cp == 1.00 && cu == 0)
        {
            i = 0;
            break;
        }
        else
        {
            if (cp == 1.00 && cu == 0)
            {
                printf("Invalid pin! %d attempts left\n", l);
            }
            else if (cp == 1.00 && cu != 0)
            {
                printf("Invalid username! %d attempts left\n", l);
            }
            else
            {
                printf("Wrong Credentials! %d attempts left\n", l);
            }

            k++;
            l--;
            if (l < 0)
            {
                break;
            }
        }
    }

    if (k >= 2)
    {
        printf("You have Exceeded the limit. Please try again later\n\n");
    }
    else if (i == 0)
    {
        printf("\nWelcome! You entered the correct credentials\n");
        //code or function
    }
}

int main()
{
    int len;
    long int correct_pin; //correct pin 
    FILE *ptr;
    ptr = fopen("credentials.txt", "r");
    fscanf(ptr, "%d", &len);
    char correct_username[len]; //correct username
    fscanf(ptr, "%s", correct_username);
    fscanf(ptr, "%d", &correct_pin);
    fclose(ptr);

    //printf("Hint - Username = %s and pin = %d\n\n", correct_username, correct_pin); //hint

    password(correct_pin, correct_username);
    printf("\nCompleted\n\n");
    printf("Press any key to exit");
    getch();
    return 0;
}