g++ -o Solutions/Linear Solutions/Linear.cpp
for i in $(seq 1 10)
do
  ./Solutions/Linear < ../OmegaUpPackage/cases/1_small_fixed.$i.in > ../OmegaUpPackage/cases/1_small_fixed.$i.out
done
for i in $(seq 1 25)
do
  ./Solutions/Linear < ../OmegaUpPackage/cases/2_small_brute.$i.in > ../OmegaUpPackage/cases/2_small_brute.$i.out
done
for i in $(seq 1 25)
do
  ./Solutions/Linear < ../OmegaUpPackage/cases/3_big_nm_small_k.$i.in > ../OmegaUpPackage/cases/3_big_nm_small_k.$i.out
done
for i in $(seq 1 40)
do
  ./Solutions/Linear < ../OmegaUpPackage/cases/4_no_restrictions.$i.in > ../OmegaUpPackage/cases/4_no_restrictions.$i.out
done