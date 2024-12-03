#!/bin/bash
grep -Eo "(mul\([0-9]{1,3},[0-9]{1,3}\)|do\(\)|don't\(\))" | awk "/don't\(\)/{f=1}!f;/do\(\)/{f=0}" | awk -F'[(),]' '{sum += $2 * $3} END {print sum}'
