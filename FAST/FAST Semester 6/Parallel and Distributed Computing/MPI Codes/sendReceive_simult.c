#include <mpi.h>
#include <stdio.h>


int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc,&argv);
    
 MPI_Status status;	
    // Get the number of processes -> how many processes are to be created
    int p;
	int i;
	//MPI_COMM_WORLD is an communicator object that contains all the processes
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	int a=my_rank;
	int b;	
	int sendTag=1;
	int recvTag=1;
	
		int next=(my_rank+1)%p; //determine my right node
		int previous=((my_rank-1+p)%p); //determine my left node	
		MPI_Sendrecv(&a,1,MPI_INT,next,sendTag,
					 &b,1,MPI_INT,previous,recvTag, MPI_COMM_WORLD, &status );
			
		printf("I\'m %d: Received:%d from %d and Sent:%d to %d\n ",my_rank ,b,previous, a,next);
    // Finalize the MPI environment.
    MPI_Finalize();
}
