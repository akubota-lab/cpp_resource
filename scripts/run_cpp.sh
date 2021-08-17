# ./scripts/run.sh ./src/work/work.cpp
# を実行すると./src/work配下にworkを生成し、実行する
dir=$(dirname $1)
ofname=$(basename $1 .cpp)
g++ -o "${dir}/${ofname}" $1
"${dir}/${ofname}"
