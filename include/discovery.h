
#ifndef _BOZ_DISCOVERY_H_
#define _BOZ_DISCOVERY_H_

typedef struct boz_disc_s *boz_disc_t;

int boz_discovery_init(boz_disc_t *manager);
int boz_discovery_term(boz_disc_t *manager);

#endif
