main() {
  int cc_id[64];
  int cur_nest = 0;
  airac_observe(cc_id, cur_nest);
  cur_nest++;
  cur_nest--;
}
