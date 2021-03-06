#ifdef _BOARD_H_
#ifndef _INPUT_OUTPUT_H_
#define _INPUT_OUTPUT_H_

#include "board.h"

enum action_e {
    SWAP, 
    CONTINUE
};

enum cancel_type_e {
    MOVEMENT,
    STEP
};

typedef enum action_e action;
typedef enum cancel_type_e cancel_type;


/**
 * \file input_output.h
 *
 * \brief A simple input/output manager.
 *
 * In this file, all the functions for the input/output managment are defined.
 *  
 * \authors Morisse & Guibout
 *
 */

/**
 * \mainpage Project 2020-2021 for IUT Grand Ouest Normandie, 
 * computer science department.
 *
 * The project is divided into various files. Mostly, the engine of the game,
 * implementing the detailed rules, is provided in the files board.c and board.h
 *
 * \section rules Detailed rules of the game.
 * 
 * The game is played by two players on a six by six squares board, 
 * with two goals. Detailed rules are included in the pdf subject, not recalled here (yet).
 */

/**
 * @brief Allows you ask a number to the user.
 * 
 * @param prompt the string to show
 * @param min the minimun value to read (-1 for no minium)
 * @param max the maximum value to read (-1 for no maximum)
 * @returns the inputed number
 */
int read_number(const char *prompt, int min, int max);

/**
 * @brief Asks the player a single char
 * 
 * Asks the player for a char to be used for the next action.
 * It could be a direction, the winning move, if he wants to quit or which type of action he wants to do (i.e. swap/move)
 * 
 * @param prompt the string to show
 * @param args_count the number of different accepted characters. if num <= 0 every character will be accepted.
 * @param ... the different accepted characters
 * 
 * @returns the inputed character
*/
char read_char(const char *prompt, int args_count, ...);

/**
 * @brief reads the input of the player.
 * 
 * @param prompt the string to show
 * @returns the direction inputed by the player, returns -1 if cancelled.
 * */
direction read_direction(const char *prompt);

/**
 * @brief Is used in order print an error.
 * 
 * Prints any given error to the screen.
 * 
 * @param error the error to show.
 */
void print_error(const char *error);

/**
 * @brief Annouces the winner once game has one.
 * 
 * @param player the winning player.
 */
void announce_winner(board game);

/**
 * @brief Displays the board inside the console.*
 * 
 * Displays a given game board to the screen.
 * 
 * @param board the board to be displayed.
 */
void show_board(board game);

/**
 * @brief Announces the current player that needs to play.
 * 
 * @param player the player enum to cycle through
 */
void announce_turn(player player);

/**
 * @brief Asks the line where the player wants to play.
 * 
 * @returns the inputed value.
*/
int get_line();

/**
 * @brief Asks the column where the player wants to play.
 * 
 * @returns the inputed value.
 */
int get_column();

/**
 * @brief Asks the size of piece the player wants to play.
 * 
 * @returns the inputed size.
 */
size get_size();

/**
 * @brief Same as read_direction but it uses a default prompt.
 * 
 * @returns the direction inputed by the player, returns -1 if cancelled.
 * */
direction get_direction();

/**
 * @brief Asks the player if he wants to swap pieces up and down
 * 
 * @returns the chosen decision. It can be SWAP to swap pieces or CONTINUE to continue moving
 */
action get_action();

/**
 * @brief Asks the type of cancel the player wants to do
 * 
 * @return the chosen decision. It can be MOVEMENT or STEP
 */
cancel_type get_cancel_type();

/**
 * @brief Asks to the player for a confirmation
 * 
 * @returns true if the player inputed 'O' or false if he inputed 'N'
 */
bool confirm(char *prompt);

/**
 * @brief Asks the player if he really want to swap the pieces.
 * 
 * Used to ask the player if he really wants to swap the pieces, else he can rollback his last move
 *  * @returns true if he really wants to swap, false otherwise
 */
bool confirm_swap();

/**
 * @brief Asks the player if he really want to move the piece when he has the choice
 * 
 * Sometimes, the player can chose between swaping two pieces or continue moving, this function asks
 * him if he really wants to move. If not, cancel.
 * @returns true if he really wants to continue, false otherwise
 */
bool confirm_continue();

#endif /* _INPUT_OUTPUT_H_ */ 
#endif /* _BOARD_H_ */