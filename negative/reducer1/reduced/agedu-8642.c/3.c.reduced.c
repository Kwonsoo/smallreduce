typedef struct triebuild triebuild;
struct triebuild {
  char lastpath;
} * main_ctx_0;
char main_buf___0;
int main_tf___0, triencmp_blen;
void *srealloc_q;
main() {
  main_ctx_0 = triebuild_new();
  while (1)
    triebuild_add(main_ctx_0, main_buf___0, main_tf___0);
}

void triebuild_add(triebuild *tb, char pathname, const file) {
  int a = tb->lastpath, off = 0;
  while (1) {
    if (triencmp_blen)
      goto while_break;
    off++;
  }
while_break:
  airac_observe(a, off);
  srealloc_q = realloc(tb, tb);
  tb->lastpath = srealloc_q;
}
