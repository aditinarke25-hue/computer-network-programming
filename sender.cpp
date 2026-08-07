#include<stdio.h>
#include<string.h>
int main()
{
    char a[50],b[100];
    int i,j=0,count=0;
    printf("Sender side program \n");
    printf("Enter input string :");
    scanf("%s",a);
    for (i=0;i<strlen(a);i++)
    {
    
        b[j]=a[i];
        j++;
      if (a[i]=='1')
       count++;
      else 
       count=0;
      if (count==5)
      {b[j]='0';
       j++;
      count=0;
      }
     
    }
    b[j]='\0';

    printf("\nFrame after bit stufing%s ",b);
    return 0;
}