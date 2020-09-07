set terminal postscript color
set output "output.ps"
set xlabel "size"
set ylabel "time (seconds)"

plot [:][:] "data5" using 1:2 with lines
