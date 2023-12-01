#include <stdio.h>
#include <time.h>
#include <string.h>

#include "page_new.h"
#include "page.h"

// call this function to start a nanosecond-resolution timer
struct timespec timer_start(){
	struct timespec start_time;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
	return start_time;
}

// call this function to end a timer, returning nanoseconds elapsed as a long
long timer_end(struct timespec start_time){
	struct timespec end_time;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
	long diffInNanos = (end_time.tv_sec - start_time.tv_sec) * (long)1e9 + (end_time.tv_nsec - start_time.tv_nsec);
	return diffInNanos;
}

int main() {
	unsigned char value = 0;

	struct timespec start = timer_start();
	
	unsigned char page[8192];
	double main;
	double new;
	
	for(int i = 0; i < 100000000; ++i) {
		memset(page,value++,sizeof(page));
		pg_checksum_page(page,0);
	}
	
	main = timer_end(start) / 1000000000.0;
	start = timer_start();

	for(int i = 0; i < 100000000; ++i) {
		memset(page,value++,sizeof(page));
		pgPageChecksum(page,0, 8192);
	}

	new = timer_end(start) / 1000000000.0;
	printf("main: %lf\nnew: %lf\nnew / main = %lf", main, new, new / main);
	
	return 0;
}
