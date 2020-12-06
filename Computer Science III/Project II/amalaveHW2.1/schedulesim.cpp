#include<iostream>
#include<cstdlib>
#include<string>
#include "simulate.hpp"

using namespace std;

//TWO GRAPHS:
//1) Time vs CPU-Bound procs -- plotting overhead for both schedulers
//2) Ratio (avgCPUBTime/avgIOBTime) vs CPU-Bound procs -- plot ratios for both schedulers

int main(int argc, char* args[]){
	int CPUprocs = atoi(args[1]);
	int IOprocs = atoi(args[2]);
	int CPUcycles = atoi(args[3]);

	Scheduler* sched = new RoundRobin();
	Scheduler* sched2 = new FastRoundRobin();
	Scheduler* schedArr[] = {sched,sched2};

	string strArray[] = {"ROUNDROBIN","FASTROUNDROBIN"};
	//must make an array of 2 strings which are used to label the simulation results
	for(int i = 0; i < 2; i++){
		double* arr = simulate(schedArr[i],CPUprocs,IOprocs,CPUcycles);
		cout << "\n======================================" << endl;
		cout << strArray[i] << " SIMULATION RESULTS: " << endl;
		cout << "======================================" << endl;
		cout << "\nOverhead Caused: " << arr[0] << " nanoseconds" << endl;
		cout << "Average CPU time of CPU-bound processes: " << arr[1] << " cycles" << endl;
		cout << "Average wait time of CPU-bound processes: " << arr[2] << " cycles" << endl;
		cout << "Average CPU time of IO-bound processes: " << arr[3] << " cycles" << endl;
		cout << "Average wait time of IO-bound processes: " << arr[4] << " cycles" << endl;
		cout << "\n======================================" << endl;

		cout << "number I need: " << arr[3] / arr[1] << endl;
	}
}