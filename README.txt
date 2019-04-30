CSCI 340 FINAL PROJECT

Contributors:
Daniel Lee
Alex Thropp
Daniel Baczmaga

Files:
project.c

Project Goals:
Find - 
1. How big is a cache block? 
2. How big is the cache? 
3. How long does a reference to main memory take to complete? 
4. How long does a reference that can be satisfied from cache take to complete?

There are several aspects of modern operating systems that presented themselves as obstacles when 
completing this project. There is more than one layer of cache, so for most of these questions we 
assumed that the project was referencing only L1 cache. Still, there were significant challenges 
with trying to discover the different cache parameters. That being said, we answered the questions 
to the best of our abilities and the answers written are our best estimates.

Explanation of Functions:

get_cache_speed():
For this function, we started by running a large loop and calculating the time it takes to access
elements from an equally large array. We then outputted the times to the screen. When looking through 
the numbers, we found that a vast majority of them were around 30 nanoseconds, a smaller group was in 
the hundreds, a smaller group in the thousands and an even smaller group was in the ten thousands. 
Obviously, the smallest group of numbers would most likely be the accesses satisfied by the L1 cache.
We add all the numbers less than 35 and get the average, which usually ends up between 28-31. Although
this is a bit slower than what would be expected by L1 cache (~2 nanoseconds), a lot of that excess is
likely due to the fact that this was run on a virtualized system and there were probably some other 
unforseen excesses.

get_main_memory_speed():
For this function, we do something similar to the implementation of get_cache_speed. This was more
difficult however, because there were some numbers in the hundreds of thousands, and even in the
millions of nanoseconds (on the scale of milliseconds, which seems way too long for memory access).
For this, we decided to limit the upper scale of nanoseconds to 200. This gives a more reasonable
answer, around 120 nanoseconds, but it also cuts out a lot of data points. 

get_cache_size():
For this function we again started by calculating the times it takes to access elements from a large array.
After this, we loop through the results, and try to find elements in the array of times that are significantly larger 
than the element preceding it. We hypothesize that these "jumps" are due to a miss of the L1 cache and therefore
it takes more time to get that value from a lower tier of memory. This represents a 'limit' of the cache. We count how 
many times a jump like this happens and then divide the size of the array by the number of jumps + 1 to get a rough 
estimate of the size. On my (Daniel Lee) desktop computer, I normally get values between 30KB and 35KB, with some outliers that
are higher and lower. This makes sense because the L1 cache for my processor is 32KB. The numbers farther away from this could possibly
be due to the cache replacement algorithm.

get_cache_line_size():
