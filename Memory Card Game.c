#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
#define RESET   "\033[0m"
#define RED     "\033[1;31m" 
#define GREEN   "\033[1;32m" 
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m" 
#define MAGENTA "\033[1;35m" 
#define CYAN    "\033[1;36m" 
#define WHITE   "\033[1;37m" 
int menu();
int level_menu();
void shuffle(int voith[],int i);
int chose_cards(int cards[][N],int voith[], int a,int b,int c);
void output(int k,int cards[][N]); 
void game_cards(int a, int saw_cards[][N],int cards[][N]);
int read_card(int saw_cards[][N],int cards[][N],int *column,int a);
int main()
{
	int ep,i,j,k;
	int row,col,row2,col2;
	int zeugaria = 0,tries=0,lev=2;
	int cards[N][N],voith[N*N];
	int saw_cards[N][N] = {0};
	srand(time(NULL));
	chose_cards(cards,voith,8,16,4);
	ep = menu();
	while (ep != 4)
	{
		for (i=0;i<N;i++)
			for (j=0;j<N;j++)
				saw_cards[i][j] = 0;
		switch (ep)
		{
			case 1:
				//printf ("\n First <and last> display of the memo-cards' board <just for testing purpose>\n");
				zeugaria = 0;
				tries = 0;
				if (lev == 1)
				{
				// an thelw na fainontai oi airthmoi - output(2,cards); -
					while (zeugaria < 2)
					{
						game_cards(2,saw_cards,cards);
						row = read_card(saw_cards,cards,&col,1);
						game_cards(2,saw_cards,cards);
						row2 = read_card(saw_cards,cards,&col2,2);
						if (cards[row][col] == cards[row2][col2])
						{
							tries++;
							zeugaria++;
							game_cards(2,saw_cards,cards);
							printf ("Cards Matched\n\n");
						}
						else 
						{
							tries++;
							game_cards(2,saw_cards,cards);
							printf ("No Match\n\n");
							saw_cards[row][col] = 0;
							saw_cards[row2][col2] = 0;
						}
					}
					printf (GREEN"Congratulations!!! You won!!!\n");
				}
				else if (lev == 2)
				{
				// an thelw na fainontai oi airthmoi - output(4,cards); -
					while (zeugaria < 8)
					{
						game_cards(4,saw_cards,cards);
						row = read_card(saw_cards,cards,&col,1);
						game_cards(4,saw_cards,cards);
						row2 = read_card(saw_cards,cards,&col2,2);
						if (cards[row][col] == cards[row2][col2])
						{
							tries++;
							zeugaria++;
							game_cards(4,saw_cards,cards);
							printf ("Cards Matched\n\n");
						}
						else 
						{
							tries++;
							game_cards(4,saw_cards,cards);
							printf ("No Match\n\n");
							saw_cards[row][col] = 0;
							saw_cards[row2][col2] = 0;
						}
					}
					printf ("Congratulations!!! You won!!!\n");
				}
				else if (lev == 3)// .......
				{
				// an thelw na fainontai oi airthmoi - output(6,cards); -
					while (zeugaria < 18)
					{
						game_cards(6,saw_cards,cards);
						row = read_card(saw_cards,cards,&col,1);
						game_cards(6,saw_cards,cards);
						row2 = read_card(saw_cards,cards,&col2,2);
						if (cards[row][col] == cards[row2][col2])
						{
							tries++;
							zeugaria++;
							game_cards(6,saw_cards,cards);
							printf ("Cards Matched\n\n");
						}
						else 
						{
							tries++;
							game_cards(6,saw_cards,cards);
							printf ("No Match\n\n");
							saw_cards[row][col] = 0;
							saw_cards[row2][col2] = 0;
						}
					}
					printf ("Congratulations!!! You won!!!\n");
				}
				break;
			case 2: 
			{
				lev  = level_menu();
				switch (lev)
				{
					case 1:
						chose_cards(cards,voith,2,4,2);
						break;
					case 2: 
						chose_cards(cards,voith,8,16,4);
						break;
					case 3:
						chose_cards(cards,voith,18,36,6);
						break;
				}
				break;
			}
			case 3:
			{
				if (lev == 1)
					printf (MAGENTA"\n\n Level: Easy\n\n");
				else if (lev == 2)
					printf ("\n\n Level: Medium\n\n");
				else if (lev == 3)
					printf ("\n\n Level: Hard\n\n");
				printf ("CONGRATS!!! You've done it after %d tries!!\n",tries);
				break;
			}
		}
		ep = menu();
	}
	printf(RESET);
	return 0;
}
void output(int k,int cards[][N])
{
	int i,j;
	for (i=0;i<k;i++)
	{
		for (j=0;j<k;j++)
		{
			if (cards[i][j] >= 10)
				printf ("%d  ",cards[i][j]);
			else 
				printf ("%d   ",cards[i][j]);
		}
		printf ("\n");
	}
	printf ("\n\n");
}
int menu()
{
	int ep;
	printf (YELLOW"\nMEMORY GAME MENU\n");
	printf ("--------------------------------------------\n");
	printf ("1.Play   2.Level   3.Statistics   4.Exit\n");
	printf ("Enter choice: ");
	do 
	{
		scanf ("%d",&ep);
		if (ep < 1 || ep > 4)
			printf ("Wrong Number\n");
	}
	while (ep < 1 || ep > 4);
	return ep;
}
int level_menu()
{
	int lev;
	printf (RED"\nLEVEL MENU\n");
	printf ("--------------------------------------------------\n");	
	printf ("1.Easy <2x2>   2.Medium <4x4>   3.Hard <6x6>\n");
	printf ("Select Level: ");
	do
	{
		
		if (scanf ("%d",&lev) != 1 || lev < 1 || lev > 3)
		{
			printf ("Wrong Number\n");
			while (getchar() != '\n')
				lev = 0;
		}
	}
	while (lev < 1 || lev > 3);
}
int read_card(int saw_cards[][N],int cards[][N],int *column,int a)
{
	int row,col;
	if (a == 1)
		printf (WHITE"Please insert the first card row and column\n");
	else if (a == 2)
		printf (WHITE"Please insert the second card row and column\n");
	scanf("%d%d",&row,&col);
	row = row - 1;
	col = col - 1;
	printf ("Its value: %d\n\n",cards[row][col]);
	do
	{
		if (saw_cards[row][col] == 1)
		{
			printf ("This card is open\n");
			if (a == 1)
				printf ("Please insert the first card row and column\n");
			else if (a == 2)
				printf ("Please insert the second card row and column\n");
			scanf("%d%d",&row,&col);
			row = row - 1;
			col = col - 1;
			printf ("Its value: %d\n\n",cards[row][col]);
		}
		else 
		{
			saw_cards[row][col] = 1;
			break;
		}
	}
	while (saw_cards[row][col] == 0);
	*column = col;
	return row;
}
void shuffle(int voith[],int size)
{
	int i,j,temp;
	for (i=size-1;i>0;i--)
	{
		j = rand() % (i+1);
		temp = voith[i];
		voith[i] = voith[j];
		voith[j] = temp;
	}

	
}
int chose_cards(int cards[][N],int voith[], int a,int b,int c)
{
	int k=0,i,j;
	for (i=1;i<=a;i++)
	{
		voith[k++] = i;
		voith[k++] = i;
	}
	shuffle(voith,b);
	k=0;
	for (i=0;i<c;i++)
		for (j=0;j<c;j++)
		{
			cards[i][j] = voith[k];
			k++;
		}
}
void game_cards(int a,int saw_cards[][N],int cards[][N])
{
	int i,j,k;
	printf (CYAN"  ");
	for (i=0;i<a;i++)
		printf ("%6d ",i+1);
	printf ("\n   ---------------------------------------------\n");
	for (j=0;j<a;j++)
	{
		printf ("%d |",j+1);
		for (k=0;k<a;k++)
		{
			if (saw_cards[j][k] != 0)
				printf ("%6d ",cards[j][k]);
			else 
				printf ("%6c ", '*');
		}
		printf ("\n");
	}	
}
