#!/usr/bin/python3

set tmargin 2
set bmargin 7
set size ratio 0.675

set xlabel 'Size of array' font ',20' offset 0.0,-1.5
set ylabel 'Microseconds fot one iteration' font ',20' offset -4.5,0.0

set tics font ',20'
set key font ',20'
set key top center
#  set key box lc 'black' lw 1

set tics nomirror

set object 1 rectangle from screen 0,0 to screen 1,1 fillcolor rgb"0x00cccccc" behind

# Build plots one at a time
#  plot 'bubble.plot' us 1:2 title 'Bubble' pt 7 ps 2.5
#  plot 'shaker.plot' us 1:2 title 'Shaker' pt 7 ps 2.5
#  plot 'select.plot' us 1:2 title 'Select' pt 7 ps 2.5
#  plot 'quick.plot' us 1:2 title 'Quick' pt 7 ps 2.5
#  plot 'merge.plot' us 1:2 title 'Merge' pt 7 ps 2.5
#  plot 'heap.plot' us 1:2 title 'Heap' pt 7 ps 2.5
#  plot 'merge1000.plot' us 1:2 title 'Merge' pt 7 ps 1.5
#  plot 'count.plot' us 1:2 title 'Count' pt 7 ps 1.5

# Build all plots together
#  plot 'bubble.plot' us 1:2 title 'Bubble' pt 7 ps 1, \
	 #  'shaker.plot' us 1:2 title 'Shaker' pt 7 ps 1, \
	 #  'select.plot' us 1:2 title 'Select' pt 7 ps 1, \
	 #  'quick.plot'  us 1:2 title 'Quick'  pt 7 ps 1, \
	 #  'merge.plot'  us 1:2 title 'Merge'  pt 7 ps 1, \
	 #  'heap.plot'   us 1:2 title 'Heap'   pt 7 ps 1 

# Build plots of effective sorting
plot 'quick.plot'  us 1:2 title 'Quick'  pt 7 ps 1 lc rgb 'orange', \
	 'merge.plot'  us 1:2 title 'Merge'  pt 7 ps 1 lc rgb 'yellow', \
	 'heap.plot'   us 1:2 title 'Heap'   pt 7 ps 1 lc rgb 'blue'
