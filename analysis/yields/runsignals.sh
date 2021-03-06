#!/usr/bin/env bash


# dir="v3.28_ss_mar9_allsignals_v1"
# dir="v3.28_ss_mar12allsigs_v1"
# dir="v3.28_ss_mar13allsigs_v1"
dir="v3.31_ss_Jun26_v1c"

# Run backgrounds, data, etc.
python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --slim 

# Run signals now
# Break up into chunks because of memory issues/leaks

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t1ttbb*" --year 2016
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t1ttbb*" --year 2017
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t1ttbb*" --year 2018

python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5ttcc*" --year 2016
python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5ttcc*" --year 2017
python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5ttcc*" --year 2018

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5tttt*" --year 2016
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5tttt*" --year 2017
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5tttt*" --year 2018

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t1tttt*" --year 2016
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t1tttt*" --year 2017
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t1tttt*" --year 2018

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t6ttww*" --year 2016
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t6ttww*" --year 2017
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t6ttww*" --year 2018

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5qqqqvv_*" --year 2016
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5qqqqvv_*" --year 2017
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5qqqqvv_*" --year 2018

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5qqqqvvdm20*" --year 2016
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5qqqqvvdm20*" --year 2017
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5qqqqvvdm20*" --year 2018

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5qqqqww_*" --year 2016
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5qqqqww_*" --year 2017
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5qqqqww_*" --year 2018

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5qqqqwwdm20*" --year 2016
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5qqqqwwdm20*" --year 2017
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5qqqqwwdm20*" --year 2018

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5tttt*" --year 2016
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5tttt*" --year 2017
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t5tttt*" --year 2018

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t6tthzbrb*" --year 2016
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t6tthzbrb*" --year 2017
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t6tthzbrb*" --year 2018

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t6tthzbrh*" --year 2016
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t6tthzbrh*" --year 2017
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t6tthzbrh*" --year 2018

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t6tthzbrz*" --year 2016
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t6tthzbrz*" --year 2017
# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t6tthzbrz*" --year 2018

# python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --proc "fs_t1qqqql*"

# At the end, don't loop, but make shapes for all the things
python py_doAll.py --tag ${dir}  --ss --fastsim --ncpu 30 --shapes --noloop
