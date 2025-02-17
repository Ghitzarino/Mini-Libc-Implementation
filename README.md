# Mini libc Implementation  

This project is a minimalistic implementation of the standard C library (libc), designed to provide essential functionality while offering a deeper understanding of **system calls**, **wrapper functions**, and **low-level programming concepts**. By building a custom libc, this project serves as an educational tool to explore the core mechanisms behind library routines and their interaction with the operating system.  

---

## **Key Features**  
- **System Call Wrappers**: Lightweight wrappers around Linux system calls to provide basic libc functionality.  
- **Low-Level Coding**: Combines **C** and **Assembly** to handle system-level interactions and optimize performance.  
- **Minimalistic Design**: Focuses on core functions like **I/O**, **memory management**, and **string manipulation**.  
- **Educational Focus**: Demonstrates how system calls are made and how library routines interact with the kernel.  

---

## **Technologies Used**  
- **C**: Primary language for implementing library functionality.  
- **Assembly**: Used for direct system call invocations and low-level optimizations.  
- **Operating System**: Linux.  

---

## **Implementation Details**  
### **System Call Handling**  
- Directly invokes Linux system calls using **Assembly** to bypass the standard libc.  
- Implements lightweight wrappers in **C** to provide a user-friendly interface for system calls.  

### **Core Functionality**  
- **I/O Operations**: Basic input/output functions like `read`, `write`, and `open`.  
- **Memory Management**: Custom implementations of `malloc`, `free`, and related functions.  
- **String Manipulation**: Essential string functions like `strlen`, `strcpy`, and `strcmp`.  

### **Minimal Environment**  
- Ensures the library operates independently without relying on the standard libc or default runtime environment.  

---

## **Challenges Faced**  
- **System Call Handling**: Gained insights into Linux syscall conventions and learned how to invoke them directly.  
- **Assembly Integration**: Bridged **C** and **Assembly** for seamless syscall handling and wrapper creation.  
- **Minimal Environment**: Ensured the library functions correctly without external dependencies.  

---

## **Lessons Learned**  
- A deeper understanding of how **libc** works under the hood.  
- Practical knowledge of **system calls** and the **Linux kernel interface**.  
- Enhanced skills in **low-level programming** with a focus on efficiency and precision.  

---

## **How to Use**  
1. Clone the repository to your local machine.  
2. Compile the library using the Makefile (make).  
3. Link the library with your programs to replace the standard libc or test each implemented function separately.  

---

## **Key Takeaways**  
- A functional, minimalistic libc implementation built from scratch.  
- Hands-on experience with **system-level programming** and **low-level optimizations**.  
- Improved understanding of **operating system interactions** and **library design**.  

This project serves as both an **educational exercise** and a **practical demonstration** of creating foundational library routines from scratch. It is a stepping stone to mastering low-level programming and understanding the intricacies of system-level interactions.  
