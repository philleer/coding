#!/bin/bash

# =============================================================================
# Desciption: Given a text file file.txt that contains list of phone numbers
#       (one per line), write a one liner bash script to print all valid phone
#       numbers. You may assume that a valid phone number must appear in one of
#       the following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. You may also
#       assume each line in the text file must not contain leading or trailing
#       white spaces.
# Example: Assume that file.txt has the following content:
#           987-123-4567
#           123 456 7890
#           (123) 456-7890
#       Your script should output the following valid phone numbers:
#           987-123-4567
#           (123) 456-7890
# =============================================================================

# Read from the file file.txt and output all valid phone numbers to stdout.
while read line
do
    if [[ $line = '('[0-9][0-9][0-9]') '[0-9][0-9][0-9]'-'[0-9][0-9][0-9][0-9] ]]
    then
        echo $line
    elif [[ $line = [0-9][0-9][0-9]'-'[0-9][0-9][0-9]'-'[0-9][0-9][0-9][0-9] ]]
    then
        echo $line
    fi
done < file.txt

# I don't know why the following does not work well yet, and I'll check it then
# if [[ $line = "^\([0-9]{3}\)[[:space:]][0-9]{3}-[0-9]{4}$" ]] || \
#    [[ $line =~ "[0-9]{3}-[0-9]{3}-[0-9]{4}$" ]]; then
#   echo #line
# fi

# And also the following methods
# <a> Using grep: grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
# <b> Using sed: sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' \
#                file.txt
# <c> Using awk: awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt
