> NTUT Embedded Systems <br> Midterm Review <br> Cron Stuff

##
**1. What is the cron daemon?**

> The daemon in a linux system that handles periodic execution. The daemon reads configuration files (crontabs) and executes commands on time.

##
**2. What is the cron command format?**

> minute hour day month weekday command

##
```crontab
0 0 14 2 *
```
**3. What time and date does this format get translated to?**

> On the midnight of Valentine's day

##
```crontab
45 10 * * 1-5
```
**4. What time and date does this format get translated to?**

> 10:45 AM, from Mon to Fri

##
```crontab
/3 * * * *
```
**5. What time and date does this format get translated to?**

> Every three minutes

##
```crontab
0,30 * 13 * 5
```
**6. What time and date does this format get translated to?**

> Every half hour on Friday and every half hour on the 13th