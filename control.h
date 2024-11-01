#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

namespace control 
{

    class board 
    {
    protected:	vector<vector<char> > matrix;
				char player;

    public:     board() : matrix(3, vector<char>(3, ' ')), player('X') {}
				void disp_board() 
				{
					cout << "\033[35m"<<endl;
					cout << "                                                  ";//gap to center
					cout << "  0   1   2" << endl;
					cout << "                                                  ";//gap to center
					cout << " +---+---+---+" << endl;

					for (int i = 0; i < 3; ++i) 
					{
						cout << "                                                  ";//gap to center
						cout << i << "|";
						for (int j = 0; j < 3; ++j) 
						{	
							if(matrix[i][j]=='X')
							cout<<" "<<"\033[31m"<< matrix[i][j]<<"\033[35m"<<" |";
							else if(matrix[i][j]=='O')
							cout<<" "<<"\033[34m"<< matrix[i][j]<<"\033[35m"<<" |";
							else
							cout << " " << matrix[i][j] << " |";
						}
						cout << endl;
						cout << "                                                  ";//gap to center
						cout << " +---+---+---+" << endl;
					}
				}

				void changeplayer() 
				{
					player = (player == 'X') ? 'O' : 'X';
				}

				char getplayer() const 
				{
					return player;
				}

				bool makemove(int x, int y) 
				{
					if (x >= 0 && y >= 0 && x < 3 && y < 3 && matrix[x][y] == ' ') 
					{
						matrix[x][y] = player;
						return true;
					}
					return false;
				}

				virtual bool winner() = 0;
    };

    class ttt : public board 
    {
    public: bool winner();
    };

    bool ttt::winner() 
    {
        for (int i = 0; i < 3; i++) 
        {
            if ((matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player) ||
                (matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == player)) 
                {return true;}
        }
        if ((matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player) ||
            (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player)) 
            {return true;}
        return false;
    }
}
