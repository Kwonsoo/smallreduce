struct link {
  void *data;
} list_append_link___0, *timer_info_find_link___0;
struct __anonstruct_list_t_54 {
  struct link *head;
} timer_info_list;
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
};
struct sample_delta_list {
  int;
  struct __anonstruct_list_t_54;
};
static sample_list;
void *list_append_tmp, *timer_info_find_tmp___0;
list_append(struct __anonstruct_list_t_54 *p1, void *p2) {
  list_append_link___0.data = p2;
  p1->head = &list_append_link___0;
  struct sample_delta_item *sdi;
  list_append_tmp = calloc(1, sizeof(struct sample_delta_list));
  list_append(sample_list, list_append_tmp);
  sdi = p2;
  airac_observe(sdi, 0);
}

main() {
  timer_info_find_link___0 = timer_info_list.head;
  timer_info_find_info = timer_info_find_link___0->data;
  timer_info_find_tmp___0 = calloc(1, sizeof(struct timer_info));
  timer_info_find_info = timer_info_find_tmp___0;
  list_append(&timer_info_list, timer_info_find_info);
}
