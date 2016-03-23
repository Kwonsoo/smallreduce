typedef struct cfglist *cfgListPtr;
struct cfglist {
  char;
  cfgListPtr;
} typedef cfgList;
cfgListPtr parse_simple_tmp___17;
void *parse_simple_tmp___18, *parse_simple_tmp___19;
parse_simple() {
  cfgList *listptr = strtoul();
  if (0)
  if_break___0 : {
    parse_simple_tmp___18 = malloc(sizeof(cfgList));
    parse_simple_tmp___17 = parse_simple_tmp___18;
    listptr = parse_simple_tmp___17;
  }
  else {
    parse_simple_tmp___19 = malloc(sizeof(cfgList));
    listptr = parse_simple_tmp___19;
  }
  airac_observe(listptr, 0);
}
