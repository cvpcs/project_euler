#!/bin/bash

# re-format the input to make it more... usable
sed -r 's/"//g' - | sed -r 's/,/\n/g' | sort
