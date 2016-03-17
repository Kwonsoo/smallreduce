struct mode_change {
  struct mode_change *next;
} * mode_compile_head;
struct name {
  struct name *next;
} * xmalloc_p, *namelast;
void *mode_compile_tmp___0;
int decode_options_new_argc;
mode_append_entry(struct mode_change **p1, struct mode_change *p2) { *p1 = p2; }

decode_options(p1) {
  xmalloc_p = malloc(decode_options_new_argc);
  decode_options_new_argc = p1;
  mode_compile_tmp___0 = malloc(sizeof(struct mode_change));
  mode_append_entry(&mode_compile_head, mode_compile_tmp___0);
  struct mode_change *changes = mode_compile_head;
  airac_observe(changes, 0);
  changes = changes->next;
}

main(p1, p2) {
  decode_options(p1);
  namelast->next = namelast = xmalloc_p;
}
