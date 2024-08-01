# Minitalk-42

## Project Information

#### About

Minitalk is a project that demonstrates inter-process communication using UNIX signals. The project includes a server and a client program, where the client sends messages to the server using signals, and the server acknowledges receipt of these messages.

SIGUSR1 and SIGUSR2 were used for communication because they are user-defined signals, allowing flexible handling of custom tasks.
Messages are encoded into a sequence of signals. Each character in the message is sent as a series of bits using SIGUSR1 for binary 0 and SIGUSR2 for binary 1.
For synchronization was used the pause() function to wait for signals, ensuring synchronization between the server and client during message transmission.

#### Mandatory

• The server must be capable of handling multiple clients sending messages simultaneously.
• The client and server communicate through UNIX signals, specifically SIGUSR1 and SIGUSR2.
• The server must acknowledge every message received by sending a signal back to the client.

#### Bonus

• The server acknowledges every message received by sending back a signal to the
client.
• Unicode characters support!

#### Technologies Used
* C Programming Language:
	The entire project is implemented in C, leveraging low-level system calls and memory management.
* POSIX API:
	Used for signal handling and process control. Functions like sigaction, kill, and getpid are crucial for the implementation.
* Makefile:
	A Makefile was created to automate the build process, ensuring that all dependencies are correctly compiled.


### Allowed Functions
In this project, only a restricted set of functions are allowed, ensuring a deep understanding of low-level operations:

- [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)
- [`signal`](https://man7.org/linux/man-pages/man2/signal.2.html)
- [`sigemptyset & sigaddset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html)
- [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html)
- [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)
- [`sleep`](https://man7.org/linux/man-pages/man3/sleep.3.html)
- [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)
- [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)

### Installing the Project:
1. Clone the repository:
```C
    git clone git@github.com:lh-lena/42_minitalk.git
```
2. Navigate to the project directory:
```C
    cd 42_minitalk
```
3. Compile the project: 
```C
    make
```

### Running the Project
1. Running server: 
 
```C
    ./server 
```
The server will print print its PID and continue to listen indefinitely.

2. Running client:
```C
    ./client <SERVER PID> <MESSAGE TO SEND>
```
To send a message to a server replace <SERVER PID> with the PID of the server, and <MESSAGE TO SEND> with the message you want to transmit.





