#include <iostream>
#include <cmath>
using namespace std;

class gameManager {

private:
    bool whitesTurn = true;
    int moveCount = 0;

    //To help with check + checkmate
    int blackKingRow = 7;
    int blackKingCol = 4;
    int whiteKingCol= 0;
    int whiteKingRow = 4;

    Pieces board[8][8] = {
            Pieces(BLACK, 1, ROOK, 7, 0), Pieces(BLACK, 0, KNIGHT, 7, 1),   Pieces(BLACK, 0, BISHOP, 7, 2), Pieces(BLACK, 0, QUEEN, 7, 3),  Pieces(BLACK, 0, KING, 7, 4),   Pieces(BLACK, 0, BISHOP, 7, 5), Pieces(BLACK, 0, KNIGHT, 7, 6), Pieces(BLACK, 2, ROOK, 7, 7),
            Pieces(BLACK, 0, PAWN, 6, 0), Pieces(BLACK, 0, PAWN,   6, 1),   Pieces(BLACK, 0, PAWN,   6, 2), Pieces(BLACK, 0, PAWN,  6, 3),  Pieces(BLACK, 0, PAWN, 6, 4),   Pieces(BLACK, 0, PAWN,   6, 5), Pieces(BLACK, 0, PAWN,   6, 6), Pieces(BLACK, 0, PAWN, 6, 7),
            Pieces(NONE, 0, BLANK, 5, 0), Pieces(NONE, 0, BLANK,   5, 1),   Pieces(NONE, 0, BLANK,   5, 2), Pieces(NONE, 0, BLANK,  5, 3),  Pieces(NONE, 0, BLANK, 5, 4),   Pieces(NONE, 0, BLANK,   5, 5), Pieces(NONE, 0, BLANK,   5, 6), Pieces(NONE, 0, BLANK, 5, 7),
            Pieces(NONE, 0, BLANK, 4, 0), Pieces(NONE, 0, BLANK,   4, 1),   Pieces(NONE, 0, BLANK,   4, 2), Pieces(NONE, 0, BLANK,  4, 3),  Pieces(NONE, 0, BLANK, 4, 4),   Pieces(NONE, 0, BLANK,   4, 5), Pieces(NONE, 0, BLANK,   4, 6), Pieces(NONE, 0, BLANK, 4, 7),
            Pieces(NONE, 0, BLANK, 3, 0), Pieces(NONE, 0, BLANK,   3, 1),   Pieces(NONE, 0, BLANK,   3, 2), Pieces(NONE, 0, BLANK,  3, 3),  Pieces(NONE, 0, BLANK, 3, 4),   Pieces(NONE, 0, BLANK,   3, 5), Pieces(NONE, 0, BLANK,   3, 6), Pieces(NONE, 0, BLANK, 3, 7),
            Pieces(NONE, 0, BLANK, 2, 0), Pieces(NONE, 0, BLANK,   2, 1),   Pieces(NONE, 0, BLANK,   2, 2), Pieces(NONE, 0, BLANK,  2, 3),  Pieces(NONE, 0, BLANK, 2, 4),   Pieces(NONE, 0, BLANK,   2, 5), Pieces(NONE, 0, BLANK,   2, 6), Pieces(NONE, 0, BLANK, 2, 7),
            Pieces(WHITE, 0, PAWN, 1, 0), Pieces(WHITE, 0, PAWN,   1, 1),   Pieces(WHITE, 0, PAWN,   1, 2), Pieces(WHITE, 0, PAWN,  1, 3),  Pieces(WHITE, 0, PAWN, 1, 4),   Pieces(WHITE, 0, PAWN,   1, 5), Pieces(WHITE, 0, PAWN,   1, 6), Pieces(WHITE, 0, PAWN, 1, 7),
            Pieces(WHITE, 0, ROOK, 0, 0), Pieces(WHITE, 0, KNIGHT, 0, 1),   Pieces(WHITE, 0, BISHOP, 0, 2), Pieces(WHITE, 0, QUEEN, 0, 3),  Pieces(WHITE, 0, KING, 0, 4),   Pieces(WHITE, 0, BISHOP, 0, 5), Pieces(WHITE, 0, KNIGHT, 0, 6), Pieces(WHITE, 0, ROOK, 0, 7),
    };

public:
    // constructor
    gameManager() {
        
    }

