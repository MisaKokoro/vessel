PROGRAMPATH=$PWD/build/src
# echo PROGRAMPATH

for i in {1..12}
do
    echo > out
    for j in {1..400}
    do
        $PROGRAMPATH/wamrTest ${i} >> out
    done
    python3 calc.py
done


