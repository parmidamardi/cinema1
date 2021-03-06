#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "quicksort.h"
void date(char time2[])
{
    time_t current_time;
    char* c_time_string;

    /* Obtain current time. */
    current_time = time(NULL);

    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Print to stdout. ctime() has already added a terminating newline character. */
    strcpy(time2,c_time_string);
    // exit(EXIT_SUCCESS);
    
}
void todayDate(char time[],char today[])
{
    int cnt = 0;
    int i;
    for(i = 0;cnt < 3;i++)
    {
        today[i] = time[i];
        if(time[i] == ' ')
        {
            cnt++;
        }
    }
    today[i] = '\0';
}
void clockTime(char time[],int *hour, int *min, int *sec)
{
   int cnt = 0;
   for(int i = 0;cnt < 4;i++)
   {
      if(time[i] == ' ')
      {
          cnt++;
      }
      if(cnt == 3)
      {
          *hour = (time[i+1]-'0')*10 + (time[i+2]-'0');
          *min = (time[i+4]-'0')*10 + (time[i+5]-'0');
          *sec = (time[i+7]-'0')*10 + (time[i+8]-'0');
          break;
      }
   }
}
struct Sons
{
    char structDate[200];
    int hour;
    int min;
    int sec;
    int freeSeats;
    char seats[6][6];
};
struct Auditorium
{
    char movieName[100];
    struct Sons TodaySons[7];
};
struct Movie
{
    char movieName[200];
    int movieTime;
    char summary[10000];
    char movieJenre[100];
};
struct Movie movieFill(struct Movie M,int num)
{
    if(num == 0)
    {
        strcpy(M.movieName,"The Green Mile");
        M.movieTime = 2;
        strcpy(M.summary,"Paul Edgecomb, the head guard of a prison, meets an\n inmate, John Coffey, a black man who is accused of\n murdering two girls. His life changes drastically when\n he discovers that John has a special gift.");
        strcpy(M.movieJenre,"crime drama");
    }
    else if(num == 1)
    {
        strcpy(M.movieName,"The prestige");
        M.movieTime = 3;
        strcpy(M.summary,"Two friends and fellow magicians become bitter\n enemies after a sudden tragedy. As they devote\n themselves to this rivalry, they make sacrifices that\n bring them fame but with terrible consequences.");
        strcpy(M.movieJenre,"psychological thriller");
    }
    else if(num == 2)
    {
        strcpy(M.movieName,"shutter island");
        M.movieTime = 2;
        strcpy(M.summary,"Teddy Daniels and Chuck Aule, two US marshals, are\n sent to an asylum on a remote island in order to\n investigate the disappearance of a patient, where\n Teddy uncovers a shocking truth about the place.");
        strcpy(M.movieJenre,"neo-noir psychological thriller");
    }
    return M;
}
void auditoriumFill(struct Auditorium *Salon)
{
    char time[200];
    char today[100];
    int hour,min,sec;
    date(time);
    todayDate(time,today);
    clockTime(time,&hour,&min,&sec);
    for(int k = 0;k < 7;k++)
    {
        for(int i = 0;i < 6;i++)
        {
            for(int j = 0;j < 6;j++)
            {
                Salon[0].TodaySons[k].seats[i][j] = '*';
                Salon[1].TodaySons[k].seats[i][j] = '*';
                Salon[2].TodaySons[k].seats[i][j] = '*';
            }
        }
    }
    strcpy(Salon[0].movieName,"The Green Mile");
    strcpy(Salon[1].movieName,"The prestige");
    strcpy(Salon[2].movieName,"shutter island");
    for(int i = 0;i < 7;i++)
    {

        strcpy(Salon[0].TodaySons[i].structDate,today);
        strcpy(Salon[1].TodaySons[i].structDate,today);
        strcpy(Salon[2].TodaySons[i].structDate,today);
        if(i < 3)
        {
            Salon[0].TodaySons[i].hour = 10 + (i*2);
            Salon[1].TodaySons[i].hour = 10 + (i*3);
            Salon[2].TodaySons[i].hour = 10 + (i*2);
        }
        else
        {
            Salon[0].TodaySons[i].hour = -1;
            Salon[1].TodaySons[i].hour = -1;
            Salon[2].TodaySons[i].hour = -1;            
        }
        Salon[0].TodaySons[i].min = 0;
        Salon[1].TodaySons[i].min = 0;
        Salon[2].TodaySons[i].min = 0;
        Salon[0].TodaySons[i].sec = 0;
        Salon[1].TodaySons[i].sec = 0;
        Salon[2].TodaySons[i].sec = 0;
        Salon[0].TodaySons[i].freeSeats = 36;
        Salon[1].TodaySons[i].freeSeats = 36;
        Salon[2].TodaySons[i].freeSeats = 36; 
    }
}
void salonPrint(struct Auditorium *Salon,struct Movie *M,int numSalon)
{
    char time[200];
    char today[100];
    int hour,min,sec;
    date(time);
    todayDate(time,today);
    clockTime(time,&hour,&min,&sec);
    for(int i = 0; i < 7;i++)
    {
        if(Salon[numSalon-1].TodaySons[i].hour != -1 )//&& Salon[numSalon-1].TodaySons[i].hour > hour)
        {
            printf("\n\n<<<<<<<<<parde namayesh>>>>>>>>>\n");
            for(int j = 0;j < 6;j++)
            {
                printf("\t");
                for(int k = 0;k < 6;k++)
                {
                    printf("%c  ",Salon[numSalon-1].TodaySons[i].seats[j][k]);
                }
                printf("\n");
            }
            printf("%s\n",Salon[numSalon-1].TodaySons[i].structDate);
            printf("saat: %d : %d : %d\n",Salon[numSalon-1].TodaySons[i].hour,Salon[numSalon-1].TodaySons[i].min,Salon[numSalon-1].TodaySons[i].sec);
            printf("Movie :%s\n",M[numSalon-1].movieName);
            printf("zamane film : %d hours\n",M[numSalon-1].movieTime);
            printf("kholase :%s\n",M[numSalon-1].summary);
            printf("jenre: :%s\n",M[numSalon-1].movieJenre);  
        }
    }
}
int sonsCheck(struct Sons AddedSons,struct Auditorium Salon)
{
    for(int i = 0;i < 7; i++)
    {
        if(AddedSons.hour > Salon.TodaySons[i].hour && AddedSons.hour < Salon.TodaySons[i].hour)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    struct Movie M[3];
    struct Auditorium Salon[3];
    struct Sons AddedSons;
    char time[200];
    char today[100];
    int hour,min,sec;
    int trueOrFalse;
    int sonsCounter = 3;
    date(time);
    todayDate(time,today);
    clockTime(time,&hour,&min,&sec);
    strcpy(AddedSons.structDate,time);
    auditoriumFill(Salon);
    M[0] = movieFill(M[0],0);
    M[1] = movieFill(M[1],1);
    M[2] = movieFill(M[2],2);
    int state;
    printf("1.Ezafe kardan sons\n2.kharide bilit\nshomare mored nazar: ");
    scanf("%d",&state);
    while(state != 1 && state != 2)
    {
        printf("shomare vared shode eshtebah ast\nshomare mored nazar:");
        scanf("%d",&state);
    } 
    while(state != 3)
    {
        if(state == 1)
        {
            int numSalon;
            printf("1.salon 1  movie: The Green Mile\n");
            printf("2.salon 2  movie: The prestige\n");
            printf("3.salon 3  movie: shutter island\n");
            printf("salone mored nazar: ");
            scanf("%d",&numSalon);
            while(numSalon != 1 && numSalon != 2 && numSalon != 3)
            {
                printf("shomare vared shode eshtebah ast\nshomare mored nazar:");
                scanf("%d",&numSalon);
            }         
            quicksort(Salon[numSalon-1].TodaySons,0,6);
            salonPrint(Salon,M,numSalon);
            printf("sons khod ra ezafe konid:\ndate: %s\n",AddedSons.structDate);
            printf("hour: ");
            scanf("%d",&AddedSons.hour);
            printf("min: ");
            scanf("%d",&AddedSons.min);
            printf("sec: ");
            scanf("%d",&AddedSons.sec);
            trueOrFalse = sonsCheck(AddedSons,Salon[numSalon-1]);
            while(trueOrFalse == 0)
            {
                printf("sons ha tadakhod darand. sons jadid vared konid:\ndate: %s\n",AddedSons.structDate);
                printf("hour: ");
                scanf("%d",&AddedSons.hour);
                printf("min: ");
                scanf("%d",&AddedSons.min);
                printf("sec: ");
                scanf("%d",&AddedSons.sec);
                trueOrFalse = sonsCheck(AddedSons,Salon[numSalon-1]);
            }
            for(int i = 0; i < 7; i++)
            {
                if(Salon[numSalon-1].TodaySons[i].hour == -1)
                {
                    Salon[numSalon-1].TodaySons[i].hour = AddedSons.hour;
                    Salon[numSalon-1].TodaySons[i].min = AddedSons.min;
                    Salon[numSalon-1].TodaySons[i].sec = AddedSons.sec;
                    sonsCounter++;
                    break;
                }
            }
            printf("1.Ezafe kardan sons\n2.kharide bilit\n3.payan\nshomare mored nazar: ");
            scanf("%d",&state);
            while(state != 1 && state != 2 && state != 3)
            {
                printf("shomare vared shode eshtebah ast\nshomare mored nazar:");
                scanf("%d",&state);
            }
            if(state == 1)
            {
                if(sonsCounter >= 7)
                {
                    printf("sons ha por ast\n");    
                    printf("2.kharide bilit\n3.payan\nshomare mored nazar: ");
                    scanf("%d",&state);
                    while(state != 2 && state != 3)
                    {
                        printf("shomare vared shode eshtebah ast\nshomare mored nazar:");
                        scanf("%d",&state);
                    }

                }
            }

        }
        else
        {
    
        }
    }
}