set terminal postscript color
set output "output.ps"
set xlabel "size"
set ylabel "time (seconds"

plot sin(x) with lines
