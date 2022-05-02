# Mars-Rover
Create a Mars Rover object and a 2D array object with randomly generated obstacles. Navigate rover across the array grid map.

What the program does:
-- Creates a Mars map (2D array object of class Sample) 
-- Randomly generates obstacles and bodies of water at various map locations (grid cells)
-- Creates a rover object (of class Rover)
-- Moves rover throughout map
-- Rover collects one unit of water upon landing on a body of water

What the program entails:
-- Coded in C++
-- Object-oriented design
-- Functions to initialize map, print map, and move rover
-- Constant integer map dimensions
-- Number and placement of water and obstacles are randomly generated 
-- 2% chance an array element is blocked by an obstacle
-- 2% chance an array element is a body of water
-- An average of 8 unconventional array elements per map, or 4% of the map 
-- Displays rover's location after each move
-- Rover moves either down, left, right, or up based on user input
-- Utilizes pointers/addresses and the values at those addresses to determine: whether the rover can move in a certain direction and still stay on the map, 
whether the address holds a body of water or an obstacle, and whether the rover leaves tracks to be stored at that address 
-- Rover cannot occupy a blocked/obstacle array element and cannot move off the map
-- Rover collects one unit of water at each body of water
-- Increments row and column dimensions of rover's current location to allow rover to move
-- Preserves rover's path by leaving tracks on the non-water elements on which the rover has traversed 
-- Rover can move an unlimited times, until the user input of 'x' indicates that the user wants to quit the program
-- Testing function to test: the initialize map function, the print map function, user direction input, and the rover movement function
-- Stores the output in a text file 

Further applications -- added complexity for gaming:
-- User-generated map dimensions
-- More varied obstacles, with creative descriptions when they are encountered
-- Health points, weapons, treasure, and other prizes that can be picked up, in addition to units of water
-- More varied classes besides rovers as character types, and function to move these different characters
-- A tiebreaker function when one character tries to occupy an element that another character already occupies
