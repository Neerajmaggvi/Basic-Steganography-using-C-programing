#include <stdio.h>
int main() 
{
    // ----------------------- Encoding ------------------------------
    char buffer[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}; // Data in which we are going to hide data.

    char ch = 'A'; // Data to hide.

    printf("Buffer before encoding ===> ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c",buffer[i]);
    }
    printf("\n");

    int i = 7;
    int j = 0;
    int store;

    while(i >= 0)
    {
        store = (ch & (1 << i)) >> i; // Get the MSB bit from ch.

        int clear = buffer[j] & (~1); // Clear the MSB bit.
        buffer[j] = store | clear; // set the LSB bit.
        i--;
        j++;
    }

    printf("Buffer after encoding ===> ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c",buffer[i]);
    }
    printf("\n");
    
    // ------------------------ Decoding -------------------------
    int bit;
    int pos = 7;
    int result = 0;
    int k = 0;

    while (k < 8)
    {
        bit = buffer[k] & 1;
        result = result | (bit << pos);
        k++;
        pos--;
    }

    printf("Information =====> %c\n",result);
    

    return 0;
}