#include<stdio.h>
#include<string.h>
int main()
{
        int test,i,j;
        
                printf("\nEnter test cases:");
                scanf("%d",&test);

        for(i=0;i<test;i++)
        {
                int rank = 0,q=0,p;

                char pattern[1000];
                char text[100000];

                printf("\nEnter Pattern:");
                scanf("%s",pattern);

                printf("\nEnter Text:");
                scanf("%s",text);

                int length = strlen(pattern);
                int flag[200] = {0};
                int count = 0;
                
                for(j=0;j<length;j++)
                {
                        flag[pattern[j]]++;
                }
                
                int check[200] = {0};
             
                
                for(p=0;p<strlen(text);p++)
                {
                        q++;
                        check[text[p]]++;
                
                   if(check[text[p]] == flag[text[p]])
                   {
                        count = count + check[text[p]];
                   }
                        
                        if(q >= length)
                        {
                                if(count == length)
                                {
                                        printf("\nYES\n");
                                        rank = 1;
                                        break;
                                }

                        else{
                                if( check[text[p-length+1]] == flag[text[p-length+1]] )
                                        
                                        count = count-flag[text[p-length+1]];
                                             check[text[p-length+1]]--;
                            } 
                        }

                }
                        if(rank == 0)
                                printf("\nNO\n");
        }       
}



/************OUTPUT***************

gcc program_new.c
student@HP800G1:~$ ./a.out

Enter test cases:3

Enter Pattern:hack

Enter Text:indiahacks

YES

Enter Pattern:code

Enter Text:eddy

NO

Enter Pattern:coder

Enter Text:iamredoc

YES
*/
