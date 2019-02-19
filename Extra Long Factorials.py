#!/bin/python

import math
import os
import random
import re
import sys

# Complete the extraLongFactorials function below.
def extraLongFactorials(n):
    if n == 0:
        return 1
    elif n ==1: 
        return 1;
    else :
        return extraLongFactorials(n-1)*n;

if __name__ == '__main__':
    n = int(raw_input())

    print extraLongFactorials(n)
