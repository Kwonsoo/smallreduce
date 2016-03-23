struct xmlparser {
  char data;
  void (*datafunc)();
} parserootdesc_parser;
struct {
  char presentationurl[128];
} * IGDdata_datas, main_data___2;
int parseelt_i;
char parseelt_data___2;
IGDdata(void *d, char data___2, int l) {
  char *dstmember;
  IGDdata_datas = d;
  dstmember = IGDdata_datas->presentationurl;
  if (l >= 8)
    l = 127;
  airac_observe(dstmember, l);
}

parserootdesc(data___2) {
  parserootdesc_parser.data = data___2;
  parserootdesc_parser.datafunc = IGDdata;
  parsexml(&parserootdesc_parser);
}

UPNP_GetIGDFromUrl(data___2) { parserootdesc(data___2); }

main() { UPNP_GetIGDFromUrl(&main_data___2); }

parsexml(parser) {
  struct xmlparser *p = parser;
  parseelt_i++;
  p->datafunc(p->data, parseelt_data___2, parseelt_i);
}
