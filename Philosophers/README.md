# Philosophers


## Starting ##

```bash
# Compile the program
make

# To run (example)
./philo 5 800 200 200

# To remove objects and executable
make fclean
```

## Summary ##
Threads that the operating system runs concurrently are called processes. Processes can also have threads running concurrently within themselves, and they are also called Threads.

Synchronization is needed from time to time between different processes or between Threads in the same process because these Threads want to access a shared resource provided by the operating system or maintained within the process itself to perform their tasks. As an example, let's take the case where Threads wants to write logs to a log file or screen. If two Threads try to write to the log file at the same time, the logs written to the file will be mixed up and become unreadable. Here a mechanism is needed to queue Threads to write to the log file.

Mutex (MUTual EXclusions) is designed to provide exactly this mechanism. Mutexs are simple data structures provided by the language in which the application is written and the Runtime. For each resource shared by different Threads, a Mutex is created to regulate access to the resource. The code region in which the shared resource is accessed is called the Critical Section. Thread with resource tries to take ownership of Mutex (Acquire). If the mutex is not currently held by another Thread, it takes the Thread Mutex, enters the Critical Section and uses the relevant resource. In the other case, that is, if the Mutex is currently being used by another Thread, the second Thread is put on hold by the processor. When the Thread holding the Mutex finishes the Critical Segment and leaves the Mutex, the Thread awaiting the release of the Mutex awakens and takes ownership of the Mutex and gains access to the shared resource by entering the Critical Segment.



## Image ##
<img width="966" alt="Image-1" src="https://user-images.githubusercontent.com/97880185/210461944-01c7ec37-78ea-4d6e-9047-730aa91f65e7.png">

<img width="939" alt="Image-2" src="https://user-images.githubusercontent.com/97880185/210462008-2a476961-eca1-4266-b95c-2365c3662b0c.png">
