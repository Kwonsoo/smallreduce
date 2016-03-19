int nest_level;
int nest_literal_stack[4];
main() {
  while (1) {
    if (nest_level >= 3)
      ;
    else
      airac_observe(nest_literal_stack, nest_level);
    nest_level++;
    if (nest_level <= 0)
      nest_level--;
  }
}
