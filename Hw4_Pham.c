
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

// functions declaration
void setBoard(int*);
void setComputerBoard(int*);
int playGame(int*, int*);
int main(){
    int y[2], z[2], t;
   
    setBoard(y);
    srand(time(0));
    setComputerBoard(z);
    
    t = playGame(y, z);
    if(t==1){
        printf("\nHuman wins!");
    }
    else{
        printf("\nComputer wins!");
    }
  
    return 0;
}
// function to set the human's board
void setBoard(int *x){
    
    for(int i=0; i<2; i++){
      printf("Enter %dst position: ", i+1);
      scanf("%d", &*(x+i) );
      
    }
}
// function to set the computer's board
void setComputerBoard(int*x){
    
    int num1, num2;
    num1 = rand()%10;
    if(num1==9){
        num1==8;
        num2==9;
    }
    else {
        num2 = num1+1;
    }
    
    
  *x = num1;
  *(x+1) = num2;
    
}
// function to set the game
int playGame(int *x, int *y){
    int n, b; // n is input number from user, b is random number
    int r =0; // count the 'hit' times in the computer board
    int a=0; // count the 'hit' times in the human board

    char arrs[10]; // arrays of lements on human board
    char arrs1[10]; // arrays of lements on computer board
    for(int e=0; e<10; e++){
         arrs[e] = '*';
         arrs1[e]= '*';
         
    }
    //  S– printed off in the slots where the human’s ship is located
    arrs[*x]='S';
    arrs[*(x+1)]= 'S';
     //  S– printed off in the slots where the computer’s ship is located     
    arrs1[*y]='S';
    arrs1[*(y+1)]= 'S';
    
    while ( r<2 && a<2) {
     // first, let the computer guesses
      b=rand()%10-1;
      printf("\nComputer guess %d\n", b);
     // the condition when computer hit human ship
      if(b==*(x) || b==*(x+1)){
            
            printf("HIT!\n");
            arrs[b]='H';
            r++;
       }
      else{
            printf("MISS!\n");
            arrs[b]='M';
      }
     // print out human and computer board when computer guesses.
     
     printf("\nHuman Board:\n0 1 2 3 4 5 6 7 8 9\n");
     
     for(int k=0; k<10; k++){
        printf("%c ", arrs[k]);
     }
     
     printf("\nComputer Board:\n0 1 2 3 4 5 6 7 8 9\n");
    
     for(int l = 0; l<10; l++){
         printf("%c ", arrs1[l]);
     }
     // second let the human guesses 
     printf("\nEnter guess: ");
     scanf("%d", &n);
     printf("\nyou guessed %d\n", n);
     
    
        if(n==*y|| n==*(y+1)){
            
            printf("HIT ");
            
            arrs1[n]='H';
            a++;
        }
        else{
            printf("MISS ");
            arrs1[n]='M';
          
        }
     
     // print out human and computer board when human guesses
     printf("\nHuman Board:\n0 1 2 3 4 5 6 7 8 9\n");
     for(int k=0; k<10; k++){
        printf("%c ", arrs[k]);
     }
     printf("\nComputer Board:\n0 1 2 3 4 5 6 7 8 9\n");
     for(int l = 0; l<10; l++){
         printf("%c ", arrs1[l]);
     }
      
     
    }
    // return 1 if human wins, 0 if computer wins 
    if(a>r){
        return 1;
    }
    else if(a<r) {
        return 0;
    }
        
}
