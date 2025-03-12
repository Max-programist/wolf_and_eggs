#include <iostream>
#include <unistd.h>
// #include <conio.h>
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

 struct wolf wolf = {5, 5};
 std::vector<std::vector<char>> create();
 void  fill(std::vector<std::vector<char>>  &arr);
 void print(const std::vector<std::vector<char>>& arr);
 void generation_eggs(std::vector<std::vector<char>>& arr);
// void move_eggs(std::vector<std::vector<char>>& arr);
// void wolf(std::vector<std::vector<char>>& arr);


 int main() {
      srand(time(0));
   
       std::vector<std::vector<char>> arr = create();
       fill(arr);
      //wolf(arr);

      for( ; ; ) {
       generation_eggs(arr);
//        move_eggs(arr);
         print(arr);
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



void print(const std::vector<std::vector<char>>& arr) {
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



// void move_eggs(std::vector<std::vector<char>>& arr) {


  
//   for(int i = A - 2; i >= 1; i--) {
//     for(int j = 1; j < B - 1; j++) {
   
//       if(arr[i][j] == 'o') {
//         arr[i][j] = '.';
//         arr[i + 1][j] = 'o';
//       }
//     }
//   }



// }



// void wolf(std::vector<std::vector<char>>& arr) {

//   char c = getchar();
//   if(c == 'q') {
//     exit(0);
//   } else if(c == 'a') {
//     //to do smt
//   } else if(c == 'd') {
//     //smt
//   }
  

// }