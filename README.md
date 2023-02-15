# Threads and multi-threading in C

**Threads and multithreading** refer to the concept of executing **multiple tasks simultaneously** within a single process.

**A thread** is a unit of execution within a process, and each process can contain multiple threads. By using threads, a program can perform multiple operations at the same time, making the most of the available CPU resources and increasing the program’s overall efficiency.

in C, the **POSIX** thread library provides functions for creating and managing threads.

```
pthread_create //used to create a new thread
pthread_join   //used to wait for a thread to finish its execution
pthread_exit   //used to exit from a thread
pthread_cancel //used to cancel a thread
```

Threads can **communicate** with each other by using various sync mechanisms, such as **semaphores**, **mutexes**, and **condition variables**, which help to control access to shared resources and prevent race conditions.


# POSIX Thread Library

`pthread_t` is a data type in the POSIX thread library that represents a thread ID. It is used to identify and manipulate threads within a process.

## pthread_create

This function creates a new thread of execution that starts executing from a specified function, and with a specified argument. It returns `0` on success and `non-zero` on failure.

```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, 
                   void *(*start_routine)(void *), void *arg);
```
### Parameters

* `thread`: A pointer to a `pthread_t` variable that will receive the thread ID of the newly created thread.
* `attr`: A pointer to a `pthread_attr_t` structure that specifies the attributes of the newly created thread, such as its stack size, priority, and scheduling policy. The value `NULL` can be passed for this argument to use the default values.
* `start_routine`: A pointer to a function that will be executed by the newly created thread. The function should have a return type of `void *` and take a single type of `void *`.
* `arg`: An argument that will be passed to the `start_routine` function when the thread starts executing.

## pthread_join

The `pthread_join` function is used to wait for a thread to finish its execution. The function blocks the calling thread until the specified thread has completed its execution and terminates. It returns `0` on success and a `non-zero` on failure.

```c
int pthread_join(pthread_t thread, void **retval);
```
### Parameters
* `thread`: The thread ID of the thread to wait for.
* `retval`: A pointer to a pointer to a `void` data type that will receive the return value of the `start_routine` function executed by the specified thread. The return value of the `start_routine` function can be used to pass information from the terminated thread to the calling thread.

## Race conditions :

- Race conditions occur in multi-threaded programs when two or more threads access a shared resource concurrently, and the result of the program depends on the order in which the threads execute. This can lead to unpredictable and incorrect behavior of the program.

- For example, if two threads try to increment a shared counter at the same time, they might both read the same value of the counter, increment it, and then write the same value back, resulting in only one increment instead of two.

- To prevent race conditions, synchronization mechanisms like locks, semaphores, or atomic operations can be used to ensure that only one thread at a time accesses the shared resource.

### Example : Bank Account
Consider the following scenario:

* A bank account has a balance of $1000.
* Two threads attempt to withdraw $500 from the account at the same time.

If the threads execute the withdraw function at the same time, a race condition occurs. The following steps might occur:
1. Thread 1 calls `get_balance()` and retrieves a balance of $1000.
2. Thread 2 calls `get_balance()` and retrieves a balance of $1000.
3. Thread 1 subtracts $500 from the balance, resulting in a new balance of $500.
4. Thread 2 subtracts $500 from the balance, also resulting in a new balance of $500.
5. Thread 1 calls `set_balance(500)`, updating the balance to $500.
6. Thread 2 calls `set_balance(500)`, overwriting the previous update and also updating the balance to $500.

As a result, the final balance of the account is $500 instead of the expected $0.
