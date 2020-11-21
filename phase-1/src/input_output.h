#ifdef _BOARD_H_
#ifndef _INPUT_OUTPUT_H_
#define _INPUT_OUTPUT_H_

#include "board.h"

enum action_e {
    SWAP, 
    MOVE
};

typedef enum action_e action;

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
 * @param num the number of different accepted characters. if num <= 0 every character will be accepted.
 * @param ... the different accepted characters
 * 
 * @returns the inputed character
*/
char read_char(const char *prompt, int num, ...);

/**
 * @brief Is used in order to ask a number to the user or the character "q" to quit.
 * 
 * Asks if the player wants to quit the game.
 * If the answer is "Quit", the game will stop running properly.
 * Else, the game will go on.
 * 
 * @param prompt the string to show
 * @returns the inputed value, or -1 if quit 
 */
int read_digit_with_quit(const char *prompt);

/**
 * @brief Asks the user if he really wants to quit the game.
 * 
 * Asks the player if he really want to quit.
 * This avoids quitting because of a typo.
 * 
 * @returns whether the player wants to quit or not.
 */
bool confirm_quit();

/**
 * @brief Is used in order print an error.
 * 
 * Prints any given error to the screen.
 * 
 * @param error the error to show.
 */
void print_error(const char *error);

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
 * @brief reads the input of the player.
 * 
 * @param prompt the string to show
 * @returns the direction inputed by the player.
 * */
direction read_direction(const char *prompt);

/**
 * @brief same as read_direction but it uses a default prompt.
 * 
 * @returns the direction inputed by the player.
 * */
direction get_direction();

//////////////////////// Faire la doc de AskAction
action get_action();

/**
 * @brief Annouces the winner once game has one.
 * 
 * @param player the winning player.
 */
void announce_winner(player winner);

/**
 * @brief Asks the column where the player wants to play.
 * 
 * @returns the inputed value.
 */
int get_column();

/**
 * @brief Asks the line where the player wants to play.
 * 
 * @returns the inputed value.
*/
int get_line();

/**
 * @brief Cycles through player list.
 * 
 * @param player the current player, which will change 
*/
void change_player(player * current);

/**
 * @brief Asks the size of piece the player wants to play.
 * 
 * @returns the inputed size.
 */
size get_size();

#endif /* _INPUT_OUTPUT_H_ */ 
#endif /* _BOARD_H_ */