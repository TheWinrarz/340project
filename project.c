#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

unsigned int n = 1000000;
int i;
struct timespec start, finish;
long nseconds;
int * results;
int * test_array;
unsigned int overhead;
unsigned long int x;
int count = 0;

unsigned long int get_cache_speed()//unsigned int * array)
{
  unsigned long int x;
  clock_gettime(CLOCK_REALTIME, &start);
  for (i = 0; i < n; i++)
  {
    //empty loop to calculate overhead
  }
  clock_gettime(CLOCK_REALTIME, &finish);
  overhead = finish.tv_nsec - start.tv_nsec;
  overhead = overhead/n;
  printf("Avg overhead: %d\n", overhead);

  for (i = 0; i < n; i++)
  {
    clock_gettime(CLOCK_REALTIME, &start);
    x = test_array[n];
    clock_gettime(CLOCK_REALTIME, &finish);
    nseconds = finish.tv_nsec - start.tv_nsec;
    results[i] = nseconds;
  }

  x = 0;
  count = 0;
  for (i = 0; i < n; i++)
  {
    if (results[i] < 50)
    {
      x = x + results[i];
      count++;
    }
  }
  x = x/count;
  printf("Average time to access cache: %ld nanoseconds\n", x - overhead);
  return x;
}


int get_cache_size()
{

  x = 1;

  for (i = 1; i < n; i++)
  {
    if (results[i]/results[i - 1] > 2 && results[i - 1] < 35)
      x++;
  }

  x = n/x * sizeof(int);
  printf("Estimated cache size: %ld bytes\n", x);
  return 0;
}

int get_main_memory_speed()
{
}

int get_cache_line_size()
{
}

int main()
{
  printf("Start\n");
  results = (int*) malloc(n * sizeof(int));
  test_array = (int*) malloc(n * sizeof(int));


  for (i = 0; i < n; i++)
    test_array[i] = i * 2;
  x = 0;
  get_cache_speed();
  get_cache_size();


  return 0;
}