    bool isItWhitesTurn() {                 // not yet operated // 
        return whitesTurn;
    }

    void changeTurn() {
        whitesTurn = !whitesTurn;
    }

    void printBoard() {
        cout << "  -------------------------";
        cout << endl;
        for (int i = 0; i < 8; i++) {
            cout << 7 - i + 1 << " |";
            for (int j = 0; j < 8; j++) {
                piece piecetype = board[i][j].getPiece();  // adding coordinates later today 
                color colortype = board[i][j].getColor();

                //below can be used of check of piece 
                    // if peicetype called at coordinates x,y 
                    // to be continued - push coming tonight 
                
                char symbol = ' '; // Default for empty space

                switch (piecetype) {
                case PAWN: symbol = 'P';
                    break;
                case ROOK: symbol = 'R'; 
                    break;
                case KNIGHT: symbol = 'N';  // ect.    // 
                    break;
                case BISHOP: symbol = 'B'; // bishop 
                    break;
                case QUEEN: symbol = 'Q'; // queen
                    break;
                case KING: symbol = 'K'; // king
                    break;
                case BLANK: symbol = ' '; // representing blank 
                    break;
                  // above can be usful for checking 
                }
                char colorSymbol = ' '; // default value for color
                if(colortype == WHITE)
                    colorSymbol = 'W';
                if(colortype == BLACK)
                    colorSymbol = 'B';
                cout << colorSymbol << symbol << '|';
              
            }
            cout << endl;
            cout << "  -------------------------";
            cout << endl;
        }
        cout << "   a  b  c  d  e  f  g  h" << endl;
    }

    //This shows the values of the getRow and getColumn Function of the Pieces Value.
    // AKA it shows where every piece "thinks" it is 
    void printBoardTEST() {
        cout << "-------------------------";
        cout << endl;
        for (int i = 0; i < 8; i++) {
            cout << '|';
            for (int j = 0; j < 8; j++) {
                Pieces piecetype = board[i][j];  // adding coordinates later today 
                color colortype = board[i][j].getColor();

                cout << piecetype.getColumn() << piecetype.getRow() << '|';

              
            }
            cout << endl;
            cout << "-------------------------";
            cout << endl;
        }
    }

        /// <summary>
        /// ///////////dany edit above naming peices others for alternative, below movement of peice from a certian positon - who ever doing movement let me see what u got planned please :
        /// </summary>

    void coordbypeicenum(int piece_number) {

    }

