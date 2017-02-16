#include <kos.h>
#include <assert.h>
#include <png/png.h>
#include <zlib/zlib.h>

/* execute a binary (c) 2002 Dan Potter, (c) 2011 PH3NOM */

void bin_exec( char * binary ) {

    /* Open the input bin file */
    FILE * bin_file = fopen( binary,"rb" );
    assert( bin_file);

    /* obtain the bin file size using fseek */
    fseek ( bin_file , 0, SEEK_END );
    int lSize = ftell   ( bin_file );
    fseek ( bin_file , 0, SEEK_SET );

    /* allocate the buffer, then read the file into it */
    unsigned int * bin_buffer = malloc( lSize );
    assert( bin_buffer );
    fread ( bin_buffer, 1, lSize, bin_file );
    fclose( bin_file );

    /* Tell exec to replace us */
    arch_exec( bin_buffer, lSize );

}

int main(void)
{
    int done = 0;

    /* init kos  */
    pvr_init_defaults();
 
    /* set the video mode  */
    vid_set_mode(DM_640x480, PM_RGB565);        

/* Todo: search for binaries on the disc */
    bin_exec("/cd/games/GAME01.BIN");

    return 0;
}