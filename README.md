# 📚 Library Management System in C

A simple and efficient **Library Management System** developed in **C Programming** using **Data Structures (Linked Lists)**.
This project allows users to manage books, users, borrowing, and returning operations through a menu-driven console application.

Built as a mini-project to strengthen concepts of:

* Data Structures
* Linked Lists
* Dynamic Memory Allocation
* File Handling Concepts
* User Management Logic
* Structured Programming in C

---

## 🚀 Features

✅ Add New Books

✅ Display Available Books

✅ Add New Users

✅ Borrow Books

✅ Return Books

✅ Display User Borrowed Books

✅ Book Availability Status

✅ Linked List Implementation

✅ Dynamic Memory Management

✅ Menu Driven Console Interface


---

## 🛠 Technologies Used

* **Language:** C
* **Concepts:** Data Structures & Algorithms
* **Data Structure Used:** Singly Linked List
* **Compiler:** GCC / Turbo C / VS Code C Compiler

---

## 📂 Project Structure

```bash
Library-Management-System-C/
│
├── main.c
├── README.md
```

---

## 🧠 Data Structures Used

### 📖 Book Structure

```c
struct Book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char ISBN[20];
    int isBorrowed;
    struct Book* next;
};
```

### 👤 User Structure

```c
struct User {
    char name[MAX_NAME];
    char ID[MAX_ID];
    struct Book* borrowedBooks[MAX_BORROWED];
    int borrowedCount;
    struct User* next;
};
```

---

## ⚙️ Functionalities Explained

### 1️⃣ Add Book

* Adds a new book to the library
* Stores:

  * Title
  * Author
  * ISBN
* Inserts book dynamically into linked list

---

### 2️⃣ Display Books

Displays all books available in the library with:

* Title
* Author
* ISBN
* Borrow Status

---

### 3️⃣ Add User

Creates a new library user with:

* User Name
* User ID

---

### 4️⃣ Borrow Book

Allows a user to borrow a book if:

* Book exists
* Book is available
* User exists
* Borrow limit not exceeded

---

### 5️⃣ Return Book

Allows user to:

* Return borrowed books
* Update book availability status
* Remove book from borrowed list

---

### 6️⃣ Display User Borrowed Books

Displays all books borrowed by a specific user.

---

## 💻 How to Run

### 🔹 Compile the Program

Using GCC:

```bash
gcc main.c -o library
```

### 🔹 Run the Program

```bash
./library
```

For Windows:

```bash
library.exe
```

---

## 📸 Sample Menu

```text
--- Library Management Menu ---

1. Add Book
2. Display Books
3. Add User
4. Borrow Book
5. Return Book
6. Display User's Borrowed Book
7. Exit
```

---

## 🔄 Program Flow

```text
Start Program
      ↓
Display Menu
      ↓
Take User Choice
      ↓
Perform Operation
      ↓
Update Linked List Data
      ↓
Return to Menu
      ↓
Exit
```

---

## 📚 Concepts Learned

This project helped in understanding:

* Linked Lists
* Dynamic Memory Allocation
* Structures in C
* Pointer Manipulation
* Menu Driven Programs
* Real World Data Management
* Searching Techniques
* Borrow/Return Logic

---

## 🔐 Error Handling Included

✔ Invalid Menu Input Handling
✔ Memory Allocation Check
✔ Borrow Limit Validation
✔ User Validation
✔ Book Availability Check

---

## 🚀 Future Improvements

* File Handling for Permanent Storage
* Admin Login System
* Search by ISBN
* Delete Book/User
* Fine Calculation System
* Due Date Management
* Queue for Book Reservations
* GUI Version using C++
* Database Integration

---

## 📌 Repository

[Library Management System Repository](https://github.com/bishusharma1/Library-Management-System-C?utm_source=chatgpt.com)

---

## 👨‍💻 Author

**Bishu Sharma**

* C Programmer
* Data Structures Enthusiast
* Computer Science Student

---

## ⭐ If You Like This Project

Give this repository a ⭐ on GitHub and share your feedback!

---

## 📄 License

This project is open-source and available for learning and educational purposes.

---
