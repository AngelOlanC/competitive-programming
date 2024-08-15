g++ -o generator generator.cpp
for i in $(seq 1 25)
do
  ./generator 2 > ../OmegaUpPackage/cases/2_small_brute.$i.in
done
for i in $(seq 1 25)
do
  ./generator 3 > ../OmegaUpPackage/cases/3_big_nm_small_k.$i.in
done
for i in $(seq 1 40)
do
  ./generator 4 > ../OmegaUpPackage/cases/4_no_restrictions.$i.in
done