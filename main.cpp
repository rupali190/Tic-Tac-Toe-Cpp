#include<iostream>
using namespace std;
char board[3][3] = {
                   {'1','2','3'},
                   {'4','5','6'},
                   {'7','8','9'}};
char current;
int current_player;
void draw()
{
    cout<<"\n==================================\n";
    cout<< "    TIC TAC TOE                    \n";
    cout<<"\n==================================\n";
    cout<<"       |     |      \n";
    cout<<"    "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
        cout<<"       |     |      \n";
        cout<<"       |     |      \n";
    cout<<"    "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
        cout<<"       |     |     \n";    
        cout<<"       |     |     \n";
    cout<<"    "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";         
}
bool marker(int slot)
{
    int row=(slot-1)/3;
    int col=(slot-1)%3;
    if(board[row][col]!='X' && board[row][col]!='O')
    {
        board[row][col]=current;
        return true;
    }
    else{
        return false;
    }
}
bool winner()
{
    //row
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1]&& board[i][1]==board[i][2])
        {
            return true;
        }
    }
    //col
    for(int i=0;i<3;i++)
    {
        if(board[0][i]==board[1][i]&& board[1][i]==board[2][i])
        {
            return true;
        }
    }
    //diagonal
        if(board[0][0]==board[1][1]&& board[1][1]==board[2][2])
        {
            return true;
        }
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        {
            return true;
        }
        return false;
    
}
int game()
{
    int win = 0;
    int slot;
    char symbol;
    cout << "Player 1, choose your marker (X or O): ";
    cin >> symbol;
    symbol = toupper(symbol);
    
    current = symbol;
    current_player = 1;
    
    for (int i = 0; i < 9; i++) {
        draw();
        cout << "Player " << current_player << " (" << current << "), enter your slot (1-9): ";
        cin >> slot;
        
        if (slot < 1 || slot > 9 || !marker(slot)) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }
        
        if (winner()) {
            draw();
            cout << "\nPlayer " << current_player << " wins!\n";
            return 0;
        }
        
        // Swap player logic
        if (current == 'X') current = 'O';
        else current = 'X';
        
        current_player = (current_player == 1) ? 2 : 1;
    }
    
    draw();
    cout << "\nIt's a tie!\n";
    return 0;
}

int main() {
    game();
    return 0;
}
