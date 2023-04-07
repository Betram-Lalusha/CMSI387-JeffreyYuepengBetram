#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUMSEATS 5


struct arg_struct {
    int num;
    char* bools;
};

void *philosopher (void *restrict args) {
	int seatNum = ((struct arg_struct*)args)->num;
	char* forks = ((struct arg_struct*)args)->bools;
	while(1) {
		if (!forks[seatNum]) {
			forks[seatNum]++;
			if(!forks[(seatNum + 1) % NUMSEATS]) {
				forks[(seatNum + 1) % NUMSEATS]++;
				printf("philosopher %d is eating\n", seatNum);
				sleep(1);
				printf("philosopher %d is full\n", seatNum);
				forks[seatNum]--;
				forks[(seatNum + 1) %NUMSEATS]--;
				sleep(4);
			} else {
				printf("philosopher %d hungers\n", seatNum);
				forks[seatNum]--;
				sleep(1);
			}
		} else {
			printf("philosopher %d hungers\n", seatNum);
			sleep(1);
		}
	}
}

/*
The only way a philosopher can be prevented from eating indefinitely is if
the people sitting next to them alternate when they eat so both forks are
always in use. To maximize the time the philsopher can't eat, one tablemate
must begin eating for 1 second, the philsopher checks utensil availability
immediately after, then checks again just before that tablemate finishes
eating, their other tablemate starts eating, the philosopher immediately
checks if they can eat, then checks again just before the second tablemate
finishes eating, then waits a second before checking one final time if they
can commence consuming their food. 4 seconds have elapsed, and their first
tablemate is still full, and can't pick up their utensil. The philsopher can
now begin eating.

Whether there exists a stable but unfair state, i.e. 1 philosopher happens
to eat twice as much as their compatriots, is left unproven, though the fact
that 2/5 philsophers can eat at a time, but a philsopher can spend at most
1/5 of their time eating suggests that it should even out quite a bit.
*/

int main() {
	char forks[NUMSEATS];
	pthread_t philosophers[NUMSEATS];
	struct arg_struct args[NUMSEATS];
	int i;
	for (i = 0; i < NUMSEATS; i++) {
		args[i].num = i;
		args[i].bools = forks;
		int code = pthread_create(&philosophers[i], NULL, philosopher, (void*)&(args[i]));
		if(code){
			fprintf(stderr, "pthread_create failed with code %d\n", code);
		}
	}
	sleep(30);
	for (i = 0; i < NUMSEATS; i++) {
		pthread_cancel(philosophers[i]);
	}
}
