#include <stdio.h>
#include <string.h>

inline static void assemble_flag(char *flag) {
    const char *flag_str = "flag{HideMe}";
    strcpy(flag, flag_str);
}

__declspec(dllexport) int check_key(char *key) {
    // Encrypted key: "CTF34D3X" XOR'd with 0x5
   static char encrypted_key[8];
    encrypted_key[0] = 'F';
    encrypted_key[1] = 'Q';
    encrypted_key[2] = 'C';
    encrypted_key[3] = '6';
    encrypted_key[4] = '1';
    encrypted_key[5] = 'A';
    encrypted_key[6] = '6';
    encrypted_key[7] = ']';

    //(forces compiler to keep encrypted key)
   char first_char = encrypted_key[0];

    for (int i = 0; i < 8; i++) {
        if ((key[i] ^ 0x5) != encrypted_key[i]) {
            return 0;  // Key is incorrect if any character doesn't match
        }
    }
    return 1;  // Key is correct if all characters match
}

int main() {
    char key[50];
    char flag[50];

    printf("Enter the serial key: ");
    scanf("%49s", key);  // Read up to 49 characters to avoid buffer overflow

    // Ensure check_key is used directly
    if (check_key(key)) {
        assemble_flag(flag);
        printf("Correct! The flag is: %s\n", flag);
    } else {
        printf("Incorrect key! Try again.\n");
    }

    return 0;
}