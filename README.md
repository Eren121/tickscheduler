# tickscheduler

Tick-based scheduler written in C++11.

## What does that mean ?

It is exaclty like **cron**, but instead of working in time intervals, it use integral ticks. This has the flexibility of pausing or change the speed of the scheduler, as the user decides what a tick is. To behave exactly like cron, the user has just to define a tick as a second and update the scheduler each second.


## Example


<details>
 
  <summary>
    <a href="example/example.cpp">example.cpp</a> output
  </summary>
  
```
 hello (after 0 ticks)
==== tick 1:
==== tick 2:
==== tick 3:
==== tick 4:
==== tick 5:
 hello (after 5 ticks)
==== tick 6:
==== tick 7:
==== tick 8:
==== tick 9:
==== tick 10:
==== tick 11:
==== tick 12:
==== tick 13:
==== tick 14:
==== tick 15:
==== tick 16:
==== tick 17:
==== tick 18:
==== tick 19:
==== tick 20:
 hello (after 20 ticks)
==== tick 21:
==== tick 22:
==== tick 23:
==== tick 24:
==== tick 25:
==== tick 26:
==== tick 27:
==== tick 28:
==== tick 29:
==== tick 30:
==== tick 31:
==== tick 32:
==== tick 33:
==== tick 34:
==== tick 35:
==== tick 36:
==== tick 37:
==== tick 38:
==== tick 39:
==== tick 40:
==== tick 41:
==== tick 42:
==== tick 43:
==== tick 44:
==== tick 45:
==== tick 46:
==== tick 47:
==== tick 48:
==== tick 49:
==== tick 50:
 hello (after 50 ticks)
 hello (submitted at tick 0 to run after 50 ticks
==== tick 51:
==== tick 52:
==== tick 53:
==== tick 54:
==== tick 55:
==== tick 56:
==== tick 57:
==== tick 58:
==== tick 59:
==== tick 60:
 hello (submitted at tick 10 to run after 50 ticks
==== tick 61:
==== tick 62:
==== tick 63:
==== tick 64:
==== tick 65:
==== tick 66:
==== tick 67:
==== tick 68:
==== tick 69:
==== tick 70:
 hello (submitted at tick 20 to run after 50 ticks
==== tick 71:
==== tick 72:
==== tick 73:
==== tick 74:
==== tick 75:
==== tick 76:
==== tick 77:
==== tick 78:
==== tick 79:
==== tick 80:
 hello (after 80 ticks)
 hello (submitted at tick 30 to run after 50 ticks
==== tick 81:
==== tick 82:
==== tick 83:
==== tick 84:
==== tick 85:
==== tick 86:
==== tick 87:
==== tick 88:
==== tick 89:
==== tick 90:
 hello (submitted at tick 40 to run after 50 ticks
==== tick 91:
==== tick 92:
==== tick 93:
==== tick 94:
==== tick 95:
==== tick 96:
==== tick 97:
==== tick 98:
==== tick 99:
==== tick 100:
```
  
 </details>
