#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>




int main()
{
  printf("Start\n");
  unsigned int n = 1000000;
  int i;
  int test_array[n];
  unsigned int overhead;
  int results[n];
  unsigned long int x;
  int count = 0;
  printf("Arrays allocated\n");

  struct timespec start, finish;
  long nseconds;

  for (i = 0; i < n; i++)
    test_array[i] = i * 2;

  //TODO: create empty loop to factor out null loop
  x = 0;
  clock_gettime(CLOCK_REALTIME, &start);
  for (i = 0; i < n; i++)
  {
    //
  }
  clock_gettime(CLOCK_REALTIME, &finish);
  overhead = finish.tv_nsec - start.tv_nsec;
  overhead = overhead/n;
  printf("Avg overhead: %d\n", overhead);

  for (i = 0; i < n; i++)
  {
    clock_gettime(CLOCK_REALTIME, &start);

    x = test_array[i];
    clock_gettime(CLOCK_REALTIME, &finish);
    nseconds = finish.tv_nsec - start.tv_nsec;
    results[i] = nseconds;
  }

  for (i = 0; i < n; i++)
  {
    if (results[i] < 100)
    {
      x = x + results[i];
      count++;
    }
  }
  printf("%ld\n", x);
  printf("%d\n", count);
  x = x/count;
  printf("%ld\n", x);
  printf("Average time to access L1 cache: %ld nanoseconds\n", x - overhead);// overhead));

  x = 0;
  for (i = 1; i < n; i++)
  {
    if (results[i]/results[i - 1] > 7 && results[i - 1] < 35)
      x++;
  }
  printf("%ld\n", (n/x) * sizeof(int));


  return 0;
}
