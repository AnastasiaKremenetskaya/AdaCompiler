#filelist="test0.txt file2.txt file3.txt"
for f in /Users/anastasiakremeneckaa/github/AdaCompiler/out/*.txt;
  do dot -Tpng -O ${f}
done;