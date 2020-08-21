void sort(int *a, int len);

int main() {
  int a[30];
  for (int i=0; i<30; i++)
    a[i] = 30-i;
  sort(a, 30);
  return 0;
}

void sort(int *a, int len) {
  int min, tmp;
  for (int i=0; i<len; i++) {
    min = i;
    for (int j=i+1; j<len; j++)
      if (a[min] > a[j])
        min = j;
    tmp = a[i];
    a[i] = a[min];
    a[min] = tmp;
  }
}

