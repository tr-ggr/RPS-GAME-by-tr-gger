#include<stdio.h>
#include <stdlib.h>
#include<time.h>

enum choice
{
    S = 1, R, P
} user;


int main()
{
    FILE * file = fopen("Highscores.txt", "a+");

    if(file == NULL)
    {
        file = fopen("Highscores.txt", "a");
    }

    int HS;
    
    if(fscanf(file, "%d", &HS) <= 0)
    {
        fprintf(file, "0");
        HS = 0;
    }

    int score = 1, i = 0; 
    printf("    +~+ RPS GAME by tr-gger +~+\n\n");
    printf("\t  Highscore: %d", HS);

    time_t t;
    srand((unsigned)time(&t));

    while(1)
    {
        
        user;
        int cpu = rand() % 3 + 1;
        printf("\n\n\t  round %d:\n", i + 1);
        printf("\n[1] Scissor\n");
        printf("[2] Rock\n");
        printf("[3] Paper\n");
        printf("\nInput: ");
        scanf("%d", &user);

        printf("CPU: %d\n", cpu);

        if(user == P && cpu == R)
        {
            i++;
            printf("\nYou won!\nscore: %d", i);
        }
        else if(user == S && cpu == P)
        {
            i++;
            printf("\nYou won!\nscore: %d", i);
        }
        else if(user == R && cpu == S)
        {
            i++;
            printf("\nYou won!\nscore: %d", i);
        }

        else if(user == S && cpu == R)
        {
            printf("\nYou lose!\nscore: %d", i);
            break;
        }
        else if(user == R && cpu == P)
        {
            printf("\nYou lose!\nscore: %d", i);
            break;
        }
        else if(user == P && cpu == S)
        {
            printf("\nYou lose!\nscore: %d", i);
            break;
        }
        else
        {
            printf("BRUH");
        }
        
    }

    fclose(file);

    printf("\n\nOVERALL SCORE: %d", i);

    int input;

    printf("\n\nSave high scores?\n[1] = yes\n[2] = no\n\nInput: ");
    scanf("%d", &input);

    if(input == 1)
    {

    file = fopen("Highscores.txt", "r");
    int cHS;
    fscanf(file ,"%d", &cHS);

    if(cHS > i)
    {
        fclose(file);
        return 0;
    }
    fclose(file);

    file = fopen("Highscores.txt", "w");
    
    fprintf(file, "%d", i);
    fclose(file);
    }
    else
    {
        return 0;
    }

    
}