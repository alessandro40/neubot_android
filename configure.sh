JAVASRCDIR=src/org/neubot/neubot
JAVAGENDIR=$JAVASRCDIR/swig
JAVANATIVEDIR=jni

install -d $JAVASRCDIR $JAVANATIVEDIR $JAVAGENDIR
swig -java -package org.neubot.neubot.swig -outdir $JAVAGENDIR $JAVANATIVEDIR/neubot.i
