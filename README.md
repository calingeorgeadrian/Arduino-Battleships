# Battleships

# Game Description
Battleships is a guessing game for two players. It is played on ruled grids on which each player's fleet of ships are marked. The locations of the fleets are concealed from the other player. Players alternate turns taking "shots" at the other player's ships, and the objective of the game is to destroy the opposing player's fleet.  
  
# How to Play
When the Arduino is turned on, both players will be greeted with the message "Press the left button to begin". After both players press the buttons, they can start placing their ships.
  
Before the game begins, each player secretly arranges their ships on their grid by moving them using the joystick and placing the ship using the left button. Each ship occupies a number of consecutive squares on the grid, arranged either horizontally or vertically (sadly, currently rotating a ship is not possible due to a bug). The number of squares for each ship is determined by the type of the ship. The ships cannot overlap (i.e., only one ship can occupy any given square in the grid). The types and numbers of ships allowed are the same for each player.
  
After the ships have been positioned, the game proceeds in a series of rounds. In each round, each player takes a turn to pick a target  square (by moving the joystick) in the opponent's grid which is to be shot at. The player will be announced on his LCD whether or not the square is occupied by a ship, and if it is a "miss", the LCD will say "Missed at X Y" and next time the led on the matrix will flash, telling him that he missed at those coordinates; if it is a "hit"  the LCD will say "Ship hit at X Y" and next time the led on the matrix will be lit, telling him that he hit a ship at those coordinates. The X and Y are the coordinates of the target.

If all of a player's ships have been sunk, the game is over and their opponent wins.
  
# Components used
  - Arduino Mega
  - 2 8x8 Matrices
  - 2 MAX7219 Drivers
  - 2 16x2 LCDs
  - 4 Buttons
  - 2 Joysticks
  - 1 Buzzer
  - Many Resistances, Capacitors and Jumpers
