#include <iostream>

#include <stdio.h>

#include <windows.h>

#include <string>

#include <vector>

using namespace std;

char GAMESET[18][32];

char PLAYAREA[18][32] = {

"===============================",
"|    $$$$$      $$    $$   %  |",
"|    $   $      $ $  $ $      |",
"|    $$$$$      $  $$  $      |",
"|    $          $      $    ^ |",
"|    $          $      $      |",
"|                             |",
"|      $     %      $      %  |",
"|     $ $          $ $        |",
"|    $$$$$        $$$$$       |",
"|   $     $      $     $      |",
"|                         %   |",
"| %                           |",
"|   $$$$$        $$   $       |",
"|   $            $ $  $       |",
"|   $            $  $ $       |",
"|   $$$$$    %   $   $$     % |",
"==============================="

};



void move_to_xy( short x, short y )
{
    HANDLE temp = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;

    SetConsoleCursorPosition( temp , position ) ;
}


class Player final {

private:
int x;
int y;

public:
Player( int x, int y ){
this ->x = x;
this ->y = y;
}

void move_x( int p ){
if( PLAYAREA[y][x+p] == ' ' )
    x =x+ p;
}

void move_y( int p ){
if( PLAYAREA[y+p][x] == ' ' )
y =y+ p;
}

void move( int p, int q ){
x =x+ p;
y =y+ q;
}

int get_x(){
return x;
}

int get_y(){
return y;
}

};

class MOVE{
    public:
short moves_counter;
short x;
short y;
short back;

virtual void energizer(){
    cout<<"ENERGIZER";
}

};

class Monster:public MOVE {
public:
short x;
short y;

void energizer(){
cout<<"+";
}

};

vector<Monster> move_in_array;

vector<MOVE> Pacman_X_array;

void AddArray( int x, int y, int wc , int back ){
if( GAMESET[y][x] == ' ' || GAMESET[y][x] == '.' ){
GAMESET[y][x] = '#';
MOVE temporary;
temporary.x = x;
temporary.y = y;
temporary.moves_counter = wc;
temporary.back = back;
Pacman_X_array.push_back( temporary );
}
}

void PresentMap()
{
for(int i = 0; i < 18; i++) {
cout<<PLAYAREA[i]<<endl;
}
}

void CatchPacman_X( int a, int b, int c, int d ){
memcpy( GAMESET, PLAYAREA, sizeof(PLAYAREA) );
Pacman_X_array.clear();
MOVE w;
w.x = a;
w.y = b;
w.moves_counter = 0;
w.back = -1;
Pacman_X_array.push_back( w );
int i = 0;
while( i < Pacman_X_array.size() ){
if( Pacman_X_array[i].x == c && Pacman_X_array[i].y == d ){
move_in_array.clear();
Monster m;
while( Pacman_X_array[i].moves_counter != 0 ){
m.y = Pacman_X_array[i].y;
m.x = Pacman_X_array[i].x;
move_in_array.push_back( m );
i = Pacman_X_array[i].back;
}
break;
}
AddArray( Pacman_X_array[i].x+1, Pacman_X_array[i].y, Pacman_X_array[i].moves_counter+1, i );
AddArray( Pacman_X_array[i].x-1, Pacman_X_array[i].y, Pacman_X_array[i].moves_counter+1, i );
AddArray( Pacman_X_array[i].x, Pacman_X_array[i].y+1, Pacman_X_array[i].moves_counter+1, i );
AddArray( Pacman_X_array[i].x, Pacman_X_array[i].y-1, Pacman_X_array[i].moves_counter+1, i );
i++;
}
Pacman_X_array.clear();
}


