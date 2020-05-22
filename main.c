/*
 * main.c
 * Count-up the reads in BAM file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htslib/sam.h"

size_t NREADS = 0;

int main(int argc, char **argv)
{
    if(argc < 2) {
        fprintf(stderr, "usage: bamReadCount in.bam\n");
        exit(-1);
    }
    const char *bamname = argv[1];
    samFile *fp = sam_open(bamname, "r");
    sam_hdr_t *hdr = sam_hdr_read(fp);
    bam1_t *b = bam_init1();
    while(sam_read1(fp, hdr, b) >= 0){
        NREADS++;
    }
    sam_close(fp);
    sam_hdr_destroy(hdr);
    bam_destroy1(b);
    fprintf(stdout, "%zu reads in %s\n", NREADS, bamname);
    return 0;
}
