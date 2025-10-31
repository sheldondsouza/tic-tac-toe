# ✖️⭕✖️ Tic-Tac-Toe

<div align="center">

<!-- TODO: Add project logo or a fun ASCII art representation of Tic-Tac-Toe -->

[![GitHub stars](https://img.shields.io/github/stars/sheldondsouza/tic-tac-toe?style=for-the-badge)](https://github.com/sheldondsouza/tic-tac-toe/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/sheldondsouza/tic-tac-toe?style=for-the-badge)](https://github.com/sheldondsouza/tic-tac-toe/network)
[![GitHub issues](https://img.shields.io/github/issues/sheldondsouza/tic-tac-toe?style=for-the-badge)](https://github.com/sheldondsouza/tic-tac-toe/issues)
[![GitHub license](https://img.shields.io/github/license/sheldondsouza/tic-tac-toe?style=for-the-badge)](LICENSE)

**Relive the classic paper-and-pencil game with an interactive C++ console experience and engaging audio feedback!**

</div>

## 📖 Overview

This repository hosts a straightforward, interactive command-line implementation of the classic Tic-Tac-Toe game, developed in C++. Designed for two players, it provides a simple yet engaging experience with clear console output and integrated audio cues for moves and game outcomes, bringing a nostalgic feel to a digital format.

## ✨ Features

-   🎯 **Classic 3x3 Grid Gameplay**: Standard Tic-Tac-Toe rules apply.
-   👥 **Two-Player Mode**: Players take turns marking 'X' or 'O'.
-   🏆 **Automatic Win/Draw Detection**: The game intelligently identifies winning lines and draws.
-   🔊 **Audio Feedback**: Enjoy distinct sound effects for player moves (`click.wav`) and game victories (`win.wav`).
-   ✍️ **Interactive Console Interface**: User-friendly text-based prompts for player input and game state display.

## 🛠️ Tech Stack

**Core Language:**
[![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)

**Audio (Windows-specific):**
Uses native Windows API for sound playback.

## 🚀 Quick Start

### Prerequisites

To compile and run this project from source, you will need:

-   A C++ compiler (e.g., GCC/G++, MinGW for Windows, or MSVC).
-   On Windows, for audio support, the `winmm` library (usually linked automatically with MinGW/GCC via `-lwinmm`).

### Installation & Run

You have two options to get the game running:

#### Option 1: Run the Pre-compiled Executable (Windows)

If you are on Windows, you can directly run the pre-compiled executable:

1.  **Clone the repository**
    ```bash
    git clone https://github.com/sheldondsouza/tic-tac-toe.git
    cd tic-tac-toe
    ```
2.  **Execute the game**
    ```bash
    ./ttt.exe
    ```

#### Option 2: Compile from Source

1.  **Clone the repository**
    ```bash
    git clone https://github.com/sheldondsouza/tic-tac-toe.git
    cd tic-tac-toe
    ```

2.  **Compile the source code**
    Use your preferred C++ compiler. For GCC/MinGW, use the following command (the `-lwinmm` flag is necessary for audio playback on Windows systems):

    ```bash
    g++ main.cpp -o tic-tac-toe -lwinmm
    ```
    *If compiling on Linux/macOS, you might need to adjust or remove the `-lwinmm` flag if you encounter linker errors, as the audio playback might be Windows-specific or require a different library.*

3.  **Run the compiled game**
    ```bash
    ./tic-tac-toe
    ```

## 🎮 Usage

Once the game is running (either via `ttt.exe` or `./tic-tac-toe`):

1.  The Tic-Tac-Toe board will be displayed in the console.
2.  Players will be prompted to enter the number corresponding to the cell where they want to place their 'X' or 'O'.
3.  The game will announce wins, losses, or draws.
4.  Audio cues will play for each move and when a player wins.

## 📁 Project Structure

```
tic-tac-toe/
├── main.cpp        # Main source code for the Tic-Tac-Toe game logic
├── ttt.exe         # Pre-compiled Windows executable of the game
├── click.wav       # Audio file for player move sound effect
├── win.wav         # Audio file for winning sound effect
└── README.md       # Project README file
```

## 🤝 Contributing

While this is a simple game, contributions are welcome! If you have suggestions for improvements, bug fixes, or new features (e.g., AI opponent, better UI), feel free to fork the repository and submit a pull request.

## 📄 License

This project is licensed under the [LICENSE_NAME](LICENSE) - see the LICENSE file for details. <!-- TODO: Add actual license type and file if available -->

## 🙏 Acknowledgments

-   The classic game of Tic-Tac-Toe for endless simple fun.
-   The C++ community and standard library for providing the tools.

## 📞 Support & Contact

-   🐛 Issues: Feel free to report any bugs or suggest features on the [GitHub Issues page](https://github.com/sheldondsouza/tic-tac-toe/issues).

---

<div align="center">

**⭐ Star this repo if you find this simple game enjoyable!**

Made with ❤️ by [sheldondsouza](https://github.com/sheldondsouza)

</div>
