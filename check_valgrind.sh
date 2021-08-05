g++ $1 $2
valgrind --leak-check=full --show-leak-kinds=all ./a.out