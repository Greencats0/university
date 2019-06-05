#include <stdio.h>
#include <stdbool.h>


#define BUFSZ 180
// void read_sections(int s, int e, unsigned char* array, bool integer){
//   for(int i = s; i < e; ++i){
//     if(integer){ printf("%i", array[i]); }
//     else { printf("%c", array[i]); }
//   }
// }
// struct comm_packet {                               // Offset
//   char            Id[4];                         //   0
//   char            NodeName[8];                   //   4
//   int             NodeNumber;                    //  12
//   int             tx_packet_nbr;                 //  16
//   int             rx_packet_nbr;                 //  20
//   int             track_object_nbr;              //  24
//   int             track_object_x_pos;            //  28
//   int             track_object_y_pos;            //  32
//   int             track_object_z_pos;            //  36
//   int             track_object_velocity;         //  40
//   int             status_code;                   //  44
//   unsigned char   msg_length;                    //  48
//   char            status_msg[128];               //  49
// };
int main (int argc, char **argv) {

    unsigned char buf[BUFSZ] = {0};
    unsigned char key[9] = {0x36,0x13,0x92,0xa5,0x5a,0x27,0xf3,0x00,0x32};
    int index = 0;
    size_t bytes = 0, i, readsz = sizeof buf;
    FILE *fp = argc > 1 ? fopen (argv[1], "rb") : stdin;

    if (!fp) {
        fprintf (stderr, "error: file open failed '%s'.\n", argv[1]);
        return 1;
    }

    /* read/output BUFSZ bytes at a time */
    while ((bytes = fread (buf, sizeof *buf, readsz, fp)) == readsz) {
        for (i = 0; i < readsz; i++){
          buf[i] = buf[i] ^ key[index%sizeof(key)];
          printf("%c", buf[i]);
          index++;
        }
    }
    if (fp != stdin)
        fclose (fp);
    printf("ID: ");
    // read_sections(0, 4, buf, false);
    return 0;
}
