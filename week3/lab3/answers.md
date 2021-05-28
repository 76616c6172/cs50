
# Timing the output:
```bash
for f in *.txt ; do echo sort1 "$f" && time ./sort1 $f > sort1.out ; done
for f in *.txt ; do echo sort2 "$f" && time ./sort2 $f > sort2.out ; done
for f in *.txt ; do echo sort3 "$f" && time ./sort3 $f > sort3.out ; done
```
Times rounded to 1 decimal point :
```bash
# sort1
sort1 random10000.txt
user		0m1.2
sort1 random50000.txt
user    0m13.7
sort1 random5000.txt
user    0m0.1
sort1 reversed10000.txt
user    0m0.6
sort1 reversed50000.txt
suser    0m13.8
sort1 reversed5000.txt
user    0m0.1
sort1 sorted10000.txt
user    0m0.0
sort1 sorted50000.txt
user    0m0.0
sort1 sorted5000.txt
user    0m0.0
# sort2
sort2 random10000.txt
user    0m0.1     
sort2 random50000.txt
user    0m0.1       
sort2 random5000.txt   
user    0m0.1       
sort2 reversed10000.txt
user    0m0.1       
sort2 reversed50000.txt
user    0m0.1      
sort2 reversed5000.txt
user    0m0.1      
sort2 sorted10000.txt
user    0m0.1     
sort2 sorted50000.txt
user    0m0.1    
sort2 sorted5000.txt
user    0m0.1
# sort3
sort3 random10000.txt
user    0m0.2
sort3 random50000.txt
user    0m4.7
sort3 random5000.txt
user    0m0.0
sort3 reversed10000.txt
user    0m0.2
sort3 reversed50000.txt
user    0m4.8
sort3 reversed5000.txt
user    0m0.1
sort3 sorted10000.tft
user    0m0.2
sort3 sorted50000.txt
user    0m4.6
sort3 sorted5000.txt
user    0m0.0
```

# Comparing sort times
```bash
## random 50k - reversed 50k --  sorted 50k
sort3 4.7  ---- sort3 0.2 ------ sort3 4.6
sort2 0.1  ---- sort2 0.1 ------ sort2 0.1
sort1 13.7 ---- sort1 0.6 ------ sort1 0.0
```

# sort1 uses:  SELECTION SORT
How do you know?:  
It took an extreme amount of time to sort the random data set compared to the other two it's really an outlier.

# sort2 uses: BUBBLE SORT
How do you know?:  
Process of elimination, also looks like bubble sort becaause in the "best case" it can outperform merge sort, which appears to be the case in all of the datasets I used for comparison.

# sort3 uses: MERGE SORT
How do you know?  
Looks like merge sort because it slaps on reverse ordered data and performs consistent otherwise.
