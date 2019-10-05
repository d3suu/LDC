# Objects

## timer
Timer object, selected by keyword.
```
offdelay timer<0.01, 2000, 2000> MyTOFTimer;
ondelay timer<0.01, 2000, 2000> MyTONTimer;
pulse timer<0.01, 2000, 2000> MyPulseTimer;
```

#### Keywords
 - `offdelay` - TOF timer
 - `ondelay` - TON timer
 - `pulse` - TP timer

#### Syntax
```
timer<TimeBase, SetValue, CurrentValue> TimerName;
```

#### Object methods
 - `.done` - Done bit (`%TMi.Q`)
 - `.value` - Timer current value (`%TMi.V`)
 - `.max` - Timer task value (`%TMi.P`)

 - `.enable()` - Call timer to start counting


## counter [FIX ME]
