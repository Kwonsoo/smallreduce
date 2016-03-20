typedef triebuild;
triebuild main_ctx_0, main_tf___0, triencmp_blen;
char main_buf___0;
main() {
  main_buf___0 = fgetline();
  triebuild_add(main_ctx_0, main_buf___0, main_tf___0);
}

triencmp(b) {
  int off = 0;
  while (1) {
    if (triencmp_blen)
      goto while_break;
    off++;
  }
while_break:
  airac_observe(b, off);
}

triecmp(char a, char b, int offset) { triencmp(b); }

void triebuild_add(triebuild tb, char pathname, const file) {
  int depth = triecmp(tb, pathname, depth);
}
