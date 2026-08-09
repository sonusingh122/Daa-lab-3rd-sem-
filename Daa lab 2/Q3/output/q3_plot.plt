set terminal pngcairo size 1000,700 enhanced
set output 'q3_merge.png'

set title 'Comparison of Two K-Way Merge Methods'
set xlabel 'Number of Arrays (k)'
set ylabel 'Growth / Operations'

set grid
set key outside

plot 'q3_merge.txt' using 1:2 with lines lw 2 title 'Method 1 O(nk^2)', 'q3_merge.txt' using 1:3 with lines lw 2 title 'Method 2 O(nk log_2 k)'

set output
