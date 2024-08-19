g++ -o Solutions/Quadratic Solutions/Quadratic.cpp
g++ -o Solutions/Linear Solutions/Linear.cpp

for i in $(seq 1 100)
do
  cat > input < ../OmegaUpPackage/cases/$i.in
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
rm input
rm outQuadratic
rm outLinear