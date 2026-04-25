#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <random>
#include <iomanip>

enum class Player { NONE, BLUE, RED };

class HexGame {
private:
    int size;
    std::vector<std::vector<Player>> board;
    Player currentPlayer;
    std::mt19937 rng;

public:
    HexGame(int boardSize) : size(boardSize), currentPlayer(Player::BLUE) {
        board.resize(size, std::vector<Player>(size, Player::NONE));
        
        // random number generator
        std::random_device rd;
        rng = std::mt19937(rd());
    }

    void displayBoard() const {
        std::cout << "\n";
        // column nums
        std::cout << "   ";
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(2) << j << " ";
        }
        std::cout << "\n";

        for (int i = 0; i < size; ++i) {
            // hex layout formatting
            std::cout << std::string(i * 2, ' ');
            
            // row nums
            std::cout << std::setw(2) << i << " ";
            
            // board cells
            for (int j = 0; j < size; ++j) {
                char symbol;
                switch (board[i][j]) {
                    case Player::BLUE: symbol = 'B'; break;
                    case Player::RED: symbol = 'R'; break;
                    default: symbol = '.'; break;
                }
                std::cout << symbol << " - ";
            }
            std::cout << "\n";
            
            // print board lines except for final row
            if (i < size - 1) {
                std::cout << std::string(i * 2 + 3, ' ');
                for (int j = 0; j < size; ++j) {
                    std::cout << "\\ / ";
                }
                std::cout << "\n";
            }
        }
        std::cout << "\n";
    }

    bool isValidMove(int row, int col) const {
        return row >= 0 && row < size && col >= 0 && col < size && board[row][col] == Player::NONE;
    }

    void playerMove() {
        int row, col;
        
        while (true) {
            // player moving choice
            std::cout << "Enter your move (row col): ";
            std::cin >> row >> col;
            
            if (isValidMove(row, col)) {
                break;
            }
            
            // if its invalid then they have to input again
            std::cout << "Invalid move. Try again.\n";
        }
        
        makeMove(row, col, currentPlayer);
    }

    void computerMove() {
        // the computer moves by random
        std::vector<std::pair<int, int>> emptyCells;
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == Player::NONE) {
                    emptyCells.emplace_back(i, j);
                }
            }
        }
        
        if (!emptyCells.empty()) {
            std::uniform_int_distribution<int> dist(0, emptyCells.size() - 1);
            int idx = dist(rng);
            int row = emptyCells[idx].first;
            int col = emptyCells[idx].second;
            
            std::cout << "Computer plays at: " << row << " " << col << "\n";
            makeMove(row, col, currentPlayer);
        }
    }

    void makeMove(int row, int col, Player player) {
        board[row][col] = player;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == Player::BLUE) ? Player::RED : Player::BLUE;
    }

    Player getCurrentPlayer() const {
        return currentPlayer;
    }

    bool hasWon(Player player) {
        // blue: check if there is a path from top to bottom (row 0 to row size-1)
        // red: check if there is a path from left to right (col 0 to col size-1)
        
        if (player == Player::BLUE) {
            // find all blue cells in top row to start BFS
            std::queue<std::pair<int, int>> queue;
            std::set<std::pair<int, int>> visited;
            
            for (int j = 0; j < size; ++j) {
                if (board[0][j] == Player::BLUE) {
                    queue.push({0, j});
                    visited.insert({0, j});
                }
            }
            
            // BFS to find path
            while (!queue.empty()) {
                auto [i, j] = queue.front();
                queue.pop();
                
                // checks to see if we reached bottom row
                if (i == size - 1) {
                    return true;
                }
                
                // checks neighbors
                std::vector<std::pair<int, int>> neighbors = getNeighbors(i, j);
                for (const auto& [ni, nj] : neighbors) {
                    if (board[ni][nj] == Player::BLUE && visited.find({ni, nj}) == visited.end()) {
                        queue.push({ni, nj});
                        visited.insert({ni, nj});
                    }
                }
            }
            
            return false;
        }
        else if (player == Player::RED) {
            // finds all red cells in leftmost column to start BFS
            std::queue<std::pair<int, int>> queue;
            std::set<std::pair<int, int>> visited;
            
            for (int i = 0; i < size; ++i) {
                if (board[i][0] == Player::RED) {
                    queue.push({i, 0});
                    visited.insert({i, 0});
                }
            }
            
            // BFS to find path
            while (!queue.empty()) {
                auto [i, j] = queue.front();
                queue.pop();
                
                // checks to see if we reached rightmost column
                if (j == size - 1) {
                    return true;
                }
                
                // checks neighbors
                std::vector<std::pair<int, int>> neighbors = getNeighbors(i, j);
                for (const auto& [ni, nj] : neighbors) {
                    if (board[ni][nj] == Player::RED && visited.find({ni, nj}) == visited.end()) {
                        queue.push({ni, nj});
                        visited.insert({ni, nj});
                    }
                }
            }
            
            return false;
        }
        
        return false;
    }

    std::vector<std::pair<int, int>> getNeighbors(int i, int j) const {
        // all possible hex neighbors (6-way connectivity)
        std::vector<std::pair<int, int>> neighbors;
        
        // define the 6 possible neighbor directions in hex grid
        const std::vector<std::pair<int, int>> directions = {
            {-1, 0}, {-1, 1},   // up-left, up-right
            {0, -1}, {0, 1},    // left, right
            {1, -1}, {1, 0}     // down-left, down-right
        };
        
        for (const auto& [di, dj] : directions) {
            int ni = i + di;
            int nj = j + dj;
            
            if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                neighbors.emplace_back(ni, nj);
            }
        }
        
        return neighbors;
    }

    bool isBoardFull() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == Player::NONE) {
                    return false;
                }
            }
        }
        return true;
    }

    std::string getPlayerName(Player player) const {
        switch (player) {
            case Player::BLUE: return "Blue";
            case Player::RED: return "Red";
            default: return "None";
        }
    }
};

int main() {
    std::cout << "=== HEX GAME ===\n";
    
    // we can either play size 7 or 11 so we have to ask here
    int boardSize;
    std::cout << "Enter board size (7 or 11 recommended): ";
    std::cin >> boardSize;
    
    HexGame game(boardSize);
    
    // gives player a choice between blue or red
    char playerChoice;
    std::cout << "Do you want to play as Blue (B) or Red (R)? ";
    std::cin >> playerChoice;
    
    Player humanPlayer = (playerChoice == 'B' || playerChoice == 'b') ? Player::BLUE : Player::RED;
    
    bool gameOver = false;
    
    while (!gameOver) {
        game.displayBoard();
        
        Player currentPlayer = game.getCurrentPlayer();
        std::cout << "Current player: " << game.getPlayerName(currentPlayer) << "\n";
        
        if (currentPlayer == humanPlayer) {
            game.playerMove();
        } else {
            game.computerMove();
        }
        
        if (game.hasWon(currentPlayer)) {
            game.displayBoard();
            std::cout << game.getPlayerName(currentPlayer) << " has won the game!\n";
            gameOver = true;
        } else if (game.isBoardFull()) {
            game.displayBoard();
            std::cout << "The game is a draw!\n";
            gameOver = true;
        } else {
            game.switchPlayer();
        }
    }
    
    std::cout << "Game over. Thanks for playing!\n";
    
    return 0;
}