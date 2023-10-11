# Modified xv6 Operating System Project

## Introduction
The aim of this project is to enhance the [xv6 Operating System](https://github.com/mit-pdos/xv6-public) by introducing new features and functionalities, such as extended keyboard shortcuts for the console, additional system calls, CPU scheduling improvements, and synchronization mechanisms. This project will be executed in multiple phases, each building upon the previous one.

### Phase 1 - Introduction to xv6
In the initial phase, we familiarize ourselves with the xv6 codebase and make the following enhancements:
- Add the names of contributors to the boot message for acknowledgment.
- Introduce three new keyboard shortcuts in the xv6 shell:
  - `CTRL + T`: Swaps the last two letters before the cursor.
  - `CTRL + O`: Converts all letters after the cursor into uppercase.
  - `CTRL + A`: Moves the cursor to the beginning of the line.
- Design and implement a user-level program called `factor`.

### Phase 2 - System Calls
In the second phase, we expand the system calls available in xv6 by adding the following functions:
- `calculate_sum_of_digits(int num)`: Returns the sum of all digits in `num`.
- `get_file_sectors(int fd)`: Prints the block number on disk for each block of the file.
- `get_parent_id(void)`: Prints the parent process ID of the currently running process.
- `set_process_parent(int pid)`: Establishes the currently running process as the parent of the specified process (`pid`).

### Phase 3 - CPU Scheduling
For the third phase, we implement a more advanced CPU scheduling system. Processes are categorized into different priority levels, with three levels in total:
- Level 1: Round Robin (RR)
- Level 2: Last Come First Serve (LCFS)
- Level 3: Modified Highest Response Ratio Next (MHRRN)
We introduce the following system calls to manage this scheduling:
- `change_queue(int pid, int queue)`: Moves a process to a different priority queue.
- `set_process_MHRRN(int pid, int MHRRN_priority)`: Sets the MHRRN priority for a process.
- `set_system_MHRRN(int MHRRN_priority)`: Configures the system-wide MHRRN priority.
- `print_info(void)`: Prints relevant scheduling information.

### Phase 4 - Synchronization
In the fourth phase, we implement a counting semaphore and tackle the Dining Philosophers problem using a monitor. The following system calls are introduced:
- `sem_init(int i, int v, int init)`: Initializes a counting semaphore with an initial value.
- `sem_acquire(int i)`: Acquires the counting semaphore.
- `sem_release(int i)`: Releases the counting semaphore.
We simulate the Dining Philosophers problem with five philosophers to demonstrate synchronization techniques.

### Phase 5 - Memory Management
The final phase involves memory management improvements. We introduce a POSIX-compliant Unix system call called `mmap` that allows mapping files or devices into memory, enabling memory-mapped file I/O. The following system calls are added:
- `get_free_pages_count()`: Retrieves the count of free pages in memory.
- `mmap(void* addr, size_t length, int prot, int flags, int fd, int offset)`: Maps files or devices into memory, offering enhanced memory management capabilities.

This project aims to progressively enhance the xv6 Operating System, making it more feature-rich, efficient, and capable of handling various tasks. Each phase builds upon the previous one, ultimately creating a more robust and versatile operating system.
