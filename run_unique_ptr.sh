g++ $1
if [ $? == 0 ]; then
    echo "==============="
    ./a.out
    echo "==============="
else
    echo "*** compile error ***"
fi