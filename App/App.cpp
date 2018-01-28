#include <iostream>
#include "Enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"
#include <string.h>
#include <cstdlib>
#include <string.h>
#include <iostream>

const char RED[8]="\033[0;31m";
const char GREEN[8]="\033[0;32m";
const char YELLOW[8]="\033[0;33m";
const char NO_COLOR[7]="\033[0m";

/* Global EID shared by multiple threads */
sgx_enclave_id_t global_eid = 0;

int main(int argc, char const *argv[]) {
    if (initialize_enclave(&global_eid, "enclave.token", "./bin/enclave.signed.so") < 0) {
        std::cerr << "Fail to initialize enclave." << std::endl;
        return 1;
    }

    int result;
    char c;
    char pass[25];

    std::cout << YELLOW << "Generating a key:"<<NO_COLOR;

    for (int i; i<=25; i++)  {
        std::cout<< '.';
        sgx_status_t status2 = hello (global_eid, &result, &c);
        pass[i] = c;
        if (status2 != SGX_SUCCESS) {
            std::cerr << "Enclave have not called sucessfully" << std::endl;
            return 1;
        }
    }

    //Terminating the color and displaying done
    std::cout<< GREEN << "DONE"<< NO_COLOR << std::endl;

    std::cout<<"GANARATED KEY: "<< GREEN;
    for (int i = 25; i>=0; i--){
      std::cout<< pass[i];
    }
    std::cout <<NO_COLOR<< std::endl;
    return 0;
}
