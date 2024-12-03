#!/bin/bash
grep -Eo "mul\([0-9]{1,3},[0-9]{1,3}\)" | awk -F'[(),]' '{sum += $2 * $3} END {print sum}'
