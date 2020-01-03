#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Sons1
{
    char structDate[200];
    int hour;
    int min;
    int sec;
    int freeSeats;
    char seats[6][6];
};
struct Auditorium1
{

    char movieName[100];
    struct Sons1 TodaySons[7];
};
void swap(struct Sons1 TodaySons[],int y,int x)
{
    struct Sons1 temp;
    temp = TodaySons[x];
    TodaySons[x] = TodaySons[y];
    TodaySons[y] = temp;
}
int func(struct Sons1 TodaySons[], int start, int end)
{
    srand(time(NULL));
    int point = start + (rand()%(end - start));
    swap(TodaySons,start,point);
    point = start + 1;
    for(int i = start + 1; i <= end; i++)
    {
        if(TodaySons[i].hour < TodaySons[i].hour)
        {
            swap(TodaySons, i, point);
            point++;
        }
        else if (TodaySons[i].hour == TodaySons[i].hour)
        {
            if(TodaySons[i].min < TodaySons[i].min)
            {
               swap(TodaySons, i, point);
               point++;
            }
            else if(TodaySons[i].min == TodaySons[i].min)
            {
                if(TodaySons[i].sec < TodaySons[i].sec)
                {
                    swap(TodaySons, i, point);
                    point++;
                }   
            }
        }
    }
    swap(TodaySons, start, (point-1));
    return (point - 1);
   
}
void quicksort(struct Sons1 TodaySons[], int start, int end)
{
    int point;
    if(start < end)
    {
        point = func(TodaySons,start,end);
        quicksort(TodaySons, start, point-1);
        quicksort(TodaySons, point + 1, end);
    }
}