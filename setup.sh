therelease=CMSSW_7_4_7_patch1

# export SCRAM_ARCH=slc6_amd64_gcc530
if [ ! -d "common/$therelease" ]; then
    (cd common/ ; cmsrel "$therelease")
    mkdir "common/$therelease/src/HiggsAnalysis/"
    ln -s ../../../HiggsAnalysis-CombinedLimit "common/$therelease/src/HiggsAnalysis/CombinedLimit"
fi

cd "common/$therelease/src"
cmsenv
cd "../../.."

export LD_LIBRARY_PATH=$PWD/babymaking/batch:$LD_LIBRARY_PATH
export PYTHONPATH=$PWD:$PYTHONPATH

if [ "$1" = "build" ]; then
    (cd "common/$therelease/src" ; scram b -j 15)
    make -j15 -C common/CORE
fi
