#include <iostream>
#include <unistd.h>
#include <conio.h>

//plan:
//1.draw
//2.eggs
//3.wolf



#define  A  15  
#define  B  10

char** create();
void free_arr(char** arr);
void  fill(char** arr);
void print(char** arr);
void generation_eggs(char** arr);
void move_eggs(char** arr);
void wolf(char** arr);

int main() {
    srand(time(0));

    std::cout << "Hello world" << std::endl;

    char** arr = create();
    fill(arr);
    arr[A - 1][B / 2] = 'w';
    wolf(arr);
    //ctrukt
    // for( ; ; ) {
    //   generation_eggs(arr);
    //   move_eggs(arr);
    //   print(arr);
    //   sleep(1);

    // }


    free_arr(arr);
    return 0;
}

char** create() {
  std::cout << "allocated memory for arr" << std::endl;
    char** arr = (char**)malloc(A * sizeof(char*));
      for(int i = 0; i < A; i++) {
        arr[i] = (char*)malloc(B * sizeof(char));
      }
      return arr;
}

void  fill(char** arr) {
    for(int i = 0; i < A; i++) {
      for(int j = 0; j < B; j++) {
        
        arr[i][j] = '.';
        if(i == 0 || j == 0 || j == B - 1) {
          arr[i][j] = '|';
        }
      }
    }

}



void print(char** arr) {
  for(int i = 0; i < A; i++) {
    for(int j = 0; j < B; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


void free_arr(char** arr){
    for(int i = 0; i < A; i++) {
        free(arr[i]);
    }
    free(arr);
}

// 1.......8
void generation_eggs(char** arr) {
//          x % (b - a + 1) + 2  
  
  

  if(rand() % 100 >= 29) {
    int egg = rand() % (B - 2) + 1;
    arr[1][egg] = 'o'; 
  }

  

}



void move_eggs(char** arr) {


  
  for(int i = A - 2; i >= 1; i--) {
    for(int j = 1; j < B - 1; j++) {
   //s   std::cout << "aaaaaaaaaa0" << std::endl;
      if(arr[i][j] == 'o') {
        arr[i][j] = '.';
        arr[i + 1][j] = 'o';
      }
    }
  }



}



void wolf(char** arr) {

  char c = getchar();
  if(c == 'q') {
    exit(0);
  } else if(c == 'a') {
    //to do smt
  } else if(c == 'd') {
    //smt
  }
  

}












