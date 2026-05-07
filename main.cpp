#include <iostream>
#include <string>

struct Student {
	int id;
	std::string name;
	std::string email;
	std::string NIM;
};

//~ Student sort_students(Student students[]);

void sort_by_nim(Student array[], size_t size){
	Student temp;

	for (int i=0; i < (int)size-1; i++) {
		for (int j=0; j < (int)size-i-1; j++) {
			if (array[j].NIM > array[j+1].NIM) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}



void print_students(Student students[], size_t size) {
	
	std::cout << "ID\t|\tName\t|\tEmail\t\t|\tNIM\n";

	for (size_t i = 0; i < size; i++) {
    auto student = students[i];

    std::cout << student.id << "\t ";
    std::cout << student.name << "\t\t ";
    std::cout << student.email << "\t ";
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
		std::cout << "2. Create Student\n";
		std::cout << "3. Update Student\n";
		std::cout << "4. Delete Student\n";
		std::cout << "5. Exit\n";

		std::cout << "Enter Input (1-5): ";
		std::cin >> input;
		
		switch (input) {
			case 1:{
				if (students_size == 0){
					std::cout << "No Student Data Found" << "\n\n";
				} else {
					int option;
					bool looping = 1;
					do {
						std::cout << "View Student Option\n";
						std::cout << "1. Sort by NIM\n";
						std::cout << "2. Don't sort\n";
						std::cout << "Enter Input (1-2): ";
						std::cin >> option;
						
						switch(option){
							case 1:{
								Student temp[MAX_STUDENTS_SIZE];
								for (size_t i = 0; i < students_size; i++){
									temp[i] = students[i];
								}
									
								sort_by_nim(students, students_size);
								std::cout << "Displaying Student Data Sorted by NIM:\n";
								print_students(students, students_size);
								looping = 0;
								break;
							}
							case 2:{
								std::cout << "Displaying Student Data:\n";
								print_students(students, students_size);
								looping = 0;
								break;
							}
							default:{
								std::cout <<"Invalid Input";
							}
						}
					} while (looping);					
				}
				break;
			}

			case 2: {
				std::cout << "Adding new students..." << "\n";
				Student student;

				student.id = students_size;

				std::cout << "nama: ";
				std::cin >> student.name;

				std::cout << "email: ";
				std::cin >> student.email;

				std::cout << "student NIM: ";
				std::cin >> student.NIM;

				students[students_size] = student;
				students_size++;

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
				break;
			}
			default:{
				std::cout << "Invalid Input\n";
				break;
			}
		}

	} while (input != 5);
}
