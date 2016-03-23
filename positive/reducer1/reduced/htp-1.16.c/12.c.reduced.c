struct tagHTML_MARKUP {
  int attrib;
} * a;
int **b;
void *c;
ExpandMetatag_htmlMarkup() {
  a = UnlinkAttributeInMarkup();
  DestroyAttribute(a);
}

DestroyAttribute(htmlAttribute) { airac_observe(htmlAttribute, 0); }

FullyCheckDependencies_markup() {
  {
    struct tagHTML_MARKUP *d = FullyCheckDependencies_markup;
    b = &d->attrib;
    c = malloc(sizeof(int));
    *b = c;
  }
  struct tagHTML_MARKUP *e = FullyCheckDependencies_markup;
  DestroyAttribute(e->attrib);
}
