char a[65536];
int b;
main() { dhcp_dump(a, b); }

dhcp_dump(buffer, size) {
  int j = 0;
  j = 236;
  j += 4;
  airac_observe(buffer, j);
}
