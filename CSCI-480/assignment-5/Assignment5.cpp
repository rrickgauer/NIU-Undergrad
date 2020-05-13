/********************************************************************
CSCI 480						Assignment 5  							Spring 2020

Progammer:	Ryan Rickgauer
Section:		2
TA:					Jingwan Li
Date Due:		4/6/2020

Purpose:		The purpose of this assignment, we are going to use POSIX  
 			threads, semaphores and a mutex to illustrate the 
 			Producer-Consumer Problem.			
*********************************************************************/

#include <iostream>
#include <list>
#include <utility>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

// global constants
#define P_NUMBER 7			// the number of producers
#define C_NUMBER 5			// the number of consumers
#define BUFFER_SIZE 35	// the maximum size of the buffer
#define P_STEPS 5				// the number of iterations for each producer thread
#define C_STEPS 7				// the number of iterations for each consumer thread

// global variables
sem_t notFull;
sem_t notEmpty;
pthread_mutex_t buffMut;
list<pair<long, int>> buffer;

// function prototypes
void* Produce(void *pidVoid);
void* Consume(void *pidVoid);
void Insert(long pid, int widgetNum);
void Remove(long pid);
void PrintBuffer();

int main()
{
	cout << "Simulation of Producer and Consumers\n\n";
	
	// initalize variables
	int exitVal;
	
	pthread_t conTh[C_NUMBER];
	pthread_t proTh[P_NUMBER];
	
	exitVal = sem_init(&notFull, 0, BUFFER_SIZE);	
	if (exitVal != 0) {
		cerr << "sem_init failed with exit code: " << exitVal;
		exit(-1);
	}
	
	exitVal = sem_init(&notEmpty, 0, 0);
	if (exitVal != 0) {
		cerr << "sem_init failed with exit code: " << exitVal;
		exit(-1);
	}
	
	exitVal = pthread_mutex_init(&buffMut, nullptr);
	if (exitVal != 0) {
		cerr << "pthread_mutex_init failed with exit code: " << exitVal;
		exit(-1);
	}
	
	cout << "The semaphores and mutex have been initialized.\n\n";
	
	
	// generate consumer threads
	for (long i = 0; i < C_NUMBER; i++) 
	{
		exitVal = pthread_create(&conTh[i], NULL, Consume, (void *) i);
		if (exitVal != 0) {
			cerr << "pthread_create failed with exit code: " << exitVal;
			exit(-1);
		}
	}
	
	// generate producer threads
	for (long i = 0; i < P_NUMBER; i++) 
	{
		exitVal = pthread_create(&proTh[i], NULL, Produce, (void *) i);
		if (exitVal != 0) {
			cerr << "pthread_create failed with exit code: " << exitVal;
			exit(-1);
		}
	}
	
	
	// wait on all Producer Threads to finish
	for (int i = 0; i < P_NUMBER; i++) 
	{
		exitVal = pthread_join(proTh[i], NULL);
		if (exitVal != 0) {
			cerr << "pthread_join failed with exit code: " << exitVal;
			exit(-1);
		}
	}
	
	// wait on all Consuer threads to Finish
	for (int i = 0; i < C_NUMBER; i++) 
	{
		exitVal = pthread_join(conTh[i], nullptr);
		if (exitVal != 0) {
			cerr << "pthread_join failed with exit code: " << exitVal;
			exit(-1);
		}
	}
	
	
	
	cout << "\nAll the producer and consumer threads have been closed.\n\n";
	
	// remove semaphores and mutexes
	exitVal = sem_destroy(&notFull);
	if (exitVal != 0) {
		cerr << "sem_destory failed with exit code: " << exitVal;
		exit(-1);
	}
	
	exitVal = sem_destroy(&notEmpty);
	if (exitVal != 0) {
		cerr << "sem_destory failed with exit code: " << exitVal;
		exit(-1);
	}
	
	exitVal = pthread_mutex_destroy(&buffMut);
	if (exitVal != 0) {
		cerr << "pthread_mutex_destroy failed with exit code: " << exitVal;
		exit(-1);
	}
	
	
	cout << "The semaphores and mutex have been deleted.\n\n";
	
	return 0;
}


