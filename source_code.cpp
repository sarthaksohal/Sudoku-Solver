#include<bits/stdc++.h>
using namespace std;
bool checkthevalueinthatgrid(int grid[][9],int row,int column,int num){
    for(int i=0;i<9;i++){
        if(grid[row][i]==num)
            return false;
  }
    for(int i=0;i<9;i++){
        if(grid[i][column]==num)
            return false;
    }
    int rowfactor=row-row%3;
    int colfactor=column-column%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[rowfactor+i][colfactor+j]==num)
                return false;
        }
    }
    return true;
}
bool itcontainzero(int grid[][9],int& row,int& column){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]==0){
                 row=i;
                column=j;
                return true;
        }}
    }
}
 bool sudokusolver(int grid[][9]){
     int row,column;
     if(itcontainzero(grid,row,column)==false)
     {
         return true;
 }
     for(int i=1;i<=9;i++){
         if(checkthevalueinthatgrid(grid,row,column,i))
         {
             grid[row][column]=i;
             if(sudokusolver(grid))
             
                 return true;
         grid[row][column]=0;
             }
     }
     return false;
     }

int main(){
    //int input;
int arr[9];
 int grid[9][9];//this is a grid of sudoku
     int input;
    for(int i=0;i<9;i++){     
        for(int j=0;j<9;j++){
            cin>>input;
            arr[j]=input;
            }
     for(int k=0;k<9;k++){
            
             grid[i][k]=arr[k];
         }
     }
 if(sudokusolver(grid))
 cout<<"true";   
    else
     cout<<"false";
    return 0;
}
