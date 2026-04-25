#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <limits>

enum class Player { EMPTY, BLUE, RED };
enum class GameState { ONGOING, BLUE_WINS, RED_WINS };

class HexBoard {
private:
    static const int BOARD_SIZE = 11;
    std::vector<std::vector<Player>> board;
    std::mt19937 rng;

public:
    HexBoard() : board(BOARD_SIZE, std::vector<Player>(BOARD_SIZE, Player::EMPTY)) {
        rng.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    }

    // copy constructor for simulations
    HexBoard(const HexBoard& other) : board(other.board), rng() {
        rng.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    }

    bool isValidMove(int row, int col) const {
        return row >= 0 && row < BOARD_SIZE && 
               col >= 0 && col < BOARD_SIZE && 
               board[row][col] == Player::EMPTY;
    }

    bool makeMove(int row, int col, Player player) {
        if (!isValidMove(row, col)) return false;
        board[row][col] = player;
        return true;
    }

    void undoMove(int row, int col) {
        board[row][col] = Player::EMPTY;
    }

    std::vector<std::pair<int, int>> getEmptyPositions() const {
        std::vector<std::pair<int, int>> empty;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == Player::EMPTY) {
                    empty.push_back({i, j});
                }
            }
        }
        return empty;
    }

    Player getCell(int row, int col) const {
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            return Player::EMPTY;
        }
        return board[row][col];
    }

    // check if Blue (X) has won by connecting top to bottom
    bool checkBlueWin() const {
        std::vector<std::vector<bool>> visited(BOARD_SIZE, std::vector<bool>(BOARD_SIZE, false));
        
        // start DFS from top row
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[0][j] == Player::BLUE && !visited[0][j]) {
                if (dfsBlue(0, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    // check if Red (O) has won by connecting left to right
    bool checkRedWin() const {
        std::vector<std::vector<bool>> visited(BOARD_SIZE, std::vector<bool>(BOARD_SIZE, false));
        
        // start DFS from left column
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board[i][0] == Player::RED && !visited[i][0]) {
                if (dfsRed(i, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    GameState getGameState() const {
        if (checkBlueWin()) return GameState::BLUE_WINS;
        if (checkRedWin()) return GameState::RED_WINS;
        return GameState::ONGOING;
    }

    void displayBoard() const {
        std::cout << "\n    ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << std::setw(2) << j << " ";
        }
        std::cout << "\n\n";

        for (int i = 0; i < BOARD_SIZE; ++i) {
            // row number
            std::cout << std::setw(2) << i << "  ";
            
            // indentation for hex pattern
            for (int k = 0; k < i; ++k) {
                std::cout << " ";
            }

            // drawing board cells
            for (int j = 0; j < BOARD_SIZE; ++j) {
                char symbol = '.';
                if (board[i][j] == Player::BLUE) symbol = 'X';
                else if (board[i][j] == Player::RED) symbol = 'O';
                
                std::cout << symbol;
                if (j < BOARD_SIZE - 1) std::cout << " - ";
            }
            
            std::cout << "\n";
            
            // drawing ze connection lines (except for last row)
            if (i < BOARD_SIZE - 1) {
                std::cout << "     ";
                for (int k = 0; k <= i; ++k) {
                    std::cout << " ";
                }
                for (int j = 0; j < BOARD_SIZE - 1; ++j) {
                    std::cout << "\\ / ";
                }
                std::cout << "\\\n";
            }
        }
        std::cout << "\nX (Blue) connects top-bottom, O (Red) connects left-right\n";
    }

    // this is the Monte Carlo simulation
    // play random moves until the end of the game
    Player simulateRandomGame(Player currentPlayer) {
        HexBoard simBoard(*this);
        Player turn = currentPlayer;
        
        while (true) {
            auto empty = simBoard.getEmptyPositions();
            if (empty.empty()) break;
            
            GameState state = simBoard.getGameState();
            if (state != GameState::ONGOING) {
                return (state == GameState::BLUE_WINS) ? Player::BLUE : Player::RED;
            }
            
            // Random move
            std::uniform_int_distribution<int> dist(0, empty.size() - 1);
            int moveIndex = dist(rng);
            simBoard.makeMove(empty[moveIndex].first, empty[moveIndex].second, turn);
            
            turn = (turn == Player::BLUE) ? Player::RED : Player::BLUE;
        }
        
        GameState finalState = simBoard.getGameState();
        if (finalState == GameState::BLUE_WINS) return Player::BLUE;
        if (finalState == GameState::RED_WINS) return Player::RED;
        return Player::EMPTY; // failsafe bcs this should not be happening in hex anyways
    }

private:
    // Hex neighbors (6 directions)
    std::vector<std::pair<int, int>> getNeighbors(int row, int col) const {
        std::vector<std::pair<int, int>> neighbors = {
            {row-1, col}, {row-1, col+1},  // up-left, up-right
            {row, col-1}, {row, col+1},    // left, right
            {row+1, col-1}, {row+1, col}   // down-left, down-right
        };
        return neighbors;
    }

    bool dfsBlue(int row, int col, std::vector<std::vector<bool>>& visited) const {
        if (row == BOARD_SIZE - 1) return true; // reached bottom row
        
        visited[row][col] = true;
        
        for (auto [nr, nc] : getNeighbors(row, col)) {
            if (nr >= 0 && nr < BOARD_SIZE && nc >= 0 && nc < BOARD_SIZE &&
                !visited[nr][nc] && board[nr][nc] == Player::BLUE) {
                if (dfsBlue(nr, nc, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfsRed(int row, int col, std::vector<std::vector<bool>>& visited) const {
        if (col == BOARD_SIZE - 1) return true; // reached right column
        
        visited[row][col] = true;
        
        for (auto [nr, nc] : getNeighbors(row, col)) {
            if (nr >= 0 && nr < BOARD_SIZE && nc >= 0 && nc < BOARD_SIZE &&
                !visited[nr][nc] && board[nr][nc] == Player::RED) {
                if (dfsRed(nr, nc, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

class MonteCarloAI {
private:
    static const int SIMULATIONS_PER_MOVE = 1000;
    
public:
    std::pair<int, int> getBestMove(HexBoard& board, Player aiPlayer) {
        auto legalMoves = board.getEmptyPositions();
        if (legalMoves.empty()) return {-1, -1};
        
        std::pair<int, int> bestMove = legalMoves[0];
        double bestWinRate = -1.0;
        
        std::cout << "AI evaluating " << legalMoves.size() << " possible moves...\n";
        
        auto startTime = std::chrono::steady_clock::now();
        
        for (int moveIndex = 0; moveIndex < legalMoves.size(); ++moveIndex) {
            auto [row, col] = legalMoves[moveIndex];
            
            // make ai try this move
            board.makeMove(row, col, aiPlayer);
            
            int wins = 0;
            Player nextPlayer = (aiPlayer == Player::BLUE) ? Player::RED : Player::BLUE;
            
            // run simulations
            for (int sim = 0; sim < SIMULATIONS_PER_MOVE; ++sim) {
                Player winner = board.simulateRandomGame(nextPlayer);
                if (winner == aiPlayer) {
                    wins++;
                }
            }
            
            // undo the move
            board.undoMove(row, col);
            
            double winRate = static_cast<double>(wins) / SIMULATIONS_PER_MOVE;
            
            std::cout << "Move (" << row << "," << col << "): " 
                      << wins << "/" << SIMULATIONS_PER_MOVE 
                      << " = " << std::fixed << std::setprecision(3) << winRate << "\n";
            
            if (winRate > bestWinRate) {
                bestWinRate = winRate;
                bestMove = {row, col};
            }
        }
        
        auto endTime = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
        
        std::cout << "\nBest move: (" << bestMove.first << "," << bestMove.second 
                  << ") with win rate: " << std::fixed << std::setprecision(3) << bestWinRate
                  << "\nEvaluation took: " << duration.count() << " seconds\n\n";
        
        return bestMove;
    }
};

class HexGame {
private:
    HexBoard board;
    MonteCarloAI ai;
    Player humanPlayer;
    Player aiPlayer;
    
public:
    void playGame() {
        std::cout << "=== Monte Carlo Hex Game ===\n";
        std::cout << "11x11 board\n";
        std::cout << "X (Blue) connects top-bottom\n";
        std::cout << "O (Red) connects left-right\n\n";
        
        choosePlayerColor();
        
        Player currentPlayer = Player::BLUE;
        
        while (true) {
            board.displayBoard();
            
            GameState state = board.getGameState();
            if (state != GameState::ONGOING) {
                announceWinner(state);
                break;
            }
            
            if (currentPlayer == humanPlayer) {
                makeHumanMove();
            } else {
                makeAIMove();
            }
            
            currentPlayer = (currentPlayer == Player::BLUE) ? Player::RED : Player::BLUE;
        }
    }
    
private:
    void choosePlayerColor() {
        std::cout << "Choose your color:\n";
        std::cout << "1. X (Blue) - connects top to bottom, goes first\n";
        std::cout << "2. O (Red) - connects left to right, goes second\n";
        std::cout << "Enter choice (1 or 2): ";
        
        int choice;
        while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
            std::cout << "Invalid input. Please enter 1 or 2: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        if (choice == 1) {
            humanPlayer = Player::BLUE;
            aiPlayer = Player::RED;
            std::cout << "You are X (Blue). You go first!\n\n";
        } else {
            humanPlayer = Player::RED;
            aiPlayer = Player::BLUE;
            std::cout << "You are O (Red). AI goes first!\n\n";
        }
    }
    
    void makeHumanMove() {
        std::cout << "Your turn! Enter move as 'row col' (0-10): ";
        
        int row, col;
        while (true) {
            if (!(std::cin >> row >> col)) {
                std::cout << "Invalid input. Please enter two numbers: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            
            if (board.makeMove(row, col, humanPlayer)) {
                std::cout << "Move accepted: (" << row << "," << col << ")\n\n";
                break;
            } else {
                std::cout << "Invalid move. Try again (row col, 0-10): ";
            }
        }
    }
    
    void makeAIMove() {
        std::cout << "AI is thinking...\n";
        auto [row, col] = ai.getBestMove(board, aiPlayer);
        
        if (row != -1 && col != -1) {
            board.makeMove(row, col, aiPlayer);
            std::cout << "AI plays: (" << row << "," << col << ")\n\n";
        }
    }
    
    void announceWinner(GameState state) {
        std::cout << "\n=== GAME OVER ===\n";
        if (state == GameState::BLUE_WINS) {
            std::cout << "X (Blue) wins by connecting top to bottom!\n";
            if (humanPlayer == Player::BLUE) {
                std::cout << "Congratulations! You won!\n";
            } else {
                std::cout << "AI wins!\n";
            }
        } else if (state == GameState::RED_WINS) {
            std::cout << "O (Red) wins by connecting left to right!\n";
            if (humanPlayer == Player::RED) {
                std::cout << "Congratulations! You won!\n";
            } else {
                std::cout << "AI wins!\n";
            }
        }
    }
};

int main() {
    HexGame game;
    game.playGame();
    
    std::cout << "\nThanks for playing!\n";
    return 0;
}