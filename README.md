# Student Result Management System

## Overview
The **Student Result Management System** is a C-based console application designed to manage students' academic records efficiently. This project allows users to **add, update, delete, search, and display student records** including their marks, total, percentage, and grades. It also provides functionality to **save and load records from a file**, making it persistent across sessions.

This project is perfect for beginners and intermediate C programmers who want to learn about **structs, file handling, arrays, and basic CRUD operations** in C.

---

## Features

- **Add Student**: Enter student details including roll number, name, and marks in multiple subjects. The system automatically calculates total, percentage, and grade.
- **Display All Students**: View all student records in a neatly formatted list.
- **Search Student**: Find a student by roll number and view their complete record.
- **Update Student**: Modify marks for a particular student, with automatic recalculation of total, percentage, and grade.
- **Delete Student**: Remove a student record from the system.
- **File Handling**: Save all records to a file and load them when the program restarts, ensuring data persistence.
- **Grade Calculation**: Automatic grade assignment based on percentage:
  - A: 90% and above
  - B: 80% - 89%
  - C: 70% - 79%
  - D: 60% - 69%
  - F: Below 60%

---

## How It Works

1. The system uses a **`struct Student`** to store student information.
2. All student records are stored in an **array** of `struct Student`.
3. Marks, total, percentage, and grade are automatically calculated.
4. **File operations** (`saveToFile()` and `loadFromFile()`) are used to persist the data across multiple program runs.
5. The program provides a **menu-driven interface**, allowing the user to perform all operations interactively.

---

## Technical Details

- Language: **C**
- Data Structures: `struct` and arrays
- File Handling: `fopen()`, `fscanf()`, `fprintf()`, `fclose()`
- Input/Output: Console-based I/O
- Maximum number of students: **100**
- Number of subjects: **5** (can be modified using the `SUBJECTS` macro)
- Grades are calculated automatically based on percentages.



🌟 Workflow of Student Result Management System

The Student Result Management System is designed to simplify the handling of student records with ease, accuracy, and persistence. Here’s how it works step by step:

1️⃣ Program Start

When launched, the system automatically loads all existing student records from results.txt if available.

Initializes the database in memory and displays the main menu for user interaction.

2️⃣ Main Menu Options

The system provides a clear and intuitive menu with the following options:

Add Student – Record a new student’s information.

Display All Students – View all student records in a formatted list.

Search Student – Look up a student by their roll number.

Update Student – Modify marks and recalculate results.

Delete Student – Remove a student record permanently.

Save & Exit – Save all changes to the file and exit the program safely.

3️⃣ Adding a Student

Enter Roll Number and Name.

Input marks for all subjects.

The system calculates automatically:

✅ Total Marks

✅ Percentage

✅ Grade

Student record is added to the in-memory array.

4️⃣ Displaying Students

Shows a clean and readable list of all students.

Displays:

Roll Number

Name

Total Marks

Percentage

Grade

5️⃣ Searching a Student

Enter a Roll Number to search.

If found, the system displays all details of that student instantly.

If not found, an informative message is shown.

6️⃣ Updating Student Records

Enter the Roll Number of the student to update.

Update marks for each subject.

Total, percentage, and grade are recalculated automatically.

Updated record is reflected immediately in memory.

7️⃣ Deleting a Student

Enter the Roll Number of the student to delete.

The record is removed permanently from the array.

Array elements are rearranged to maintain order.

8️⃣ Saving & Exiting

All student records are saved to results.txt.

Each record includes:

Roll Number

Name

Subject Marks

Total Marks

Percentage

Grade

Data becomes persistent, available the next time the program runs.

9️⃣ Program End

User exits after saving.

On next run, all previous data is loaded automatically, ensuring no loss of records.

💡 Key Features:

Uses structs and arrays to manage data efficiently.

Implements file handling for persistent storage.

Provides real-time calculations for total, percentage, and grade.

Simple, user-friendly interface for easy operation.