#include <Arduino.h>
#include <Playtune.h>
#include <Score.h>

Playtune pt;
void setup()
{
  // Enable all 3 NANO timers for notes that are output on digital pins 10, 11, and 12.
  // Those pins should be wired to 500-ohm resistors, the other ends of which should be connected together
  // to one terminal of an 8-ohm speaker. The other terminal of the speaker should be connected to ground.
  // No other hardware is needed!

  pt.tune_initchan(10);
  pt.tune_initchan(11);
  pt.tune_initchan(12);

  // TODO
  /*Turn LED on whenever one of the pins is outputting sound.*/

#define DBUG 0
#if DBUG
  Serial.begin(9600);
  Serial.println("Debug");
#endif
}

void loop()
{
  pt.tune_playscore(score); /* start playing */
  while (pt.tune_playing)
    ;                  /* wait here until playing stops */
  pt.tune_delay(1000); /* wait a second */
}