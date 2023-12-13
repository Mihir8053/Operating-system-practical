#include<iostream>
using namespace std;

void findWaitingTime(int processes[], int n,
			int burstTime[], int waitingTime[], int quantum)
{
	
	int rem_burstTime[n];
	for (int i = 0 ; i < n ; i++)
		rem_burstTime[i] = burstTime[i];

	int t = 0; // Current time

	// Keep traversing processes in round robin manner
	while (1)
	{
		bool done = true;
		for (int i = 0 ; i < n; i++)
		{
			// If burst time of a process is greater than 0
			// then only need to process further
			if (rem_burstTime[i] > 0)
			{
				done = false; // There is a pending process

				if (rem_burstTime[i] > quantum)
				{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t += quantum;

					// Decrease the burst_time of current process
					// by quantum
					rem_burstTime[i] -= quantum;
				}

				// If burst time is smaller than or equal to
				// quantum. Last cycle for this process
				else
				{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t = t + rem_burstTime[i];

					// Waiting time is current time minus time
					// used by this process
					waitingTime[i] = t - burstTime[i];

					// As the process gets fully executed
					// make its remaining burst time = 0
					rem_burstTime[i] = 0;
				}
			}
		}

		// If all processes are done
		if (done == true)
		break;
	}
}

void findTurnAroundTime(int processes[], int n,
						int burstTime[], int waitingTime[], int tat[])
{
	// calculating turnaround time by adding
	// burstTime[i] + waitingTime[i]
	for (int i = 0; i < n ; i++)
		tat[i] = burstTime[i] + waitingTime[i];
}

void findavgTime(int processes[], int n, int burstTime[],
									int quantum)
{
	int waitingTime[n], tat[n], total_waitingTime = 0, total_tat = 0;

	// Function to find waiting time of all processes
	findWaitingTime(processes, n, burstTime, waitingTime, quantum);

	// Function to find turn around time for all processes
	findTurnAroundTime(processes, n, burstTime, waitingTime, tat);

	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";

	// Calculate total waiting time and TAT
	for (int i=0; i<n; i++)
	{
		total_waitingTime = total_waitingTime + waitingTime[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << burstTime[i] <<"\t "
			<< waitingTime[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_waitingTime / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

int main()
{
	int processes[] = { 1, 2, 3};
	int n = sizeof processes / sizeof processes[0];
	int burst_time[] = {9, 5, 3};
	int quantum = 2;
	findavgTime(processes, n, burst_time, quantum);
	return 0;
}
