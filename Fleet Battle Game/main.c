#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void gotocenter(void)
{
    int i;
    for(i=0;i<15;i++) printf("\n");
    for(i=0;i<50;i++) printf(" ");
}

void gotoundercenter(void)
{
    int i;
    for(i=0;i<50;i++) printf(" ");
}


void delay(clock_t a)
{
    clock_t start;
    start  = clock();
    while(clock()-start<a)
    {

    }
}


void animation(char *ch)
{
    int i;
    for(i=0;ch[i]!='\0';i++)
    {
        printf("%c",ch[i]);
        delay(100);
    }
}

void showmap(int map[4][4])
{
    int i,k;
    printf("   1 2 3 4\n");
    printf("  ---------\n");
    for(i=0;i<4;i++)
    {
        printf("%d| ",i+1);
        for(k=0;k<4;k++)
        {
            if(map[i][k]==2) printf("%s","O ");
            else if(map[i][k]==3) printf("%s","X ");
            else if(map[i][k]==0) printf("%s",". ");
            else if(map[i][k]==1) printf("%s",". ");
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    FILE *leadboard;
    char begin_sentence[25]="BATAILLE NAVALE";
    char username[50];
    char rules_ends[5];
    char *dif;
    int mode;
    int start;
    int difficulty;
    int comp_map[4][4];
    int user_map[4][4];
    int score[2]={0,0};
    int user_targets=0,comp_targets=0;
    int x,y;
    int i,k;
    int user_con_play,comp_con_play;
    int win;


    //choosing mode
    gotocenter();
    printf("CHOSE A MODE :\n");
    gotoundercenter();
    printf("1. DARK MODE \n");
    gotoundercenter();
    printf("2. LIGHT MODE");
    mode=getch();
    system("CLS");
    while (mode!=49 && mode!=50)
    {
        gotocenter();
        printf("INVALIDE OPTION !\n");
        gotoundercenter();
        printf("CHOSE A MODE :\n");
        gotoundercenter();
        printf("1.  DARK MODE\n");
        gotoundercenter();
        printf("2. LIGHT MODE");
        mode=getch();
        system("CLS");
    }
    
    if(mode==49) system("COLOR 0A");
    else system("COLOR 3F");
    system("CLS");

    //STARTING GAME AND RULES
    
    for(;;)
    {
        system("CLS");
        gotocenter();
        printf("1. PLAY\n");
        gotoundercenter();
        printf("2. RULES");
        start=getch();
        system("CLS");
        if(start==49) break;
        if(start==50)
        {
            printf("HELLO WARRIOR , Get ready for the war!\n");
            printf("1. You have to destroy your opponent's war ships before he destroys yours.\n");
            printf("2. The battlefield is of 4x4 grid size in which you place your ships\n");
            printf("3. You can place your ships by entering its coordinates , i.e where x is the row number and y is the column number\n");
            printf("4. You have a fleet of 5 battle ships\n");
            printf("5. After placing your ships, you can attack the enemy area. To attack a area, enter its x y coordinate (separated by a space)\n");
            printf("6. You have 3 difficulties (EASY , MEDIUM , HARD)\n");
            printf("	6.1 EASY , MEDIUM : Attack hit to the enemy ship is denoted by a 'O'\n");
            printf("			            Attack miss is denoted by a 'X'\n");
            printf("	6.2 HARD : Attack hit to the enemy ship is denoted by a 'O' and you get an extra turn\n");
            printf("		       Attack miss is denoted by a 'X' and your turn ends\n");
            printf("Press ENTER to continue!");
            gets(rules_ends);
        }
    }



    srand(time(0));
    

    for(i=0;i<15;i++) printf("\n");
    for(i=0;i<50;i++) printf(" ");

    //BEGIN SENTENCE
    animation(begin_sentence);
    delay(1500);
    system("CLS");

    //USERNAME SAVE !
    gotocenter();
    printf("ENTER YOUR USRNAME : ");
    gets(username);
    system("cls");


    //CHOOSING DIFFICULTY
    gotocenter();
    printf("CHOSE A DIFFICULTY : \n");
    gotoundercenter();
    printf("1. EASY\n");
    gotoundercenter();
    printf("2. MEDIUM\n");
    gotoundercenter();
    printf("3. HARD");
    difficulty=getch();
    while (difficulty!=49 && difficulty!=50 && difficulty!=51)
    {
        system("CLS");
        gotocenter();
        printf("INVALIDE OPTION !\n");
        gotoundercenter();
        printf("CHOSE A DIFFICULTY \n");
        gotoundercenter();
        printf("1. EASY\n");
        gotoundercenter();
        printf("2. MEDIUM\n");
        gotoundercenter();
        printf("3. HARD");
        difficulty=getch();
    }
    system("CLS");

    //REMPLISSAGE DE MAP PAR DES 0 (DEFAUT) !
    for(i=0;i<4;i++)
    {
        for(k=0;k<4;k++)
        {
            comp_map[i][k]=0;
        }
    }
    for(i=0;i<4;i++)
    {
        for(k=0;k<4;k++)
        {
            user_map[i][k]=0;
        }
    }
    //SETTING UP USER'S MAP SHIPS !
    for(i=0;i<5;i++)
    {
        printf("IT'S THE TIME TO PLACE YOUR SHIPS !\n");
        //X cord
        printf("ENTER THE X COORDINATE OF SHIP N %d : ",i+1);
        x=getch();
        system("cls");
        while (x>52 || x<=48)
        {
            printf("YOU MUST ENTER A COORDINATE BETWEEN [1,4] !\n");
            printf("ENTER THE X COORDINATE OF SHIP N %d : ",i+1);
            x=getch();
            system("cls");
        }

        //Y cord
        printf("ENTER THE Y COORDINATE OF SHIP N %d : ",i+1);
        y=getch();
        system("cls");
        while (y>52 || y<=48)
        {
            printf("YOU MUST ENTER A COORDINATE BETWEEN [1,4] !\n");
            printf("ENTER THE Y COORDINATE OF SHIP N %d : ",i+1);
            y=getch();
            system("cls");
        }
        //setting up X and Y cords
        while (user_map[y-49][x-49]==1)
        {
            printf("THIS POSITION IS ALREDY TAKEN !\n");
            printf("ENTER THE X COORDINATE OF SHIP N %d : ",i+1);
            x=getch();
            printf("ENTER THE Y COORDINATE OF SHIP N %d : ",i+1);
            y=getch();
            system("cls");
        }
        user_map[y-49][x-49]=1;
    }
    //SETTING UP COMPUTER'S MAP SHIPS !
    for(i=0;i<5;i++)
    {
        x=rand()%4;
        y=rand()%4;
        while (comp_map[y][x]==1)
        {
            x=rand()%4;
            y=rand()%4;
        }
        comp_map[y][x]=1;

    }

    //MAIN LOOP , DIFFICULTE : FACILE
    if(difficulty==49)
    {
        dif="EASY";
        while (1)
        {
            //USER TOUR !
            printf("%s YOUR TURN !\n",username);
            showmap(comp_map);
            printf("           Score\ncomputer | %d : %d | %s \n",score[1],score[0],username);
            printf("ENTER X AND Y (SEPARATED BY SPACE): ");
            scanf("%d %d",&x,&y);
            while (x>4 || x<=0 || y>4 || y<=0)
            {
                printf("YOU MUST ENTER A COORDINATE BETWEEN [1,4] !\n");
                printf("ENTER X AND Y (SEPARATED BY SPACE): ");
                scanf("%d %d",&x,&y);
            }
            if(comp_map[y-1][x-1]==1)
            {
                animation("HIT\n");
                user_targets++;
                comp_map[y-1][x-1]=2;
                score[0]++;
            }
            else if (comp_map[y-1][x-1]==0)
            {
                animation("MISS\n");
                comp_map[y-1][x-1]=3;
            }
            system("CLS");


            //COMPUTER TOUR !
            printf("COMPUTER TURN !\n");
            showmap(user_map);
            printf("           Score\ncomputer | %d : %d | %s \n",score[1],score[0],username);
            x=rand()%4;
            y=rand()%4;
            if(user_map[y][x]==1)
            {
                animation("HIT\n");
                comp_targets++;
                user_map[y][x]=2;
                score[1]++;
            }
            else if (user_map[y][x]==0)
            {
                animation("MISS\n");
                user_map[y][x]=3;
            }

            
            delay(2000);
            system("CLS");
            //CHECKING GAME END !
            if(user_targets==5 || comp_targets==5) break;

        }
    }
    

    //MAIN LOOP , DIFFICULTE : MOYENNE !
    else if(difficulty==50)
    {
        dif="MEDIUM";
         while (1)
        {
            //USER TOUR !
            printf("%s YOUR TURN !\n",username);
            showmap(comp_map);
            printf("           Score\ncomputer | %d : %d | %s \n",score[1],score[0],username);
            printf("ENTER X AND Y (SEPARATED BY SPACE): ");
            scanf("%d %d",&x,&y);
            while (x>4 || x<=0 || y>4 || y<=0)
            {
                printf("YOU MUST ENTER A COORDINATE BETWEEN [1,4] !\n");
                printf("ENTER X AND Y (SEPARATED BY SPACE): ");
                scanf("%d %d",&x,&y);
            }
            if(comp_map[y-1][x-1]==1)
            {
                animation("HIT\n");
                user_targets++;
                comp_map[y-1][x-1]=2;
                score[0]++;
            }
            else if (comp_map[y-1][x-1]==0)
            {
                animation("MISS\n");
                comp_map[y-1][x-1]=3;
            }
            system("CLS");


            //COMPUTER TOUR !
            printf("COMPUTER TURN !\n");
            showmap(user_map);
            printf("           Score\ncomputer | %d : %d | %s \n",score[1],score[0],username);
            x=rand()%4;
            y=rand()%4;
            while (user_map[y][x]==2 || user_map[y][x]==3)
            {
                x=rand()%4;
                y=rand()%4;
            }
            if(user_map[y][x]==1)
            {
                animation("HIT\n");
                comp_targets++;
                user_map[y][x]=2;
                score[1]++;
            }
            else if (user_map[y][x]==0)
            {
                animation("MISS\n");
                user_map[y][x]=3;
            }

            
            delay(1500);
            system("CLS");
            
            
            //CHECKING GAME END !
            if(user_targets==5 || comp_targets==5) break;

        }
    }


    //MAIN LOOP , DIFFICULTE : DIFFICILE
    else
        dif="HARD";
         while (1)
        {
            user_con_play=1;
            comp_con_play=1;
            //USER TOUR !
            while(user_con_play==1 && user_targets<5)
            {
                printf("%s YOUR TURN !\n",username);
                showmap(comp_map);
                printf("           Score\ncomputer | %d : %d | %s \n",score[1],score[0],username);
                printf("ENTER X AND Y (SEPARATED BY SPACE): ");
                scanf("%d %d",&x,&y);
                while (x>4 || x<=0 || y>4 || y<=0)
                {
                    printf("YOU MUST ENTER A COORDINATE BETWEEN [1,4] !\n");
                    printf("ENTER X AND Y (SEPARATED BY SPACE): ");
                    scanf("%d %d",&x,&y);
                }
                if(comp_map[y-1][x-1]==1)
                {
                    animation("HIT\n");
                    user_targets++;
                    comp_map[y-1][x-1]=2;
                    score[0]++;
                }
                else if (comp_map[y-1][x-1]==0)
                {
                    animation("MISS\n");
                    comp_map[y-1][x-1]=3;
                    user_con_play=0;
                }
                system("CLS");
            }


            //COMPUTER TOUR !
            while(comp_con_play==1 && comp_targets<5)
            {
                printf("COMPUTER TURN !\n");
                showmap(user_map);
                printf("           Score\ncomputer | %d : %d | %s \n",score[1],score[0],username);
                x=rand()%4;
                y=rand()%4;
                while (user_map[y][x]==2 || user_map[y][x]==3)
                {
                    x=rand()%4;
                    y=rand()%4;
                }
                if(user_map[y][x]==1)
                {
                    animation("HIT\n");
                    comp_targets++;
                    user_map[y][x]=2;
                    score[1]++;
                    if(comp_targets==5) break;
                }
                else if (user_map[y][x]==0)
                {
                    animation("MISS\n");
                    user_map[y][x]=3;
                    comp_con_play=0;
                }

                
                delay(2000);
                system("CLS");
            }
            
            
            //CHECKING GAME END !
            if(user_targets==5 || comp_targets==5) break;

        }
   


    //CHECKING THE WINNER !
    system("CLS");
    if(user_targets==5 && comp_targets==5)
    {
        animation("DRAW !");
        win=2;
        delay(4000);
    }
    else if(user_targets==5) 
    {
        animation("VICTORY");
        printf("\n");
        animation(username);
        animation(" YOU WON !");
        win=1;
        delay(4000);
    }
    else
    {
        animation("YOU LOST !");
        win=0;
        delay(4000);
    }
    leadboard = fopen("leadbord.txt","a");
    if(win==1) fprintf(leadboard,"USERNAME : %s  |  %d:%d  |  W  |  DIFFICULTY : %s\n\n",username,score[0],score[1],dif);
    else if(win==0) fprintf(leadboard,"USERNAME : %s  |  %d:%d  |  L  |  DIFFICULTY : %s\n\n",username,score[0],score[1],dif);
    else fprintf(leadboard,"USERNAME : %s  |  %d:%d  |  D  |  DIFFICULTY : %s\n\n",username,score[0],score[1],dif);
    fclose(leadboard);
    return 0;
}
