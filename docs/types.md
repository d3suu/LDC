# Types

## bit
Type of single bit.
```
memory bit MyBit;
```

#### Keywords
 - `memory` - `%M0.0`
 - `system` - `%S0.0`
 - `step` - `%X0.0`



## word
Type of word (16bit).
```
memory word MyWord;
```

#### Keywords
 - `memory` - `%MW0.0`
 - `const` - `%KW0.0`
 - `system` - `%SW0.0`

#### Bit access
```
memory word MyWord;
memory bit MyBit;

MyBit = MyWord<3>; // third bit of word MyWord
```



## dword
Type of dual word (32bit).
```
memory dword MyDualword;
```

#### Keywords
 - `memory` - `%MD0`
 - `static` - `%KD0`



## input/output
Type of digital input and output (1bit).
```
local input<0> MyInput;
local output<0> MyOutput;
```

#### Keywords [FIX ME]
 - `local` - `%I0.0`



## ainput/aoutput
Type of analog input and output (16bit - word).
```
local ainput<0> MyAnalogInput;
local aoutput<0> MyAnalogOutput;
```

#### Keywords [FIX ME]
 - `local` - `%IW0.0`


## ninput/noutput  [FIX ME]
Type of network input/output word (16bit).
```
ninput<0,0>
```
