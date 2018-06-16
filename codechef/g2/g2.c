#include<stdio.h>

long board[500][500];
int mem[500][500];
int m, n;
void count_moves(int i, int j)
{
    int rbranch=0, dbranch=0;
    int ti=i,tj=j,tc;
    while(++ti < m)
    {
        if(board[ti][tj] <= board[i][j])
        {
            if(mem[ti][tj] == -1)
            {
                count_moves(ti, tj);
            }
            tc = 1 + mem[ti][tj];
            if(tc > dbranch)
                dbranch = tc;
        }
    }
    ti = i, tj = j;
    while(++tj < n)
    {
        if(board[ti][tj] >= board[i][j])
        {
            if(mem[ti][tj] == -1)
            {
                count_moves(ti, tj);
            }
            tc = 1 + mem[ti][tj];
            if(tc > rbranch)
                rbranch = tc;
        }
    }
    if(rbranch>dbranch)
        mem[i][j] = rbranch;
    else
        mem[i][j] = dbranch;
}
void read_matrix(int m,int n)
{
    register unsigned i,j,temp;
	char c;
 
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
 
			do c = getchar_unlocked(); while( c < '0' || c > '9' );
 
			temp = 0;
			while( c >= '0' && c <= '9' )
			{
				temp = ( temp << 3 ) + ( temp << 1 ) + c - '0';
				c = getchar_unlocked();
			}
 
			board[i][j] = temp;
            mem[i][j] = -1;
		}
	}
}

void count_moves_nr(int i, int j)
{
    int p=i,q=j;
    for(p=i;p<m;p++)
    {
        for(q=j;q<n;q++)
        {
            
        }
    }
}
int main()
{
    int t, i, j, temp=0, count=0;
    scanf("%d", &t);
    while(t--)
    {
        getchar();
        scanf("%d%d", &m, &n);
        read_matrix(m,n);
        count = 0;
        temp = 0;
        for(i=0;i<m;i++)
        {
            if((n-i)+m-2 <= count)
                break;
            for(j=0;j<n;j++)
            {
                if((n-i)+(m-j)-2 <= count)
                    break;
                if(mem[i][j] == -1)
                {
                    count_moves_nr(i, j);
                }
                temp = mem[i][j];
                if(temp > count)
                {
                    count = temp;
                }
            }
        }
        printf("%d\n", count + 1);
    }
    return 0;
}

