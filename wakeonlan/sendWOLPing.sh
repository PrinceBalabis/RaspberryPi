#!/bin/bash
# Run example:
# chmod u+x sendWOLPing.sh
# ./sendWOLPing.sh 00:24:1D:8B:66:76
wakeonlan $1
