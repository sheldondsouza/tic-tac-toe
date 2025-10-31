#include "raylib.h"
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

constexpr int SCREEN_W = 600;
constexpr int SCREEN_H = 600;

enum class Cell { Empty = 0, X = 1, O = 2 };

int boardIndex(int r, int c) { return r * 3 + c; }

void ResetBoard(std::array<Cell,9>& board) {
    board.fill(Cell::Empty);
}

int checkWinner(const std::array<Cell,9>& b) {
    const int lines[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };
    for (auto &ln : lines) {
        if (b[ln[0]] != Cell::Empty &&
            b[ln[0]] == b[ln[1]] &&
            b[ln[1]] == b[ln[2]]) {
            return (b[ln[0]] == Cell::X) ? 1 : 2;
        }
    }
    bool anyEmpty = false;
    for (auto &c : b) if (c == Cell::Empty) { anyEmpty = true; break; }
    if (!anyEmpty) return 3;
    return 0;
}

std::vector<int> emptyCells(const std::array<Cell,9>& b) {
    std::vector<int> out;
    for (int i=0;i<9;i++) if (b[i] == Cell::Empty) out.push_back(i);
    return out;
}

int chooseAIMove(std::array<Cell,9> b, Cell aiMark) {
    Cell human = (aiMark == Cell::X) ? Cell::O : Cell::X;
    auto empties = emptyCells(b);
    for (int idx : empties) {
        b[idx] = aiMark;
        if (checkWinner(b) == ((aiMark == Cell::X) ? 1 : 2)) return idx;
        b[idx] = Cell::Empty;
    }
    for (int idx : empties) {
        b[idx] = human;
        if (checkWinner(b) == ((human == Cell::X) ? 1 : 2)) return idx;
        b[idx] = Cell::Empty;
    }
    if (b[4] == Cell::Empty) return 4;
    const int corners[4] = {0,2,6,8};
    std::vector<int> availCorners;
    for (int c : corners) if (b[c] == Cell::Empty) availCorners.push_back(c);
    if (!availCorners.empty()) return availCorners[GetRandomValue(0, (int)availCorners.size()-1)];
    if (!empties.empty()) return empties[GetRandomValue(0, (int)empties.size()-1)];
    return -1;
}

int main() {
    InitWindow(SCREEN_W, SCREEN_H, "Tic-Tac-Toe (raylib)");
    SetTargetFPS(60);
    InitAudioDevice();
    std::srand(std::time(nullptr));
    SetRandomSeed(std::time(nullptr));

    // 🔊 Load sounds
    Sound moveSound = LoadSound("click.wav");
    Sound winSound = LoadSound("win.wav");
    Sound drawSound = LoadSound("draw.wav");

    std::array<Cell,9> board;
    ResetBoard(board);

    bool singlePlayer = false;
    bool xTurn = true;
    bool gameOver = false;
    int result = 0;

    const int cellSize = SCREEN_W / 3;
    std::string statusMsg = "X's turn. Press M for single-player mode.";

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_R)) {
            ResetBoard(board);
            xTurn = true;
            gameOver = false;
            result = 0;
            statusMsg = "Board reset. X's turn.";
        }

        if (IsKeyPressed(KEY_M)) {
            singlePlayer = !singlePlayer;
            ResetBoard(board);
            xTurn = true;
            gameOver = false;
            result = 0;
            statusMsg = singlePlayer ? "Single-player: You (X) vs AI (O)." : "Two-player mode.";
        }

        // Player move
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !gameOver) {
            Vector2 m = GetMousePosition();
            int col = (int)m.x / cellSize;
            int row = (int)m.y / cellSize;
            if (row >= 0 && row < 3 && col >= 0 && col < 3) {
                int idx = boardIndex(row, col);
                if (board[idx] == Cell::Empty) {
                    board[idx] = xTurn ? Cell::X : Cell::O;
                    PlaySound(moveSound);
                    xTurn = !xTurn;
                    result = checkWinner(board);
                    if (result != 0) {
                        gameOver = true;
                        if (result == 1) { statusMsg = "X wins!"; PlaySound(winSound); }
                        else if (result == 2) { statusMsg = "O wins!"; PlaySound(winSound); }
                        else { statusMsg = "Draw!"; PlaySound(drawSound); }
                        statusMsg += " Press R to play again.";
                    } else {
                        statusMsg = (xTurn ? "X's turn." : "O's turn.");
                    }
                }
            }
        }

        // AI move
        if (singlePlayer && !xTurn && !gameOver) {
            static int aiDelay = 0;
            aiDelay++;
            if (aiDelay > 15) {
                aiDelay = 0;
                int aiIdx = chooseAIMove(board, Cell::O);
                if (aiIdx != -1) {
                    board[aiIdx] = Cell::O;
                    PlaySound(moveSound);
                    xTurn = true;
                    result = checkWinner(board);
                    if (result != 0) {
                        gameOver = true;
                        if (result == 1) { statusMsg = "X wins!"; PlaySound(winSound); }
                        else if (result == 2) { statusMsg = "O wins!"; PlaySound(winSound); }
                        else { statusMsg = "Draw!"; PlaySound(drawSound); }
                        statusMsg += " Press R to play again.";
                    } else {
                        statusMsg = "X's turn.";
                    }
                }
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i=1;i<=2;i++) {
            DrawLine(i * cellSize, 0, i * cellSize, SCREEN_H, DARKGRAY);
            DrawLine(0, i * cellSize, SCREEN_W, i * cellSize, DARKGRAY);
        }

        for (int r=0;r<3;r++) {
            for (int c=0;c<3;c++) {
                int idx = boardIndex(r,c);
                int cx = c * cellSize + cellSize/2;
                int cy = r * cellSize + cellSize/2;
                int half = cellSize/3;
                if (board[idx] == Cell::X) {
                    DrawLine(cx - half, cy - half, cx + half, cy + half, MAROON);
                    DrawLine(cx - half, cy + half, cx + half, cy - half, MAROON);
                } else if (board[idx] == Cell::O) {
                    DrawCircleLines(cx, cy, half, DARKBLUE);
                }
            }
        }

        DrawRectangle(0, SCREEN_H - 60, SCREEN_W, 60, Fade(LIGHTGRAY, 0.6f));
        DrawText(statusMsg.c_str(), 10, SCREEN_H - 50, 20, BLACK);
        DrawText(singlePlayer ? "Mode: Single-player" : "Mode: Two-player", 10, 10, 18, BLACK);
        DrawText("Press M to toggle mode | R to reset", 10, 30, 16, GRAY);

        EndDrawing();
    }

    // 🔊 Unload and cleanup
    UnloadSound(moveSound);
    UnloadSound(winSound);
    UnloadSound(drawSound);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
