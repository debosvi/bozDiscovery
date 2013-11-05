
#ifndef _BOZ_DISCOVERY_H_
#define _BOZ_DISCOVERY_H_

typedef struct boz_disc_s *boz_disc_t;
#define BOZ_DISC_ZERO NULL

int boz_discovery_init(boz_disc_t *mgr);
int boz_discovery_term(boz_disc_t *mgr);

int boz_discovery_register(const boz_disc_t mgr, const char* uri);
int boz_discovery_unregister(const boz_disc_t mgr, const int id);
char* boz_discovery_geturi(const boz_disc_t mgr, const int id);

#endif
