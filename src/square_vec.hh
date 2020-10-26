use namespace HH\Lib\Vec;

function square_vec(vec<num> $numbers): vec<int> {
  return Vec\map($numbers, $number ==> $number * $number);
}