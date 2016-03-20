struct _xmlNode {
  struct _xmlNode *next;
};
struct __anonstruct_idlist_t_27 {
  struct idlist_t *next;
} * main_currentitem;
void *main_tmp;
main() {
  struct _xmlNode *cur1;
  if (!(cur1 != 0))
    goto while_break___1;
  airac_observe(cur1, 0);
  cur1 = cur1->next;
while_break___1:
  main_tmp = malloc(sizeof(struct __anonstruct_idlist_t_27));
  main_currentitem->next = main_currentitem = main_tmp;
}
