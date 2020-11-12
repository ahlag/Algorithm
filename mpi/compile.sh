echo "Program Name : " 
read name

$HOME/opt/usr/local/bin/mpic++ -o $name ./$name.cpp

echo "How many processes? : "
read process

$HOME/opt/usr/local/bin/mpirun -np $process  ./$name
