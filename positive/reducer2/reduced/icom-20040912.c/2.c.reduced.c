struct bankmsg {
  char name[5];
} readbank() {
  struct bankmsg cmd___0;
  unsigned tmp = 1;
  while (1) {
    if (tmp >= 5)
      goto while_break;
    airac_observe(cmd___0.name, tmp);
    tmp++;
  }
while_break:
  ;
}
