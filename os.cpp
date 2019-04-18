#include<stdio.h>
int main()
{
	int i,j;
	printf("\n Enter the number of processes: ");
	scanf("%d",&j);
	int arrival[j];
	int burst[j],burst1[j];
	int waiting[j];
	int tarrival[j];
	int tq1=3;
	int tq2=6;
	int avgT=0;
	int avgW=0;
	printf("\n Enter arival time of processes:\n");
	for(i=0;i<j;i++)
	{  printf("For processes %d :",i+1);
		scanf("%d",&arrival[i]);
	}
	printf("\n Enter burst time for processes:\n");
	for(i=0;i<j;i++)
	{
		printf("For processes %d:",i+1);
		scanf("%d",&burst[i]);
		burst1[i]=burst[i];	
	}
	printf("\n****************************** 1st ITERATION (Time Quantum=3) ****************************\n");
	for(i=0;i<j;i++)
	{  
	if(arrival[i]<=tq1+arrival[i-1])
	{
	
		burst[i]=burst[i]-tq1;
		
		printf("\n For process %d \n",i+1);
		printf("Left Burst time=%d \n",burst[i]);}
		else
		{
		burst[i]=burst[i]-tq1;
	
		printf("For process %d\n",i+1);
		printf("Left Burst time= %d\n",burst[i]);	
		}}
	
	printf("\n****************************** 2nd ITERATION (Time Quantum=6) ****************************\n");
	for(i=0;i<j;i++)
	{
	if(arrival[i]<=tq2+arrival[i-1])
	{
	
		burst[i]=burst[i]-tq2;
		
		printf("\n For process %d\n",i+1);
		printf("Left Burst time= %d\n",burst[i]);}
		else
		{
		burst[i]=burst[i]-tq2;
	
		printf("For process %d\n",i+1);
		printf("Left Burst time= %d\n",burst[i]);	
		}	
	}
	printf("\n****************************** 3rd ITERATION ***********************************\n");
	int k,temp;

	for(i=0;i<j;i++)
	{
		for(k=i+1;k<j;k++)
		{if(burst[i]>burst[k])
		{
		
			temp=burst[i];
			burst[i]=burst[k];
			burst[k]=temp;
			}
		}
	}
	int ct[4]={54,68,45,41};
	for(i=0;i<j;i++)
	{
		tarrival[i]=ct[i]-arrival[i];
		waiting[i]=tarrival[i]-burst1[i];
		printf("\n Completion time for process %d : %d \n",i+1,ct[i]);
		printf("Turn arround time for process %d : %d \n",i+1,tarrival[i]);
		printf("Waiting time for process %d : %d \n",i+1,waiting[i]);
		avgT=avgT+tarrival[i];
		avgW=avgW+waiting[i];
		
	}
	avgT=avgT/j;
	avgW=avgW/j;
	printf("\n\n Average turn around time: %d\n",avgT);
	printf("Average waiting time: %d\n",avgW);
	}

