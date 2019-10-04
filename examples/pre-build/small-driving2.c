// This version is new idea with more well-thought syntax

memory bit MyBit; // type "bit" with keyword "memory" makes basically %M type in Twido Ladder
// Translator will map any type definition in code, to first available type in Ladder, for example "memory bit MyBit -> %M0"

local input<0> StartButton;
local input<1> StopButton;
local output<0> Motor;
local output<1> CoolingFans;
/*
 * % I 0 . 1
 *   | |   |__ <1>
 *   | |______ local
 *   |________ input
*/

offdelay timer<0.01, 2000, 2000> Timer;
/*    |        |     |     |_ Accum
 *    |        |     |_______ Preset
 *    |        |_____________ Timer Base (in seconds)
 *    |_ TOF
 */

/* type "timer" has structure of:
 * .done - Timer done bit (%TMi.Q)
 * .value - Timer current value (%TMi.V)
 * .max - Timer task value (%TMi.P)
 *
 * .enable() - Call timer to start counting
 */

func main() {
	// we can have functions which will be implemented on subroutines
	MyBit = ((StartButton || MyBit) && !StopButton);
	
	if(MyBit)
		Timer.enable();

	Motor = MyBit;
	CoolingFans = Timer.done;
}
