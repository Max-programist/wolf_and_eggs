#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <vector>
// //plan:
// //1.draw
// //2.eggs
// //3.wolf



#define  A  15  
#define  B  10

struct wolf {
    int i;
    int j;

};

 struct wolf wolf = {A - 1, B / 2};
 std::vector<std::vector<char>> create();
 void  fill(std::vector<std::vector<char>>  &arr);
 void print(const std::vector<std::vector<char>>& arr, const int* points);
 void generation_eggs(std::vector<std::vector<char>>& arr);
 void move_eggs(std::vector<std::vector<char>>& arr);
//void wolf(std::vector<std::vector<char>>& arr);
void check_eggs(std::vector<std::vector<char>>& arr, int* points);

 int main() {
      srand(time(0));

      


      unsigned int x=0, y=0;
      int ch;
  
      initscr ();
      keypad (stdscr, 1);
  
      do {
          mvprintw(y, x, "Hello World !!!");
          refresh();
          ch = getch();
          mvprintw(y, x, "               ");
          
          if(ch == KEY_UP) {
            y--; 
            y %= LINES;
          } else if (ch == KEY_DOWN) {
            y++;
            y %= LINES;
          } else if(ch == KEY_LEFT) {
            x--;
            x %= COLS ;
          } else if(ch == KEY_RIGHT) {
            x++; 
            x %= COLS ;
          }

      } while (ch != 'q');
  
      endwin();

       std::vector<std::vector<char>> arr = create();
       fill(arr);
      //wolf(arr);
      int point = 0;
      for( ; ; ) {
       generation_eggs(arr);
        move_eggs(arr);
        print(arr, &point);
        check_eggs(arr, &point);
        sleep(1);

      }
    
 
    


     return 0;
}

// void aaaa(int* a, int& b, int c) {
//     if(a != NULL) {
//         *a = *a * (-1);
        
//     }
    
//     b = b * (-1);
//     c = c * (-1);
// }


std::vector<std::vector<char>> create() {
  std::cout << "create arr" << std::endl;
      std::vector<std::vector<char>> arr = {};
      for(int i = 0; i < A; i++) {
        std::vector<char> temp = {};
        for(int j = 0; j < B; j++) {
            temp.push_back('.');
        }
        arr.push_back(temp);
      }

      return arr;
}



 void  fill(std::vector<std::vector<char>> &arr) {
     for(int i = 0; i < A; i++) {
      for(int j = 0; j < B; j++) {
        
        arr[i][j] = '.';
        arr[wolf.i][wolf.j] = 'w';
        if(i == 0 || j == 0 || j == B - 1) {
          arr[i][j] = '|';
        }
      }
    }

}



void print(const std::vector<std::vector<char>>& arr, const int* points) {
  std::cout << "Points:" << *points << std::endl;
  for(int i = 0; i < A; i++) {
    for(int j = 0; j < B; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}




void generation_eggs(std::vector<std::vector<char>>& arr) {

  


  if(rand() % 100 >= 0) {

    int egg = rand() % (B - 2) + 1;
    arr[1][egg] = 'o'; 

  }

  

}



void move_eggs(std::vector<std::vector<char>>& arr) {


  
  for(int i = A - 2; i >= 1; i--) {
    for(int j = 1; j < B - 1; j++) {
   
      if(arr[i][j] == 'o') {
        arr[i][j] = '.';
        arr[i + 1][j] = 'o';
      }
    }
  }



}

void check_eggs(std::vector<std::vector<char>>& arr, int* points) {

  for(int i = 1; i < B - 1; i++) {
    if(arr[A - 2][i] == 'o') {

      if(wolf.j == i) {
        (*points)++;
        arr[A - 2][i] = '.';
      } else {
        //
      }

    } 
    
  }
}

///void wolf(std::vector<std::vector<char>>& arr) {

//   char c = getchar();
//   if(c == 'q') {
//     exit(0);
//   } else if(c == 'a') {
//     //to do smt
//   } else if(c == 'd') {
//     //smt
//   }
  

// }