set terminal pngcairo size 1000,700 enhanced
set output 'singly_linked_unsorted.png'

set title 'Singly Linked List - Unsorted'
set xlabel 'Input Size (n)'
set ylabel 'Growth / Operations'

set grid
set key outside

plot 'singly_linked_unsorted.txt' using 1:2 with lines lw 2 title 'Search O(n)', 'singly_linked_unsorted.txt' using 1:3 with lines lw 2 title 'Insert O(1)', 'singly_linked_unsorted.txt' using 1:4 with lines lw 2 title 'Delete O(n)', 'singly_linked_unsorted.txt' using 1:5 with lines lw 2 title 'Maximum O(n)', 'singly_linked_unsorted.txt' using 1:6 with lines lw 2 title 'Minimum O(n)', 'singly_linked_unsorted.txt' using 1:7 with lines lw 2 title 'Predecessor O(n)', 'singly_linked_unsorted.txt' using 1:8 with lines lw 2 title 'Successor O(n)'

set output
