enum __anonenum_TWOLAME_MPEG_mode_9 { TWOLAME_NOT_SET };
struct twolame_options_struct {
  enum __anonenum_TWOLAME_MPEG_mode_9 mode;
} * twolame_init_newoptions;
void *twolame_init_tmp;
static mode_name[6];
twolame_init_params(struct twolame_options_struct *p1) {
  p1->mode = 3;
  twolame_get_mode_name(p1);
}

twolame_get_mode_name(struct twolame_options_struct *p1) {
  int mode = p1->mode;
  airac_observe(mode_name, mode + 1);
  twolame_init_tmp = twolame_malloc();
  twolame_init_newoptions = twolame_init_tmp;
  twolame_init_newoptions->mode = -1;
  twolame_init_params(twolame_init_tmp);
}
