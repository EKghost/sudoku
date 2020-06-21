#include<iostream>
using namespace std;
#define n 9
int search_block(int board[n][n],int &r,int &c)
{
    for(r=0;r<n;r++)
    for(c=0;c<n;c++)
    if(board[r][c]==0)
    return(1);
    return(0);
}
int is_safe_col(int board[n][n],int row,int col,int num)
{
    for(int i=0;i<n;i++)
    {
        if(board[i][col]==num)
        return(0);
    }
    return(1);
}
int is_safe_row(int board[n][n],int row,int col,int num)
{
    for(int i=0;i<n;i++)
    {
        if(board[row][i]==num)
        return(0);
    }
    return(1);
}
int is_safe_block(int board[n][n],int start_r,int start_c,int num)
{
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
        if(board[start_r+i][start_c+j]==num)
        return(0);
    }
    return(1);
}
int is_safe(int board[n][n],int row,int col,int num)
{
    int x=is_safe_col(board,row,col,num);
    int y=is_safe_row(board,row,col,num);
    int z=is_safe_block(board,row-row%3,col-col%3,num);
    return(x*y*z);

}
int sudoku(int board[n][n])
{
    int row=0,col=0;
    if(search_block(board,row,col))
    {
        for(int i=1;i<=n;i++)
        if(is_safe(board,row,col,i))
        {
            board[row][col]=i;
            if(sudoku(board))
            return(1);
            else
            board[row][col]=0;
        }
        return(0);
    }
    else
    return(1);
}
int main()
{
    int cur[9][9],i,j;
    for(i=0;i<9;i++)
    for(j=0;j<9;j++)
    {
        cin>>cur[i][j];
    }
    cout<<"SUDOKU SOLVED\n";
    sudoku(cur);
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cout<<cur[i][j]<<' ';
            if(j%3==2)
            cout<<'\t';
        }
        cout<<'\n';
        if(i%3==2)
        cout<<'\n';
    }
    return (0);
}
