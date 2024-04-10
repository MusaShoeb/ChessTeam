#include <iostream>
#include <cmath>
#include <vector>
#include "piece.h"
#include "board.h"
using namespace std;

    // constructor
    gameManager::gameManager() {
        
    }
    //copy constructor
    gameManager::gameManager(gameManager& other){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j <= 7; j++){
                board[i][j] = other.board[i][j];
            }
        }
    }

    bool gameManager:: isItWhitesTurn() {                 // not yet operated // 
        return whitesTurn;
    }

    void gameManager::changeTurn() {
        whitesTurn = !whitesTurn;
    }

    void gameManager::printBoard() {
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
    void gameManager::printBoardTEST() {
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

    void gameManager::movePiece(int intColumnOfPieceToMove, int rowOfPieceToMove, int intColumnOfPieceToGoTo, int rowOfPieceToGoTo){
        
        /*Created a temp object to deep copy after replacing the piece to go to with the piece that wanted to move*/
        /*Not space efficient but also created a blank object in case of takes*/

        // the problem with this is that the row and column data inside the piece objects are not accurate.

        Pieces tempObj(board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].getColor(),0,board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].getPiece(),0,0);   
        Pieces tempobj2(board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].getColor(),0,board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].getPiece(),0,0);
        //tempobj2.setColor(board[7 - rowOfPieceToMove][intColumnOfPieceToMove].getColor());
    //    tempobj2.setPiece(board[7 - rowOfPieceToMove][intColumnOfPieceToMove].getPiece());
     //   tempObj.setColor(board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].getColor());
       // tempObj.setPiece(board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].getPiece());
        Pieces blankObj(NONE, 0, BLANK, 7 - rowOfPieceToMove, intColumnOfPieceToMove);

        //if it is white turn and the piece at the desired spot to move at is black, then replace the black piece with the white piece
        //then replace the spot the white piece was with a blank space.
        if(board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].getColor() == BLACK && whitesTurn){
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].setPiece(tempobj2.getPiece());
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].setColor(tempobj2.getColor());
            board[7 - rowOfPieceToMove][intColumnOfPieceToMove].setColor(NONE);
            board[7 - rowOfPieceToMove][intColumnOfPieceToMove].setPiece(BLANK);
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].setHas_moved(true);
        }
        //vice versa
        else if(board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].getColor() == WHITE && !whitesTurn){
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].setPiece(tempobj2.getPiece());
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].setColor(tempobj2.getColor());
            board[7 - rowOfPieceToMove][intColumnOfPieceToMove].setColor(NONE);
            board[7 - rowOfPieceToMove][intColumnOfPieceToMove].setPiece(BLANK);
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].setHas_moved(true);
        }
        //if the piece just moves to a blank space 
        else{
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].setColor(board[7 - rowOfPieceToMove][intColumnOfPieceToMove].getColor());
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].setPiece(board[7 - rowOfPieceToMove][intColumnOfPieceToMove].getPiece());
            board[7 - rowOfPieceToMove][intColumnOfPieceToMove].setColor(tempObj.getColor());  
            board[7 - rowOfPieceToMove][intColumnOfPieceToMove].setPiece(tempObj.getPiece());  
            board[7 - rowOfPieceToGoTo][intColumnOfPieceToGoTo].setHas_moved(true);
        }
    }
    
    bool gameManager:: isCheck(color kingColor){

        board[1][1];
        bool foundWhite = false;
        bool foundBlack = false;
        for(int i = 0; i < 8; i ++){
            for(int j = 0; j < 8; j++){
                if(board[i]][j].getPiece() == KING){
                    if(board[i][j].getColor() == WHITE && !(foundWhite)){
                        cout << "here the king white is: " << j << " "<<i << endl;
                        //whereTheKingIsWhite = board[i][j];
                        foundWhite = true;
                    }
                    if(board[i][j].getColor() == BLACK && !(foundBlack)){
                        //whereTheKingIsBlack = board[i][j];
                        cout << "here the king is: " << j << " "<<i << endl;
                        foundBlack = true;
                        //whereTheKingIsBlack.setColor(board[i][j].getColor());
                    //    whereTheKingIsBlack.setColumn(board[i][j].getColumn());
                     //   whereTheKingIsBlack.setRow(board[i][j].getRow());
                      //  whereTheKingIsBlack.set
                    }
                }
                
                if(foundWhite && foundBlack){
                    break;
                }
            }
            if(foundWhite && foundBlack){
                break;
            }
        }
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                if(board[i][j].getPiece() != BLANK){
                    cout << board[i][j].getPiece() << " " << endl;
                    cout << board[whereTheKingIsWhite.getRow(),whereTheKingIsWhite.getColumn()] << " ";
                    if(check_available(i,j,whereTheKingIsWhite.getRow(),whereTheKingIsWhite.getColumn())){
                        list_Of_all_Pieces_that_can_attack_whiteKing.push_back(board[i][j]); //still need to take out the piece
                    }
                
                
                    if(check_available(i,j,whereTheKingIsBlack.getRow(),whereTheKingIsBlack.getColumn())){
                        list_Of_all_Pieces_that_can_attack_blackKing.push_back(board[i]j]); //still need to take out the piece
                    }
                    
                }
            }
            cout << endl;
        }
        if(isCheckmate(WHITE)){
            abort;
        }
        cout << list_Of_all_Pieces_that_can_attack_whiteKing.size() << endl;
        if(list_Of_all_Pieces_that_can_attack_whiteKing.size() != 0){
            return true;
        }
        cout << list_Of_all_Pieces_that_can_attack_whiteKing.size() << endl ;
        if(list_Of_all_Pieces_that_can_attack_blackKing.size() != 0){
            return true;
        }
        return false;
    }

    bool gameManager:: isCheckmate(color KingColor) {
    //trying to defend the black king meaning you are attacking with white units so you inorder to get out of check you need to see if any black units can kill the white units
        for(int i = 0; i < list_Of_all_Pieces_that_can_attack_blackKing.size(); i ++){
            for(int j = 0; j < 7; j++){
                for(int k = 0; k < 7; k++){
                    if(board[j][k].getPiece() != NONE && board[j][k].getColor() == BLACK){
                        if(check_available(list_Of_all_Pieces_that_can_attack_blackKing.at(i).getRow(),list_Of_all_Pieces_that_can_attack_blackKing.at(i).getColumn(),j,k)){
                            vector_Of_all_that_can_save_Blackking.push_back(board[j][k]);
                        }
                    }
                }
            }
        }
        for(int i = 0; i < list_Of_all_Pieces_that_can_attack_whiteKing.size(); i ++){
            for(int j = 0; j < 7; j++){
                for(int k = 0; k < 7; k++){
                    if(board[j][k].getPiece() != NONE && board[j][k].getColor() == BLACK){
                        if(check_available(list_Of_all_Pieces_that_can_attack_whiteKing.at(i).getRow(),list_Of_all_Pieces_that_can_attack_whiteKing.at(i).getColumn(),j,k)){
                            vector_Of_all_that_can_save_Whiteking.push_back(board[j][k]);
                        }
                    }
                }
            }
        }
        bool youFG = false;
        for(int i = 0; i < vector_Of_all_that_can_save_Whiteking.size(); i ++){
            for(int j = 0; j < list_Of_all_Pieces_that_can_attack_whiteKing.size(); j++){
                if(check_available(vector_Of_all_that_can_save_Whiteking.at(i).getRow(),vector_Of_all_that_can_save_Whiteking.at(i).getColumn(),
                                    list_Of_all_Pieces_that_can_attack_whiteKing.at(j).getRow(),list_Of_all_Pieces_that_can_attack_whiteKing.at(j).getColumn())){
                    if(list_Of_all_Pieces_that_can_attack_whiteKing.size()-1 != 0){
                        youFG = true;
                    }
                    else{
                        youFG = false;
                    }
                }
            }
        }
        
        for(int i = 0; i < vector_Of_all_that_can_save_Blackking.size(); i ++){
            for(int j = 0; j < list_Of_all_Pieces_that_can_attack_blackKing.size(); j++){
                if(check_available(vector_Of_all_that_can_save_Blackking.at(i).getRow(),vector_Of_all_that_can_save_Blackking.at(i).getColumn(),
                                    list_Of_all_Pieces_that_can_attack_blackKing.at(j).getRow(),list_Of_all_Pieces_that_can_attack_blackKing.at(j).getColumn())){
                    if(list_Of_all_Pieces_that_can_attack_blackKing.size()-1 != 0){
                        youFG = true;
                    }
                    else{
                        youFG = false;
                    }
                }
            }
        }
        return youFG;
    }

    bool gameManager:: isStalemate() {
        return false;
    }

    bool gameManager:: doesKingStillExist(color colour){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j <= 7; j++){
                if(board[i][j].getPiece() == KING &&
                   board[i][j].getColor() == colour){
                    return true;
                }
            }
        }
        return false;
    }

    void gameManager:: availablePieces() {
        
        availableBlack.clear();
        availableWhite.clear();

        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++) {
                if (board[i][j].getColor() == WHITE) {
                    availableWhite.push_back(&board[i][j]);
                }
                else if (board[i][j].getColor() == BLACK) {
                    availableBlack.push_back(&board[i][j]);
                }
            }
        }
    }

    bool gameManager:: check_available(int rowPieceThatsMoving, int columnPieceThatsMoving, int rowItGoesTo, int columnItGoesTo){
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
                
                // If the piece has not moved, it cannot move more than two spots or diagonal 
                if(currentPiece.getHas_moved() == false){
                    if(whitesTurn){
                       if(rowItGoesTo > currentPiece.getRow() + 2)
                        {
                            return false;
                        }    
                    }
                    else if(whitesTurn == false){
                        if(rowItGoesTo < currentPiece.getRow() - 2)
                        {
                            return false;
                        }  
                    }
                }

                // If the piece has not moved, it cannot move two spots if there is a piece there
                if(currentPiece.getHas_moved() == false){
                    if(whitesTurn){
                       if(board[7-rowItGoesTo][columnItGoesTo].getPiece() != BLANK)
                        {
                            return false;
                        }    
                    }
                    else if(whitesTurn == false){
                        if(board[7-rowItGoesTo][columnItGoesTo].getPiece() != BLANK)
                        {
                            return false;
                        }  
                    }
                }

                // checks if the desired spot is the spot behind the current piece
                if(whitesTurn){
                    if(rowItGoesTo < currentPiece.getRow()){
                    return false;
                    }
                }
                else if (whitesTurn == false){
                    if(rowItGoesTo > currentPiece.getRow()){
                    return false;
                    }
                }
                
                

                // If it is white's turn and there is a piece in front of the pawn, return false 
                if(whitesTurn && currentPiece.getColumn() == columnItGoesTo ){
                    if(board[6 - rowPieceThatsMoving][columnPieceThatsMoving].getPiece() != BLANK){
                    return false;
                    }
                }
                //else it is black's turn and if there is a piece in front of a black piece, return false
                if(whitesTurn == false && currentPiece.getColumn() == columnItGoesTo){
                    if(board[8 - rowPieceThatsMoving][columnPieceThatsMoving].getPiece() != BLANK){
                    return false;
                    }
                }
                
                // If the piece has moved, it cannot move more than two spots 
                if(currentPiece.getHas_moved()){
                    if(whitesTurn){
                       if(rowItGoesTo >= rowPieceThatsMoving + 2)
                        {
                            return false;
                        }    
                    }
                    else if(whitesTurn == false){
                        if(rowItGoesTo <= rowPieceThatsMoving - 2)
                        {
                            return false;
                        }  
                    }
                    
                }

                // allows diagonally takes
                if(whitesTurn){
                       if(rowItGoesTo == rowPieceThatsMoving + 1 && columnItGoesTo == columnPieceThatsMoving + 1)
                        {
                            return true;
                        }
                        else if(rowItGoesTo == rowPieceThatsMoving + 1 && columnItGoesTo == columnPieceThatsMoving -1){
                            return true;
                        } 
                    }
                    else if(whitesTurn == false){
                        if(rowItGoesTo == rowPieceThatsMoving - 1 && columnItGoesTo == columnPieceThatsMoving - 1)
                        {
                            return true;
                        }
                        else if(rowItGoesTo == rowPieceThatsMoving - 1 && columnItGoesTo == columnPieceThatsMoving + 1){
                            return true;
                        }  
                    }
                
                // return false if they want to move the pawn left and right
                if(columnItGoesTo != columnPieceThatsMoving){
                    return false;
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

                //checks for diagonal
                if(abs(currentPiece.getColumn() - columnItGoesTo) !=
                   abs(currentPiece.getRow() - rowItGoesTo)){
                    return false;
                }

                //going up right
                if(columnItGoesTo > currentPiece.getColumn() &&
                   rowItGoesTo > currentPiece.getRow()){
                    for(int i = 1; i < columnItGoesTo - currentPiece.getColumn(); i++){
                        Pieces current = board[7 - currentPiece.getRow() - i][currentPiece.getColumn() + i];
                        if(current.getPiece() != BLANK){
                            return false;
                        }
                    }
                }

                //going up left
                if(columnItGoesTo < currentPiece.getColumn() &&
                   rowItGoesTo > currentPiece.getRow()){
                    for(int i = 1; i < abs(columnItGoesTo - currentPiece.getColumn()); i++){
                        if(board[7 - currentPiece.getRow() - i][currentPiece.getColumn() - i].getPiece() != BLANK){
                            return false;
                        }
                    }
                }

                //going down right
                if(columnItGoesTo > currentPiece.getColumn() &&
                   rowItGoesTo < currentPiece.getRow()){
                    for(int i = 1; i < columnItGoesTo - currentPiece.getColumn(); i++){
                        if(board[7 - currentPiece.getRow() + i][currentPiece.getColumn() + i].getPiece() != BLANK){
                            return false;
                        }
                    }                    
                }

                //going down left
                if(columnItGoesTo < currentPiece.getColumn() &&
                   rowItGoesTo < currentPiece.getRow()){
                    for(int i = 1; abs(i < columnItGoesTo - currentPiece.getColumn()); i++){
                        if(board[7 - currentPiece.getRow() + i][currentPiece.getColumn() - i].getPiece() != BLANK){
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
                int x_spaces = currentPiece.getColumn() - columnItGoesTo;
                int y_spaces = currentPiece.getRow() - rowItGoesTo;

                //checks for diagonal, if not diagional -> go to rook part
                if(!(currentPiece.getColumn() - columnItGoesTo != 0 &&
                     currentPiece.getRow() - rowItGoesTo != 0)){

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

                
                //checks for diagonal
                if(abs(currentPiece.getColumn() - columnItGoesTo) ==
                    abs(currentPiece.getRow() - rowItGoesTo)){
                    
                    //going up right
                    if(columnItGoesTo > currentPiece.getColumn() &&
                       rowItGoesTo > currentPiece.getRow()){
                        for(int i = 1; i < columnItGoesTo - currentPiece.getColumn(); i++){
                            Pieces current = board[7 - currentPiece.getRow() - i][currentPiece.getColumn() + i];
                            if(current.getPiece() != BLANK){
                                return false;
                            }
                        }
                    }
                    //going up left
                    if(columnItGoesTo < currentPiece.getColumn() &&
                       rowItGoesTo > currentPiece.getRow()){
                        for(int i = 1; i < abs(columnItGoesTo - currentPiece.getColumn()); i++){
                            if(board[7 - currentPiece.getRow() - i][currentPiece.getColumn() - i].getPiece() != BLANK){
                                return false;
                            }
                        }
                    }
                    //going down right
                    if(columnItGoesTo > currentPiece.getColumn() &&
                       rowItGoesTo < currentPiece.getRow()){
                        for(int i = 1; i < columnItGoesTo - currentPiece.getColumn(); i++){
                            if(board[7 - currentPiece.getRow() + i][currentPiece.getColumn() + i].getPiece() != BLANK){
                                return false;
                            }
                        }                    
                    }
                    //going down left
                    if(columnItGoesTo < currentPiece.getColumn() &&
                       rowItGoesTo < currentPiece.getRow()){
                        for(int i = 1; abs(i < columnItGoesTo - currentPiece.getColumn()); i++){
                            if(board[7 - currentPiece.getRow() + i][currentPiece.getColumn() - i].getPiece() != BLANK){
                                return false;
                            }
                        }                    
                    }
                    return true;
                }
                return false;
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
                   abs(currentPiece.getColumn() - columnItGoesTo) <= 1)
                   {
                        return true;
                   }
                //castles
                else if(abs(currentPiece.getRow() - rowItGoesTo) == 0 && // row doesnt change
                        abs(currentPiece.getColumn() - columnItGoesTo) == 2 && // attempts to move 2
                        !currentPiece.getHas_moved()) // king hasnt moved
                        { 
                        // king attempts to move towards h rook (kingSide)
                        if(columnItGoesTo > currentPiece.getColumn()){
                            if(board[7 - currentPiece.getRow()][6].getPiece() == BLANK &&
                               board[7 - currentPiece.getRow()][5].getPiece() == BLANK &&
                               !board[7 - currentPiece.getRow()][7].getHas_moved()){
                                movePiece(7,rowItGoesTo,5,rowItGoesTo);
                                return true;
                            }
                        }
                        // king attempts to move towards a rook (queenSide)
                         if(columnItGoesTo < currentPiece.getColumn()){
                            if(board[7 - currentPiece.getRow()][1].getPiece() == BLANK &&
                               board[7 - currentPiece.getRow()][2].getPiece() == BLANK &&
                               board[7 - currentPiece.getRow()][3].getPiece() == BLANK &&
                               !board[7 - currentPiece.getRow()][0].getHas_moved()){
                                movePiece(0,rowItGoesTo,3,rowItGoesTo);
                                return true;
                            }
                        }
                    }
                return false;
            }
        abort();  
    }

    // these two are mostly for testing
    void gameManager:: incMoveCount() {
        moveCount++;
    }

    int gameManager:: getMoveCount() {
        return moveCount;
    }

    void gameManager:: printBoardSpaces(){
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
