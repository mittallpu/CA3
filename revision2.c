#include<stdio.h>
int main()
{
int ts,spid[10],sneed[10],swt[10],stat[10],i,j,sn,sn1,fpid[10],fneed[10],fwt[10],ftat[10],fn,fn1;
int sbt[10],sflag[10],sttat=0,stwt=0,fbt[10],fflag[10],fttat=0,ftwt=0;
float sawt,satat,fawt,fatat,tt;
printf("\t\t \n");
printf("Enter the number of student queries ");
scanf("%d",&sn);
sn1=sn;
for(i=1;i<=sn;i++)
{
 printf("\n Enter the %d student query ID ",i);
 scanf("%d",&spid[i]);
 printf("\n Enter the Burst Time for the query ");
 scanf("%d",&sbt[i]);
 sneed[i]=sbt[i];
}
printf("\n Enter the number of faculty queries ");
scanf("%d",&fn);
fn1=fn;
for(i=1;i<=fn;i++)
{
 printf("\n Enter the %d faculty query ID ",i);
 scanf("%d",&fpid[i]);
 printf("\n Enter the Burst Time for the query ");
 scanf("%d",&fbt[i]);
 fneed[i]=fbt[i];
}
printf("\n Enter the Timeslice ");
scanf("%d",&ts);
for(i=1;i<=sn;i++)
{
 sflag[i]=1;
 swt[i]=0;
}
while(sn!=0)
{
 for(i=1;i<=sn;i++)
 {
 if(sneed[i]>=ts)
 {
 for(j=1;j<=sn;j++)
 {
 if((i!=j)&&(sflag[i]==1)&&(sneed[j]!=0))
 swt[j]+=ts;
 }
 
 sneed[i]-=ts;
 if(sneed[i]==0)
 {
sflag[i]=0;
sn--;
 }
 }
 else
 {
 for(j=1;j<=sn;j++)
 {
 if((i!=j)&&(sflag[i]==1)&&(sneed[j]!=0))
 swt[j]+=sneed[i];
 }
 sneed[i]=0;
 sn--;
 sflag[i]=0;
 }
}
}
for(i=1;i<=sn1;i++)
{
 stat[i]=swt[i]+sbt[i];
 stwt=stwt+swt[i];
 sttat=sttat+stat[i];
}
satat=sttat/sn1;
printf("-----------------------------------------STUDENT QUERIES --------------------------------------------------- \n");
printf("\n\n query \t query ID \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
for(i=1;i<=sn1;i++)
{
 printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", i,spid[i],sbt[i],swt[i],stat[i]);
}
printf(" \n ");

for(i=1;i<=fn;i++)
{
 fflag[i]=1;
 fwt[i]=0;
}
while(fn!=0)
{
 for(i=1;i<=fn;i++)
 {
 if(fneed[i]>=ts)
 {
 for(j=1;j<=fn;j++)
 {
 if((i!=j)&&(fflag[i]==1)&&(fneed[j]!=0))
 fwt[j]+=ts;
 }
 
 fneed[i]-=ts;
 if(fneed[i]==0)
 {
fflag[i]=0;
fn--;
 }
 }
 else
 {
 for(j=1;j<=fn;j++)
 {
 if((i!=j)&&(fflag[i]==1)&&(fneed[j]!=0))
 fwt[j]+=fneed[i];
 }
 fneed[i]=0;
 fn--;
 fflag[i]=0;
 }
}
}
for(i=1;i<=fn1;i++)
{
 ftat[i]=fwt[i]+fbt[i];
 ftwt=ftwt+fwt[i];
 fttat=fttat+ftat[i];
}
for(i=1;i<=fn1;i++)
{
	tt=tt+ftat[i];
}
for(i=1;i<=sn1;i++)
{
	tt=tt+stat[i];
}
fatat=fttat/fn1;
printf("-----------------------------------------FACULTY QUERIES --------------------------------------------------- \n");
printf("\n\n query \t query ID \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
for(i=1;i<=sn1;i++)
{
 printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", i,fpid[i],fbt[i],fwt[i],ftat[i]);
}
printf("\n The amount of time spent on queries %f",tt);
printf("\n The average Turn around %f",satat+fatat);
} 
