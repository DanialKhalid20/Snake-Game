#include <iostream>
#include<cstring>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include<conio.h>
using namespace std;
struct points{
	int x;
	int y;
};

void gotoxy(int x, int y);

void printsnake(points p[], int size){

	for(int i=0; i<size; i++)
	{
		gotoxy(p[i].x,p[i].y);
		cout<<"O";			
	}
}

void removesnake(points p[], int size){

	for(int i=0; i<size; i++)
	{
			gotoxy(p[i].x,p[i].y);
			cout<<" ";		
		
	}
}


int moveup(points p[],int size){

	int index;

	for(index=size; index>0; index--){
		p[index].x=p[index-1].x;
		p[index].y=p[index-1].y;
}
	p[index].y=p[index].y-1;
}


int movedown(points p[], int size){

	int index;

	for(index=size; index>0; index--){
		p[index].x=p[index-1].x;
		p[index].y=p[index-1].y;
}	p[index].y=p[index].y+1;
}



int moveright(points p[],int size){

	int index;

	for(index=size; index>0; index--){
		p[index].x=p[index-1].x;
		p[index].y=p[index-1].y;
}	p[index].x=p[index].x+1;
}


int moveleft(points p[],int size){
	
	int index;

	for(index=size; index>0; index--){
		p[index].x=p[index-1].x;
		p[index].y=p[index-1].y;

}
	p[index].x=p[index].x-1;
}


void movement(char input,points p[],int size,char &lastinput){
	if(input=='w'){
	moveup(p,size);
	}
	
	else if(input=='s'){
	movedown(p,size);	
	}


	else if(input=='a'){
	moveleft(p,size);
	}

	else if(input=='d'){
	moveright(p,size);
	}

}


int snakereverse(points p[], char lastinput, char input, int size)
       {
		if(lastinput=='w'&&input=='s'){
				moveleft(p,size);
				movedown(p,size);	
	
		}
		 else if( lastinput=='s'&&input=='w')
       {  
            	moveright(p,size);
				moveup(p,size);

		}	
		
		else if(lastinput=='a'&&input=='d' ){
				
				movedown(p,size);
				moveright(p,size);		
		
		}
	    else if( lastinput=='d'&&input=='a')
       {
			     
				moveup(p,size);
			    moveleft(p,size);

		}		
	}
	


void Boundry(){
char input=220,input1=219;
int x=1, y=0;

for(y; y<=26; y++)
{
	
	gotoxy(x,y);
	cout<<"|";	
	
}

x=2,y=0;
for(x; x<=82; x++)
{
	
	gotoxy(x,y);
	cout<<"=";
		
}

x=82; y=0;
for(y; y<=26; y++)
{
	
	gotoxy(x,y);
	cout<<"|";
		
}

x=2,y=26;
for(x; x<=81; x++)
{
	
	gotoxy(x,y);
	cout<<"=";
		
}	
}

int storepoints(points p[], int size){
	int x=8,y=7;
	for(int i=0; i<size; i++){
		p[i].x=x;
		p[i].y=y;
		
		x--;
		
	}
}

int gameoverbybody(points p[],int size){
	for(int i=2; i<size; i++){
	
	if(p[0].x==p[i].x &&p[0].y==p[i].y){
	gotoxy(0,28);
	cout<<"GAME OVER :( ";
	exit(0);
	}
}
	
}


int gameoverbyhurdle(points p[]){



	//upper horizontal line
	int x=14,y=4;
	for(int i=0; i<55; i++){
	
	if(p[0].x==x && p[0].y==y){
	gotoxy(0,28);
	cout<<"GAME OVER :( ";
	exit(0);	
	
	}		
	
	x++;

	}

	
	//lower horizontal line
	x=14,y=21;
	for(int i=0; i<55; i++){
	
	if(p[0].x==x && p[0].y==y){
	gotoxy(0,28);
	cout<<"GAME OVER :( ";
	exit(0);	
	
	}	
	
	x++;
	}
	
	//upper left vertical line
	x=14,y=4;
	for(int i=0; i<5; i++){
	
	if(p[0].x==x && p[0].y==y){
	gotoxy(0,28);
	cout<<"GAME OVER :( ";
	exit(0);	
	
	}
			
	y++;
	}
	
	//upper right vertical line

	x=68,y=4;
	for(int i=0; i<5; i++){
	
	if(p[0].x==x && p[0].y==y){
	gotoxy(0,28);
	cout<<"GAME OVER :( ";
	exit(0);	
	
	}
			
	y++;
	}
	
	//lower left vertical line

	x=14,y=18;
	for(int i=0; i<4; i++){
	
	if(p[0].x==x && p[0].y==y){
	gotoxy(0,28);
	cout<<"GAME OVER :( ";
	exit(0);	
	
	}		
	y++;
	
	}
	
	
	//lower right vertical line

	x=68,y=18;
	for(int i=0; i<4; i++){
	
	if(p[0].x==x && p[0].y==y){
	gotoxy(0,28);
	cout<<"GAME OVER :( ";
	exit(0);	
	
	}		
	y++;
	
	}

}

