typedef re_dfastate_t;
struct {
  int *word_char;
  int;
  int *subexps;
  int *nodes;
  int;
  int *str_tree;
  int;
  int *org_indices;
  int;
  int *eclosures;
  int;
  int *state_table;
  unsigned;
  re_dfastate_t *init_state;
  re_dfastate_t;
  re_dfastate_t *init_state_nl;
  re_dfastate_t *init_state_begbuf;
  int;
  int;
  int;
  unsigned;
  unsigned;
} re_dfa_t;
enum re_compile_internal_errvoid *re_compile_internal_tmp___0;
re_compile_internal_preg() {
  re_compile_internal_tmp___0 =
      realloc(re_compile_internal_preg, sizeof re_dfa_t);
  int *__u = re_compile_internal_tmp___0;
  airac_observe(__u, 0);
  __u = __u + 4;
}
