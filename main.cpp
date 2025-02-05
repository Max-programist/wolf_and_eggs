#include <iostream>
//plan:
//1.draw
//2.eggs
//3.wolf

#define  A  20  
#define  B  10

char** create();

int main() {


    std::cout << "Hello world" << std::endl;

    char** arr = create();
    return 0;
}

char** create() {
    char** arr = (char**)malloc(A * sizeof(char*));
      for(int i = 0; i < A; i++) {
        arr[i] = (char*)malloc(B * sizeof(char));
      }
      return arr;
}

// void  draw(int** arr) {
//     for(int i = 0; i < )


// }

// void free()