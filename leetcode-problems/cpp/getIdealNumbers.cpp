

using namespace std;

// dont have my solution copied as it was an OA

// but basically giving a range low and high, we want to find the number of ideal numbers in that range
// numbers that are divisible by both 3 and 5 *


long getIdealNumbers(long low, long high) {

   long result = 0;

   for (long x = 1; x <= high; x *= 3) { // multiples of 3
       for (long y = x; y <= high; y *= 5) { // multiples of 5
           if (y >= low) {
            result++;
           }
       }
   }
   return result;
}

