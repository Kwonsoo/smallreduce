struct link {
  void *data;
} list_append_link___0, *sample_find_link___0, *samples_dump_link___0,
    *timer_info_find_link___0;
struct __anonstruct_list_t_54 {
  struct link *head;
} timer_info_list, sample_list;
struct timer_info {
  int;
  char *task;
  char;
  char *func;
  char;
  char *ident;
  _Bool;
  long;
} * timer_info_find_info;
struct sample_delta_item {
  unsigned;
  struct timer_info *info;
} list_append_sdi;
struct sample_delta_list {
  int;
  struct __anonstruct_list_t_54 list;
} * list_append_sdl;
void *list_append_tmp, *timer_info_find_tmp___0;
list_append(struct __anonstruct_list_t_54 *p1, void *p2) {
  list_append_link___0.data = p2;
  p1->head = &list_append_link___0;
  list_append_tmp = calloc(1, sizeof(struct sample_delta_list));
  list_append_sdl = list_append_tmp;
  list_append(&sample_list, list_append_tmp);
  list_append(&list_append_sdl->list, &list_append_sdi);
}

sample_find(struct sample_delta_list *p1) {
  sample_find_link___0 = p1->list.head;
}

samples_dump() {
  struct sample_delta_item *sdi___0 = sample_find_link___0->data;
  airac_observe(sdi___0, 0);
  samples_dump_link___0 = sample_list.head;
  sample_find(samples_dump_link___0->data);
}

timer_stat_add() {
  timer_info_find_link___0 = timer_info_list.head;
  timer_info_find_info = timer_info_find_link___0->data;
  timer_info_find_tmp___0 = calloc(1, sizeof(struct timer_info));
  timer_info_find_info = timer_info_find_tmp___0;
  list_append(&timer_info_list, timer_info_find_info);
}