/***************************************************************
Function: 	Produce

Use:      	produces the widgets used in the program.

Arguments:	pidVoid - the pid

Returns:   	nothing
***************************************************************/
void* Produce(void * pidVoid)
{
	int exitVal;
	long pid = (long) pidVoid;
	
	// produce P_STEPS number of widgets
	for (int i = 0; i < P_STEPS; i++)
	{
		// wait on semaphore->Insert wdiget into buffer->update Semaphore
		exitVal = sem_wait(&notFull);
		if (exitVal != 0) {
			cerr << "sem_wait failed with exit code: " << exitVal;
			exit(-1);
		}
		
		Insert(pid, i);
		exitVal = sem_post(&notEmpty);
		
		// check for sem_post failure
		if (exitVal != 0) {
			cerr << "sem_post failed with exit code: " << exitVal;
			exit(-1);
		}
		
		
		sleep(1);
	}
	
	pthread_exit(nullptr);
}

/***************************************************************
Function: 	Consume

Use:      	consumes the widgets

Arguments:	pidVoid - the pid

Returns:   	nothing
***************************************************************/
void* Consume(void * pidVoid)
{
	int exitVal;
	long pid = (long) pidVoid;
	
	// [roduce P_STEPS number of widgets
	for (int i = 0; i < C_STEPS; i++)
	{
		// wait on semaphore->Remove widget from buffer
		// update the buffer
		exitVal = sem_wait(&notEmpty);
		if (exitVal != 0) {
			cerr << "sem_wait failed with exit code: " << exitVal;
			exit(-1);
		}
		
		Remove(pid);									// remove the pid
		exitVal = sem_post(&notFull);	// set the exit val
		
		if (exitVal != 0) {
			cerr << "sem_post failed with exit code: " << exitVal;
			exit(-1);
		}
		
		sleep(1);
	}
	
	pthread_exit(nullptr);
}


/***************************************************************
Function:		Insert

Use:				respecting the locks, this function inserts a widget
						into the buffer

Arguments:	pid - a long representing the pid of the widget
						widgetNum - the current number of the current widget 
 												generated by the calling thread

Returns:		nothing
***************************************************************/
void Insert(long pid, int widgetNum)
{
	int exitVal;
	
	// wait and lock mutex
	exitVal = pthread_mutex_lock(&buffMut);
	if (exitVal != 0) {
		cerr << "pthread_mutex_lock failed with exit code: " << exitVal;
		exit(-1);
	}
	
	pair<long, int> widget(pid, widgetNum);
	
	// insert new Widget into buffer
	buffer.push_back(widget);
	cout << "Producer " << pid << " inserted one item.  Total is now " << buffer.size() << ". ";
	
	PrintBuffer();
	
	// unlock mutex
	exitVal = pthread_mutex_unlock(&buffMut);
	if (exitVal != 0)
	{
		cerr << "pthread_mutex_unlock failed with exit code: " << exitVal;
		exit(-1);
	}
}

/***************************************************************
Function:		Remove

Use:				removes the widget from the buffer

Arguments:	pid - a long representing the pid of the widget to remove

Returns:   	nothing
***************************************************************/
void Remove(long pid)
{
	int exitVal;	// the exit value 
	
	// wait and lock mutex
	exitVal = pthread_mutex_lock(&buffMut);
	if (exitVal != 0) {
		cerr << "pthread_mutex_lock failed with exit code: " << exitVal;
		exit(-1);
	}
	
	// remove widget from buffer
	buffer.pop_front();
	cout << "Consumer " << pid << " removed one item.  Total is now " << buffer.size() << ". ";
	PrintBuffer();
	
	// unlock mutex
	exitVal = pthread_mutex_unlock(&buffMut);
	if (exitVal != 0)
	{
		cerr << "pthread_mutex_unlock failed with exit code: " << exitVal;
		exit(-1);
	}
}

/***************************************************************
Function:		PrintBuffer

Use:				prints the buffer

Arguments:	none

Returns:   	nothing
***************************************************************/
void PrintBuffer()
{
	if (buffer.empty())
		cout << "Buffer is now empty\n";
	else
	{
		cout << "Buffer now conatins: ";
		for (list<pair<long, int>>::iterator it = buffer.begin(); it != buffer.end(); it++)
			cout << 'P' << it->first << 'W' << it->second << ' ';
		
		cout << endl;
		
	}
}
