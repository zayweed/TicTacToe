#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct student {
  char first[20];
  char last[20];
  int id;
  float GPA;
};

int main() {

  vector <student*> studentlist;
  
  int a = 0;
  
  while (a == 0) {

    char input[20];

    cin >> input;

    if (strcmp(input, "ADD") == 0) {
      cout << "add";
    }

    if (strcmp(input, "PRINT") == 0) {
      
    }

    if (strcmp(input, "DELETE") == 0) {
      
    }

    if (strcmp(input, "QUIT") == 0) {
      
    }
  }

  
  
  return 0;
}
