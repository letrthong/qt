echo "generate makefile"
qmake SampleProject.pro

echo "start compiler"
make

echo "start out file"

./qt.out
