set terminal postscript color
set output "output.ps"
set xlabel "size"
set ylabel "time (seconds"

plot [:][:] "first.data" using 1:2 with lines, "second.data" using 1:2 with lines, "third.data" using 1:2 with lines
