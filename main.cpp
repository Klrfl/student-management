#include <iostream>
#include <string>

void bubbleSort(int array[], int size){
  int temp;

	for (int i=0; i < size-1; i++) {
		for (int j=0; j < size-i-1; j++) {
			if (array[j] > array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

struct Student {
  int id;
  std::string name;
  std::string email;
  std::string NIM;
};

Student sort_students(Student students[]);

void print_students(Student students[], size_t size) {
  for (int i = 0; i <= size; i++) {
    auto student = students[i];

    std::cout << "id\t |\t nama \t|\t email \t|\t NIM\n";
    std::cout << student.id << "\t";
    std::cout << student.name << "\t";
    std::cout << student.email << "\t";
    std::cout << student.NIM << "\n";
  }
}

int main () {
	int input;

  size_t students_size = 0;
  const int MAX_STUDENTS_SIZE = 10;
  Student students[MAX_STUDENTS_SIZE] = {};
	
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
					std::cout << "Showing list of students: " << "\n";

            // TODO: implement
            // sort_students(students);
            print_students(students, students_size);

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
