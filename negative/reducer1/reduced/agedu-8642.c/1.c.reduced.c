typedef struct triebuild triebuild;
struct triebuild {
  char lastpath;
} * main_ctx_0;
char main_buf___0;
int main_tf___0;
void *srealloc_q;
main() {
  main_ctx_0 = triebuild_new();
  while (1)
    triebuild_add(main_ctx_0, main_buf___0, main_tf___0);
}

triencmp(a) {
  int off = 0;
  while (1) {
    airac_observe(a, off);
    off++;
  }
}

void triebuild_add(triebuild *tb, char pathname, const file) {
  triencmp(tb->lastpath);
  srealloc_q = realloc(tb, tb);
  tb->lastpath = srealloc_q;
}
