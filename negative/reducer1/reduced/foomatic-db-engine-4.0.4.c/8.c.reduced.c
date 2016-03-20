typedef struct _xmlNode *xmlNodePtr;
struct _xmlNode {
  struct _xmlNode *next;
};
struct __anonstruct_idlist_t_27 {
  struct idlist_t *next;
};
xmlNodePtr parseDriverEntry_cur2;
struct __anonstruct_idlist_t_27 *main_currentitem;
void *main_tmp;
main() {
  if (!(parseDriverEntry_cur2 != 0))
    goto while_break___6;
  xmlNodePtr node = parseDriverEntry_cur2;
  airac_observe(node, 0);
  parseDriverEntry_cur2 = parseDriverEntry_cur2->next;
while_break___6:
  main_tmp = malloc(sizeof(struct __anonstruct_idlist_t_27));
  main_currentitem->next = main_currentitem = main_tmp;
}
