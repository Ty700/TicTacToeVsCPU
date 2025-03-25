# TicTacToe vs CPU

A command-line implementation of the classic Tic-Tac-Toe game where players can play against an AI opponent with multiple difficulty settings or against other players over a network.

## Back Story
This was my first "big" project when I was learning C++ and programming fundamentals. I decided to revisit it and enhance it with some new features. If you're curious about the original version, switch to the [TicTacToe2023 branch](https://github.com/Ty700/TicTacToeVsCPU/tree/TicTacToe2023) and prepare your eyes for that monstrosity. This was prior to my knowledge of git, so I straight up copied and pasted the code into GitHub, forgetting to add the .cpp extension for color formatting. Hence, the latest commit is only a few months old (at the time of this writing).

## Features
* Player vs. AI gameplay
* Three AI difficulty levels:
  * Easy: makes random moves
  * Medium: combines strategy with some randomness
  * Hard: implements the Minimax algorithm for optimal play (unbeatable)
* Network play (NEW!) - play against other players over the internet
* Colorized board with red 'X' and blue 'O'
* Configurable player names and symbols
* Option to select which player goes first

## Building the Game

## Dependencies

### Linux
* CMake 3.28 or later
* C++ compiler with C++17 or later support
* Python 3.6 or later
* OpenSSL 1.1.1 or later
* Protobuf (for network play)

```bash
# For Ubuntu/Debian
sudo apt-get install cmake build-essential libprotobuf-dev protobuf-compiler libssl-dev

# For Fedora
sudo dnf install cmake gcc-c++ protobuf-devel protobuf-compiler openssl-devel
```

### Windows
* Currently, the game doesn't build for Windows, but this is in-progress!

### Mac
* Currently, the game doesn't build for Mac, and I am not sure when Mac support will be available as I don't have a reliable way to test Mac OS!

### Compilation
You can build the game using the python build script: build.py

#### Production Version
```
python3 build.py
```

#### Debug Version
```
python3 build.py -d
```

You can also clean the binaries and CMake files via:
```
python3 build.py -c
```

## Gameplay

1. Configure the game through the setup menu:
   * Set your name
   * Select your symbol
   * Choose to play against an AI, local player, or over network
   * Decide who goes first

2. During the game
   * Enter a number 1-9 to select where to place your symbol
   * The board positions are numbered
```
 1 | 2 | 3
 ---------
 4 | 5 | 6
 ---------
 7 | 8 | 9
```

3. The game ends when either:
   * A player gets three of their symbols in a row, column, or diagonal
   * All positions are filled, resulting in a tie

## Network Play (NEW!)

The game now supports network multiplayer using Valve's GameNetworkingSockets library!

### As a server:
```
./bin/release/TicTacToe --server
```

### As a client:
```
./bin/release/TicTacToe --client SERVER_IP_ADDRESS
```

Replace `SERVER_IP_ADDRESS` with the IP address of the server.

## Screenshots

#### Game Setup:
<img src="img/Screenshot%20from%202025-03-20%2010-52-15.png" width="250" alt="Game Setup">

#### Gameplay:
<img src="img/Screenshot%20from%202025-03-20%2010-53-13.png" width="200" alt="Gameplay">

## File Structure
* tictactoe.cpp: main program entry point
* Game.cpp/h: Handles the game logic and board state
* GameConfig.cpp/h: Manages game setup and configuration
* Player.cpp/h: Defines player attributes and behaviors
* AIMoves.cpp/h: Contains AI algorithms for different difficulty levels
* Client.cpp/h: Handles network client functionality
* Server.cpp/h: Handles network server functionality
* NetworkingUtils.cpp/h: Common networking utilities

## AI Implementation

### Easy Mode
* Makes completely random moves with no strategy.

### Medium Mode
* Uses a prioritized strategy:
  1. Tries to win if possible
  2. Blocks the player if they're about to win
  3. Takes the center position if available
  4. Takes a corner position if available
  5. Makes a random move if none of the above applies

### Hard Mode
* Implements the Minimax algorithm to make optimal moves, resulting in an unbeatable gameplay. The AI will either win or force a draw.

## Network Implementation
The game uses Valve's GameNetworkingSockets library, which provides:
* Reliable and unreliable message delivery over UDP
* Automatic reconnection
* Encryption
* Traffic prioritization

## Future Improvements
* Game statistics Tracking
* Windows/Mac Compatibility
* GUI???