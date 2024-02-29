#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void merge(int arr[],int left[],int right[],int left_size,int right_size)
{
    int i=0,j=0,k=0;

    while(i<left_size&&j<right_size)
    {
        if(left[i]<right[j])
        {
            arr[k++]=left[i++];
        }
        else
        {
            arr[k++]=right[j++];
        }
    }
    while(i<left_size)
    {
        arr[k++]=left[i++];
    }
    while(j<right_size)
    {
        arr[k++]=right[j++];
    }
}

void BS(int arr[],int N,char T)
{
    int i,j;
    if(T=='b')
    {
        for(i=0;i<=N-1;i++)
        {
            for(j=0;j<N-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                }
            }
        }
    }
    if(T=='c')
    {
        for(i=0;i<=N-1;i++)
        {
            for(j=0;j<N-1;j++)
            {
                if(arr[j]<arr[j+1])
                {
                    int temp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                }
            }
        }
    }
}

void IS(int arr[],int N,char T)
{
    int i,j;
    if(T=='b')
    {
        for(i=1;i<N;i++)
        {
            for(j=i;j>=0;j--)
            {
                if(arr[j]<arr[j-1]);
                {
                    int temp=arr[j-1];
                    arr[j-1]=arr[j];
                    arr[j]=temp;
                }
                if(arr[j]>arr[j-1])break;
            }
        }
    }
    if(T=='c')
    {
        for(i=1;i<N;i++)
        {
            for(j=i;j>=0;j--)
            {
                if(arr[j]>arr[j-1])
                {
                    int temp=arr[j-1];
                    arr[j-1]=arr[j];
                    arr[j]=temp;
                }
                if(arr[j]>arr[j-1])break;
            }
        }
    }
}

void MS(int arr[],int N,char T)
{
    if(N<2)return ;
    int mid=N/2;
    int left[mid],right[N-mid];
    for(int i=0;i<mid;i++)
    {
        left[i]=arr[i];
    }
    for(int j=0;j<mid;j++)
    {
        right[j]=arr[mid+j];
    }
    MS(left,mid,T);
    MS(right,N-mid,T);

    merge(arr,left,right,mid,N-mid);
}

int main()
{
    FILE *fp;
    int N,min,max;
    char T;
    clock_t start, end;
    double cpu_time_used;

    fp=fopen("D:\\project\\Data Generator\\data.txt","w");
    if(fp==NULL)
    {
        printf("unable to open the file");
        return 1;
    }
    //设置种子
    srand(time(NULL));
    scanf("%d %d %d",&N,&min,&max);
    getchar();
    scanf("%c",&T);

    int num;
    if(T=='a')
    {
        start=clock();
        for(int i=1;i<=N;i++)
        {
            num=rand()%(max-min+1)+min;
            fprintf(fp,"%d ",num);
            if(i%10==0)
            {
                fprintf(fp,"\n");
            }
        }
        end=clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("mission completed\n");
        printf("time=%.20lf",cpu_time_used);
    }

    if(T=='b')
    {
        int arr[1000000];

        for(int i=1;i<=N;i++)
        {
            arr[i-1]=rand()%(max-min+1)+min;
        }
        start=clock();
        BS(arr,N,'b');
        end=clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        for(int i=0;i<N;i++)
        {
            fprintf(fp,"%d ",arr[i]);
            if(i%10==9)
            {
                fprintf(fp,"\n");
            }
        }
        printf("mission completed\n");
        printf("time=%.10lf",cpu_time_used);
    }

    if(T=='c')
    {
        int arr[1000000];
        for(int i=1;i<=N;i++)
        {
            arr[i-1]=rand()%(max-min+1)+min;
        }
        start=clock();
        BS(arr,N,'c');
        end=clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        for(int i=0;i<N;i++)
        {
            fprintf(fp,"%d ",arr[i]);
            if(i%10==0)
            {
                fprintf(fp,"\n");
            }
        }
        printf("mission completed\n");
        printf("time=%.10lf",cpu_time_used);
    }
    fclose(fp);

    return 0;
}