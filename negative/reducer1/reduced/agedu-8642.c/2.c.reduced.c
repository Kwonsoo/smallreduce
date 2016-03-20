typedef triebuild;
triebuild main_ctx_0, main_tf___0;
char main_buf___0;
main() {
  main_buf___0 = fgetline();
  triebuild_add(main_ctx_0, main_buf___0, main_tf___0);
}

triencmp(b) {
  int off = 0;
  while (1) {
    airac_observe(b, off);
    off++;
  }
}

triecmp(char a, char b, int offset) { triencmp(b); }

void triebuild_add(triebuild tb, char pathname, const file) {
  int depth = triecmp(tb, pathname, depth);
}
