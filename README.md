# MUSIC-SYSTEM-
🎵 Playlist Manager (C++ Linked List Project)
📌 Overview

This project is a Playlist Manager built using C++ and Linked List data structure. It allows users to manage a music playlist through a simple menu-driven interface in the console.

The program demonstrates the use of dynamic memory allocation, object-oriented programming, and linked list operations in a practical real-world scenario.

🚀 Features
➕ Add songs to playlist
Insert at beginning
Insert at end
❌ Delete songs
Delete from beginning
Delete from end
🔍 Search songs by name
📃 Display full playlist
🎧 Play songs one-by-one
🔢 Count total number of songs
🧠 Concepts Used
Singly Linked List
Classes & Objects (OOP)
Dynamic Memory Allocation (new, delete)
Pointers
Menu-driven programming
🏗️ Project Structure
🔹 NODE Class

Represents each song in the playlist.

Attributes:

SID → Song ID
SONG → Song Name
ARTIST → Artist Name
NEXT → Pointer to next node
🔹 LinkList Class

Manages the entire playlist.

Key Functions:

insertNode() → Add new song
deleteNode() → Remove song
showNode() → Display playlist
searchSong() → Find song by name
playSongs() → Simulate playing songs
countNodes() → Count total songs
MainMenu() → User interface
▶️ How It Works
Program starts with a main menu
User selects an operation:
Add / Delete / Search / Play
Operations are performed using linked list traversal
Songs are dynamically stored in memory
💡 Example Output
====== 🎵 Playlist Manager ======

1. Add Songs
2. Show Playlist
3. Delete Songs
4. Search Song
5. Play Playlist
6. Count Songs
7. Exit
⚠️ Limitations
Data is not stored permanently (no file handling)
Uses conio.h (not portable for all compilers)
Limited delete options (only beginning/end)
🔮 Future Enhancements
✅ Add file handling (save playlist)
✅ Delete song by name
✅ Update song details
✅ Reverse playlist
✅ GUI or Web-based version
🛠️ Technologies Used
Language: C++
Concepts: Data Structures & OOP
Compiler: Turbo C++ / GCC


