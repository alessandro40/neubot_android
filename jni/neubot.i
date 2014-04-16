%module(directors="1") neubotjava;
%feature("director");
%include "./libneubot/neubot.h"
%{
#include "./libneubot/neubot.h"
%}
