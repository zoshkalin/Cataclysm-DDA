#include "output.h"
#include "rng.h"
#include <stdlib.h>

long rng(long val1, long val2)
{
    // Input order of parameters doesn't matter, we just swap things around if val1 is higher than val2.
    if(val1 <= val2)
    {
        return val1 + long((val2 - val1 + 1) * double(rand() / double(RAND_MAX + 1.0)));
    }
    else
    {
        return val2 + long((val1 - val2 + 1) * double(rand() / double(RAND_MAX + 1.0)));
    }
}

bool one_in(int chance)
{
 if (chance <= 1 || rng(0, chance - 1) == 0)
  return true;
 return false;
}
bool x_in_y(double x, double y)
{
 if( ((double)rand() / RAND_MAX) <= ((double)x/y) )
  return true;
 return false;
}

int dice(int number, int sides)
{
 int ret = 0;
 for (int i = 0; i < number; i++)
  ret += rng(1, sides);
 return ret;
}


// http://www.cse.yorku.ca/~oz/hash.html
// for world seeding.
int djb2_hash(const unsigned char *str){
 unsigned long hash = 5381;
 unsigned char c = *str++;
 while (c != '\0'){
  hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  c = *str++;
 }
 return hash;
}

