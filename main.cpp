#include <iostream>

void bubbleSort(int array[], int n){
	for (int i=0; i < n-1; i++){
		for (int j=0; j < n-i-1; j++){
			if (array[j] > array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

int main (){
	int input;
	
	do {
		std::cout << "=========================\n";
		std::cout << "Student Management System\n";
		std::cout << "=========================\n";
		std::cout << "1. View Student List\n";
		std::cout << "2. Create Student List\n";
		std::cout << "3. Update Student List\n";
		std::cout << "4. Delete Student List\n";
		std::cout << "5. Exit\n";
		std::cout << "Masukkan pilihan (1-5): ";
		std::cin >> input;
		
			switch (input) {
				case 1:{
					std::cout << "Menu 1" << "\n";
					break;
				}
				case 2:{
					std::cout << "Menu 2" << "\n";
					break;
				}		
				case 3:{
					std::cout << "Menu 3" << "\n";
					break;
				}
				case 4:{
					std::cout << "Menu 4" << "\n";
					break;
				}
				case 5:{
					std::cout << "Goodbye, Admin!";
					return 0;
					break;
				}
				default:{
					std::cout << "Invalid Input\n";
					break;
				}
			}

	} while (input != 5);
}
