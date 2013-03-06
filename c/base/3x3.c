    #include<stdio.h>   
    #include<conio.h>   
    #define N 10   
       
    void write(int a[])   
    {int i,j;   
     for(i=0;i<3;i++)   
     {   
         for(j=0;j<3;j++) printf("%3d",a[3*i+j]);   
         printf("\n");   
     }   
     printf("******************\n");   
     //getch();    
    }   
       
       
    int b[N+1],a[10];   
       
    int isPrime(int m)   
    {int i;   
    int primes[]={2,3,5,7,11,13,17,19,23,29,-1};   
    //if(m==1||m%2==0) return 0;   
    for(i=0;primes[i]>0;i++)   
      if(m==primes[i]) return 1;   
    /*for(i=3;i*i<=m;)  
    {  
      if(m%i==0) return 0;  
      i+=2;  
    }  
    printf("%d --  \n",m); */   
    return 0;   
    }   
       
    int checkMatrix[][3]={   
        {-1},{0,-1},{1,-1},   
        {0,-1},{1,3,-1},{2,4,-1},   
        {3,-1},{4,6,-1},{5,7,-1}};   
       
    int selectNum(int start)   
    {int j;   
    for(j=start;j<=N;j++)   
    if(b[j]) return j;   
    return 0;   
    }   
       
    int check(int pos)   
    {int i,j;   
       
      if (pos<0) return 0;   
      for(i=0;(j=checkMatrix[pos][i])>=0;i++)   
          if(!isPrime(a[pos]+a[j])) return 0;   
           
      return 1;   
    }   
       
    int extend(int pos)   
    {   
        a[++pos]=selectNum(1);   
        b[a[pos]]=0;   
        return pos;   
    }   
       
    int change(int pos)   
    {int j;   
    while(pos>=0 && (j=selectNum(a[pos]+1))==0 ) b[a[pos--]]=1;   
        if(pos<0) return -1;   
        b[a[pos]]=1;   
        a[pos]=j;   
        b[j]=0;   
        return pos;   
    }void find()   
    {int ok=1,pos=0;   
    a[pos]=1;b[a[pos]]=0;   
    do   
    {   
        if(ok){    
            if(pos==8){   
                write(a);   
                pos=change(pos);   
            }   
            else pos=extend(pos);   
        }   
        else pos=change(pos);   
        ok=check(pos);   
    }while(pos>=0);   
    }   
    void main()   
    {   
        int i;   
        for(i=1;i<=N;i++) b[i]=1;   
        find();   
        getch();   
    }  
