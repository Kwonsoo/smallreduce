struct link {
  void *data;
} list_append_link___0, *timer_info_find_link___0;
struct __anonstruct_list_t_54 {
  struct link *head;
} timer_info_list, sample_add_sdl;
struct timer_info {
  long;
};
int sample_add_tmp___0;
void *timer_info_find_tmp___0;
list_append(struct __anonstruct_list_t_54 *p1, void *p2) {
  list_append_link___0.data = p2;
  p1->head = &list_append_link___0;
}

timer_stat_diff() {
  sample_add_tmp___0 = calloc(1, sizeof(int));
  list_append(&sample_add_sdl, sample_add_tmp___0);
  struct timer_info *info;
  timer_info_find_link___0 = timer_info_list.head;
  info = timer_info_find_link___0->data;
  timer_info_find_tmp___0 = calloc(1, sizeof(struct timer_info));
  info = timer_info_find_tmp___0;
  airac_observe(info, 0);
  list_append(&timer_info_list, info);
}
