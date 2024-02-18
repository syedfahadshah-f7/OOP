#include <iostream>
using namespace std;

class ChessPiece {
private:
    string name, color;
    char symbol;

    

public:
    ChessPiece() {
        name = "pawn", color = "white", symbol = 'P';
    }

    ChessPiece(string n, string col, char sym) {
        name = n, color = col, symbol = sym;
    }

    void setName(string n) {
        name = n;
    }

    void setColor(string col) {
        color = col;
    }

    void setSymbol(char sym) {
        symbol = sym;
    }

    string getName() {
        return name;
    }

    string getColor() {
        return color;
    }

    char getSymbol() {
        return symbol;
    }

};

class ChessBoard {
public:
    ChessPiece boardPieces[8][8];

    ChessBoard() {
        // for white pieces
        for (int i = 0; i < 8; i++) {
            boardPieces[1][i] = ChessPiece("Pawn", "white", 'p');
        }
        boardPieces[0][0] = ChessPiece("Rook", "white", 'r');
        boardPieces[0][1] = ChessPiece("Knight", "white", 'n');
        boardPieces[0][2] = ChessPiece("Bishop", "white", 'b');
        boardPieces[0][3] = ChessPiece("Queen", "white", 'q');
        boardPieces[0][4] = ChessPiece("King", "white", 'k');
        boardPieces[0][5] = ChessPiece("Bishop", "white", 'b');
        boardPieces[0][6] = ChessPiece("Knight", "white", 'n');
        boardPieces[0][7] = ChessPiece("Rook", "white", 'r');

        // for black pieces
        for (int i = 0; i < 8; i++) {
            boardPieces[6][i] = ChessPiece("Pawn", "black", 'P');
        }
        boardPieces[7][0] = ChessPiece("Rook", "black", 'R');
        boardPieces[7][1] = ChessPiece("Knight", "black", 'N');
        boardPieces[7][2] = ChessPiece("Bishop", "black", 'B');
        boardPieces[7][3] = ChessPiece("Queen", "black", 'Q');
        boardPieces[7][4] = ChessPiece("King", "black", 'K');
        boardPieces[7][5] = ChessPiece("Bishop", "black", 'B');
        boardPieces[7][6] = ChessPiece("Knight", "black", 'N');
        boardPieces[7][7] = ChessPiece("Rook", "black", 'R');

        // Initialize empty spaces
        for (int i = 2; i <= 5; i++) {
            for (int j = 0; j < 8; j++) {
                boardPieces[i][j] = ChessPiece("", "", '.');
            }
        }
    }

    void movePiece(string source, string destination) {
        //converting  source and destination location in axes form
        int sx,sy,dx, dy;
        sx = source[1]-'0';
        sy = source[0]-'0'-48;
        dx = destination[1]-'0';
        dy = destination[0] -'0'-48;

        // checking movement for Pawn
       if(boardPieces[dx][dy].getSymbol() == '.') {
            if(boardPieces[sx][sy].getName() == "Pawn"){
                if(abs(dx-sx) <=2 && dy == sy && (dx-sx) >0){
                    boardPieces[dx][dy] = boardPieces[sx][sy];
                    boardPieces[sx][sy]= ChessPiece("","",'.');
                    display();
                }else{
                    cout<<" Move can not be possible"<< endl;
                }
            }
        // checking movement for knight
            sy--;dy--;
            if(boardPieces[sx][sy].getName() == "Knight"){
                    if(abs(dx-sx) ==2 && (dy == sy+1)){
                    boardPieces[dx][dy] = boardPieces[sx][sy];
                    boardPieces[sx][sy]= ChessPiece("","",'.');
                        display();
                        
                    }
                    else{
                        cout<<" Move can not be possible"<< endl;
                    }
                }
                
            }
       else{
            cout<<" Move can not be possible"<< endl;
       }
    }       

    void display() {
        //displaying boared
        cout<<"  a  b  c  d  e  f  g  h  "<<endl;
        for (int i = 0; i < 8; i++) {
            cout<<i+1<<" ";
            for (int j = 0; j < 8; j++) {
                cout << boardPieces[i][j].getSymbol() << "  ";
            }
            cout<<i+1<<" ";
            cout << endl;
        }
        cout<<"  a  b  c  d  e  f  g  h  "<<endl;
        cout<<endl<<endl;
    }
    
};

int main() {
    ChessBoard obj;
    obj.display();
    cout<<"MOVE FOR WHITE PAWN  "<<endl<<endl;
    obj.movePiece("c1","c3");
    cout<<"MOVE FOR BLACK KNIGHT  "<<endl<<endl;
    obj.movePiece("b7","c5");
}
