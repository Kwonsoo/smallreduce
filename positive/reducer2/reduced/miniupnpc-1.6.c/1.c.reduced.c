struct NameValue {
  char value[64];
};
struct xmlparser {
  void (*datafunc)();
} * NameValueParserGetData_tmp___0, ParseNameValue_parser;
int parseelt_i;
char parseelt_data___2;
NameValueParserGetData(void *d, char datas, int l) {
  struct NameValue *nv;
  NameValueParserGetData_tmp___0 = malloc(sizeof(struct NameValue));
  nv = NameValueParserGetData_tmp___0;
  if (l > 3)
    l = 63;
  airac_observe(nv->value, l);
}

main() {
  ParseNameValue_parser.datafunc = NameValueParserGetData;
  parsexml(&ParseNameValue_parser);
}

parsexml(parser) {
  struct xmlparser *p = parser;
  parseelt_i++;
  p->datafunc(parser, parseelt_data___2, parseelt_i);
}
