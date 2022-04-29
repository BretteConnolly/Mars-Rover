#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// TODO: create a Rover class with two integer data members called "currentRow" and "currentCol", both set to zero


// TODO: create a Sample class with two bool members "isBlocked" and "hasRoverTracks", both set to false



void initMarsMap ( Sample map[10][20], int rowCount, int colCount );// prototype - do not change (DONE FOR YOU below main())
void printMarsMap( Sample map[10][20] ,  int rowCount,  int colCount, Rover * roverPtr  ); //prototype - do not change (implement below main())
void moveRover( Sample map[10][20] ,  int rowCount,  int colCount, Rover * roverPtr, char direction ); // prototype - do not change (implement below main())
void testMe( Sample map[10][20], int rowCount, int  colCound, Rover *roverPtr); // prorotype - do not change (DONE FOR YOU below main())

int main() {
  char userResponse; // what direction the Nasa engineer wants the rover to go
  const int numberOfRows = 10; 
  const int numberOfCols = 20;

  // TODO: Create a 2D array called "marsMap" that is of type "Sample", where each row, col location of your map is a Sample instance
  // TODO: Create a single instance of the Rover class, called "myRover"
  // TODO: call the initMarsMap() function (provided below) to initialize the marsMap


  while ( true ) { // loop until we break;
    
    // TODO: print the map
    // TODO: print the rover's current row and column location
    
    cout << "Please enter a direction for the rover (r, l, u, d, x) "; // TODO: prompt the user for a direction character r, l, u, d
    cin >> userResponse; // collect the rover direction from the user

    if ( userResponse == 'x'  ) { // DONE: break out of the loop if the user response is 'x'
      cout << "Goodbye from Mars! " << endl;
        break;
    }

    // TODO: otherwise, call your moveRover() function to move the rover in the requested direciton
    
  } // end while


  // testMe(marsMap, numberOfRows, numberOfCols, &myRover ); // TODO: call the testMe() function to test your code before submission 

} // end main();


// DONE FOR YOU
void initMarsMap ( Sample map[10][20], int rowCount, int colCount ){
  
  for(int r=0; r<rowCount; r++){
    for(int c=0; c<colCount; c++) {
      // OBSTACLES
      if ( rand()%45 == 0) // 1/45 chance of being blocked at this location
        map[r][c].isBlocked = true; // create an obstacle here
      else
        map[r][c].isBlocked = false;
    }
  }
} // end initMarsMap()


// TODO Finish implementation of your moveRover Function (see Lab 24)
// ADD the further restriction that the rover cannot move through any obstacles
//  that is, if the isBlocked data member of a Sample is true, then the rover cannot move in that direction and the function should return

void moveRover( Sample map[10][20] ,  int rowCount,  int colCount, Rover *roverPtr, char direction ) {

  // MOVE RIGHT on column (DONE FOR YOU)
  if ( direction == 'r'){
    if (roverPtr->currentCol+1 >= colCount ) {
      cout << "moveRover(): cannot move right because that would be off the map. Please try again" << endl;
      return; // we failed to ove
    }
    else if ( map[roverPtr->currentRow][roverPtr->currentCol+1].isBlocked) {
      cout << "moveRover(): cannot move right because that location is blocked. Please try again" << endl;
      return; // we failed to move
    }
    else {
      map[roverPtr->currentRow][roverPtr->currentCol].hasRoverTracks = true; // DONE: leave tracks at the Rover's current row, column location using roverPtr->
      roverPtr->currentCol++; // DONE: update the rover position by incrementing the current column
    }
  } // end MOVE RIGHT

  // MOVE LEFT one column (if possible)
  else if ( direction == 'l') {
    // TODO: Implement similar logic as shown above, but by attempting to move left
  } // end MOVE LEFT

  // MOVE UP one row (if possible)
  else if ( direction == 'u') {
    // TODO: Implement similar logic as shown above, but by attempting to move up
  } // end MOVE UP

  // MOVE DOWN one row (if possible)
  else if ( direction == 'd' ) {
    // TODO: Implement similar logic as shown above, but by attempting to move down
  } // end MOVE DOWN
  
} // end moveRover()



// TODO: implement your printMarsMap() function here (see lab 23)
//     print "R" for any location that exactly matches the current row and column of the Rover  
//     otherwise, print "*" for any location that is blocked
//     otherwise, print "T" for any location that has been visited by the Rover and left Tracks
//     otherwise, print "-" (dash)

void printMarsMap() {
  cout << "Map of Mars (R=Rover, T=Tracks,  *=Blocked) " << endl << endl;

} // end printMarsMap()



// DONE: The testMe() function is done for you.  Call it from the bottom of main() before your program exits
void testMe( Sample map[10][20] ,  int rowCount,  int colCount, Rover * roverPtr ) {

  srand( 12 ); // set the random seed so our marsMap will be initialized in a predictable way.
  const char * directions = "rldu";// r is at position 0, l is at position 1, etc.

  cout << "Ready to test? (y, else quit)? ";
  char response;
  cin >> response;

  if (response != 'y' ) {
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
  
  for(int x=0; x<10000; x++){
    int randomDirection = rand()%4;
    cout << "moving direction = " << directions[randomDirection] << endl;
    moveRover( map, rowCount, colCount, roverPtr, directions[randomDirection]) ;
  }

  std::cout.rdbuf(coutbuf); //reset to standard output again

  cout << "Final map: " << endl;
  printMarsMap( map, rowCount, colCount, roverPtr ); 
  cout << "See out.txt for standard output, if any" << endl;
} // end testMe()