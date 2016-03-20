struct _xmlNode {
  struct _xmlNode *next;
};
struct __anonstruct_idlist_t_27 *main_currentitem;
void *main_tmp;
struct __anonstruct_idlist_t_27 {
  struct idlist_t *next;
} parseDriverEntry() {
  struct _xmlNode *cur1;
  airac_observe(cur1, 0);
  if (cur1 != 0)
    cur1 = cur1->next;
}

main() {
  parseDriverEntry();
  main_tmp = malloc(sizeof(struct __anonstruct_idlist_t_27));
  main_currentitem->next = main_currentitem = main_tmp;
}
