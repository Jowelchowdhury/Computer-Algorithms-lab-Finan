#include<stdio.h>
#include<math.h>
int m[20], count;
int main()
{

    int i, j, n;
    void queen(int row, int colum);
    printf("Enter the number of queen: ");
    scanf("%d", &n);
    queen(1,n);
    return 0;
}
void print(int n)
{

    int i, j;
    printf("\nSolution %d:\n", ++count);
    for (i=1; i<=n; i++)
        printf("\t%d", i);
        for (i=1; i<=n; ++i)
        {

            printf("\n%d", i);
            for(j=1; j<=n; ++j)
                {
                    if(m[i]==j)

                    printf("\tQ");
            else
                printf("\t-");

            }
        }



}
int place(int row, int column)
{

    int i;
    for(i=1; i<=row-1; i++)
    {

        if(m[i]==column)
            return 0;
        else
            if(abs(m[i]-column)==abs(i-row))
            return 0;
    }
    return 1;
}
void queen(int row, int n)
{

    int column;
    for(column=1; column<=n; ++column)
    {

        if(place(row, column))
        {

            m[row]=column;
            if(row==n)
                print(n);
            else
                queen(row+1, n);
        }
    }
}
