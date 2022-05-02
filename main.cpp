#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Rover
{
  public:
    int currentRow = 0;
    int currentCol = 0;
    int waterUnits = 0; 
};

class Sample
{
  public:
    bool isBlocked = false;
    bool hasWater = false;
    bool hasRoverTracks = false;
};

void initMarsMap (Sample map[10][20], int rowCount, int colCount);

void printMarsMap(Sample map[10][20], int rowCount, int colCount, Rover *roverPtr); 

void moveRover( Sample map[10][20], int rowCount, int colCount, Rover *roverPtr, char direction ); 

void testMe(Sample map[10][20], int rowCount, int  colCount, Rover *roverPtr); 

int main() 
{
  char userResponse; // what direction the NASA engineer wants the rover to go
  const int numberOfRows = 10; 
  const int numberOfCols = 20;
  Sample marsMap[numberOfRows][numberOfCols];
  Rover myRover;

  initMarsMap (marsMap, numberOfRows, numberOfCols);

  while (true) 
  { 
    printMarsMap(marsMap, numberOfRows, numberOfCols, &myRover);
    
    cout << endl << "Current location: " << myRover.currentRow << ", " << myRover.currentCol << endl;
    
    cout << "Please enter a direction for the rover (r, l, u, d, x) "; 
    cin >> userResponse; // Collect the rover direction from the user

    if (userResponse == 'x') // Break out of the loop if the user response is 'x'
    { 
      cout << "Goodbye from Mars! " << endl;
        break;
    }
    else
      moveRover(marsMap, numberOfRows, numberOfCols, &myRover, userResponse); 
  } 

  testMe(marsMap, numberOfRows, numberOfCols, &myRover ); 
} 

void initMarsMap (Sample map[10][20], int rowCount, int colCount)
{
  for(int r = 0; r < rowCount; r++)
  {
    for(int c = 0; c < colCount; c++) 
    {
      // OBSTACLES
      if (rand() % 45 == 0) // 1/45 chance of being blocked at this location
        map[r][c].isBlocked = true; // create an obstacle here
      else
        map[r][c].isBlocked = false;
      // WATER
      if (rand() % 45 == 0) // 1/45 chance of being water at this location
        map[r][c].hasWater = true; // create water here
      else
        map[r][c].hasWater = false;
    }
  }
} 

