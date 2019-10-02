// Timer Off Delay function (idk if its async, so the rest of loop can just work)
extern async void TOF(struct timer, double timerBase, int preset, int accum);

// Timer T1
struct timer {
	bit DN; // Timer Done Bit
	bit EN; // Timer Enable Bit
} T1;

// The loop
void loop {
	if((Input0 || Bit0) && !Input1)
		Bit0 = high; // or true or whatever
	else
		Bit0 = low;
	
	if(Bit0) // if its high (or true)
		TOF(T1, 0.01, 2000, 2000); // We dont need to pass struct pointer, only name (hardcoded?)

	if(Bit0)
		Output0 = high; // Motors
	else
		Output0 = low;

	if(T1.DN) // if Timer 1 done bit is high
		Output1 = high; // Cooling Fans
	else
		Output1 = low;
}
