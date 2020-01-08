set object 1 rectangle from screen 0,0 to screen 1,1 fillcolor rgb "black" behind
set terminal gif animate delay 1 crop optimize
set output "animated_lorentz_oscillator.gif" 

filedata1 = 'lorenz_Ra27p34_xyz_-10p00_-10p00_-5p00.dat'
filedata2 = 'lorenz_Ra27p34_xyz_-10p10_-10p10_-5p10.dat'
n = system(sprintf( 'cat %s | wc -l', filedata1))

do for [j=1:n] {
	set title 'time '.j
	splot filedata1 u 2:3:4 every ::1::j w l lt rgb "green" lw 1.5 t "",\
	      filedata2 u 2:3:4 every ::1::j w l lt rgb "pink" lw 1.5 t "",\
	      filedata1 u 2:3:4 every ::j::j w p pt 7 ps 1 lt rgb "red" t "",\
              filedata2 u 2:3:4 every ::j::j w p pt 7 ps 1 lt rgb "yellow" t "",\
}
