#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
#include <cstdio>
using namespace std;

static char board[3][3]={{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}},ch1;
string p1,p2;
int r,c;
int a=0;

class MyGame{
public:
void boardReset(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			board[i][j]=' ';			
		}
	}
} 
void displayBoard(){
    system("cls");
    cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= TIC-TAC-TOE GAME =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*"<<endl;
    cout<<"\n\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                cout<<"\t\t\t\t\t\t\t";
			}
            cout<<" "<<board[i][j]<<" ";
            if(j!=2)
                cout<<"|";
        }
        cout<<"\n";
        if(i!=2){
            cout<<"\t\t\t\t\t\t\t-----------\n";
    	}
    }
}


bool isWinner(char ch4){
	return((board[0][0]==ch4&&board[0][1]==ch4&&board[0][2]==ch4)||
			(board[1][0]==ch4&&board[1][1]==ch4&&board[1][2]==ch4)||
			(board[2][0]==ch4&&board[2][1]==ch4&&board[2][2]==ch4)||
			(board[0][0]==ch4&&board[1][0]==ch4&&board[2][0]==ch4)||
			(board[0][1]==ch4&&board[1][1]==ch4&&board[2][1]==ch4)||
			(board[0][2]==ch4&&board[1][2]==ch4&&board[2][2]==ch4)||
			(board[0][0]==ch4&&board[1][1]==ch4&&board[2][2]==ch4)||
			(board[0][2]==ch4&&board[1][1]==ch4&&board[2][0]==ch4));
}

bool boardfull(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j]==' '){
				return false;
			}
		}
	}
	return true;
}

void makeMove(char c1){
	if(board[r-1][c-1]==' '){
		board[r-1][c-1]=c1;
	}
	else {
	cout<<"\n\t\t\t\tThis place is already occupied!!! Choose another space!\n";
	a--;
}
}
void playGame(){
	do{
		if(a%2==0){
			cout<<endl<<"\n\t\t\t\t\t\t\t"<<p1<<"'s Turn\n";
			ch1='O';
		}
		else{
			cout<<endl<<"\n\t\t\t\t\t\t\t"<<p2<<"'s Turn\n";
			ch1='X';
		}
		
        while(1){
            cout<<"\t\t\t\t\t\tChoose your row no.: ";
            cin>>r;
            if((r<1||r>3))
                cout<<"\n\t\t\t\t\tPlease choose your row between 1-3!!!\n\n";
            else
                break;
        }
        while(1){
            cout<<"\t\t\t\t\t\tChoose your column no.: ";
            cin>>c;
            if(c<1||c>3)
                cout<<"\n\t\t\t\t\tPlease choose your column between 1-3!!!\n\n";
            else
                break;
        }
		makeMove(ch1);
		a++;
		displayBoard();
		}while(!isWinner(ch1)&&!boardfull());
	}
};
int main(){
	char ch;
	system("color 5f");
	system("cls");
	MyGame g;
	do{
	cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= TIC-TAC-TOE GAME =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*"<<endl;
	cout<<"\n\t\t\t\t\t\tEnter 1st player's name: ";
	cin>>p1;
	cout<<"\t\t\t\t\t\tEnter 2nd player's name: ";
	fflush(stdin);
	cin>>p2;
	g.displayBoard();	
	g.playGame();
	cout<<"\n\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*";
	cout<<"\n\n\t\t\t\t\t\t\t RESULT\n\n";
	if(g.boardfull()&&!(g.isWinner('X')||g.isWinner('O')))
		cout<<"\n\t\t\t\t\t\t   IT'S A TIE!!!\n\n";
	else if(a%2==0)
		cout<<"\t\t\t\t\t\t   CONGRATS,"<<p2<<" WINS!!\n\n";
	else 
		cout<<"\t\t\t\t\t\t   CONGRATS,"<<p1<<" WINS!!\n\n";
	cout<<"*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*";
	cout<<"\nDo you want to play again?(Y/N): ";
	g.boardReset();
	a=0;
	cin>>ch;	
}while(ch=='y'||ch=='Y');
}
