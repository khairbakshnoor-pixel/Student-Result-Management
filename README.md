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

---

## Installation & Running

1. **Clone the repository:**

```bash
git clone https://github.com/khairbakshnoor-pixel/Student-Result-Management.git
