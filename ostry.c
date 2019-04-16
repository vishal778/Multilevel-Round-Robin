#include<stdio.h>
int check(int n,int start,int end,int a[])
{
    int i;
    for(i=start;i<end;i++)
        if(a[i]==n)
            return 0;
    return 1;
}
int main()
{
    int PR[]={1,2,3,4,5,6},AT[]={0,1,2,3,4,6},BT[]={4,5,2,1,6,3},Q[]={1,2,1,1,2,1},cycle[50],BT1[50],BT2[50],a[50],ATF[50],BTF[50];
    int ATS[50],BTS[50],PRF[50],PRS[50],TAT[50],WT[50],CT[50];
    int TQ1=2,size=6,i,min,j,limit[50],looplimit=0,temp,pos,t,sizef,sizet,pos1,min1;
    double avg_time,sum=0;


    printf("\n");
    j=0;
    t=0;
    for(i=0;i<size;i++)
    {
        if(Q[i]==1)
        {
            BTF[j]=BT[i];
            ATF[j]=AT[i];
            PRF[j]=PR[i];
            j++;
        }
        else
        {
            BTS[t]=BT[i];
            ATS[t]=AT[i];
            PRS[t]=PR[i];
            t++;
        }
    }
    sizef=j;
    sizet=t;
    for(j=0;j<sizef;j++)
    {
    min=ATF[j];
    pos=j;
    for(i=j+1;i<sizef;i++)
    {
        if(ATF[i]<min)
        {
          min=ATF[i];
          pos=i;
        }
    }
    temp=ATF[j];
    ATF[j]=min;
    ATF[pos]=temp;
    BT1[j]=BTF[pos];
    temp=BTF[j];
    BTF[j]=BTF[pos];
    BTF[pos]=temp;
    temp=PRF[j];
    PRF[j]=PRF[pos];
    PRF[pos]=temp;
    }
    for(i=0;i<sizef;i++)
    {
        looplimit=looplimit+BTF[i];
    }

    for(j=0;j<sizet;j++)
    {
    min=ATS[j];
    pos=j;
    for(i=j+1;i<sizet;i++)
    {
        if(ATS[i]<min)
        {
          min=ATS[i];
          pos=i;
        }
    }

    temp=ATS[j];
    ATS[j]=min;
    ATS[pos]=temp;
    BT2[j]=BTS[pos];
    temp=BTS[j];
    BTS[j]=BTS[pos];
    BTS[pos]=temp;
    temp=PRS[j];
    PRS[j]=PRS[pos];
    PRS[pos]=temp;
    }



    int l=0,lm,s=0,k=0;
    i=0;
    j=0;
    while(looplimit!=0)
    {
    if(BT1[i]<=TQ1 && BT1[i]!=0)
    {
        l+=BT1[i];
        looplimit=looplimit-BT1[i];
        cycle[j]=PRF[i];
        limit[j]=l;
        BT1[i]=0;
        j++;
    }
    else if(BT1[i]!=0)
    {
        l+=TQ1;
        looplimit=looplimit-TQ1;
        cycle[j]=PRF[i];
        limit[j]=l;
        BT1[i]=BT1[i]-TQ1;
        j++;
    }
        for(lm=0;lm<sizef;lm++)
        {
            if(ATF[lm]<=l && lm != i && check(lm,s,k,a))
                    a[k++]=lm;
        }
    i=a[s++];
    }
    for(i=0;i<sizet;i++)
    {
        looplimit=looplimit+BTS[i];

    }
    i=0;
    s=0;
    k=0;
    int at[50];
    while(looplimit!=0)
    {

    if(BT2[i]<=TQ1 && BT2[i]!=0)
    {
        l+=BT2[i];
        looplimit=looplimit-BT2[i];
        cycle[j]=PRS[i];
        limit[j]=l;
        BT2[i]=0;
        j++;
    }
    else if(BT2[i]!=0)
    {
        l+=TQ1;
        looplimit=looplimit-TQ1;
        cycle[j]=PRS[i];
        limit[j]=l;
        BT2[i]=BT2[i]-TQ1;
        j++;
    }
        for(lm=0;lm<sizet;lm++)
        {
            if(ATF[lm]<=l && lm != i && check(lm,s,k,a))
                    at[k++]=lm;
        }
    i=at[s++];
    }

    printf("/--------------------------MULTILEVEL QUEUE WITH ROUND ROBIN------------------------/");
    printf("\n");
    printf("********GANTT CHART*********\n");
    for(i=0;i<j;i++)
        printf("P%d     ",cycle[i]);
    printf("\n");

   /* for(i=0;i<j;i++)
        printf("%d     ",limit[i]);    //limit of gantt chart*/

    i=i-1;
    temp=i;
    int c=1;
    for(j=0;j<size;j++)
    {
      for(k=temp;k>=0;k--)
      {
          if(cycle[k]==c)
          {
            CT[c-1]=limit[k];
            break;
          }
      }
      c++;
    }
    printf("\n\n");
    printf("**********COMPLETION TIME**********");
    printf("\n");
    for(i=0;i<size;i++)
    {
        printf("P%d--%d      ",i+1,CT[i]);
    }
    printf("\n\n");
     printf("**********TURNAROUND TIME**********");
    for(i=0;i<size;i++)
    {
        TAT[i]=CT[i]-AT[i];
    }


    printf("\n\n");

    for(i=0;i<size;i++)
    {
        printf("P%d--%d      ",i+1,TAT[i]);
    }
    printf("\n\n");
    printf("**********WAITING TIME**********");

    for(i=0;i<size;i++)
    {
        WT[i]=TAT[i]-BT[i];
    }
    printf("\n\n");


    for(i=0;i<size;i++)
    {
        printf("P%d--%d      ",i+1,WT[i]);
    }
    for(i=0;i<size;i++)
    {
        sum=sum+TAT[i];

    }
     printf("\n\n\n");

    printf("Process\tAT\tBT\tQueue\tCT\tTAT\tWT");
    printf("\n");
     for(i=0;i<size;i++)
    {
        printf("%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d",PR[i],AT[i],BT[i],Q[i],CT[i],TAT[i],WT[i]);
        printf("\n");
    }



    avg_time=sum/size;
    printf("\n\n\n");
    printf("AVERAGE QUERY TIME:   %.2lf",avg_time);

    sum=0;

    for(i=0;i<size;i++)
    {
        sum=sum+WT[i];
    }
    avg_time=sum/size;
    printf("\n\n");
    printf("\nAverage waiting time: %.2lf",avg_time);
}
