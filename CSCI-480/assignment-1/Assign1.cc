/*********************************************
CSCI 480 - Assignment 1 - Spring 2020

Programmer: Ryan Rickgauer
zID:        z1729300
Section:    2
Date Due:   1/24/2020

Purpose:    The purpose of this assignment is
            to use the linux system functions
            such as fork(), getpid(), sleep(),
            getppid(), wait(), and system().
**********************************************/

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, const char * argv[]) {

	// current process
	cout << "This is the current process." << endl;
	cout << "Its id is:        " << getpid() << endl;
	cout << "Its parent id is: " << getppid() << endl;

	// call first fork
	cout << "\nCalling the first fork." << endl;
	pid_t pid = fork();

	// check if fork failed
	if (pid < 0) {
		cout << "First fork failed." << endl;
		exit(-1);
	}

	// child process
	else if (pid == 0) {
		cout << "\nThis is the child process." << endl;
		cout << "Its id is:        " << getpid() << endl;
		cout << "Its parent id is: " << getppid() << endl;


		// calling a second fork
		cout << "\nCalling a second fork." << endl;
		pid_t pid2 = fork();

		// check if second fork failed
		if (pid2 < 0) {
			cout << "Second fork failed." << endl;
			exit(-1);
		}

		// grandchild process
		else if (pid2 == 0)
		{
			cout << "\nThis is the grandchild process." << endl;
			cout << "Its id is:        " << getpid() << endl;
			cout << "Its parent id is: " << getppid() << endl;

			// sleep for 3 seconds
			sleep(3);
			cout << "\nThe grandchild process should now be an orphan." << endl;
			cout << "Its id is:        " << getpid() << endl;
			cout << "Its parent id is: " << getppid() << endl;

			// call ps command
			cout << "\nThe grandchild process will now call the 'ps' command:" << endl;
			system("ps");

			// exit grandchild process
			cout << "\nGrandchild process will now exit." << endl;
			exit(0);
		}



		// child process
		else {
			// identify the child process
			cout << "\nThis is the child process." << endl;
			cout << "Its id is:        " << getpid() << endl;
			cout << "Its parent id is: " << getppid() << endl;

			// sleep for 2 seconds
			sleep(2);

			// exit
			cout << "\nThe child process will now exit." << endl;
			exit(0);
		}

 }

 	// parent process
 	else {
		// identify the parent process
		cout << "\nThis is the parent process." << endl;
		cout << "Its id is:        " << getpid() << endl;
		cout << "Its parent id is: " << getppid() << endl;

		// call sleep function
		sleep(2);

		cout << "\nThe parent process is about to call ps and the the child should appear as a zombie." << endl;

		system("ps");
		sleep(3);
		wait(0);

		cout << "\nHaving waited on the child, the parent process is going to call ps again." << endl;
		system("ps");

		cout << "\nThe parent process will now terminate." << endl;
		exit(0);
 	}



	return 0;
}
