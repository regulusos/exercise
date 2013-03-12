#include<stdio.h>
int sum;
int store[10];

void Output()

{
	int i;
    for(i = 3; i>=0; --i)
    {
       	printf("%d ",store[i]);
    }

   	printf("\n");
   ++sum;
}
 

void Cumput(int score, int num)
{
	int i;
   if(score < 0 || score > (num+1)*10 ) //´ÎÊınumÎª0¡«9
      return;

   if(num == 0) 
     {
        store[num] = score;
        Output();
        return;
     }

   for(i = 0; i <= 2; ++i)
     {
        store[num] = i;
        Cumput(score - i, num - 1);
     }

}

 

int main(int argc, char* argv[])

{

       Cumput(2, 3);
       return 0;

}
