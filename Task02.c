#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256

void printBN(char *msg, BIGNUM * a){
    char * number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
}

int main(){
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *n = BN_new(); // Public Key
    BIGNUM *e = BN_new(); // Public Key
    BIGNUM *M = BN_new(); // Private Msg
    BIGNUM *d = BN_new(); // Private Key

    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&M, "4120746f702073656372657421");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

    BIGNUM *enc_msg = BN_new(); // Encrypted message
    BN_mod_exp(enc_msg, M, e, n, ctx);
    printBN("Encrypted Message = ", enc_msg);

    BN_free(n);
    BN_free(e);
    BN_free(d);
    BN_free(M);

    return 0;
}