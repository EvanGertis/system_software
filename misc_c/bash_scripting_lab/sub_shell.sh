#!/bin/bash
local_files=$(ls)
permissions=$(ls -l | cut -d " " -f 1)

echo $permissions
