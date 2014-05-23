#ifndef __LOCATION_H__
#define __LOCATION_H__

typedef struct _location location;

location * location_new(const char * filename, const char * name);
void       location_destroy(location * l);

#endif //__LOCATION_H__

