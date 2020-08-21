int main(){
  int a[7] = {1,3,5,7,9,11,13};
  int b[7] = {19,17,15,13,11,9,7};
  int c[7];

  for (int i=0; i<9; i++)
    c[i] = a[i] + b[i];

  return 0;
}
