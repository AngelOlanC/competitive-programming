g++ -o Solutions/Quadratic Solutions/Quadratic.cpp
g++ -o Solutions/Linear Solutions/Linear.cpp

for i in $(seq 1 10)
do
  cat > input < ../OmegaUpPackage/cases/1_small_fixed.$i.in
  ./Solutions/Linear < input > outLinear
  ./Solutions/Quadratic < input > outQuadratic
  diff -Z outLinear outQuadratic > /dev/null || break
done
echo "WA on the following test:"
cat input
echo "Linear output:"
cat outLinear
echo "Quadratic output is:"
cat outQuadratic
for i in $(seq 1 25)
do
  cat > input < ../OmegaUpPackage/cases/2_small_brute.$i.in
  ./Solutions/Linear < input > outLinear
  ./Solutions/Quadratic < input > outQuadratic
  diff -Z outLinear outQuadratic > /dev/null || break
done
echo "WA on the following test:"
cat input
echo "Linear output:"
cat outLinear
echo "Quadratic output is:"
cat outQuadratic
for i in $(seq 1 25)
do
  cat > input < ../OmegaUpPackage/cases/3_big_nm_small_k.$i.in
  ./Solutions/Linear < input > outLinear
  ./Solutions/Quadratic < input > outQuadratic
  diff -Z outLinear outQuadratic > /dev/null || break
done
echo "WA on the following test:"
cat input
echo "Linear output:"
cat outLinear
echo "Quadratic output is:"
cat outQuadratic
for i in $(seq 1 40)
do
  cat > input < ../OmegaUpPackage/cases/4_no_restrictions.$i.in
  ./Solutions/Linear < input > outLinear
  ./Solutions/Quadratic < input > outQuadratic
  diff -Z outLinear outQuadratic > /dev/null || break
done
echo "WA on the following test:"
cat input
echo "Linear output:"
cat outLinear
echo "Quadratic output is:"
cat outQuadratic
rm outQuadratic
rm outLinear