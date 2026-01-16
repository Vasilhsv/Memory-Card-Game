# Memory Card Game

Welcome to the **Memory Card Game**! This is a console-based puzzle game written in C, where your goal is to find matching pairs of numbers on the board.

## 📥 Download

To get started, you need to download the source code file to your computer:
* [Memory_Card_Game.c](Memory_Card_Game.c)

---

## ⚙️ Installation Guide (Windows)

To compile and run this game, you need the **GCC compiler**. If you don't have it installed, please follow these steps:

### Step 1: Install MSYS2
1.  Open **PowerShell** or **CMD** (Command Prompt).
2.  Run the following command:
    ```powershell
    winget install -e --id MSYS2.MSYS2
    ```

### Step 2: Install GCC
1.  After installation, open the **MSYS2 UCRT64** application (search for it in the Start Menu).
2.  In the terminal that opens, type the following command to install the toolchain:
    ```bash
    pacman -S mingw-w64-ucrt-x86_64-gcc
    ```
3.  When asked `Proceed with installation? [Y/n]`, type **y** and press **Enter**.

### Step 3: Add to Windows Path
To make the compiler accessible from Windows:
1.  Press the **Windows Key** and type: `env`.
2.  Select **"Edit the system environment variables"**.
3.  Click on the **Environment Variables...** button.
4.  Under **System variables** (bottom section), find the row named **Path**, select it, and click **Edit**.
5.  Click **New** and paste the following path (assuming default installation):
    `C:\msys64\ucrt64\bin`
6.  Click **OK** on all windows.
7.  **Important:** Close any open CMD or PowerShell windows for the changes to take effect.

### Step 4: Verification
Open a new terminal and type:
   ```cmd
   gcc --version
   ```
If you see a message like gcc.exe (Rev...) 13.2.0, you are ready to go!


## 🚀 How to Compile & Run
Open your terminal (CMD or PowerShell) inside the folder where you saved Memory_Card_Game.c and run the following commands:

🔹 If using PowerShell:
   ```powershell
    gcc Memory_Card_Game.c -o Memory_Card_Game.exe
    ./Memory_Card_Game.exe
   ```
🔹 If using CMD:
   ```cmd
   gcc Memory_Card_Game.c -o Memory_Card_Game.exe
   Memory_Card_Game.exe
   ```

## 🎮 Gameplay Instructions
This is a classic memory game. You will be asked to select positions on the board to reveal hidden numbers.

If the two selected numbers are the same, they remain open.

If they are different, they will be hidden again.

The game ends when all pairs are found.

Difficulty Levels
There are 3 difficulty levels to choose from:

1.  Easy: 2x2 Grid

2.  Medium (Default): 4x4 Grid

3.  Hard: 6x6 Grid
