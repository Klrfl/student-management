#include <fstream>
#include <sstream>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

struct Student {
	int id;
	std::string name;
	std::string email;
	std::string NIM;
};

std::string get_str_input(const std::string &prompt) {
  bool is_valid = false;
  std::string input;

  while(!is_valid) {
    std::cout << prompt;
    std::getline(std::cin, input);

    if(!std::cin) {
      std::cin.clear(); 
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "invalid input.\n";
      continue;
    }
  }

  return input;
}

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

Student* find_students(Student students[], int students_size, int target_id) {
   for (int i = 0; i < students_size; i++) {
     Student student = students[i];

     if (student.id == target_id) {
       return &students[i];
     }
   }

   return NULL;
}

void delete_student(Student students[], size_t &students_size, int target_id) {
  for(int i = 0; i < students_size; i++) {
    Student student = students[i];
    if (student.id == target_id) {

      students_size--;

      for(int j = i; j < students_size; j++) {
        students[j] = students[j+1]; // shift elements to the left 
      }
    }
  }
}

std::ifstream i_file("data.csv");

void read_students_from_csv(Student *students, size_t &student_size) {
  std::string tmp_line;
  std::vector<std::vector<std::string>> rows = {};


  // TODO: skip reading the header
  while (std::getline(i_file, tmp_line)) {
    std::vector<std::string> row = {};
    std::stringstream line_stream(tmp_line);
    std::string cell;

    /** cols (0-indexed) in the .csv file are:
    * id
    * name
    * email
    * nim
    */
    while(std::getline(line_stream, cell, ',')) {
      row.push_back(cell);
    }

    rows.push_back(row);
    row.clear();
  }

  for (int i = 0; i < rows.size(); i++ ) {
    auto row = rows.at(i);
    Student new_student;
    
    new_student.id = std::stoi(row.at(0));
    new_student.name = row.at(1);
    new_student.email = row.at(2);
    new_student.NIM = row.at(3);

    students[i] = new_student;
    student_size++;
  }
};

void write_students_to_csv(Student students[], size_t &students_size) {
  std::ofstream file("data.csv");

  for (int i = 0; i < students_size; i++) {
    Student student = students[i];
    std::string row = std::to_string(student.id) + "," + student.name + "," + student.email + "," + student.NIM;
    file << row;

    file << "\n";
  }
};

int main () {
	int input;
  int student_size_total = 0;

  std::ifstream size_file("total.txt");
  std::string tmp_line;
  std::getline(size_file, tmp_line);
  student_size_total = std::stoi(tmp_line);


	size_t students_size = 0;
	const int MAX_STUDENTS_SIZE = 10;
	Student students[MAX_STUDENTS_SIZE] = {};

  read_students_from_csv(students, students_size);

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
          break;
				}

        int option;
        bool is_looping = true;

        do {
          std::cout << "View Student Option\n";
          std::cout << "1. Sort by NIM\n";
          std::cout << "2. Don't sort\n";
          std::cout << "Enter Input (1-2): ";
          std::cin >> option;
          
          switch(option) {
            case 1: {
              Student temp[MAX_STUDENTS_SIZE];
              for (size_t i = 0; i < students_size; i++){
                temp[i] = students[i];
              }
                
              sort_by_nim(temp, students_size);

              std::cout << "Displaying Student Data Sorted by NIM:\n";
              print_students(temp, students_size);
              is_looping = 0;
              break;
            }

            case 2: {
              std::cout << "Displaying Student Data:\n";
              print_students(students, students_size);
              is_looping = 0;
              break;
            }

            default: {
              std::cout <<"Invalid Input\n";
            }
          }

        } while (is_looping);

				break;
			}

			case 2: {
				std::cout << "Adding new students..." << "\n";

				Student student;

				student.id = ++student_size_total;
        student.name = get_str_input("name: ");
				student.email = get_str_input("email: ");
        student.NIM = get_str_input("student NIM: ");

				students[students_size] = student;

				students_size++;

        write_students_to_csv(students, students_size);
        std::ofstream size_file("total.txt");
        size_file << student_size_total;

				break;
			}

			case 3: {
				std::cout << "Update student" << "\n";

        print_students(students, students_size);

        int target_id;
        std::cout << "input id of student to update: ";
        std::cin >> target_id;
        Student* student = find_students(students, students_size, target_id);

        std::string tmp = get_str_input("input student new name (leave empty to keep): ");
        if(!tmp.empty()) {
          student->name = tmp;
        }

        tmp.clear();

        tmp = get_str_input("input student new email (leave empty to keep): ");
        if(!tmp.empty()) {
          student->email = tmp;
        }

        tmp = get_str_input("input student new NIM (leave empty to keep): ");
        if(!tmp.empty()) {
          student->NIM = tmp;
        }

        write_students_to_csv(students, students_size);

        std::cout << "successfully updated student!";
				break;
			}

			case 4: {
				std::cout << "Delete student" << "\n";
        print_students(students, students_size);
        std::cout << "choose student to delete (id): ";

        int target_id;
        std::cin >> target_id;

        delete_student(students, students_size, target_id);
        write_students_to_csv(students, students_size);

        std::cout << "successfully deleted student with id " << target_id << ".\n";
        
				break;
			}

			case 5: {
				std::cout << "Goodbye, Admin!";
				break;
			}

			default: {
				std::cout << "Invalid Input\n";
				break;
			}
		}

	} while (input != 5);
}
