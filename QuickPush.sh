#! /bin/sh

git add --all
git commit -m "Auto Push"
git push
rm ./*/*.run
rm ./*/*/*.run
rm ./*/*/*/*.run
