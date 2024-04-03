#include <iostream>
#include <cmath>
using namespace std;

class gameManager {

private:
    bool whitesTurn = true;
    int moveCount = 0;
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
        cout << "-------------------------";
        cout << endl;
        for (int i = 0; i < 8; i++) {
            cout << '|';
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
            cout << "-------------------------";
            cout << endl;
        }
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

        Pieces tempObj = board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo];
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
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo] = board[7 - rowOfPieceToMove][intColumnOfPieceToMove];
            board[7 - rowOfPieceToMove][intColumnOfPieceToMove] = tempObj;  
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
    
    bool isCheck(){

        return false;
    }

    bool isCheckmate() {

        return false;
    }
  
    bool isStalemate() {

        return false;
    }

    bool check_available(int initialx, int initialy, int desired_x_space, int desired_y_space){
            Pieces& currentPiece = board[initialx][initialy];
            if(currentPiece.getPiece() == BLANK){
                return false;
            }
            int x_spaces = currentPiece.getRow() - desired_x_space;
            int y_spaces = currentPiece.getColumn() - desired_y_space;
            if(currentPiece.getPiece() ==  ROOK){
                if((x_spaces != y_spaces) && ((x_spaces > 0) || (y_spaces > 0)))
                for(int i = currentPiece.getRow();  (i < x_spaces); i += (x_spaces > 0)  ? 1:-1){
                    try{
                        if((board[i][currentPiece.getColumn()].getColor() != currentPiece.getColor())){
                                if(board[i][currentPiece.getColumn()].getColor() != NONE){
                                    return true;
                                }
                        }
                        else{
                            
                            throw out_of_range("puss");
                        }  
                    }
                    catch(out_of_range){
                        return false;
                    }
                }
                for(int i = currentPiece.getRow();  (i < y_spaces); i += (y_spaces > 0)  ? 1:-1){
                    try{
                        if((board[i][currentPiece.getColumn()].getColor() != currentPiece.getColor())){
                                if(board[i][currentPiece.getColumn()].getColor() != NONE){
                                    return true;
                                }
                            }
                        else{
                            
                            throw out_of_range("puss");
                        }  
                    }
                    catch(out_of_range){
                        return false;
                    }
                }
            return true;
            }
            if(currentPiece.getPiece() ==  BISHOP){
                if(abs(x_spaces) == abs(y_spaces)){
                    int i = currentPiece.getRow();
                    int j = currentPiece.getRow();
                for(; (i < x_spaces); i += (x_spaces > 0)  ? 1:-1){
                    for(;  (j < y_spaces); j += (y_spaces > 0)  ? 1:-1){
                        try{
                            if(board[i][j].getColor() != currentPiece.getColor()){                                
                                if(board[i][j].getColor() != NONE){
                                    return true;
                                }                            
                            }
                            else{
                                
                                throw out_of_range("puss");
                            }  
                        }
                        catch(out_of_range){
                            return false;
                        }
                        break;
                    }
                }
                
                }
            return true;
            } 
            if(currentPiece.getPiece() == QUEEN){ //TODO
                //THE ROOK PART OF THE QUEEN slay pur pur
                if((x_spaces != y_spaces) && ((x_spaces > 0) || (y_spaces > 0))){
                    //UNSURE IF WE NEED <= OR < WE NEED TO CHECK THE DESIRED SPACE THAT THE PIECE WANTS TO MOVE SO I THINK IT IS <= 
                    //LETS SAY OUR DESIRED ROW IS 5 AND OUR PIECE IS ON 3 THAT WOULD MEAN i is less our desired_x_space 
                    //so we will run this for loop until i is greater than desired_x_space 
                    //x_spaces is = to the difference between our desired row and our current row so in this Example x_spaecs = 2
                    //2 is greater than 0 so we will increase our current row by 1 moving us closer to our desired_x_space
                    //Visa versa if in desired row is less than our current row
                    for(int i = currentPiece.getRow();  i < desired_x_space ? (i < desired_x_space): (i > desired_x_space); i += (x_spaces > 0)  ? 1:-1){ 
                        try{
                            //WE WE CAN MOVE TO A SPACE IF OUR COLOR DOES MATCH THE PIECE THAT IS ON THE SPACE.
                            if((board[i][currentPiece.getColumn()].getColor() != currentPiece.getColor())){
                                if(board[i][currentPiece.getColumn()].getColor() != NONE){
                                    return true;
                                }
                            }
                            else{
                                
                                throw out_of_range("puss");
                            }  
                        }
                        catch(out_of_range){
                            return false;
                        }
                    }
                    
                    //Same thing as row explaination but with the word row swapped with column
                    for(int i = currentPiece.getColumn();  i < desired_y_space ? (i < desired_y_space): i > desired_y_space; i += (y_spaces > 0)  ? 1:-1){                        
                        try{
                            //WE WE CAN MOVE TO A SPACE IF OUR COLOR DOES MATCH THE PIECE THAT IS ON THE SPACE.
                            if((board[i][currentPiece.getColumn()].getColor() != currentPiece.getColor())){
                                //IF NOTHING IS THERE WE CAN JUST MOVE THEIR IF IT IS THE OPPOSING COLOR THAT MEANS WE CAN ATTACK
                                if(board[i][currentPiece.getColumn()].getColor() != NONE){
                                    return true;
                                }
                            }
                            else{
                                
                                throw out_of_range("puss");
                            }  
                        }
                        catch(out_of_range){
                            return false;
                        }
                    }
                }
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
            if(currentPiece.getPiece() == KNIGHT){ //TODO
                int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};   
                int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
                for(int i = 0; i < 8; i++){
                    //IF THE PLACE THEY WANT TO MOVE TO FOLLOWS ONE OF THE PATTERNS  ABOVE THEY ARE GOOD TO MOVE THERE
                    if((desired_x_space == currentPiece.getRow() + dx[i]) && (desired_y_space == currentPiece.getColumn() + dy[i])) {
                        if(board[currentPiece.getRow()+dx[i]][currentPiece.getColumn() + dy[i]].getColor() != currentPiece.getColor()){
                            if(board[currentPiece.getRow()+dx[i]][currentPiece.getColumn() + dy[i]].getColor() != NONE){
                                //THIS MEANS THAT THE PIECE CAN ATTACK THE ENEMY PIECE ADD THE ATTACKING CODE HERE
                                return true;
                            }
                            //THIS MEANS THAT THEY ARE JUST MOVING TO THE OTHER SQUARE
                            else{ 
                                return  true; 
                            }
                            //THIS MEANST THAT THE PLACE THEY WANTED TO MOVE TO WAS OCCUPIED BY A FRIENDLY 
                            return false;
                        }
                            
                    }
                }
                    
            }
            if(currentPiece.getPiece() ==  KING){ // the king is only allowed to move one square at a time so that is what this is
                if( (abs(x_spaces) <= 1) && abs(y_spaces <= 1)){

                }
                //IF THE CURRENT PIECE IS BLACK WE CHECK TO SEE IF IT IS ON THE 8th FILE AND IF IT IS WHITE WE CHECK TO SEE IF IT IS ON THE 1ST FILE
                //THEN WE CHECK TO MAKE SURE WE ARE STARTING ON THE RIGHT SPOT 
                // WE THEN CHECK TO MAKE SURE THAT THE PIECE HAS NOT MOVED WHICH KIND OF MAKES EVERYTHING BEFORE USELESS
                //THEN WE MAKE SURE THE DESIRED SPOT IS TWO SPACES AWAY BECAUSE THAT IS WHAT CASTLING IS 
                else if ((((currentPiece.getColor() == BLACK && currentPiece.getColumn() == 8) || (currentPiece.getColor() == WHITE && currentPiece.getColumn() == 1)) 
                && ( currentPiece.getColumn() == 5)) && (currentPiece.has_moved == false) && (abs(x_spaces) == 2) && isCheck(/*currentPiece,desired_x_space,desired_y_space*/) == false)
                {
                    for(int i = currentPiece.getRow();  i < desired_x_space ? (i < desired_x_space): (i > desired_x_space); i += (x_spaces > 0)  ? 1:-1){
                        try{
                            if(board[i][currentPiece.getColumn()].getPiece() != BLANK){
                                throw out_of_range("DUMB");
                                return false;
                            }
                            else{

                            }
                        }
                        catch (out_of_range){
                            return false;
                        }
                    }
                    return true;
                }
                
            }
            return true;
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
