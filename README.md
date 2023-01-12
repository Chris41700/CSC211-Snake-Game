# Modified Snake Game
A C++ program that modifies the snake game by generating invisible fruits with point variants, a scoreboard, and game over.

## How to install & run
- Download [Microsoft Visual Studio](https://visualstudio.microsoft.com/) 
- Clone the repository from Github 
- Go to Build >> Rebuild Solution & Run 

## Original Snake Game
* Allow movements from up, left, down, and right ('w', 'a', 's', 'd')
* Snake has a head and tail
* Spawns a border in a fixed size
* Spawns a fruit at a random location within the border
* Scores increases by 10 when a fruit is picked up
* Game over when the head hits the border or itself
* User can press 'x' to end the game

## Features Added
- [x] Changed border size
- [x] Spawns 15 invisible fruits varying with points (+10, +20, +30, +50)
- [x] Increases tail based on points/10 
- [x] Invisible fruits respawn at a random location once collected
- [x] At Game Over, a scoreboard will be displayed with the top 3 scores
- [x] Asks the user if they would like to play again

## Project Running
![2022-10-06-02-25-15](https://user-images.githubusercontent.com/60550186/194232788-823a1217-7a36-4319-88f6-ca92f3f59a29.gif)
