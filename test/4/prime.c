int is_prime(int x);

int main(){
  int x = 101;
  int re;
  re = is_prime(x);
  return re;
}

int is_prime(int x){
  for (int i=2; i<x/2; i++)
    if (x % i == 0)
      return i;
  return 707;
}
