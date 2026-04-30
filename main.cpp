#include <iostream>



int main (){
  std::cout << "=========================\n";
  std::cout << "Student Management System\n";
  std::cout << "=========================\n";
  std::cout << "1. View Student List\n";
  std::cout << "2. Create Student List\n";
  std::cout << "3. Update Student List\n";
  std::cout << "4. Delete Student List\n";
  std::cout << "5. Exit\n";
  
  int input;
  std::cin >> input;

  switch (input) {
    case 1:{
      std::cout << "Menu 1";
      break;
    }
    case 2:{

      std::cout << "Menu 2";
      break;
    }
    case 3:{

      std::cout << "Menu 3";
      break;
    }
    case 4:{

      std::cout << "Menu 4";
      break;
    }
    case 5:{

      std::cout << "Menu 5";
      break;
    }
    default:{
      std::cout << "Invalid Input\n";
      break;
    }
  }

}