    void movePiece(int intColumnOfPieceToMove, int rowOfPieceToMove, int intColumnOfPieceToGoTo, int rowOfPieceToGoTo){
        
        /*Created a temp object to deep copy after replacing the piece to go to with the piece that wanted to move*/
        /*Not space efficient but also created a blank object in case of takes*/

        // the problem with this is that the row and column data inside the piece objects are not accurate.

        Pieces tempObj;
        
        tempObj.setColor(board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].getColor());
        tempObj.setPiece(board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].getPiece());
        Pieces blankObj(NONE, 0, BLANK, 7 - rowOfPieceToMove, intColumnOfPieceToMove);

        //if it is white turn and the piece at the desired spot to move at is black, then replace the black piece with the white piece
        //then replace the spot the white piece was with a blank space.
        if(board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].getColor() == BLACK && whitesTurn){
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo] = board[7 - rowOfPieceToMove][intColumnOfPieceToMove];
            board[7 - rowOfPieceToMove][intColumnOfPieceToMove] = blankObj;
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].has_moved = true;
        }
        //vice versa
        else if(board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].getColor() == WHITE && !whitesTurn){
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo] = board[7 - rowOfPieceToMove][intColumnOfPieceToMove];
            board[7 - rowOfPieceToMove][intColumnOfPieceToMove] = blankObj;
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].has_moved = true;
        }
        //if the piece just moves to a blank space 
        else{
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].setColor(board[7 - rowOfPieceToMove][intColumnOfPieceToMove].getColor());
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].setPiece(board[7 - rowOfPieceToMove][intColumnOfPieceToMove].getPiece());
            

            board[7 - rowOfPieceToMove][intColumnOfPieceToMove].setColor(tempObj.getColor());  
            board[7 - rowOfPieceToMove][intColumnOfPieceToMove].setPiece(tempObj.getPiece());  

            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].has_moved = true;
        }
        
    }


        // do we want one string containing the move to be the argument (like now), or for the main to parse it, and pass row, column, piece, as arguments?
    void attemptMove(int columnPieceThatsMoving, int rowPieceThatsMoving, int columnItGoesTo, int rowItGoesTo){
            //more methods in here? one for each piece?
            /*
            
            if(check_available()){
                Pieces tempBlank(NONE, 0, BLANK, rowPieceThatsMoving, columnPieceThatsMoving);
                board[columnItGoesTo][rowItGoesTo] = board[columnPieceThatsMoving][rowPieceThatsMoving];
                board[columnPieceThatsMoving][rowPieceThatsMoving] = tempBlank;
                changeTurn();
            }

            */
        }
    
    bool isCheck(color kingColor){

        int searchRow;
        int searchCol;

        int originRow;
        int originCol;

        if (kingColor == WHITE) {
             searchCol, originCol = whiteKingCol;
             searchRow, originRow = whiteKingRow;

        }
        
        if (kingColor == BLACK) {
             searchCol = blackKingCol;
             searchRow = blackKingRow;
        }
        //For all 8 directions
        struct Direction {
            int ypos;
            int xpos;

            Direction (int x, int y) : ypos(y), xpos(x) {}

        };

        Direction directions[] = {
            Direction(1, 0),   // Right
            Direction(1, 1),   // Right-Up
            Direction(0, 1),   // Up
            Direction(-1, 1),  // Left-Up
            Direction(-1, 0),  // Left
            Direction(-1, -1), // Left-Down
            Direction(0, -1),  // Down
            Direction(1, -1)
        };
        
        for (const auto& dir : directions) {
            while ((searchRow + dir.ypos >= 0 && searchRow + dir.ypos < 8) && (searchCol + dir.xpos >= 0 && searchCol + dir.xpos < 8)) {
                 searchCol += dir.xpos;
                 searchRow += dir.ypos;

                 if(board[searchRow][searchCol].getColor() != board[originRow][originCol].getColor()) {
                     if(check_available(searchRow,searchCol,blackKingRow,blackKingCol))
                        return true;
                 }
            }
       

        
       
    }
     return false;
    }

    bool isCheckmate() {

        return false;
    }
  
    bool isStalemate() {

        return false;
    }

    bool check_available(int rowPieceThatsMoving, int columnPieceThatsMoving, int rowItGoesTo, int columnItGoesTo){
            Pieces& currentPiece = board[7 - rowPieceThatsMoving][columnPieceThatsMoving];
            // if the piece being moved is empty
            if(currentPiece.getPiece() == BLANK){
                return false;
            }
            //if the piece being moved is not that players turn
            if(currentPiece.getColor() == WHITE && !whitesTurn){
                return false;
            }
            if(currentPiece.getColor() == BLACK && whitesTurn){
                return false;
            }
            //if the piece being moved is trying to takes its own piece 
            if(currentPiece.getColor() == board[7 - rowItGoesTo][columnItGoesTo].getColor()){
                return false;
            }
            

            //Pawns
            if(currentPiece.getPiece() == PAWN){
                
                // return false if they want to move the pawn left and right
                //this also let the pawn to take piece diagonally from them
                if(columnItGoesTo != columnPieceThatsMoving && board[7 - rowItGoesTo][columnItGoesTo].getPiece() == BLANK){
                    return false;
                }

                

                // checks if the desired spot is the spot behind the current piece
                if(whitesTurn){
                    if(rowItGoesTo < currentPiece.getRow()){
                    return false;
                    }
                }
                
                else{
                    if(rowItGoesTo > currentPiece.getRow()){
                    return false;
                    }
                }
                
                // If it is white's turn and there is a piece in front of the pawn, return false 
                if(whitesTurn){
                    if(board[6 - rowPieceThatsMoving][columnPieceThatsMoving].getPiece() != BLANK){
                    return false;
                    }
                }
                //else it is black's turn and if there is a piece in front of a black piece, return false
                else{
                    if(board[8 - rowPieceThatsMoving][columnPieceThatsMoving].getPiece() != BLANK){
                    return false;
                    }
                }

             
                // If the piece has not moved, it cannot move more than two spots or diagonal 
                if(currentPiece.has_moved == false){
                    if(whitesTurn){
                       if(rowItGoesTo > currentPiece.getRow() + 2 || columnItGoesTo != columnPieceThatsMoving)
                        {
                            return false;
                        }    
                    }
                    else{
                        if(rowItGoesTo < currentPiece.getRow() - 2 || columnItGoesTo != columnPieceThatsMoving)
                        {
                            return false;
                        }  
                    }
                    
                }

                // implement a check if the piece hasn't moved and they cannot take a piece in the second spot.
                // if there is a piece at the second spot and the piece that wants to move has not moved, return false
                if(currentPiece.has_moved == false){
                    if(whitesTurn){
                        if(board[5 - rowPieceThatsMoving][columnPieceThatsMoving].getPiece() != BLANK){
                        return false;
                        }
                    }   
                //else it is black's turn and if there is a piece in front of a black piece, return false
                    else{
                        if(board[9 - rowPieceThatsMoving][columnPieceThatsMoving].getPiece() != BLANK){
                        return false;
                        }
                }
                }

                // If the piece has moved, it cannot move more than two spots 
                if(currentPiece.has_moved){
                    if(whitesTurn){
                       if(rowItGoesTo >= rowPieceThatsMoving + 2)
                        {
                            return false;
                        }    
                    }
                    else{
                        if(rowItGoesTo <= rowPieceThatsMoving - 2)
                        {
                            return false;
                        }  
                    }
                    
                }
                
                return true;
                
            }

            //rooks
            if(currentPiece.getPiece() ==  ROOK){

                //checks for diagonal
                if(currentPiece.getColumn() - columnItGoesTo != 0 &&
                   currentPiece.getRow() - rowItGoesTo != 0){
                    return false;
                }

                //if rows are changing and columns are not 
                if(currentPiece.getColumn() - columnItGoesTo == 0){
                    if(currentPiece.getRow() < rowItGoesTo){
                        for(int i = currentPiece.getRow() + 1; i < rowItGoesTo; i++)
                            if(board[7 - i][columnItGoesTo].getPiece() != BLANK){
                                return false;
                        }
                    }                    
                }
                //if rows are changing and columns are not
                //other direction
                if(currentPiece.getColumn() - columnItGoesTo == 0){
                    if(currentPiece.getRow() > rowItGoesTo){
                        for(int i = rowItGoesTo; i < currentPiece.getRow(); i++)
                            if(board[7 - i][columnItGoesTo].getPiece() != BLANK){
                                return false;
                        }
                    }
                }
                //if columns are changing and rows are not 
                if(currentPiece.getRow() - rowItGoesTo == 0){
                    if(currentPiece.getColumn() < columnItGoesTo){
                        for(int i = currentPiece.getColumn() + 1; i < columnItGoesTo; i++)
                            if(board[7 - currentPiece.getRow()][i].getPiece() != BLANK){
                                return false;
                        }
                    }   
                }
                //other direction
                if(currentPiece.getRow() - rowItGoesTo == 0){
                    if(currentPiece.getColumn() > columnItGoesTo){
                        for(int i = columnItGoesTo; i < currentPiece.getColumn(); i++)
                            if(board[7 - currentPiece.getRow()][i].getPiece() != BLANK){
                                return false;
                        }
                    }
                }
                return true;
            }

            //bishops
            if(currentPiece.getPiece() ==  BISHOP){

                int desired_x_space = columnItGoesTo;
                int desired_y_space = rowItGoesTo;
                int x_spaces = currentPiece.getColumn() - desired_x_space;
                int y_spaces = currentPiece.getRow() - desired_y_space;

                if(abs(x_spaces) == abs(y_spaces)){//CHECK TO MAKE SURE THAT WE ARE MOVING DIAGONALLY
                //we need to increment the x coord and the y coord at the same time so that it why initizalied both the i and the j
                // we are checking the desired row is less than or greater than the row we are currently on and same goes for the column                       
                    for(int i = currentPiece.getRow(), j = currentPiece.getColumn(); i < desired_x_space ? (i < x_spaces):(i > x_spaces),
                                j < desired_y_space ? (j < desired_y_space):(j > desired_y_space); i += (x_spaces > 0)  ? 1:-1, j += (y_spaces > 0)  ? 1:-1){ //CONDITIONAL FOR LOOP IDK HOW IT FULLY WORKS TBH
                        //CONDITIONAL FOR LOOP IDK HOW IT FULLY WORKS TBH
                            try{
                                //WE WE CAN MOVE TO A SPACE IF OUR COLOR DOES MATCH THE PIECE THAT IS ON THE SPACE.
                                //IF NOTHING IS THERE WE CAN JUST MOVE THEIR IF IT IS THE OPPOSING COLOR THAT MEANS WE CAN ATTACK
                                if(board[i][j].getColor() != currentPiece.getColor()){                                
                                    if(board[i][j].getColor() != NONE){
                                        //THIS MEANS THAT WE ARE ATTACKING ADD IN THE ATTACKING CODE HERE
                                        return true; //TEMP
                                    }
                                    else{
                                        //THIS MEANS THE SPACE WE WANT TO MOVE TO HAS NO PIECE ON IT. IT IS VALID TO MOVE THERE
                                        
                                    }                            
                                }
                                //WE ENTER THIS IF WE FIND OUT THAT THERE IS A PIECE IN THE PATH OF WHERE WE WANT TO MOVE 
                                else{
                                    
                                    throw out_of_range("puss");
                                }  
                            }
                            catch(out_of_range){
                                return false;
                            }
                    }
                
                }
            return true;
            }  
            //queens
            if(currentPiece.getPiece() == QUEEN){ //TODO
                int desired_x_space = columnItGoesTo;
                int desired_y_space = rowItGoesTo;
                int x_spaces = currentPiece.getColumn() - desired_x_space;
                int y_spaces = currentPiece.getRow() - desired_y_space;

                //THE ROOK PART OF THE QUEEN slay pur pur
                //if rows are changing and columns are not 
                                //checks for diagonal
                if(currentPiece.getColumn() - columnItGoesTo != 0 &&
                   currentPiece.getRow() - rowItGoesTo != 0){
                    return false;
                }

                //if rows are changing and columns are not 
                if(currentPiece.getColumn() - columnItGoesTo == 0){
                    if(currentPiece.getRow() < rowItGoesTo){
                        for(int i = currentPiece.getRow() + 1; i < rowItGoesTo; i++)
                            if(board[7 - i][columnItGoesTo].getPiece() != BLANK){
                                return false;
                        }
                    }                    
                }
                //if rows are changing and columns are not
                //other direction
                if(currentPiece.getColumn() - columnItGoesTo == 0){
                    if(currentPiece.getRow() > rowItGoesTo){
                        for(int i = rowItGoesTo; i < currentPiece.getRow(); i++)
                            if(board[7 - i][columnItGoesTo].getPiece() != BLANK){
                                return false;
                        }
                    }
                }
                //if columns are changing and rows are not 
                if(currentPiece.getRow() - rowItGoesTo == 0){
                    if(currentPiece.getColumn() < columnItGoesTo){
                        for(int i = currentPiece.getColumn() + 1; i < columnItGoesTo; i++)
                            if(board[7 - currentPiece.getRow()][i].getPiece() != BLANK){
                                return false;
                        }
                    }   
                }
                //other direction
                if(currentPiece.getRow() - rowItGoesTo == 0){
                    if(currentPiece.getColumn() > columnItGoesTo){
                        for(int i = columnItGoesTo; i < currentPiece.getColumn(); i++)
                            if(board[7 - currentPiece.getRow()][i].getPiece() != BLANK){
                                return false;
                        }
                    }
                }
                return true;

                //the bishop part of the queen
                if(abs(x_spaces) == abs(y_spaces)){//CHECK TO MAKE SURE THAT WE ARE MOVING DIAGONALLY
                //we need to increment the x coord and the y coord at the same time so that it why initizalied both the i and the j
                // we are checking the desired row is less than or greater than the row we are currently on and same goes for the column                       
                    for(int i = currentPiece.getRow(), j = currentPiece.getColumn(); i < desired_x_space ? (i < x_spaces):(i > x_spaces),
                                j < desired_y_space ? (j < desired_y_space):(j > desired_y_space); i += (x_spaces > 0)  ? 1:-1, j += (y_spaces > 0)  ? 1:-1){ //CONDITIONAL FOR LOOP IDK HOW IT FULLY WORKS TBH
                        //CONDITIONAL FOR LOOP IDK HOW IT FULLY WORKS TBH
                            try{
                                //WE WE CAN MOVE TO A SPACE IF OUR COLOR DOES MATCH THE PIECE THAT IS ON THE SPACE.
                                //IF NOTHING IS THERE WE CAN JUST MOVE THEIR IF IT IS THE OPPOSING COLOR THAT MEANS WE CAN ATTACK
                                if(board[i][j].getColor() != currentPiece.getColor()){                                
                                    if(board[i][j].getColor() != NONE){
                                        //THIS MEANS THAT WE ARE ATTACKING ADD IN THE ATTACKING CODE HERE
                                        return true; //TEMP
                                    }
                                    else{
                                        //THIS MEANS THE SPACE WE WANT TO MOVE TO HAS NO PIECE ON IT. IT IS VALID TO MOVE THERE
                                        
                                    }                            
                                }
                                //WE ENTER THIS IF WE FIND OUT THAT THERE IS A PIECE IN THE PATH OF WHERE WE WANT TO MOVE 
                                else{
                                    
                                    throw out_of_range("puss");
                                }  
                            }
                            catch(out_of_range){
                                return false;
                            }
                    }
                
                }
            return true;
            
            }       
            //knights 
            if(currentPiece.getPiece() == KNIGHT){ 
                int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};   
                int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
                for(int i = 0; i <= 7; i++){
                    if(currentPiece.getRow() + dx[i] == rowItGoesTo &&
                       currentPiece.getColumn() + dy[i] == columnItGoesTo){
                        return true;
                    }
                }
                return false;
            }
            //kings
            if(currentPiece.getPiece() ==  KING){ 
                if(abs(currentPiece.getRow() - rowItGoesTo) <= 1 &&
                   abs(currentPiece.getColumn() - columnItGoesTo <= 1))
                   {
                        return true;
                   }
                else if(false /* attempts castle */){

                }
                return false;

            }
            if(currentPiece.getPiece() == PAWN){

                return true;       
            }

        abort();  
        }

    // these two are mostly for testing
    void incMoveCount() {
        moveCount++;
    }

    int getMoveCount() {
        return moveCount;
    }

    void printBoardSpaces(){
        cout << "-------------------------";
        cout << endl;
        for (int i = 0; i < 8; i++) {
            cout << '|';
            for (int j = 0; j < 8; j++) {
                cout << char(j + 97) << abs(i - 7) + 1 << '|';
            }
            cout << endl;
            cout << "-------------------------";
            cout << endl;
        }
    }
};