void moveRover(Sample map[10][20], int rowCount, int colCount, Rover *roverPtr, char direction) 
{
  // MOVE RIGHT on column 
  if (direction == 'r')
  {
    if (roverPtr->currentCol == colCount - 1) 
    {
      cout << "moveRover(): cannot move right because that would be off the map. Please try again" << endl;
      return; // we failed to move
    }
    else if (map[roverPtr->currentRow][roverPtr->currentCol + 1].isBlocked) 
    {
      cout << "moveRover(): cannot move right because that location is blocked. Please try again" << endl;
      return; // we failed to move
    }
    else if (map[roverPtr->currentRow][roverPtr->currentCol].hasWater)
      roverPtr->currentCol++; 
    else
    {
      // leave tracks at the Rover's current row, column location 
      map[roverPtr->currentRow][roverPtr->currentCol].hasRoverTracks = true; 
      roverPtr->currentCol++; // Update the rover position by incrementing the current column
    }
  }
  else if (direction == 'l') 
  {
    if (roverPtr->currentCol == 0) 
    {
      cout << "moveRover(): cannot move left because that would be off the map. Please try again" << endl;
      return; // We failed to move
    }
    else if (map[roverPtr->currentRow][roverPtr->currentCol - 1].isBlocked) 
    {
      cout << "moveRover(): cannot move left because that location is blocked. Please try again" << endl;
      return; 
    }
   else if (map[roverPtr->currentRow][roverPtr->currentCol].hasWater)
      roverPtr->currentCol--; // Update the rover position by decrementing the current column
    else
    {
      // Leave tracks at the rover's current row, column location
      map[roverPtr->currentRow][roverPtr->currentCol].hasRoverTracks = true; 
      roverPtr->currentCol--; 
    }
  }  
  else if (direction == 'u') 
  {
    if (roverPtr->currentRow == 0) 
    {
      cout << "moveRover(): cannot move up because that would be off the map. Please try again" << endl;
      return; // We failed to move
    }
    else if (map[roverPtr->currentRow - 1][roverPtr->currentCol].isBlocked) 
    {
      cout << "moveRover(): cannot move up because that location is blocked. Please try again" << endl;
      return; 
    }
    else if (map[roverPtr->currentRow][roverPtr->currentCol].hasWater)
      roverPtr->currentRow--; // Update the rover position by decrementing the current row
    else
    {
      map[roverPtr->currentRow][roverPtr->currentCol].hasRoverTracks = true;
      // Leave tracks at the rover's current row, column location
      roverPtr->currentRow--;
    }
  }
  else if (direction == 'd') 
  {
    if (roverPtr->currentRow == rowCount - 1) 
    {
      cout << "moveRover(): cannot move down because that would be off the map. Please try again" << endl;
      return; // We failed to move
    }
    else if (map[roverPtr->currentRow + 1][roverPtr->currentCol].isBlocked) 
    {
      cout << "moveRover(): cannot move down because that location is blocked. Please try again" << endl;
      return; 
    }
    else if (map[roverPtr->currentRow][roverPtr->currentCol].hasWater)
      roverPtr->currentRow++; // Update the rover's location by incrementing its row
    else
      map[roverPtr->currentRow][roverPtr->currentCol].hasRoverTracks = true; 
    // Leave tracks where the rover has been 
      roverPtr->currentRow++; 
  }
  if (map[roverPtr->currentRow][roverPtr->currentCol].hasWater)
    roverPtr->waterUnits++; // Collect water if the rover is on a body of water
} 

void printMarsMap(Sample map[10][20], int rowCount, int colCount, Rover * roverPtr)
{
   cout << "Map of Mars (R=Rover, T=Tracks, W=Water  *=Blocked) " << endl << endl;
  for(int row = 0; row < rowCount; row++)
   {
     for(int col = 0; col < colCount; col++)
       {
         if(row == roverPtr->currentRow && col == roverPtr->currentCol)
           cout << 'R';
            else if(map[row][col].isBlocked)
           cout << '*';
         else if(map[row][col].hasWater)
           cout << 'W'; 
         else if(map[row][col].hasRoverTracks)
           cout << 'T';
         else
           cout << '-';
       }
     cout << endl;
   }
  cout << "The rover has collected " << roverPtr->waterUnits << " units of water." << endl;
}

void testMe(Sample map[10][20],  int rowCount, int colCount, Rover *roverPtr) 
{
  srand( 12 ); // set the random seed so our marsMap will be initialized in a predictable way.
  const char *directions = "rldu";// r is at position 0, l is at position 1, etc.

  cout << "Ready to test? (y, else quit)? ";
  char response;
  cin >> response;

  if (response != 'y' ) 
  {
    cout << "Abort test - goodbye" << endl;
  }

  cout << "Placing the rover in row, column 0, 0..";
  roverPtr->currentRow = roverPtr->currentCol = 0;
  cout  << "DONE" << endl;

  cout << "Re-Initializing the Mars Map..";
  initMarsMap( map, rowCount, colCount );
  cout  << "DONE" << endl;

  std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
  
  for(int x=0; x<10000; x++)
  {
    int randomDirection = rand() % 4;
    cout << "moving direction = " << directions[randomDirection] << endl;
    moveRover(map, rowCount, colCount, roverPtr, directions[randomDirection]) ;
  }

  std::cout.rdbuf(coutbuf); //reset to standard output again

  cout << "Final map: " << endl;
  printMarsMap( map, rowCount, colCount, roverPtr ); 
  cout << "See out.txt for standard output, if any" << endl;
} 