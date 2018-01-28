#include "Enclave_t.h"
#include "sgx_trts.h"
#include "sgx_urts.h"
#include <cstdlib>
#include <string.h>


void hello(int *a, char *c){
  int pass2;
  char f[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','4','7','8'};
  uint32_t val;
  sgx_read_rand((unsigned char *) &val, 4);
  pass2 = val % strlen(f) ;
  *c = f[pass2];
}
