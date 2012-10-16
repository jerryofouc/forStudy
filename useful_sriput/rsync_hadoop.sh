#!/bin/bash
for a in `sort -u $HADOOP_HOME/conf/{slaves,masters}`; 
do 
	rsync -e ssh -a --exclude 'logs/*' --exclude 'src/*' --exclude 'docs/*' \
	--exclude 'docs/*' "${HADOOP_HOME}" ${a}:"${HADOOP_HOME}";
done
