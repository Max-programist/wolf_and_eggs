#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <vector>
#include <sys/select.h>
#include <fcntl.h>
#include <thread>
#include <chrono>

#define  A  15  
#define  B  6

struct wolf {
  int i;
  int j;
  uint speed;
};

struct wolf position_wolf = {A - 1, B / 2, 1000000000};
std::vector<std::vector<char>> create();
void  fill(std::vector<std::vector<char>>  &arr);
void print(const std::vector<std::vector<char>>& arr, const int* points);
void generation_eggs(std::vector<std::vector<char>>& arr);
void move_eggs(std::vector<std::vector<char>>& arr);
void wolf_controller(std::vector<std::vector<char>>& arr);
bool check_eggs(std::vector<std::vector<char>>& arr, int* points);
void speed(const uint& points);


int main() {
  
  srand(time(0));
  
  int flags = fcntl(0, F_GETFL, 0);
  fcntl(0, F_SETFL, flags | O_NONBLOCK);

  system("stty raw -echo");

  std::vector<std::vector<char>> arr = create();
  fill(arr);
  int point = 0;
  
  
  
  for( ; ; ) {
    wolf_controller(arr);
    speed(point);
    bool check = check_eggs(arr, &point);
    move_eggs(arr);
    generation_eggs(arr);
    print(arr, &point);
    if(check == true) {
      break;
    }
    
    std::this_thread::sleep_for(std::chrono::nanoseconds(position_wolf.speed));
    
  }
  std::cout << "Game over" << std::endl;
  system("stty sane");

    
    
    return 0;
}


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
        arr[position_wolf.i][position_wolf.j] = 'w';
        if(i == 0 || j == 0 || j == B - 1) {
          arr[i][j] = '|';
        }
      }
    }

}



void print(const std::vector<std::vector<char>>& arr, const int* points) {
  std::cout << "\033[2J\033[1;1H";
  std::cout << "Points:" << *points << "\r" << std::endl;
  for(int i = 0; i < A; i++) {
    for(int j = 0; j < B; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "\r\n";
  }
}




void generation_eggs(std::vector<std::vector<char>>& arr) {

  if(rand() % 100 >= 50) {

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

bool check_eggs(std::vector<std::vector<char>>& arr, int* points) {
  
  for(int i = 1; i < B - 1; i++) {
    if(arr[A - 2][i] == 'o') {

      if(position_wolf.j == i) {
        (*points)++;
        arr[A - 2][i] = '.';
      } else {
        arr[A - 2][i] = '.'; 
        arr[A - 1][i] = 'o';  
        return true;           
      }
    } 
  
  }
  return false;
}

void wolf_controller(std::vector<std::vector<char>>& arr) {

  char c = getchar();
  if(c != EOF) {
    if(c == 'q') {
      system("stty sane");
      exit(0);

    } else if(c == 'd') {
      arr[position_wolf.i][position_wolf.j] = '.';
      position_wolf.j = 3;
      arr[position_wolf.i][position_wolf.j] = 'w';

    } else if(c == 'a') {
      arr[position_wolf.i][position_wolf.j] = '.';
      position_wolf.j = 1;
      arr[position_wolf.i][position_wolf.j] = 'w';
 
    } else if(c == 's') {
      arr[position_wolf.i][position_wolf.j] = '.';
      position_wolf.j = 2;
      arr[position_wolf.i][position_wolf.j] = 'w';
    } else if(c == 'f') {
      arr[position_wolf.i][position_wolf.j] = '.';
      position_wolf.j = 4;
      arr[position_wolf.i][position_wolf.j] = 'w';
    }

  
  }  
}

void speed(const uint& points) {

                                                //4 200 000 000 * 1.1 = 4 620 000 000 
  if((points % 5 == 0) && (position_wolf.speed <  4294967295 - position_wolf.speed * 0.1)) {
    position_wolf.speed *= 1.1;
    //−2 147 483 648-----------------------------------0--------------------------------------------->2 147 483 648
    //0-------------------------------------------------------------------------------->  4 294 967 295
  }



}