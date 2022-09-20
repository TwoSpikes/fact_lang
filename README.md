my programming language, btw


Examples:
```print next print ins 50 print prev print ins 99 print next next next```

Output:
```--------------------
lines_str='print next print ins 50 print prev print ins 99 print next next next'                                                                        splitted=['print', 'next', 'print', 'ins', '50', 'print', 'prev', 'print', 'ins', '99', 'print', 'next', 'next', 'next']                                ------ parsing 14 words... ------
------ interpreting 12 commands... ------
0. ---- print 0 ----
0
1. ---- next after=1 ----
2. ---- print 1 ----
0
3. ---- insert oper=50 ind=1 ----
4. ---- print 1 ----
50
5. ---- prev after=0 ----
6. ---- print 0 ----
0
7. ---- insert oper=99 ind=0 ----
8. ---- print 0 ----
99
9. ---- next after=1 ----
10. ---- next after=2 ----
11. ---- next after=3 ----
```

At the end of file you must write ```FILEEND``` at the new line.
