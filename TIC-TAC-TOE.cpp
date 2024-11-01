#include <iostream>
#include <vector>
#include "control.h"
using namespace control;
using namespace std;

enum key { up = 72, down = 80, lt = 75, rt = 77 };

void move(int x,int y)
{cout<<"\033["<<y<<";"<<x<<"H";} //x=54,y=6 is top left. next line is y+2,next column is x+4

int main() 
{
    ttt x;
    int r=0,c=0,moves=0,a=54,b=6;
    cout << "\033[0;0H";  // Move cursor to top-left

    while (true) 
    {  
		cout<<"\033[31m";
		cout << "NOTE: Use Arrow Keys To Select\n\n"<<"\033[35m";
        char ch;
        x.disp_board();
		cout<<"\033[13;51H"<<"\033[32m";
        cout << "Player " << x.getplayer() << "'s TURN\n"<<"\033[36m";
        while (true) 
        {
            if (_kbhit()) 
            {
                ch = _getch();
                switch (ch) 
                {
                    case up: if(b>6)b-= 2; break;
                    case down:if(b < 10)b+= 2; break;
                    case lt: if(a > 54)a-= 4; break;
                    case rt: if (a < 62)a+= 4; break;
                }
            }
            move(a,b);
            if(a==54 && b==6){r=0;c=0;}
            if(a==58 && b==6){r=0;c=1;}
            if(a==62 && b==6){r=0;c=2;}
            
            if(a==54 && b==8){r=1;c=0;}
            if(a==58 && b==8){r=1;c=1;}
            if(a==62 && b==8){r=1;c=2;}
            
            if(a==54 && b==10){r=2;c=0;}
            if(a==58 && b==10){r=2;c=1;}
            if(a==62 && b==10){r=2;c=2;}
            
            if (ch == 13 && x.makemove(r, c)) 
            {  // Enter key
                moves++;
                break;
            }
        }

        system("CLS");  // Clear screen 
        if (x.winner()) 
        {
			x.disp_board();
			cout<<"\033[11;51H";
            cout << "Player " << x.getplayer() << " is the winner!\n";
            break;
        }
        if (moves == 9) 
        {
			x.disp_board();
			cout<<"\033[11;51H";
            cout <<"Draw match!!\n";
            break;
        }
        x.changeplayer();
    }
    return 0;
}
