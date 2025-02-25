#include "GameConfig.h"
#include "Player.h"

#include <iostream>
#include <string>
#include <memory>

/**
 * FUNCTION: Sets up the game. When calling game loop, will use this config as settings
 * PARAMS:   VOID
 * RETURNS:  VOID
 */
void GameConfig::setupGame(void){

    constexpr int FINISH_BUTTON = 4;

    while(menuOption != FINISH_BUTTON){
            #ifndef DEBUG
                #ifdef _WIN32
                    system("cls");
                #else 
                    system("clear");
                #endif /* _WIN32 */
            #endif /* DEBUG */


            std::cout << "1. Player One's Name: " << playerOneName << std::endl;
            std::cout << "2. Player One's Symbol: " << playerOneSymbol << std::endl;
            std::cout << "3. Playing Against: ";

            if(playingAgainstAI){
                std::cout << "AI" << std::endl;
                std:: cout << "   AI's Name: " << playerTwoName << std::endl;
                std::cout <<  "   AI's Symbol: ";

                if(playerOneSymbol == 'X'){
                    playerTwoSymbol = 'O';
                    std::cout << playerTwoSymbol << std::endl;
                } else {
                    playerTwoSymbol = 'X';
                    std::cout << playerTwoSymbol << std::endl;
                }

            } else {
                std::cout << "Player" << std::endl;
                std::cout << "   Player Two's Name: " << playerTwoName << std::endl;
                std::cout << "   Player Two's Symbol: ";

                if(playerOneSymbol == 'X'){
                    playerTwoSymbol = 'O';
                    std::cout << playerTwoSymbol << std::endl;
                } else {
                    playerTwoSymbol = 'X';
                    std::cout << playerTwoSymbol << std::endl;
                }
            }

            std::cout << "4. Start" << std::endl;

            std::cin >> menuOption;

        switch (menuOption)
        {
            case (1):
                playerOneName = capturePlayerName();
                break;
            
            case(2):
                if(playerOneSymbol == 'X'){
                    playerOneSymbol = 'O';
                } else {
                    playerOneSymbol = 'X';
                }
                break;

            case(3):
                playingAgainstAI = !playingAgainstAI;

                if(!playingAgainstAI){
                    playerTwoName = capturePlayerName();    
                } else {
                    playerTwoName = generateAIName();
                }

                break;

            case(FINISH_BUTTON):
                /* Starting game */
                playerOne = std::make_unique<Player>(playerOneName, playerOneSymbol, false);
                
                if(playingAgainstAI){
                    playerTwo = std::make_unique<Player>(playerTwoName, playerTwoSymbol, true);
                } else {
                    playerTwo = std::make_unique<Player>(playerTwoName, playerTwoSymbol, false);
                }
                break;

            default:    
                std::cout << "Invalid Option." << std::endl;
        }
    }
}
