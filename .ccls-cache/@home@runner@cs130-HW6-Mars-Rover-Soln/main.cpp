#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Rover {
  public:
    int currentRow = 0; // TODO: give your Rover class a "currentRow"  public data member
    int currentCol = 0;  // TODO: give your Rover class a "currentCol"  public data member
}; 

class Sample { // sample location at some location on Mars
  public:
    bool isBlocked = false; // true if the rover cannot move past this location
    bool hasRoverTracks = false;
};



void initMarsMap ( Sample map[10][20], int rowCount, int colCount );// prototype - do not change (DONE FOR YOU)
void printMarsMap( Sample map[10][20] ,  int rowCount,  int colCount, Rover * roverPtr  ); //prototype
void moveRover( Sample map[10][20] ,  int rowCount,  int colCount, Rover * roverPtr, char direction ); // prototype
void testMe( Sample map[10][20], int rowCount, int  colCound, Rover *roverPtr); // prorotype

int main() {
  char userResponse; // what direction the Nasa engineer wants the rover to go

  const int numberOfRows = 10; 
  const int numberOfCols = 20;
  
  Sample marsMap[ numberOfRows ][ numberOfCols ]; // 20 rows by 40 columns

  Rover myRover; // TODO: Create a single instance of the Rover class, called "myRover"
  
  initMarsMap( marsMap, numberOfRows, numberOfCols ); // TODO: call the initMarsMap() function to initialize the map


  while ( true ) { 
    printMarsMap( marsMap, numberOfRows, numberOfCols, &myRover ); // TODO: print the map
    cout << "The Rover is sitting at row, column location == " << myRover.currentRow <<  ", " << myRover.currentCol << endl; // TODO: print the rover's current position
    cout << "Please enter a direction for the rover (r, l, u, d, x) "; // TODO: prompt the user for a direction character r, l, u, d
    cin >> userResponse; // collect the rover direction from the user

    if ( userResponse == 'x'  ) { // TODO: break out of the loop if the user response is 'x'
      cout << "Goodbye from Mars! " << endl;
        break;
    }

    moveRover( marsMap,numberOfRows, numberOfCols, &myRover, userResponse ); // TODO: otherwise, call your moveRover() function to move the rover in the requested direciton
    
  } // end while



  testMe(marsMap, numberOfRows, numberOfCols, &myRover ); // TODO: call the testMe() function to test your code before submission 

} // end main();


// DONE FOR YOU
void initMarsMap ( Sample map[10][20], int rowCount, int colCount ){

  cout << "Map of Mars (R=Rover, T=Tracks,  *=Blocked) " << endl << endl;
  
  for(int r=0; r<rowCount; r++){
    for(int c=0; c<colCount; c++) {
      // OBSTACLES
      if ( rand()%45 == 0)
        map[r][c].isBlocked = true; // create an obstacle 1 out of 5 times
      else
        map[r][c].isBlocked = false;
    }
  }

} // end initMarsMap()

// TODO Implement your moveRoverFunction (see Lab 24)
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
    // TODO: Implement similar logic as shown above, but by attemptig to move left
    if (roverPtr->currentCol-1 < 0 ) {
      cout << "moveRover(): cannot move left because that would be off the map. Please try again" << endl;
      return; // we failed to ove
    }
    else if ( map[roverPtr->currentRow][roverPtr->currentCol-1].isBlocked) {
      cout << "moveRover(): cannot move left because that location is blocked. Please try again" << endl;
      return; // we failed to move
    }
    else {
      map[roverPtr->currentRow][roverPtr->currentCol].hasRoverTracks = true; // TODO: leave tracks at the Rover's current row, column location using roverPtr->
      roverPtr->currentCol--; // DONE: update the rover position by decrementing its current column, using roverPtr->currentCol
    }
  }

  // MOVE UP one row (if possible)
  else if ( direction == 'u') {
    // TODO: Implement similar logic as shown above, but by attemptig to move up
    if (roverPtr->currentRow-1 < 0 ) {
      cout << "moveRover(): cannot move up because that would be off the map. Please try again" << endl;
      return; // we failed to move
    }
    else if (  map[roverPtr->currentRow-1][roverPtr->currentCol].isBlocked) {
      cout << "moveRover(): cannot move up because that location is blocked. Please try again" << endl;
      return; // we failed to move
    }
    else {
      map[roverPtr->currentRow][roverPtr->currentCol].hasRoverTracks = true; // TODO: leave tracks at the Rover's current row, column location using roverPtr->
      roverPtr->currentRow--; // DONE: update the rover position by decrementing its current row, using roverPtr->currentRow
    }
  }

  // MOVE DOWN one row (if possible)
  else if ( direction == 'd' ) {
    // TODO: Implement similar logic as shown above, but by attemptig to move down
    if (roverPtr->currentRow+1 >= rowCount ) {
      cout << "moveRover(): cannot move down because that would be off the map. Please try again" << endl;
      return; // we failed to ove
    }
    else if (  map[roverPtr->currentRow+1][roverPtr->currentCol].isBlocked) {
      cout << "moveRover(): cannot move down because that location is blocked. Please try again" << endl;
      return; // we failed to move
    }
    else {
      map[roverPtr->currentRow][roverPtr->currentCol].hasRoverTracks = true; // TODO: leave tracks at the Rover's current row, column location using roverPtr->
      roverPtr->currentRow++; // DONE: update the rover position by incrementing its current row, using roverPtr->currentRow
    }
  }
} // end moveRover()



// TODO: implement your printMarsMap() function here
//     print "R" for any location that exactly matches the current row and column of the Rover  
//     otherwise, print "*" for any location that is blocked
//     otherwise, print "T" for any location that has been visited by the Rover and left Tracks
//     otherwise, print "W" for any location that has water.
//     otherwise, print "-" (dash)

void printMarsMap( Sample map[10][20] ,  int rowCount,  int colCount, Rover * rover ){

  cout << endl;
  for(int r=0; r<rowCount; r++){
    for(int c=0; c<colCount; c++) {
      
      if ( rover->currentRow == r && rover->currentCol == c) {
        cout << "R";
      }
      else if ( map[r][c].isBlocked )
        cout << "*";
      else if ( map[r][c].hasRoverTracks )
        cout << "T";
      else
        cout << "-";
    }
    cout << endl;
  }
} // end printMarsMap()


void testMe(Sample map[10][20] ,  int rowCount,  int colCount, Rover * roverPtr ) {

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
}