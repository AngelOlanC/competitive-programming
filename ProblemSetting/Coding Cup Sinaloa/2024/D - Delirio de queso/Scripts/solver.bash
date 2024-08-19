g++ -o Solutions/Linear Solutions/Linear.cpp
for i in $(seq 1 100)
do
  ./Solutions/Linear < ../OmegaUpPackage/cases/$i.in > ../OmegaUpPackage/cases/$i.out
done