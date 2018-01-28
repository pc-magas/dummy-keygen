#include <iostream>
#include "Enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"
#include <string.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
using namespace std;

/* Global EID shared by multiple threads */
sgx_enclave_id_t global_eid = 0;

int main(int argc, char const *argv[]) {
    if (initialize_enclave(&global_eid, "enclave.token", "./bin/enclave.signed.so") < 0) {
        std::cerr << "Fail to initialize enclave." << std::endl;
        return 1;
    }

    int result,a=2, b=1, g=25;

    char c;
    char pass[25];
    char pin[25];

    std::cout << "Calling secure adding" << std::endl;
    sgx_status_t status = sum(global_eid, &a,&b,&result);
    for (int i; i<=25; i++)

    {sgx_status_t status2 = hello (global_eid, &result, &c);
        pass[i] = c;

        //cout << "piou";

    }
    //sgx_status_t status3 = keyGen (global_eid, pin, pass);
    std::cout << "Enclave Returned status: " << std::hex << status << std::endl;

    if (status != SGX_SUCCESS) {
        std::cerr << "Enclave have not called sucessfully" << std::endl;
        return 1;
    }
    //std::cout << "EDO" << '\n';
    for (int i = 25; i>=0; i--){
      cout<< pass[i];
    }
    std::cout << "\n \n \n Sum result: " << result << std::endl;
    //std::cout << "Hello Result: %s "<< c << std::endl;
    //std::cout << "Your Pass fff: "<< pass << std::endl;
    //printf("Your Pass fff: %s\n", pass);

    return 0;
}
