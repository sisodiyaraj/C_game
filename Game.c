#include<stdio.h>
#include<stdlib.h>
int cash=100;
void play(int bet)
{
    char c[]={'Q','K','J'};
    printf("suffling....\n");
    srand(time(NULL));
    int i; 
    for(i=0;i<5;i++)
    {
        int x=rand()%3;
        int y=rand()%3;
        int temp =c[x];
        c[x]=c[y];
        c[y]=temp;
    }
    int playerGuess;
    printf("What is the position of queen -> 1 , 2 or 3 : \n");
    scanf("%d",&playerGuess);
    if(c[playerGuess-1]=='Q')
    {
        cash+=3*bet;
        printf("Hurrray... You won ! result = %c %c %c   \n total cash =%d \n",c[0],c[1],c[2],cash);
    }
    else
    {
        cash=cash-bet;
        printf("ooops... You loose ! result = %c %c %c   \n total cash =%d \n",c[0],c[1],c[2],cash);

    }
    
}

void main()
{
    char ch;
    int bet;
    printf("**********************************************************************\n");
    printf("Note:- \tstarting balance=100\ttotal card=3(K,Q,J)\n***if you win, you will get 3 times of bet amaount\n");

    do{
        printf("Whats your bet?\n");
        scanf("%d",&bet);
        if(cash>=bet || cash !=0)
        {
            play(bet);
        }
        else
        {
            printf("oops ! looks like you have insufficient balance\n");
            break;           
        }
        printf(" Wanna play again??? (Y/N)\n");
        getchar();
        scanf("%c",&ch);
        printf("**********************************************************************\n");

    } while(ch == 'Y' || ch == 'y');
    
    getchar();
}