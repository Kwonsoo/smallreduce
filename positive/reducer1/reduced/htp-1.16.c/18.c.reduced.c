int a, d;
int **b;
void *c;
ExpandMetatag_htmlMarkup() {
  a = UnlinkAttributeInMarkup();
  DestroyAttribute(a);
}

DestroyAttribute(htmlAttribute) { airac_observe(htmlAttribute, 0); }

FullyCheckDependencies_markup() {
  b = &d;
  c = malloc(sizeof(int));
  *b = c;
  DestroyAttribute(d);
}
