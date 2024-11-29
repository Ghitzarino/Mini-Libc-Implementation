# Mini libc Implementation

## Overview:
This project is a minimalistic implementation of the standard C library (libc), designed to provide essential functionality and a deeper understanding of system calls, wrapper functions, and low-level programming concepts.
By building a custom libc, the project offers hands-on experience with the core mechanisms behind library routines and their interaction with the operating system.

## Key Features:
* System Call Wrappers: Implemented lightweight wrappers around Linux system calls to provide basic libc functionality.
* Low-Level Coding: Combined C/C++ and Assembly to handle system-level interactions and optimize performance.
* Educational Focus: Emphasized understanding how system calls are made and how library routines interact with the kernel.
* Minimalistic Design: Focused on core functions like I/O, memory management, and string manipulation.

## Technologies Used:
* C/C++: For implementing the majority of the library functionality.
* Assembly: For direct system call invocations and low-level optimizations.
* Operating System: Linux.

## Challenges Faced:
* System Call Handling:
Gained insights into Linux syscall conventions and how to invoke them directly.
* Assembly Integration:
Bridging C and Assembly for seamless syscall handling and wrapper creation.
* Minimal Environment:
Ensuring the library works without relying on the standard libc or default runtime environment.
* Lessons Learned:
  * A deeper understanding of how libc works under the hood.
  * Practical knowledge of system calls and the Linux kernel interface.
  * Enhanced skills in low-level programming with a focus on efficiency and precision.

This mini libc project serves as both an educational exercise and a practical demonstration of creating foundational library routines from scratch.
It is a stepping stone to mastering low-level programming and understanding the intricacies of system-level interactions.
