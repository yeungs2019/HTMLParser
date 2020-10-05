set terminal postscript color
set output "output.ps"
set xlabel "size"
set ylabel "time (seconds)"

plot [:][:] "data1" using 1:2 with lines
