/*
 getDigits.ino
 Author: Pete Milne
 Date: 01-01-2016
 Version: 0.1

 Test case for getDigits func

*/

#include <limits.h>

void setup() {
  Serial.begin(9600);
  test();
}
void loop() {}

/*-------------------------------------------------------------------------*/
/* Returns number of digits incl minus sign for int n in range             */
/* INT_MIN <= n <= INT_MAX defined in <limits.h>                           */
/*-------------------------------------------------------------------------*/
byte getDigits(int n) {

  // there's at least one digit
  byte digits = 1;

  // special case avoiding abs overflow
  if (n == INT_MIN) n++;
  
  int dividend = abs(n) / 10;
  // continually divide the value by ten,
  // adding one to the digit count for each
  // time you divide, until you're at 0
  while (dividend > 0) {
    dividend = dividend / 10;
    digits++;
  }
  // for negative numbers add 1 for minus sign
  if (n < 0)
    return ++digits;
  else
    return digits;
}

void test() {
  // Test Min INT value
  Serial.print(INT_MIN);
  Serial.print(":");
  Serial.println(getDigits(INT_MIN));
  
  // Test zero value
  Serial.print("0:");
  Serial.println(getDigits(0));

  // Test Max INT value
  Serial.print(INT_MAX);
  Serial.print(":");
  Serial.println(getDigits(INT_MAX));

  // Test Speed of light
  Serial.print(186000); 
  Serial.print(":");
  Serial.println(getDigits(186000));

  // Test Absolute zero
  Serial.print(-273); 
  Serial.print(":");
  Serial.println(getDigits(-273));
}

