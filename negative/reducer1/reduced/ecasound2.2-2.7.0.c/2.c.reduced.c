struct eci_string_s {
  char d;
  int size;
};
struct eci_parser {
  struct eci_string_s last_s_repp;
};
struct eci_internal {
  struct eci_parser *parser_repp;
} * eci_init_r_eci_rep, *eci_last_string_r_eci_rep;
void *eci_init_r_tmp___2, *eci_string_add_tmp___0;
int eci_string_add_tmp, play_tracks_eci;
eci_string_add(struct eci_string_s *p1) {
  eci_string_add_tmp = p1->size * 2;
  eci_string_add_tmp = 4;
  eci_string_add_tmp___0 = realloc(p1, eci_string_add_tmp);
  p1->size = eci_string_add_tmp;
  p1->d = eci_string_add_tmp___0;
}

eci_impl_set_last_values(struct eci_parser *p1) {
  eci_string_add(&p1->last_s_repp);
}

eci_impl_update_state(p1) {
  eci_impl_set_last_values(p1);
  play_tracks();
}

initialize_check_output(p1) {
  char *tmpstr;
  eci_last_string_r_eci_rep = p1;
  tmpstr = eci_last_string_r_eci_rep->parser_repp->last_s_repp.d;
  airac_observe(tmpstr, 0);
  tmpstr++;
}

initialize_chainsetup_for_playback(int *p1) {
  eci_init_r_tmp___2 = calloc(1, sizeof(struct eci_internal));
  eci_init_r_eci_rep = eci_init_r_tmp___2;
  eci_init_r_eci_rep->parser_repp = calloc;
  struct eci_internal *eci_rep = eci_init_r_tmp___2;
  eci_impl_update_state(eci_rep->parser_repp);
  *p1 = eci_init_r_tmp___2;
  initialize_check_output(*p1);
}

get_next_track(p1) { initialize_chainsetup_for_playback(p1); }

play_tracks() { get_next_track(&play_tracks_eci); }
