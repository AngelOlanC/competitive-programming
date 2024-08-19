g++ -o generator generator.cpp
for i in $(seq 1 10)
do
  ./generator 1 > ../OmegaUpPackage/cases/$i.in
done
for i in $(seq 11 35)
do
  ./generator 2 > ../OmegaUpPackage/cases/$i.in
done
for i in $(seq 36 60)
do
  ./generator 3 > ../OmegaUpPackage/cases/$i.in
done
for i in $(seq 61 100)
do
  ./generator 4 > ../OmegaUpPackage/cases/$i.in
done