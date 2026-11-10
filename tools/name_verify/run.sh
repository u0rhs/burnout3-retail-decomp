#!/bin/bash
# Independent verification of research/retail_names.csv against the code (docs/name-verification.md).
# Run from the repo root in Git Bash: bash tools/name_verify/run.sh  -> research/name_verify/*.csv
set -e
D=tools/name_verify; O=research/name_verify; mkdir -p $O
cp $D/norm.py $D/verify_tok.py $O/ 2>/dev/null || true
python -I $D/ealign.py
python -I $D/verify.py $O && python -I $D/verify2.py $O && python -I $D/verify3.py $O
python -I $D/sandwich.py $O && python -I $D/final.py $O && python -I $D/negctl.py $O
python -I $D/wikitest.py $O
