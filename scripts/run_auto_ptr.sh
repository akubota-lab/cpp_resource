g++ $1 -std=c++03
if [ $? == 0 ]; then
    echo "==============="
    ./a.out
    echo "==============="
else
    echo "*** compile error ***"
fi