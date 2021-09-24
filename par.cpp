#include <mpi.h>
#include <stdio.h>
double f(double);
double f(double x)
{
    return (4.0 / (1.0 + x * x));
}
int main(int argc, char *argv[])
{
    int myId, numprocs;
    int n, i;
    double myPi, pi;
    double h, sum, x;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myId);
    printf("Process %d of %d.\n", myId, numprocs);
    n = 100;
    h = 1.0 / (double)n;
    sum = 0.0;
    for (i = myId + 1; i <= n; i += numprocs)
    {
        x = h * ((double)i - 0.5);
        sum += f(x);
    }
    myPi = h * sum;
    MPI_Reduce(&myPi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (myId == 0)
    {
        printf("The result is %.10f.\n", pi);
    }
    MPI_Finalize();
}