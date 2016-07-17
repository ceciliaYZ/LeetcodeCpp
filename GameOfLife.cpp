//
//  GameOfLife.cpp
//  Leetcode
//
//  Created by Cecilia on 6/26/16.
//  Copyright © 2016 Cecilia. All rights reserved.
//

#include "Solution.h"
#include <iostream>

void printArrayss(vector<vector<int>>& nums){
    for (int i=0; i<nums.size(); i++) {
        for (int j=0; j<nums[0].size(); j++) {
            cout<<nums[i][j]<<", ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}


int m;
int n;

void calculator(int i, int j, vector<vector<int>>& map){
    if(map[i][j]!=2&&map[i][j]!=3){
        map[i][j]=(map[i][j]==0)?2:3;
        int sum_nbs=0;
        int new_value;
        for (int inner_i=max(i-1,0); inner_i<min(i+2,m); inner_i++) {
            for (int inner_j=max(j-1,0); inner_j<min(j+2,n); inner_j++) {
                if(inner_i!=i || inner_j!=j){
                    sum_nbs+=map[inner_i][inner_j]%2==0?0:1;
                }
            }
        }
        if((map[i][j]%2==0 && sum_nbs==3) || (map[i][j]%2==1 && sum_nbs<4 && sum_nbs>1)){
            new_value= 3;
        }else{
            new_value= 2;
        }
        for (int inner_i=max(i-1,0); inner_i<min(i+2,m); inner_i++) {
            for (int inner_j=max(j-1,0); inner_j<min(j+2,n); inner_j++) {
                if(inner_i!=i || inner_j!=j){
                    calculator(inner_i, inner_j,map);
                }
            }
        }
        map[i][j]=new_value;
    }
}
void Solution:: gameOfLife(vector<vector<int>>& board){
    if(board.size()==0||board[0].size()==0) return;
    m=(int)board.size();
    n=(int)board[0].size();
    calculator(0,0,board);
    printArrayss(board);
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++) {
            board[i][j]=(board[i][j]==2)?0:1;
        }
    }
}
