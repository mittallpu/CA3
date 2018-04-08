# CA3
#include<stdio.h>
#include<math.h>

void fcfs(int noq, int qu[10], int st)
{
 int i,s=0;
 for(i=0;i<noq;i++)
 {
  s=s+abs(st-qu[i]);
  st=qu[i];
  }
 printf("\n Total seek time :%d",s);
}
void sstf(int noq, int qu[10], int st, int visit[10])
{
 int min,s=0,p,i;
 while(1)
{
  min=999;
  for(i=0;i<noq;i++)
   if (visit[i] == 0)
    {
      if(min > abs(st - qu[i]))
       {
        min = abs(st-qu[i]);
        p = i;
        }
      }
 if(min == 999)
  break;
  visit[p]=1;
  s=s + min;
  st = qu[p];
  }
 printf("\n Total seek time is: %d",s);
 }
