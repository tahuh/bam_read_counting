#!/usr/bin/python

import pysam
import sys

if len(sys.argv) < 2:
	sys.stderr.write("usage: bamReadCount.py in.bam\n");
	exit(-1)
bamname = sys.argv[1]
bam = pysam.AlignmentFile(bamname)
nreads = 0
for read in bam.fetch():
	nreads += 1
sys.stdout.write("%d reads in %s\n"%(nreads, bamname))
bam.close()
