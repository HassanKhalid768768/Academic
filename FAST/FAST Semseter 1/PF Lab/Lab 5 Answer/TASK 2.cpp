#include <iostream>
using namespace std;
int main() {
const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';
     
     char Player1,Player2;
    
    cout << "Rock, Paper and Scissors Game!" << endl;
    cout << "Choose one of the following options for Player 1"  << endl;
    cout << "(r) for rock " << endl << "(p) for paper" << endl << "(s) for scissors " << endl;
    cin >> Player1;
    cout << "Choose one of the following options for Player 2"  << endl;
    cout << "(r) for rock " << endl << "(p) for paper" << endl << "(s) for scissors " << endl;
    cin >> Player2;
   if(Player1==SCISSORS||Player1==ROCK||Player1==PAPER||Player2==PAPER||Player2==SCISSORS||Player2==ROCK){
    if (Player1==ROCK && Player2==ROCK){
        cout<<"DRAW";
    }
    if (Player1==PAPER && Player2==PAPER){
        cout<<"DRAW";
    }
    if (Player1==SCISSORS && Player2==SCISSORS){
        cout<<"DRAW";
    }
    if (Player1==ROCK && Player2==PAPER){
        cout<<"Player 2 WINS";
    }
     if (Player1==ROCK && Player2==SCISSORS){
        cout<<"Player 1 WINS";
    }
     if (Player1==PAPER && Player2==ROCK){
        cout<<"Player 1 WINS";
    }
     if (Player1==PAPER && Player2==SCISSORS){
        cout<<"Player 2 WINS";
    }
     if (Player1==SCISSORS && Player2==ROCK){
        cout<<"Player 2 WINS";
    }
     if (Player1==SCISSORS && Player2==PAPER){
        cout<<"Player 1 WINS";
    }
   }
   else{
        cout<<"YOU HAVE ENTERED AN INCORRECT CHOICE. PLEASE RERUN PROGRAM AND TRY AGAIN";
    }

    return 0;
}