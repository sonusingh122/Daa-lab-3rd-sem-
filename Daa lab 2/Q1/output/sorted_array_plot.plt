set terminal pngcairo size 1000,700 enhanced
set output 'sorted_array.png'

set title 'Sorted Array Operations'
set xlabel 'Input Size (n)'
set ylabel 'Growth / Operations'

set grid
set key outside

plot 'sorted_array.txt' using 1:2 with lines lw 2 title 'Search O(log n)', 'sorted_array.txt' using 1:3 with lines lw 2 title 'Insert O(n)', 'sorted_array.txt' using 1:4 with lines lw 2 title 'Delete O(n)', 'sorted_array.txt' using 1:5 with lines lw 2 title 'Maximum O(1)', 'sorted_array.txt' using 1:6 with lines lw 2 title 'Minimum O(1)', 'sorted_array.txt' using 1:7 with lines lw 2 title 'Predecessor O(log n)', 'sorted_array.txt' using 1:8 with lines lw 2 title 'Successor O(log n)'

set output
