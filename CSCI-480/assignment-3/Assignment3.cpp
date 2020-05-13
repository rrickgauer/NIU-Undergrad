

#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fcntl.h>    /* For O_RDWR */

using namespace std;

/*
Funtion: Main

Use: Executes program

Parameters: none

Returns: 0: Regular exit
         128: failure to fork() a child process from main process
         256: opening a pipe() failed
*/

int main()
{
	//Initalize
	char buf[1024];
	char * holder;
	string bufCopy;
	pid_t pid;
	int status;
	string isDoublePipeHolder;

	bool continueCondition = true;
	vector<char *> commandVect;
	bool pipeflag = false;
	long unsigned int indexOfNextCommands = 0;
	int communicationPipe[2];

	//main program loop
	do
	{
		//clear buffer every round
		memset(buf, '\0', 1024);

      // read in buffer
		cout << "\n480shell: ";
		cin.getline(buf, 1024);
		bufCopy = buf;

		//no string.tolower() ?
		transform(bufCopy.begin(), bufCopy.end(), bufCopy.begin(), ::tolower);

		//check quit condition
		if ((bufCopy == "q") || (bufCopy == "quit"))
			continueCondition = false;

		//start processing commands if somthing was read
		else if (bufCopy != "") {

         // user entered about
         if (bufCopy == "about") {
            cout << "The 480shell is the work of Ryan Rickgauer, 2020";
         }

         else {

            //start tokenizing
            holder = strtok(buf, " ");

            while (holder != nullptr)
            {
               //check for pipe
               isDoublePipeHolder = holder;
               if (isDoublePipeHolder == ">+")
               {
                  //set a char* in our vector to nullptr to set a delim point for exec
                  pipeflag = true;
                  commandVect.push_back(nullptr);

                  //starting point of next commands
                  indexOfNextCommands = commandVect.size();
               }
               else
                  commandVect.push_back(holder + '\0');

               holder = strtok(nullptr, " ");
            }

            //if || was at the end of the line, we cant really pipe anything...
            if (indexOfNextCommands == commandVect.size())
               pipeflag = false;

            //char* delim point for exec
            commandVect.push_back(nullptr);


            pid = fork();

            //child
            if (pid == 0) {
               //no redirection, 1 process
               if (pipeflag == false)
               {
                  //exec a process
                  execvp(commandVect[0], &commandVect[0]);
                  cerr << "Couldn't execute \"" << commandVect[0] << "\"!\n";
                  exit(128);




                  // // open input and output files
                  // int out = open(commandVect[1], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
                  //
                  // // replace standard output with output file
                  // dup2(out, 1);
                  //
                  // // close unused file descriptors
                  // close(out);
                  //
                  // // execute grep
                  //
                  // execvp(commandVect[0], &commandVect[0]);

               }

               // redirection
               else
               {
                  //create a pipe, exit on failure
                  if (pipe(communicationPipe) == -1)
                  {
                     cerr << "pipe failed!" << endl;
                     exit(256);
                  }

                  pid = fork();

                  //child (1st command)
                  if (pid == 0)
                  {
                     // //close read pipe
                     // //1st command will use communicationPipe[1] for write
                     // close(communicationPipe[0]);
                     //
                     // //copy communicationPipe[1] into stdout's position in the FD table
                     // dup2(communicationPipe[1], 1);
                     //
                     // //we no longer need communicationPipe[1] since it is in FD=1
                     // close(communicationPipe[1]);
                     //
                     // execvp(commandVect[0], &commandVect[0]);
                     // cerr << "Couldn't execute \"" << commandVect[0] << "\"!\n";
                     // exit(128);



                     // open input and output files
                     int out = open(commandVect[2], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

                     // replace standard output with output file
                     dup2(out, 1);

                     // close unused file descriptors
                     close(out);

                     // execute grep

                     execvp(commandVect[0], &commandVect[0]);
                  }

                  //parent (2nd command)
                  else if (pid > 0)
                  {

                     // int out = open("test.txt", O_WRONLY | O_APPEND);
                     // dup2(out, 1);
                     // close(out);
                     // execvp(commandVect[1], &commandVect[1]);
                     //
                     // cout << commandVect[1] << endl;

                     //close write pipe
                     //2nd command will still use stdout for write
                     // close(communicationPipe[1]);
                     //
                     // //copy communicationPipe[0] into stdin's position in FD table
                     // dup2(communicationPipe[0], 0);
                     //
                     // //we no longer need fd[0] since it is in FD=0
                     // close(communicationPipe[0]);
                     //
                     // execvp(commandVect[indexOfNextCommands], &commandVect[indexOfNextCommands]);
                     // cerr << "Couldn't execute from parent \"" << commandVect[0] << "\"!\n";
                     // exit(128);
                  }
                  //error
                  else
                  {
                     cerr << "Fork fail, exiting..." << endl;
                     continueCondition = false;
                  }
               }
            }

            //error
            else if (pid < 0) {
               cerr << "Fork fail, exiting..." << endl;
               continueCondition = false;
            }

            //out of ifs mean we are parent
            if ( (pid = waitpid(pid, &status, 0)) < 0)
               cerr << "waitpid error" << endl;
         }


			//reset vector & flag
			commandVect.clear();
			pipeflag = false;
		}
	} while (continueCondition);
	exit(0);
}
