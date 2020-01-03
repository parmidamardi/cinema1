#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
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
struct Sons
{

};
struct Auditorium
{
    char seats[6][6];
    char movieName[100];
    struct Sons TodaySons[7];
};
int main()
{
    char time[200];
    char today[100];
    date(time);
    todayDate(time,today);
    //printf("%s",today);
}