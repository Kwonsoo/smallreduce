typedef struct _xmlNode *xmlNodePtr;
struct _xmlNode {
  struct _xmlNode *next;
};
struct __anonstruct_idlist_t_27 {
  struct idlist_t *next;
};
xmlNodePtr parseDriverEntry_cur1;
struct __anonstruct_idlist_t_27 *main_currentitem;
void *main_tmp;
main() {
  if (!(parseDriverEntry_cur1 != 0))
    goto while_break;
  xmlNodePtr node = parseDriverEntry_cur1;
  airac_observe(node, 0);
  parseDriverEntry_cur1 = parseDriverEntry_cur1->next;
while_break:
  main_tmp = malloc(sizeof(struct __anonstruct_idlist_t_27));
  main_currentitem->next = main_currentitem = main_tmp;
}
