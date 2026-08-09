#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    FILE *fp;

    /* Create data file */
    fp = fopen("unsorted_array.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp,
            "# n Search Insert Delete Maximum Minimum Predecessor Successor\n");

    for (int n = 1; n <= MAX; n++)
    {
        double search = n;      // O(n)
        double insert = 1;      // O(1)
        double delete = n;      // O(n)
        double maximum = n;     // O(n)
        double minimum = n;     // O(n)
        double predecessor = n; // O(n)
        double successor = n;   // O(n)

        fprintf(fp,
                "%d %.4lf %.4lf %.4lf %.4lf %.4lf %.4lf %.4lf\n",
                n,
                search,
                insert,
                delete,
                maximum,
                minimum,
                predecessor,
                successor);
    }

    fclose(fp);

    printf("unsorted_array.txt created successfully.\n");

    /* Create Gnuplot script */

    FILE *gp = fopen("unsorted_array_plot.plt", "w");

    if (gp == NULL)
    {
        printf("Error creating Gnuplot script.\n");
        return 1;
    }

    fprintf(gp,
            "set terminal pngcairo size 1000,700 enhanced\n"
            "set output 'unsorted_array.png'\n"
            "\n"
            "set title 'Unsorted Array Operations'\n"
            "set xlabel 'Input Size (n)'\n"
            "set ylabel 'Growth / Operations'\n"
            "\n"
            "set grid\n"
            "set key outside\n"
            "\n"
            "plot "
            "'unsorted_array.txt' using 1:2 with lines lw 2 title 'Search O(n)', "
            "'unsorted_array.txt' using 1:3 with lines lw 2 title 'Insert O(1)', "
            "'unsorted_array.txt' using 1:4 with lines lw 2 title 'Delete O(n)', "
            "'unsorted_array.txt' using 1:5 with lines lw 2 title 'Maximum O(n)', "
            "'unsorted_array.txt' using 1:6 with lines lw 2 title 'Minimum O(n)', "
            "'unsorted_array.txt' using 1:7 with lines lw 2 title 'Predecessor O(n)', "
            "'unsorted_array.txt' using 1:8 with lines lw 2 title 'Successor O(n)'\n"
            "\n"
            "set output\n");

    fclose(gp);

    printf("Gnuplot script created.\n");
    printf("Generating graph...\n");

    /* Run Gnuplot */

    int result = system("gnuplot unsorted_array_plot.plt");

    if (result != 0)
    {
        printf("\nGnuplot could not be executed.\n");
        printf("Make sure Gnuplot is installed and added to PATH.\n");
        return 1;
    }

    /* Open graph automatically */

    system("start \"\" \"unsorted_array.png\"");

    printf("Graph generated and opened successfully.\n");

    return 0;
}