int avoidfoodonhurdle(int a, int b){
	//upper horizontal line
	int x=14,y=4;
	for(int i=0; i<55; i++){
	
	if(a==x && b==y){
	return 1;
		
	}		
	
	x++;

	}

	
	//lower horizontal line
	x=14,y=21;
	for(int i=0; i<55; i++){
	
	if(a==x && b==y){
	return 1;	
	}	
	
	x++;
	}
	
	//upper left vertical line
	x=14,y=4;
	for(int i=0; i<5; i++){
	
	if(a==x && b==y){
	return 1;
	
	}
			
	y++;
	}
	
	//upper right vertical line

	x=68,y=4;
	for(int i=0; i<5; i++){
	
	if(a==x && b==y){
	return 1;	
	}
			
	y++;
	}
	
	//lower left vertical line

	x=14,y=18;
	for(int i=0; i<4; i++){
	
	if(a==x && b==y){
	return 1;	
	}		
	y++;
	
	}
	
	
	//lower right vertical line

	x=68,y=18;
	for(int i=0; i<4; i++){
	
	if(a==x && b==y){
     return 1;	
	}		
	y++;
	
	}
	
}


int avoidfoodonsnake(points p[],int a, int b,int size){
	int i;
	for(i=0; i<size; i++){
		if(a==p[i].x && b==p[i].y){
			return 1;
		}
	}
}


int food(points p[],int &size, int &score, int &a, int &b, int c,int z,int z1){


if(c==1){

   srand(time(0));
	
a=(rand()%79)+2;
b=(rand()%24)+2;


z=avoidfoodonhurdle( a, b);
if(z==1){
	return 1;
}


z1=avoidfoodonsnake(p,a,b,size);
if(z1==1){
	return 1;
}

	gotoxy(a,b);
	cout<<"o"<<endl;

}

	if(p[0].x==a && p[0].y==b){
		
		score=score+10;
		size=size+1;
		
		return 1;

		
}	
	
return 0;

}
void hurdle(){
	// upper horizontal
	int x,y=4;
	char input=220,input1=219;
	for(x=14; x<69; x++){
		gotoxy(x,y);
		cout<<input;
	}
	
	// upper left vertical
	x=14,y;
	for(y=5; y<9; y++){
		gotoxy(x,y);
		cout<<input1;
	}
	
	// upper right vertical
	x=68,y;
	for(y=5; y<9; y++){
		gotoxy(x,y);
		cout<<input1;
	}
	
	// lower horizontal
		
	x,y=21;
	for(x=14; x<68; x++){
		gotoxy(x,y);
		cout<<input;
	}
	
	// lower left vertical	
	x=14,y;
	for(y=18; y<22; y++){
		gotoxy(x,y);
		cout<<input1;
	}
	
	//lower right vertical
	x=68,y;

	for(y=18; y<22; y++){
		gotoxy(x,y);
		cout<<input1;
	}
	
		
}
int gameoverbyboundary(points p[]){
	if(p[0].x<2 || p[0].x>81){
	gotoxy(0,28);
	cout<<"GAME OVER :( ";
	exit(0);
	}
	
	else if(p[0].y<1 || p[0].y>=26){
	gotoxy(0,28);
	cout<<"GAME OVER :( ";
	exit(0);

	}


}


int main()
	{
	int size=3,score=0,x,z,y,z1,a,b,c=1;
	
	char input='s',lastinput;
	
	points p[20];

storepoints(p,size);
Boundry();
hurdle();
while(1){

if(_kbhit()){
	lastinput=input;
	input=_getch();

snakereverse( p, lastinput, input, size);	
}	
 


printsnake(p,size);

Sleep(150);

removesnake(p,size);

movement(input,p,size,lastinput);

gameoverbyboundary(p);

gameoverbybody(p,size);

gameoverbyhurdle(p);

c=food(p,size,score,a,b,c,z,z1);
if(z==1){
	break;
}
if(z1==1){
	break;
}

gotoxy(0,27);
cout<<"SCORE : "<<score<<endl;

}

return 0;

}




void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