int main()
{
    int energizer=0;
int energizer_count=10;
bool moving = true;
int Pacman_X = 10;
int Pacman_X_Y = 15;
int old_Pacman_X;
int old_Pacman_X_Y;
int Monster_X = 1;
int Monster_Y = 1;
int score = 0;
int speedmod = 3;
system("cls");
PresentMap();

move_to_xy( Pacman_X, Pacman_X_Y ); cout << "H";

int frame = 0;

CatchPacman_X( Monster_X,Monster_Y,Pacman_X,Pacman_X_Y );

while( moving ){
move_to_xy( Pacman_X, Pacman_X_Y ); cout << ' ' ;

old_Pacman_X = Pacman_X;
old_Pacman_X_Y = Pacman_X_Y;

if ( GetAsyncKeyState( VK_UP ) ){
         if ( PLAYAREA[Pacman_X_Y-1][Pacman_X] == '%' ){Pacman_X_Y--; score=score+50; }
else if( PLAYAREA[Pacman_X_Y-1][Pacman_X] == '^' ){ Pacman_X_Y--; energizer=1; }
else if( PLAYAREA[Pacman_X_Y-1][Pacman_X] == '.' ){ Pacman_X_Y--; score++; }
else if( PLAYAREA[Pacman_X_Y-1][Pacman_X] == ' ' ) Pacman_X_Y--;
if (energizer==1)
energizer_count--;
if(energizer_count==0){
    energizer=0;
    energizer_count=10;
}
}
if ( GetAsyncKeyState( VK_DOWN ) ){
     if( PLAYAREA[Pacman_X_Y+1][Pacman_X] == '%' ){ Pacman_X_Y++; score=score+50; }
else if( PLAYAREA[Pacman_X_Y+1][Pacman_X] == '^' ){ Pacman_X_Y++; energizer=1; }
else if( PLAYAREA[Pacman_X_Y+1][Pacman_X] == '.' ){ Pacman_X_Y++; score++; }
else if( PLAYAREA[Pacman_X_Y+1][Pacman_X] == ' ' ) Pacman_X_Y++;
if (energizer==1)
energizer_count--;
if(energizer_count==0){
    energizer=0;
    energizer_count=10;
}
}
if ( GetAsyncKeyState( VK_LEFT ) ){
     if( PLAYAREA[Pacman_X_Y][Pacman_X-1] == '%' ){ Pacman_X--; score=score+50; }
else if( PLAYAREA[Pacman_X_Y][Pacman_X-1] == '^' ){ Pacman_X--; energizer=1; }
else if( PLAYAREA[Pacman_X_Y][Pacman_X-1] == '.' ){ Pacman_X--; score++; }
else if( PLAYAREA[Pacman_X_Y][Pacman_X-1] == ' ' ) Pacman_X--;
if (energizer==1)
energizer_count--;
if(energizer_count==0){
    energizer=0;
    energizer_count=10;
}
}
if ( GetAsyncKeyState( VK_RIGHT ) ){
     if( PLAYAREA[Pacman_X_Y][Pacman_X+1] == '%' ){ Pacman_X++; score=score+50; }
else if( PLAYAREA[Pacman_X_Y][Pacman_X+1] == '^' ){ Pacman_X++; energizer=1; }
else if( PLAYAREA[Pacman_X_Y][Pacman_X+1] == '.' ){ Pacman_X++; score++; }
else if( PLAYAREA[Pacman_X_Y][Pacman_X+1] == ' ' ) Pacman_X++;
if (energizer==1)
energizer_count--;
if(energizer_count==0){
    energizer=0;
    energizer_count=10;
}
}

if( old_Pacman_X != Pacman_X || old_Pacman_X_Y != Pacman_X_Y ){
CatchPacman_X( Monster_X,Monster_Y,Pacman_X,Pacman_X_Y );
}

move_to_xy( Pacman_X,Pacman_X_Y ); cout << "H";

PLAYAREA[Monster_Y][Monster_X] = '.';
move_to_xy( Monster_X, Monster_Y ); cout << '.';

if( frame%speedmod == 0 && move_in_array.size() != 0 ){
Monster_X = move_in_array.back().x;
Monster_Y = move_in_array.back().y;
move_in_array.pop_back();
}

move_to_xy( Monster_X, Monster_Y ); cout << "E";

if( Monster_X == Pacman_X && Monster_Y == Pacman_X_Y ){
break;
}


move_to_xy( 32, 18 );
move_to_xy( 32, 1 ); cout << "    Your Score : " << score << "  Time remaining for Energizer : "<<energizer_count;
Sleep( 100 );
frame++;
}

system("cls");
if(energizer==1){
cout<<"You Have Eaten The Monster..\nYou WON \nYour Score is : "<<score;
}
else{
cout<<"You Have Been Caught By The Monster \nYour Score is : "<<score;
}
cin.get();
return 0;
}

