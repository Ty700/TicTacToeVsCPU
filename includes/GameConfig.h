#pragma once
#include "Player.h"

#include <string>
#include <memory>

class GameConfig{

public:
    GameConfig(){
        setupGame();
    }
    std::shared_ptr<Player> playerOne {nullptr};
    std::shared_ptr<Player> playerTwo {nullptr};
    
private:
    int menuOption              {-1};
    void setupGame();
    std::string playerOneName   {""};
    char        playerOneSymbol {'X'};
    std::string playerTwoName   {generateAIName()};
    char        playerTwoSymbol {'O'};
    bool        playingAgainstAI{true};    
    
};

